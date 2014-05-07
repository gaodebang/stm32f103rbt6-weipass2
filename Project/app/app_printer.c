/*
*********************************************************************************************************
*
*	模块名称 : 打印机模块
*	文件名称 : app_printer.c
*	版    本 : V1.0
*	说    明 : 
*
*********************************************************************************************************
*/

#include "app.h"

#define LineDot		(384)	// 721三寸机芯为576点 

uint8_t Motor_Feed_Step = 0;
static uint8_t TP_dot[16][LineDot/8+1];

//打印机电源
#define RCC_PRINTER_PWR 						(RCC_APB2Periph_GPIOA)
#define GPIO_PRINTER_PWR_PORT 			(GPIOA)
#define GPIO_PRINTER_PWR_PIN 				(GPIO_Pin_8)

#define PRINTER_PWR_ON()	do{	\
	GPIO_SetBits(GPIO_PRINTER_PWR_PORT, GPIO_PRINTER_PWR_PIN); \
}while(0)

#define PRINTER_PWR_OFF() do{	\
	GPIO_ResetBits(GPIO_PRINTER_PWR_PORT, GPIO_PRINTER_PWR_PIN); \
}while(0)

//打印机步进电机电源
#define RCC_PRINTER_MOTOR_PWR 						(RCC_APB2Periph_GPIOC)
#define GPIO_PRINTER_MOTOR_PWR_PORT 			(GPIOC)
#define GPIO_PRINTER_MOTOR_PWR_PIN 				(GPIO_Pin_11)

#define PRINTER_MOTOR_PWR_ON()	do{	\
	GPIO_SetBits(GPIO_PRINTER_MOTOR_PWR_PORT, GPIO_PRINTER_MOTOR_PWR_PIN); \
}while(0)

#define PRINTER_MOTOR_PWR_OFF() do{	\
	GPIO_ResetBits(GPIO_PRINTER_MOTOR_PWR_PORT, GPIO_PRINTER_MOTOR_PWR_PIN); \
}while(0)

//打印机马达相位信号
#define RCC_PRINTER_MOTOR 					(RCC_APB2Periph_GPIOB)
#define GPIO_PRINTER_MOTOR_PORT 		(GPIOB)
#define GPIO_PRINTER_MOTOR_1A_PIN 	(GPIO_Pin_4)
#define GPIO_PRINTER_MOTOR_1B_PIN 	(GPIO_Pin_5)
#define GPIO_PRINTER_MOTOR_2A_PIN 	(GPIO_Pin_8)
#define GPIO_PRINTER_MOTOR_2B_PIN 	(GPIO_Pin_9)

#define MOTOR_PHASE_A_FORWARD() do{	\
	GPIO_SetBits(GPIO_PRINTER_MOTOR_PORT, GPIO_PRINTER_MOTOR_1A_PIN);	\
	GPIO_ResetBits(GPIO_PRINTER_MOTOR_PORT, GPIO_PRINTER_MOTOR_1B_PIN);	\
}while(0)

#define MOTOR_PHASE_A_REVERSE()	do{	\
	GPIO_ResetBits(GPIO_PRINTER_MOTOR_PORT, GPIO_PRINTER_MOTOR_1A_PIN);	\
	GPIO_SetBits(GPIO_PRINTER_MOTOR_PORT, GPIO_PRINTER_MOTOR_1B_PIN);	\
}while(0)

#define MOTOR_PHASE_B_FORWARD()	do{	\
	GPIO_SetBits(GPIO_PRINTER_MOTOR_PORT, GPIO_PRINTER_MOTOR_2A_PIN);	\
	GPIO_ResetBits(GPIO_PRINTER_MOTOR_PORT, GPIO_PRINTER_MOTOR_2B_PIN);	\
}while(0)

#define MOTOR_PHASE_B_REVERSE()	do{	\
	GPIO_ResetBits(GPIO_PRINTER_MOTOR_PORT, GPIO_PRINTER_MOTOR_2A_PIN);	\
	GPIO_SetBits(GPIO_PRINTER_MOTOR_PORT, GPIO_PRINTER_MOTOR_2B_PIN);	\
}while(0)

#define MOTOR_PHASE_DISABLE()	do{	\
	GPIO_ResetBits(GPIO_PRINTER_MOTOR_PORT, GPIO_PRINTER_MOTOR_1A_PIN);	\
	GPIO_ResetBits(GPIO_PRINTER_MOTOR_PORT, GPIO_PRINTER_MOTOR_1B_PIN);	\
	GPIO_ResetBits(GPIO_PRINTER_MOTOR_PORT, GPIO_PRINTER_MOTOR_2A_PIN);	\
	GPIO_ResetBits(GPIO_PRINTER_MOTOR_PORT, GPIO_PRINTER_MOTOR_2B_PIN);	\
}while(0)

