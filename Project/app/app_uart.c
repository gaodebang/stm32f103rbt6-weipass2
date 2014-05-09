/*
*********************************************************************************************************
*
*	ģ������ : ����ģ��
*	�ļ����� : app_uart.c
*	��    �� : V1.0
*	˵    �� : 
*
*********************************************************************************************************
*/

#include "app.h"


#define frame_TIME_OUT 	50		//����֡�ֽڼ����ʱʱ��
#define frame_SOF				0x55	//����֡��ʼ�ֽ�
#define frame_EOF				0xAA	//����֡�����ֽ�
#define frame_MARK			0xFF	//����ת���־
#define USART1_DATA_MAX_LEN			1000


typedef enum
{
	frame_sof = 0, 
	frame_normal,
	frame_mark,
	frame_eof
}FRAME_STATE;//����������ݰ�ʱ��״̬��

uint8_t Usart1_Txd_Tempdata[10];

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
*	�� �� ��: judge_cmd_correct
*	����˵��: ������ݰ�У�飬check������
*	��    �Σ�databuf	�����ڽ��յ������ݰ������ֽڵ�ַ
						length	: ���ݰ�����
*	�� �� ֵ: �������������ţ�
						0����Ч
						1����ӡ��
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
			case 0x11://��ӡ���������
				return 1;
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
*	�� �� ��: checkout_cmd
*	����˵��: ������ݰ�У�飬check��������󣬵�����غ���
*	��    �Σ�databuf	�����ڽ��յ������ݰ������ֽڵ�ַ
						length	: ���ݰ�����
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void checkout_cmd(uint8_t *databuf, uint16_t length)
{
	switch (judge_cmd_correct(databuf, length))
	{
		case 0:
			//������󲻴���
			Usart1_Txd_Tempdata[0] = 0x00;
			Usart1_Txd_Tempdata[1] = 0x20;
			Usart1_Txd_Tempdata[2] = *(databuf + 2) | 0x80;
			Usart1_Txd_Tempdata[3] = 0x01;
			USART1_Tx_Chars(Usart1_Txd_Tempdata, 4);
			break;
		case 1:
			//��ӡ���������
			printer_CMD_DEAL(databuf+3, length-3);//���ô�ӡ������ִ�к���
			break;
		case 0xFF:
			//���ݰ�У����������ȣ�
			Usart1_Txd_Tempdata[0] = 0x00;
			Usart1_Txd_Tempdata[1] = 0x20;
			Usart1_Txd_Tempdata[2] = *(databuf + 2) | 0x80;
			Usart1_Txd_Tempdata[3] = 0x00;
			USART1_Tx_Chars(Usart1_Txd_Tempdata, 4);
			break;
		default :			
			break;
	}
}

/*
*********************************************************************************************************
*	�� �� ��: uart_SERVER_TASK
*	����˵��: �������ݷ�����������ͨ��Э�飬check�����������ݰ�
*	��    �Σ���
*	�� �� ֵ: ��
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
				//�������ݰ�
				uart_FRAME_STATE = frame_sof;//��ʼ��״̬��
			}
			else if (temp_data == frame_EOF)
			{
				uart_FRAME_STATE = frame_eof;
				checkout_cmd(Usart1_Rxd_Tempdata, USART1_RXD_CON);	//�յ�����Э������ݰ�����������
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
				//��������ݰ�
				uart_FRAME_STATE = frame_sof;//��ʼ��״̬��
			}
		}
		Rxdtime = frame_TIME_OUT;
	}
	return 0;
}