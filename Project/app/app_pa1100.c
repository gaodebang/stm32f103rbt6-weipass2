/*
*********************************************************************************************************
*
*	模块名称 : 磁头模块
*	文件名称 : app_PA1100.c
*	版    本 : V1.0
*	说    明 : 
*
*********************************************************************************************************
*/

#include "app.h"

//PA1100磁头驱动芯片的应用命令
typedef enum
{
	CESHI = 0x10
}PA1100_CMD_NAME;

/* 磁头驱动芯片引脚 */
//数据通信，SPI_MOSI、SPI_SCK
#define RCC_PA1100_INTERFACE_GPIO					(RCC_APB2Periph_GPIOA)
#define GPIO_PA1100_INTERFACE_PORT 				(GPIOA)
#define GPIO_PA1100_INTERFACE_SPI_SCK			(GPIO_Pin_5)
#define GPIO_PA1100_INTERFACE_SPI_MOSI		(GPIO_Pin_7)

#define PA1100_MOSI_HIGH()	do{	\
	GPIO_SetBits(GPIO_PA1100_INTERFACE_PORT, GPIO_PA1100_INTERFACE_SPI_MOSI); \
	bsp_DelayUS(10);\
}while(0)

#define PA1100_MOSI_LOW() do{	\
	GPIO_ResetBits(GPIO_PA1100_INTERFACE_PORT, GPIO_PA1100_INTERFACE_SPI_MOSI); \
	bsp_DelayUS(10);\
}while(0)

#define PA1100_SCK_HIGH()	do{	\
	GPIO_SetBits(GPIO_PA1100_INTERFACE_PORT, GPIO_PA1100_INTERFACE_SPI_SCK); \
	bsp_DelayUS(10);\
}while(0)

#define PA1100_SCK_LOW() do{	\
	GPIO_ResetBits(GPIO_PA1100_INTERFACE_PORT, GPIO_PA1100_INTERFACE_SPI_SCK); \
	bsp_DelayUS(10);\
}while(0)

/*
*********************************************************************************************************
*	函 数 名: is_detect_down
*	功能说明: 磁头驱动芯片数据引脚检测
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
static uint8_t is_detect_down(void) 
{
	if ((GPIO_PA1100_INTERFACE_PORT->IDR & GPIO_PA1100_INTERFACE_SPI_MOSI) == RESET) 
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
*********************************************************************************************************
*	函 数 名: set_mosi_out_pp
*	功能说明: 磁头驱动芯片数据引脚设置为推挽输出
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
static void set_mosi_out_pp(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin = GPIO_PA1100_INTERFACE_SPI_MOSI;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIO_PA1100_INTERFACE_PORT, &GPIO_InitStructure);
}

/*
*********************************************************************************************************
*	函 数 名: set_mosi_ipu
*	功能说明: 磁头驱动芯片数据引脚设置为输入上拉
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
static void set_mosi_ipu(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin = GPIO_PA1100_INTERFACE_SPI_MOSI;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIO_PA1100_INTERFACE_PORT, &GPIO_InitStructure);
}

/*
*********************************************************************************************************
*	函 数 名: spi_read_byte
*	功能说明: 磁头驱动芯片读取一字节数据
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
static uint8_t spi_read_byte(void)
{
	uint8_t i;
	uint8_t temp_data = 0;
	for(i = 0; i < 8; i ++)
	{
		if(is_detect_down())
		{
		}
		else
		{
			 temp_data |= (1 << 7 - i);
		}
		PA1100_SCK_HIGH();
		PA1100_SCK_LOW();
	}
	return temp_data;
}

/*
*********************************************************************************************************
*	函 数 名: pa1100_rst
*	功能说明: 磁头驱动芯片复位操作
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
static void pa1100_rst(void)
{
	//数据上升沿有效 发送 011	
	set_mosi_out_pp();
	
	PA1100_SCK_HIGH();
	PA1100_MOSI_HIGH();
	
	
	PA1100_MOSI_LOW();
	
	PA1100_SCK_LOW();
	PA1100_SCK_HIGH();
	PA1100_SCK_LOW();
	
	
	PA1100_MOSI_HIGH();
	
	PA1100_SCK_HIGH();
	PA1100_SCK_LOW();
	PA1100_SCK_HIGH();
	PA1100_SCK_LOW();
	
	set_mosi_ipu();
}

/*
*********************************************************************************************************
*	函 数 名: pa1100_read_data
*	功能说明: 磁头驱动芯片数据读取操作
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
static void pa1100_read_data(uint8_t *databuf)
{
	uint16_t i;
	for(i = 0; i < 270; i ++)
	{
		*(databuf + i) = spi_read_byte();
	}
	pa1100_rst();
}

/*
*********************************************************************************************************
*	函 数 名: pa1100_Init
*	功能说明: 磁头芯片驱动初始化。包含1.各驱动信号IO初始化  2.SPI初始化
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
void pa1100_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/* PA1100-SPI通信引脚 */
	RCC_APB2PeriphClockCmd(RCC_PA1100_INTERFACE_GPIO, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_PA1100_INTERFACE_SPI_SCK;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIO_PA1100_INTERFACE_PORT, &GPIO_InitStructure);

	pa1100_rst();
}