#define MOTOR_STEP_ONE()	do{ \
	MOTOR_PHASE_A_FORWARD(); \
	MOTOR_PHASE_B_FORWARD(); \
}while(0)

#define MOTOR_STEP_TWO()	do{ \
	MOTOR_PHASE_A_FORWARD(); \
	MOTOR_PHASE_B_REVERSE(); \
}while(0)

#define MOTOR_STEP_THREE()	do{ \
	MOTOR_PHASE_A_REVERSE(); \
	MOTOR_PHASE_B_REVERSE(); \
}while(0)

#define MOTOR_STEP_FOUR()	do{ \
	MOTOR_PHASE_A_REVERSE(); \
	MOTOR_PHASE_B_FORWARD(); \
}while(0)

//打印机光电检测引脚（用于检测打印纸是否正常）
#define RCC_PRINTER_DETECT 						(RCC_APB2Periph_GPIOC)
#define GPIO_PRINTER_DETECT_PORT 			(GPIOC)
#define GPIO_PRINTER_DETECT_PIN 			(GPIO_Pin_6)


//打印机加热使能引脚（使能1、2用pin0控制，使能3、4用pin1控制）
#define RCC_PRINTER_HEAT_ENABLE 						(RCC_APB2Periph_GPIOC)
#define GPIO_PRINTER_HEAT_ENABLE_PORT 			(GPIOC)
#define GPIO_PRINTER_HEAT_ENABLE_PIN_0			(GPIO_Pin_9)
#define GPIO_PRINTER_HEAT_ENABLE_PIN_1			(GPIO_Pin_8)

#define STROBE_1_ON()	do{	\
	GPIO_ResetBits(GPIO_PRINTER_HEAT_ENABLE_PORT, GPIO_PRINTER_HEAT_ENABLE_PIN_0);	\
}while(0)
#define STROBE_1_OFF()	do{	\
	GPIO_SetBits(GPIO_PRINTER_HEAT_ENABLE_PORT, GPIO_PRINTER_HEAT_ENABLE_PIN_0);	\
}while(0)

#define STROBE_2_ON()	do{	\
	GPIO_ResetBits(GPIO_PRINTER_HEAT_ENABLE_PORT, GPIO_PRINTER_HEAT_ENABLE_PIN_1);	\
}while(0)
#define STROBE_2_OFF()	do{	\
	GPIO_SetBits(GPIO_PRINTER_HEAT_ENABLE_PORT, GPIO_PRINTER_HEAT_ENABLE_PIN_1);	\
}while(0)

#define STROBE_12_ON()	do{	\
	GPIO_ResetBits(GPIO_PRINTER_HEAT_ENABLE_PORT, GPIO_PRINTER_HEAT_ENABLE_PIN_0 | GPIO_PRINTER_HEAT_ENABLE_PIN_1);	\
}while(0)
#define STROBE_12_OFF()	do{	\
	GPIO_SetBits(GPIO_PRINTER_HEAT_ENABLE_PORT, GPIO_PRINTER_HEAT_ENABLE_PIN_0 | GPIO_PRINTER_HEAT_ENABLE_PIN_1);	\
}while(0)


//打印机数据通信，SPI_MOSI、SPI_MISO、SPI_SCK
#define RCC_PRINTER_INTERFACE_GPIO				(RCC_APB2Periph_GPIOB)
#define RCC_PRINTER_INTERFACE_SPI 				(RCC_APB1Periph_SPI2)
#define GPIO_PRINTER_INTERFACE_PORT 			(GPIOB)
#define GPIO_PRINTER_INTERFACE_SPI_MOSI		(GPIO_Pin_15)
#define GPIO_PRINTER_INTERFACE_SPI_MISO		(GPIO_Pin_14)
#define GPIO_PRINTER_INTERFACE_SPI_SCK		(GPIO_Pin_13)


//打印机数据通信Latch锁存信号
#define RCC_PRINTER_LATCH 						(RCC_APB2Periph_GPIOC)
#define GPIO_PRINTER_LATCH_PORT 			(GPIOC)
#define GPIO_PRINTER_LATCH_PIN				(GPIO_Pin_7)

#define LATCH_HIGH()	do{	\
	GPIO_SetBits(GPIO_PRINTER_LATCH_PORT, GPIO_PRINTER_LATCH_PIN);	\
}while(0)

