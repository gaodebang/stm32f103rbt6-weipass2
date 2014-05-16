/*
*********************************************************************************************************
*
*	模块名称 : 串口模块
*	文件名称 : app_uart.c
*	版    本 : V1.0
*	说    明 : 
*
*********************************************************************************************************
*/

#include "app.h"


#define frame_TIME_OUT 	50		//定义帧字节间隔超时时间
#define frame_SOF				0x55	//定义帧起始字节
#define frame_EOF				0xAA	//定义帧结束字节
#define frame_MARK			0xFF	//定义转义标志
#define USART1_DATA_MAX_LEN			1000


typedef enum
{
	frame_sof = 0, 
	frame_normal,
	frame_mark,
	frame_eof
}FRAME_STATE;//定义接收数据包时的状态机

uint8_t Usart1_Txd_Tempdata[500];

void USART1_Tx_Chars(u8 *puchMsg,u16 num)
{
	u16 i;
	comSendChar(COM1, frame_SOF);
	for (i=0;i<num;i++)
	{
		if ((*(puchMsg + i) == frame_SOF)||(*(puchMsg + i) == frame_EOF)||(*(puchMsg + i) == frame_MARK))
		{
			comSendChar(COM1, frame_MARK);
		}
		comSendChar(COM1, *(puchMsg + i));
	}
	comSendChar(COM1, frame_EOF);
}

/*
*********************************************************************************************************
*	函 数 名: judge_cmd_correct
*	功能说明: 检查数据包校验，check出命令
*	形    参：databuf	：串口接收到的数据包的首字节地址
						length	: 数据包长度
*	返 回 值: 返回命令对象代号：
						0：无效
						1：打印机
*********************************************************************************************************
*/
static uint8_t judge_cmd_correct(uint8_t *databuf, uint16_t length)
{
	uint16_t message_length;
	message_length = (uint16_t)*databuf << 8 | (uint16_t)*(databuf+1);
	if (length == message_length + 2)
	{
		switch (*(databuf+2))
		{
			case PRINTER://打印机相关命令
				return 1;
			case PA1100:
				return 2;
			case ESAM8810:
				return 3;
			case PSAM_CARD:
				return 4;
			default :
				return 0;
		}
	}
	else
	{
		return 0xFF;
	}
}

/*
*********************************************************************************************************
*	函 数 名: checkout_cmd
*	功能说明: 检查数据包校验，check出命令对象，调用相关函数
*	形    参：databuf	：串口接收到的数据包的首字节地址
						length	: 数据包长度
*	返 回 值: 无
*********************************************************************************************************
*/
static void checkout_cmd(uint8_t *databuf, uint16_t length)
{
	switch (judge_cmd_correct(databuf, length))
	{
		case 0:
			//命令对象不存在
			Usart1_Txd_Tempdata[0] = 0x00;
			Usart1_Txd_Tempdata[1] = 0x20;
			Usart1_Txd_Tempdata[2] = *(databuf + 2) | 0x80;
			Usart1_Txd_Tempdata[3] = 0x01;
			USART1_Tx_Chars(Usart1_Txd_Tempdata, 4);
			break;
		case 1:
			//打印机相关命令
			printer_CMD_DEAL(databuf+3, length-3);//调用打印机命令执行函数
			break;
		case 2:
			pa1100_CMD_DEAL(databuf+3, length-3);//调用磁头命令执行函数
			break;
		case 3:
			esam8810_CMD_DEAL(databuf+3, length-3);//调用ESAM加密芯片命令执行函数
			break;
		case 4:
			psam_card_CMD_DEAL(databuf+3, length-3);
			break;
		case 0xFF:
			//数据包校验出错（长度）
			Usart1_Txd_Tempdata[0] = 0x00;
			Usart1_Txd_Tempdata[1] = 0x20;
			Usart1_Txd_Tempdata[2] = *(databuf + 2) | 0x80;
			Usart1_Txd_Tempdata[3] = 0x00;
			USART1_Tx_Chars(Usart1_Txd_Tempdata, 4);
			break;
		default :
			//命令对象不存在
			Usart1_Txd_Tempdata[0] = 0x00;
			Usart1_Txd_Tempdata[1] = 0x20;
			Usart1_Txd_Tempdata[2] = *(databuf + 2) | 0x80;
			Usart1_Txd_Tempdata[3] = 0x01;
			USART1_Tx_Chars(Usart1_Txd_Tempdata, 4);			
			break;
	}
}

/*
*********************************************************************************************************
*	函 数 名: uart_SERVER_TASK
*	功能说明: 串口数据服务函数，根据通信协议，check出正常的数据包
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
uint8_t uart_SERVER_TASK(void)
{
	uint8_t temp_data;

	static uint16_t Rxdtime = 0;
	static uint16_t USART1_RXD_CON = 0;
	static uint8_t Usart1_Rxd_Tempdata[USART1_DATA_MAX_LEN];

	static FRAME_STATE uart_FRAME_STATE = frame_sof;	
	
	if (comGetChar(COM1, &temp_data) == 0)
	{
		if (Rxdtime > 0)
		{
			Rxdtime--;
		}
		else
		{
			uart_FRAME_STATE = frame_sof;
		}
	}
	else
	{
		if ((Rxdtime == 0)&&(uart_FRAME_STATE == frame_sof)&&(temp_data == frame_SOF))
		{
			USART1_RXD_CON = 0;
			uart_FRAME_STATE = frame_normal;
		}
		else if (uart_FRAME_STATE == frame_normal)
		{
			if (temp_data == frame_MARK)
			{
				uart_FRAME_STATE = frame_mark;
			}
			else if (temp_data == frame_SOF)
			{
				//错误数据包
				uart_FRAME_STATE = frame_sof;//初始化状态机
			}
			else if (temp_data == frame_EOF)
			{
				uart_FRAME_STATE = frame_eof;
				checkout_cmd(Usart1_Rxd_Tempdata, USART1_RXD_CON);	//收到符合协议的数据包，解析命令
			}
			else
			{
				Usart1_Rxd_Tempdata[USART1_RXD_CON] = temp_data;
				USART1_RXD_CON++;
			}
		}
		else if (uart_FRAME_STATE == frame_mark)
		{
			if ((temp_data == frame_MARK) || (temp_data == frame_SOF) || (temp_data == frame_EOF))
			{
				Usart1_Rxd_Tempdata[USART1_RXD_CON] = temp_data;
				USART1_RXD_CON++;
				uart_FRAME_STATE = frame_normal;
			}
			else
			{
				//错误的数据包
				uart_FRAME_STATE = frame_sof;//初始化状态机
			}
		}
		Rxdtime = frame_TIME_OUT;
	}
	return 0;
}