/*
*********************************************************************************************************
*	函 数 名: ceshi
*	功能说明: 
*	形    参: 无
*	返 回 值: 无
*********************************************************************************************************
*/
static void ceshi(void)
{
	uint8_t temp_data;
	uint8_t databuf[300];
	
	temp_data = is_detect_down();

	if(temp_data)
	{//test 成功
		PA1100_SCK_HIGH();
		PA1100_SCK_LOW();
		PA1100_SCK_HIGH();
		PA1100_SCK_LOW();
		
		memset(databuf, 0, 300);
		pa1100_read_data(databuf);
		//comSendBuf(COM1, databuf+2, 88*3);
		Usart1_Txd_Tempdata[0] = 1;
		Usart1_Txd_Tempdata[1] = 43;
		Usart1_Txd_Tempdata[2] = PA1100;
		memcpy((char *)(Usart1_Txd_Tempdata + 3), (const char *)databuf, 300);
		USART1_Tx_Chars(Usart1_Txd_Tempdata, 303);
	}
	else
	{
		Usart1_Txd_Tempdata[0] = 0x00;
		Usart1_Txd_Tempdata[1] = 0x02;
		Usart1_Txd_Tempdata[2] = PA1100 | 0x80;
		Usart1_Txd_Tempdata[3] = 0x30;
		USART1_Tx_Chars(Usart1_Txd_Tempdata, 4);
	}
}

/*
*********************************************************************************************************
*	函 数 名: pa1100_CMD_DEAL
*	功能说明: 处理磁头相关命令
*	形    参：databuf	：串口接收到的数据包的首字节地址
						length	: 数据包长度
*	返 回 值: 无
*********************************************************************************************************
*/
void pa1100_CMD_DEAL(uint8_t *databuf, uint16_t length)
{
	switch (*databuf)
	{
		case CESHI:
			//测试命令
			if(*(databuf + 1) == 0x00)
			{
				ceshi();
			}
			else if(*(databuf + 1) == 0x01)
			{
				pa1100_rst();
				Usart1_Txd_Tempdata[0] = 0x00;
				Usart1_Txd_Tempdata[1] = 0x01;
				Usart1_Txd_Tempdata[2] = PA1100;
				USART1_Tx_Chars(Usart1_Txd_Tempdata, 3);
			}
			break;
		default :
			//对象不支持该命令
			Usart1_Txd_Tempdata[0] = 0x00;
			Usart1_Txd_Tempdata[1] = 0x02;
			Usart1_Txd_Tempdata[2] = PA1100 | 0x80;
			Usart1_Txd_Tempdata[3] = 0x10;
			USART1_Tx_Chars(Usart1_Txd_Tempdata, 4);
			break;
	}
}

/*
*********************************************************************************************************
*	函 数 名: pa1100_SERVER_TASK
*	功能说明: 磁头相关服务函数
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
void pa1100_SERVER_TASK(void)
{
  static uint32_t sys_time, time_ms = 0, time_add_up = 0;
  const uint32_t work_time_max = 2;
	uint32_t offset_time_ticks = 0;
	uint8_t timeout_flag = 0;
	DISABLE_INT();
	sys_time = Sys_Time;
	ENABLE_INT();
	
	if (time_ms != sys_time)
	{
		if (time_ms < sys_time)
		{
			offset_time_ticks = sys_time - time_ms;
			time_ms = sys_time;
			if (((uint64_t)offset_time_ticks  + (uint64_t)time_add_up) > UINT_LEAST32_MAX)
			{
				timeout_flag = 1;
				time_add_up = 0;
			}
			else if ((offset_time_ticks  + time_add_up) > work_time_max)
			{
				timeout_flag = 1;
				time_add_up = 0;
			}
			else
			{
				time_add_up += offset_time_ticks;
			}
		}
		else
		{
			offset_time_ticks = UINT_LEAST32_MAX + sys_time - time_ms;
			time_ms = sys_time;
			if (((uint64_t)offset_time_ticks  + (uint64_t)time_add_up) > UINT_LEAST32_MAX)
			{
				timeout_flag = 1;
				time_add_up = 0;
			}
			else if ((offset_time_ticks  + time_add_up) > work_time_max)
			{
				timeout_flag = 1;
				time_add_up = 0;
			}
			else
			{
				time_add_up += offset_time_ticks;
			}
		}
		if (timeout_flag == 1)
		{
			timeout_flag = 0;
			
		}
	}
}