#define LATCH_LOW()	do{	\
	GPIO_ResetBits(GPIO_PRINTER_LATCH_PORT, GPIO_PRINTER_LATCH_PIN);	\
}while(0)




/*
*********************************************************************************************************
*	函 数 名: IsDetect_Ok
*	功能说明: 判断打印纸是否正常
*	形    参: 无
*	返 回 值: 返回值1表示打印纸正常 ，0表示无打印纸
*********************************************************************************************************
*/

static uint8_t IsDetect_Ok(void) 
{
	if ((GPIO_PRINTER_DETECT_PORT->IDR & GPIO_PRINTER_DETECT_PIN) == 0) 
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
*	函 数 名: printer_Init
*	功能说明: 热敏打印模块的驱动接口初始化。包含1.各驱动信号IO初始化  2.SPI模块初始化 3.定时器初始化
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
void printer_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	SPI_InitTypeDef  SPI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
	uint8_t i,j;

	/* 打印机电源控制引脚 */
	RCC_APB2PeriphClockCmd(RCC_PRINTER_PWR, ENABLE);
	GPIO_ResetBits(GPIO_PRINTER_PWR_PORT, GPIO_PRINTER_PWR_PIN);

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_InitStructure.GPIO_Pin = GPIO_PRINTER_PWR_PIN;
	GPIO_Init(GPIO_PRINTER_PWR_PORT, &GPIO_InitStructure);

	/* 步进电机电源控制引脚 */
	RCC_APB2PeriphClockCmd(RCC_PRINTER_MOTOR_PWR, ENABLE);
	GPIO_ResetBits(GPIO_PRINTER_MOTOR_PWR_PORT, GPIO_PRINTER_MOTOR_PWR_PIN);

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_InitStructure.GPIO_Pin = GPIO_PRINTER_MOTOR_PWR_PIN;
	GPIO_Init(GPIO_PRINTER_MOTOR_PWR_PORT, &GPIO_InitStructure);

	/* 
	*	MOTOR 四线 1~4 
	*	其中PB4为jtag接口引脚需要禁用jtag功能，还要开启AFIO的时钟
	*/
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_PRINTER_MOTOR, ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable , ENABLE);//禁用jtag
	
	MOTOR_PHASE_DISABLE();
	GPIO_InitStructure.GPIO_Pin = GPIO_PRINTER_MOTOR_1A_PIN | GPIO_PRINTER_MOTOR_1B_PIN | GPIO_PRINTER_MOTOR_2A_PIN | GPIO_PRINTER_MOTOR_2B_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIO_PRINTER_MOTOR_PORT, &GPIO_InitStructure);
	
	PRINTER_PWR_ON();	
	PRINTER_MOTOR_PWR_ON();
	
	/* 步进电机电源控制引脚 */
	RCC_APB2PeriphClockCmd(RCC_PRINTER_DETECT, ENABLE);
	GPIO_ResetBits(GPIO_PRINTER_DETECT_PORT, GPIO_PRINTER_DETECT_PIN);

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_InitStructure.GPIO_Pin = GPIO_PRINTER_DETECT_PIN;
	GPIO_Init(GPIO_PRINTER_DETECT_PORT, &GPIO_InitStructure);
	
	
	/* 打印机加热使能引脚 */
	RCC_APB2PeriphClockCmd(RCC_PRINTER_LATCH, ENABLE);
	GPIO_SetBits(GPIO_PRINTER_HEAT_ENABLE_PORT, GPIO_PRINTER_HEAT_ENABLE_PIN_0 | GPIO_PRINTER_HEAT_ENABLE_PIN_1);//低电平使能，上电设置为高

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_InitStructure.GPIO_Pin = GPIO_PRINTER_HEAT_ENABLE_PIN_0 | GPIO_PRINTER_HEAT_ENABLE_PIN_1;
	GPIO_Init(GPIO_PRINTER_HEAT_ENABLE_PORT, &GPIO_InitStructure);
	
	/* 打印机Latch锁存信号引脚 */
	RCC_APB2PeriphClockCmd(RCC_PRINTER_LATCH, ENABLE);
	GPIO_SetBits(GPIO_PRINTER_LATCH_PORT, GPIO_PRINTER_LATCH_PIN);//低电平使能，上电设置为高

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_InitStructure.GPIO_Pin = GPIO_PRINTER_LATCH_PIN;
	GPIO_Init(GPIO_PRINTER_LATCH_PORT, &GPIO_InitStructure);
	
	/* 打印机SPI通信引脚 */
	RCC_APB2PeriphClockCmd(RCC_PRINTER_INTERFACE_GPIO, ENABLE);	
	RCC_APB1PeriphResetCmd(RCC_PRINTER_INTERFACE_SPI, ENABLE);
	GPIO_SetBits(GPIO_PRINTER_INTERFACE_PORT,GPIO_PRINTER_INTERFACE_SPI_MOSI | GPIO_PRINTER_INTERFACE_SPI_MISO | GPIO_PRINTER_INTERFACE_SPI_SCK);
	GPIO_InitStructure.GPIO_Pin = GPIO_PRINTER_INTERFACE_SPI_MOSI | GPIO_PRINTER_INTERFACE_SPI_MISO | GPIO_PRINTER_INTERFACE_SPI_SCK;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//设置为复用推挽功能
	GPIO_Init(GPIO_PRINTER_INTERFACE_PORT, &GPIO_InitStructure);
	
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;  //设置SPI单向或者双向的数据模式:SPI设置为双线双向全双工
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;												//设置SPI工作模式:设置为主SPI
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;										//设置SPI的数据大小:SPI发送接收8位帧结构
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;													//选择了串行时钟的稳态:空闲时为低
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;												//数据捕获于第一个时钟沿
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;														//NSS信号由硬件（NSS管脚）还是软件（使用SSI位）管理:内部NSS信号有SSI位控制
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_8;	//定义波特率预分频的值:波特率预分频值为8
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;									//指定数据传输从MSB位还是LSB位开始:数据传输从MSB位开始
	SPI_InitStructure.SPI_CRCPolynomial = 7;														//CRC值计算的多项式
	SPI_Init(SPI1, &SPI_InitStructure);  																//根据SPI_InitStruct中指定的参数初始化外设SPIx寄存器
 
	SPI_Cmd(SPI1, ENABLE); //使能SPI外设

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); //时钟使能
	TIM_TimeBaseStructure.TIM_Period = 72-1; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	 计数到71为36ms
	TIM_TimeBaseStructure.TIM_Prescaler =72000000L/72L/500L-1;	 //设置用来作为TIMx时钟频率除数的预分频值  2Khz的计数频率  
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
 
	TIM_ITConfig(  //使能或者失能指定的TIM中断
		TIM2, //TIM2
		TIM_IT_Update  |  //TIM 中断源
		TIM_IT_Trigger,   //TIM 触发中断源 
		ENABLE  //使能
		);
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;  //TIM3中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //先占优先级0级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //从优先级3级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure);  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器

	TIM_Cmd(TIM2, ENABLE);  //使能TIMx外设
	
	for (i = 0; i < 16; i ++)
	{
		for (j = 0; j < (LineDot/8+1); j ++)
		{
			if (j%8 == 0)
			{TP_dot[i][j] = 0xFF;}
			else
			{TP_dot[i][j] = 0x00;}
		}
	}
}

/*
*********************************************************************************************************
*	函 数 名: TIM2_ISR
*	功能说明: 定时器2：中断服务程序。
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
void TIM2_ISR(void)
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
	{
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
		
 	}
}

/*
*********************************************************************************************************
*	函 数 名: printer_CMD_DEAL
*	功能说明: 处理打印机相关命令
*	形    参：databuf	：串口接收到的数据包的首字节地址
						length	: 数据包长度
*	返 回 值: 无
*********************************************************************************************************
*/
static void printer_moter_feed(uint8_t * step_num)
{
	if((*step_num == 0) || (*step_num == 0xFF))
	{
		//对象命令参数错误
		Usart1_Txd_Tempdata[0] = 0x00;
		Usart1_Txd_Tempdata[1] = 0x02;
		Usart1_Txd_Tempdata[2] = 0x11 | 0x80;
		Usart1_Txd_Tempdata[3] = 0x20;
		USART1_Tx_Chars(Usart1_Txd_Tempdata, 4);		
	}
	else
	{
		Motor_Feed_Step += *step_num;
		//对象命令执行成功
		Usart1_Txd_Tempdata[0] = 0x00;
		Usart1_Txd_Tempdata[1] = 0x01;
		Usart1_Txd_Tempdata[2] = 0x11;
		USART1_Tx_Chars(Usart1_Txd_Tempdata, 3);
	}
}

/*
*********************************************************************************************************
*	函 数 名: printer_ceshi
*	功能说明: 打印测试纸
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
static void TPDataShiftOut(uint8_t *databuf, uint8_t length, uint8_t mark)
{
 	while(length--)
	{
		/* Send byte through the SPI1 peripheral */
		if(mark)
		{
			SPI_I2S_SendData(SPI2, *databuf++);
		}
		else
		{
			SPI_I2S_SendData(SPI2, ~(*databuf++));
		}
		/* Loop while DR register in not emplty */
		while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) == RESET);
	}
}

/*
*********************************************************************************************************
*	函 数 名: printer_ceshi
*	功能说明: 打印测试纸
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
static void printer_ceshi(void)
{
	uint8_t i;
	for (i = 0; i < 16; i ++)
	{
		TPDataShiftOut(&TP_dot[i][0], (LineDot/8), 0);
	}
	for (i = 0; i < 16; i ++)
	{
		TPDataShiftOut(&TP_dot[i][0], (LineDot/8), 1);
	}
}

/*
*********************************************************************************************************
*	函 数 名: printer_CMD_DEAL
*	功能说明: 处理打印机相关命令
*	形    参：databuf	：串口接收到的数据包的首字节地址
						length	: 数据包长度
*	返 回 值: 无
*********************************************************************************************************
*/
void printer_CMD_DEAL(uint8_t *databuf, uint16_t length)
{
	switch (*databuf)
	{
		case 0x10:
			//测试命令
			if (length == 1)
			{
				printer_ceshi();
			}
			else
			{
				//对象命令参数长度错误
				Usart1_Txd_Tempdata[0] = 0x00;
				Usart1_Txd_Tempdata[1] = 0x02;
				Usart1_Txd_Tempdata[2] = 0x11 | 0x80;
				Usart1_Txd_Tempdata[3] = 0x11;
				USART1_Tx_Chars(Usart1_Txd_Tempdata, 4);	
			}
			break;
		case 0x11:
			//步进电机给纸
			if (length == 2)
			{
				printer_moter_feed(databuf+1);
			}
			else
			{
				//对象命令参数长度错误
				Usart1_Txd_Tempdata[0] = 0x00;
				Usart1_Txd_Tempdata[1] = 0x02;
				Usart1_Txd_Tempdata[2] = 0x11 | 0x80;
				Usart1_Txd_Tempdata[3] = 0x11;
				USART1_Tx_Chars(Usart1_Txd_Tempdata, 4);			
			}
			break;
		default :
				//对象不支持该命令
				Usart1_Txd_Tempdata[0] = 0x00;
				Usart1_Txd_Tempdata[1] = 0x02;
				Usart1_Txd_Tempdata[2] = 0x11 | 0x80;
				Usart1_Txd_Tempdata[3] = 0x10;
				USART1_Tx_Chars(Usart1_Txd_Tempdata, 4);
			break;
	}
}

/*
*********************************************************************************************************
*	函 数 名: printer_SERVER_TASK
*	功能说明: 打印机相关服务函数
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
void printer_SERVER_TASK(void)
{
  static uint32_t sys_time, time_ms = 0, time_add_up = 0;
  const uint32_t work_time_max = 3;
	uint32_t offset_time_ticks = 0;
	uint8_t timeout_flag = 0;
	
	static uint8_t motor_state = 0;
	static uint16_t Rxdtime = 0;
	static uint16_t Cycletime = 0;
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
			if (IsDetect_Ok())
			{
				if (Motor_Feed_Step)
				{
					Rxdtime = 25;//每4mstimeout_flag置位,小计100ms
					Motor_Feed_Step--;
					switch (motor_state)
					{
						case 0:
							MOTOR_STEP_ONE();
							break;
						case 1:
							MOTOR_STEP_TWO ();
							break;
						case 2:
							MOTOR_STEP_THREE();
							break;
						case 3:
							MOTOR_STEP_FOUR();
							break;
						default:
							break;
					}			
					if (++motor_state >=4)
					{
						motor_state = 0;
					}
				}
				else
				{
					if(Rxdtime)
					{
						Rxdtime --;
					}
					else
					{
						MOTOR_PHASE_DISABLE();
					}
				}
				Cycletime = 5000;
			}
			else
			{
				if(++ Cycletime >= 5000)
				{
					Cycletime = 0;
					Motor_Feed_Step = 0;
					MOTOR_PHASE_DISABLE();
					//打印纸位置检测错误
					Usart1_Txd_Tempdata[0] = 0x00;
					Usart1_Txd_Tempdata[1] = 0x02;
					Usart1_Txd_Tempdata[2] = 0x11 | 0x80;
					Usart1_Txd_Tempdata[3] = 0x30;
					USART1_Tx_Chars(Usart1_Txd_Tempdata, 4);				
				}
			}
		}
	}
}
