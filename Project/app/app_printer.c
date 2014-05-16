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

const uint8_t ZIMO_000[]=
{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x0E,0x60,0x03,0x80,0x11,0x0C,0x30,0x00,0x01,0x80,0x00,0x00,0x0E,0x1C,0x30,0x70,0x07,0x00,0x00,0x00,0x0C,0x20,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x20,0x00,0x60,0xC0,0x00,0x60,0x30,0xCC,0x00,0x00,
0x0E,0x60,0x01,0x80,0x39,0x08,0x7F,0x7E,0x03,0xC0,0x3F,0xFC,0x78,0x9C,0x30,0x70,0x07,0x00,0x7D,0xFE,0x0E,0x70,0x7F,0xFE,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xFF,0xFE,0x37,0xFC,0x60,0xE0,0x03,0x60,0x30,0xCC,0x00,0x00,
0x0E,0x62,0xFF,0xFF,0x2D,0x58,0x6C,0x66,0x07,0xE0,0x30,0x0C,0x18,0xFC,0x33,0xFE,0xFF,0xFF,0x6D,0x86,0x0C,0x30,0x00,0x06,
0x07,0x07,0x1D,0xFD,0xF7,0xF8,0x1F,0x01,0xF8,0x7E,0x1E,0x00,0x00,0x00,0x76,0x0C,0x67,0xFC,0x1B,0xFD,0xB1,0xCF,0xFE,0x00,
0x0E,0x6E,0x00,0x00,0x6D,0x5F,0x4C,0x66,0x0E,0x70,0x3F,0xFC,0x18,0x5C,0xFC,0x70,0x0C,0x00,0x6D,0x86,0x18,0x18,0x00,0x06,
0x07,0x0F,0x1D,0xFD,0xF7,0xFC,0x3F,0x83,0xF8,0xFE,0x3F,0x80,0x3F,0xF0,0x66,0x0D,0xF3,0x18,0x32,0x61,0xB1,0x9F,0x03,0x00,
0x7E,0x7C,0x3F,0xFC,0xCD,0x52,0xFF,0xE6,0x1C,0x38,0x30,0x0C,0x18,0x1C,0x30,0x70,0x1C,0x00,0x69,0xFE,0x38,0x1C,0xFF,0xF6,
0x03,0x8F,0x1D,0xC0,0xE7,0x1E,0x71,0xC7,0x09,0xC2,0x23,0x80,0x30,0x30,0xC7,0xFC,0x63,0x38,0x60,0x61,0xB3,0x97,0x03,0x00,
0x0E,0x78,0x30,0x0C,0x1F,0xF6,0x1E,0x66,0x78,0x1C,0x3F,0xFC,0xFF,0x9C,0x30,0x70,0x1F,0xFC,0x79,0x86,0x30,0x0C,0x00,0x06,
0x03,0x8F,0x99,0xC0,0xE7,0x0E,0xE0,0xE7,0x01,0xC0,0x03,0x80,0x30,0x30,0x96,0x0C,0x67,0xFC,0x67,0xFF,0xB3,0xB7,0x03,0x00,
0x0E,0x70,0x30,0x0C,0x30,0x36,0x3B,0x7E,0x6F,0xF6,0x01,0x80,0x38,0xFC,0x33,0xFE,0x38,0x0C,0x79,0x86,0x61,0x06,0x00,0x06,
0x03,0x9F,0x99,0xC0,0xE7,0x0E,0xE0,0xE7,0x81,0xE0,0x03,0x80,0x3F,0xF0,0x3E,0x0C,0xF4,0x0C,0xC0,0x61,0xB7,0xA7,0xF1,0x80,
0x0E,0x60,0x30,0x0C,0x77,0xDE,0x73,0x00,0x01,0x80,0xFF,0xFF,0x3C,0x5C,0x3C,0x0E,0x78,0x0C,0x79,0x86,0x43,0x82,0x3F,0xC6,
0x01,0x99,0xB9,0xF8,0xE7,0x1E,0xE0,0xE3,0xF0,0xFC,0x07,0x00,0x00,0x00,0x37,0xFC,0xF4,0xCC,0xC0,0x61,0xB3,0x87,0x01,0x80,
0x0E,0x60,0x3F,0xFC,0x70,0x1E,0x7F,0xFC,0x01,0x80,0x00,0x00,0x3E,0x1C,0xF1,0x0C,0x7F,0xFC,0x6D,0xFE,0x03,0x00,0x30,0xC6,
0x01,0x99,0xB9,0xF8,0xE7,0xFC,0xE0,0xE3,0xF8,0xFE,0x0F,0x00,0xFF,0xFC,0x60,0x00,0xE8,0xC0,0xC3,0xFD,0xB1,0x87,0x01,0x80,
0x0E,0x60,0x01,0x80,0xB7,0xCC,0x30,0x0C,0x01,0x80,0x3F,0xFC,0x7E,0x1C,0x31,0x8C,0x58,0x0C,0x6D,0xE2,0x07,0x00,0x30,0xC6,
0x01,0xF9,0xF1,0xC0,0xE7,0xF0,0xE0,0xE0,0x7C,0x1F,0x1E,0x00,0xC0,0x0C,0xEF,0xFD,0xEF,0xFE,0xC3,0x65,0xB1,0x87,0x01,0x80,
0x0E,0x60,0x11,0x90,0x36,0xCC,0x30,0x0C,0x3F,0xFC,0x30,0x0C,0x78,0x3F,0x30,0xD8,0x18,0x0C,0x6D,0xB7,0x0E,0x00,0x30,0xC6,
0x01,0xF9,0xF1,0xC0,0xE7,0x00,0xE0,0xE0,0x1C,0x07,0x1C,0x00,0xCF,0xEC,0xE0,0x19,0xE3,0x00,0xC3,0x65,0xB1,0x87,0xF1,0x80,
0x3E,0x62,0x19,0x98,0x34,0xFC,0x3F,0xFC,0x01,0x80,0x3F,0xFC,0xDB,0xDC,0x30,0xF0,0x1F,0xFC,0x6D,0xBE,0x0E,0x20,0x30,0xC6,
0x00,0xF0,0xF1,0xC0,0xE7,0x00,0x71,0xC4,0x1D,0x07,0x30,0x00,0xC8,0x6C,0x6F,0xFF,0x63,0xFC,0xC3,0x65,0xB1,0x87,0x01,0x80,
0xCE,0x67,0x31,0x8C,0x34,0xFE,0x30,0x0C,0x01,0x80,0x01,0x80,0x58,0x1C,0x30,0xF8,0x18,0x0C,0x79,0x9C,0x1C,0x78,0x3F,0xC6,
0x00,0xF0,0xE1,0xFD,0xF7,0x00,0x3F,0x87,0xF9,0xFE,0x7F,0x80,0xC8,0x6C,0x66,0x18,0x63,0x0C,0xC3,0x64,0x31,0x87,0x01,0x80,
0x0E,0x67,0x61,0x86,0x3C,0xF2,0x30,0x0C,0x01,0x80,0x09,0x90,0x18,0x1C,0x31,0xDC,0x18,0x0C,0x61,0xFC,0x38,0x3C,0x30,0x06,
0x00,0xF0,0xE1,0xFD,0xF7,0x00,0x1F,0x07,0xF1,0xFC,0x7F,0x80,0xCF,0xEC,0x63,0x18,0x67,0x0C,0x63,0x6C,0x31,0x87,0x03,0x00,
0x0E,0x66,0x41,0x82,0x38,0x82,0x3F,0xFC,0x7F,0xFE,0x31,0x8C,0x18,0x1C,0x33,0x8E,0x18,0x0C,0x63,0xEE,0x3F,0xFE,0x00,0x0E,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC8,0x0C,0x62,0x18,0x6E,0x18,0x63,0x7C,0x31,0x87,0x03,0x00,
0x0E,0x7E,0x07,0x00,0x00,0x00,0x30,0x0C,0x00,0x00,0x47,0x82,0x18,0x1C,0x66,0x02,0x18,0x7C,0x63,0x82,0x00,0x04,0x00,0x7C,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x78,0x60,0xF0,0x7C,0xF8,0x30,0x60,0xE1,0x87,0x03,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x06,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

typedef enum
{
	CESHI = 0x10,
	FEED = 0x11,
	PRINT = 0x12
}PRINTER_CMD_NAME;

typedef enum
{
	TPSTATE_IDLE = 0,
	TPSTATE_CUT_FEED,
	TPSTATE_START,
	TPSTATE_HEAT1,
	TPSTATE_HEAT1Stop,
	TPSTATE_HEAT2,
	TPSTATE_HEAT2Stop,
	TPSTATE_HEAT12,
	TPSTATE_HEAT12Stop,
	TPSTATE_FEED,
	TPSTATE_END
}TPSTATE_T;

#define LINEDOT		(384)	// 两寸机芯为384点 

static uint8_t Motor_Feed_Step = 0;
static TPSTATE_T Printer_State;
//static uint8_t Printer_Dot[16][LINEDOT/8+1];

/* 各个引脚宏定义 */
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
#define GPIO_PRINTER_INTERFACE_SPI_SCK		(GPIO_Pin_13)
#define GPIO_PRINTER_INTERFACE_SPI_MISO		(GPIO_Pin_14)
#define GPIO_PRINTER_INTERFACE_SPI_MOSI		(GPIO_Pin_15)


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
*	函 数 名: is_detect_ok
*	功能说明: 判断打印纸是否正常
*	形    参: 无
*	返 回 值: 返回值1表示打印纸正常 ，0表示无打印纸
*********************************************************************************************************
*/
static uint8_t is_detect_ok(void) 
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
*	函 数 名: printer_moter_feed_step
*	功能说明: 打印机进纸函数
*	形    参：mode: 0-表示是打印进纸，1-表示只进纸
*	返 回 值: 无
*********************************************************************************************************
*/
static void printer_moter_feed_step(uint8_t mode)
{
	static uint16_t Rxdtime = 0;
	static uint8_t motor_state = 0;
	if (Motor_Feed_Step)
	{
		Rxdtime = 32;//每4ms timeout_flag置位,小计(32 + 1) * 3 = 99ms Rxdtime超时
		Motor_Feed_Step--;
		switch (motor_state)
		{
			case 0:
				MOTOR_STEP_ONE();
				break;
			case 1:
				MOTOR_STEP_TWO();
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
		if (mode == TPSTATE_CUT_FEED)//只进纸，进纸后，停止电机各相 供电
		{
			if(Rxdtime)
			{
				Rxdtime --;
			}
			else
			{
				Printer_State = TPSTATE_IDLE;
				MOTOR_PHASE_DISABLE();
			}
		}
		else if (mode == TPSTATE_FEED)
		{
			Printer_State = TPSTATE_END;
		}
		else
		{
			MOTOR_PHASE_DISABLE();
		}
	}
}

/*
*********************************************************************************************************
*	函 数 名: printer_moter_cut_feed
*	功能说明: 打印机进纸函数
*	形    参：step_num:步进的步数
*	返 回 值: 无
*********************************************************************************************************
*/
static void printer_moter_cut_feed(uint8_t * step_num)
{
	if(Printer_State == TPSTATE_IDLE)
	{
		if(*step_num == 0xFF)
		{
			//对象命令参数错误
			Usart1_Txd_Tempdata[0] = 0x00;
			Usart1_Txd_Tempdata[1] = 0x02;
			Usart1_Txd_Tempdata[2] = PRINTER | 0x80;
			Usart1_Txd_Tempdata[3] = 0x21;
			USART1_Tx_Chars(Usart1_Txd_Tempdata, 4);		
		}
		else
		{
			Motor_Feed_Step += *step_num;
			Printer_State = TPSTATE_CUT_FEED;
			//对象命令执行成功
			Usart1_Txd_Tempdata[0] = 0x00;
			Usart1_Txd_Tempdata[1] = 0x01;
			Usart1_Txd_Tempdata[2] = PRINTER;
			USART1_Tx_Chars(Usart1_Txd_Tempdata, 3);
		}
	}
	else
	{
		//对象忙碌
		Usart1_Txd_Tempdata[0] = 0x00;
		Usart1_Txd_Tempdata[1] = 0x02;
		Usart1_Txd_Tempdata[2] = PRINTER | 0x80;
		Usart1_Txd_Tempdata[3] = 0x20;
		USART1_Tx_Chars(Usart1_Txd_Tempdata, 4);		
	}
}

/*
*********************************************************************************************************
*	函 数 名: printer_moter_feed
*	功能说明: 打印机进纸函数
*	形    参：void
*	返 回 值: 无
*********************************************************************************************************
*/
static void printer_moter_feed(void)
{
	if(Printer_State == TPSTATE_IDLE)
	{
		Motor_Feed_Step += 2;
		Printer_State = TPSTATE_FEED;
		//对象命令执行成功
		Usart1_Txd_Tempdata[0] = 0x00;
		Usart1_Txd_Tempdata[1] = 0x01;
		Usart1_Txd_Tempdata[2] = PRINTER;
		USART1_Tx_Chars(Usart1_Txd_Tempdata, 3);
	}
	else
	{
		//对象忙碌
		Usart1_Txd_Tempdata[0] = 0x00;
		Usart1_Txd_Tempdata[1] = 0x02;
		Usart1_Txd_Tempdata[2] = PRINTER | 0x80;
		Usart1_Txd_Tempdata[3] = 0x20;
		USART1_Tx_Chars(Usart1_Txd_Tempdata, 4);		
	}
}

/*
*********************************************************************************************************
*	函 数 名: printer_data_out
*	功能说明: 打印测试纸
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
static void printer_data_out(uint8_t *databuf, uint8_t length, uint8_t mark)
{
 	while(length--)
	{
		while(SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) == RESET);  /// wait until Tx buffer empty
		/* Send byte through the SPI2 peripheral */
		if(mark == 0)
		{
			SPI_I2S_SendData(SPI2, 0xAA&(*databuf++));
		}
		else if(mark == 1)
		{
			SPI_I2S_SendData(SPI2, 0x55&(*databuf++));
		}
		while(SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) == SET);    /// wait until send complete
	}
}

/*
*********************************************************************************************************
*	函 数 名: printer_start
*	功能说明: 打印机开始打印
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
static void printer_start(void)
{
	Printer_State = TPSTATE_HEAT12;
	STROBE_1_ON();
	bsp_DelayUS(5000);
	STROBE_1_OFF();
	STROBE_2_ON();
	bsp_DelayUS(5000);
	STROBE_2_OFF();	
	Printer_State = TPSTATE_HEAT12Stop;
	//STROBE_12_ON();
	//TIM_Cmd(TIM2, ENABLE);		// Enable Timer
	//bsp_DelayUS(3000);
	//STROBE_12_OFF();
	
	//Printer_State = TPSTATE_FEED;
	//Motor_Feed_Step += 0x02;
	
	//标记
	//Usart1_Txd_Tempdata[0] = 0x00;
	//Usart1_Txd_Tempdata[1] = 0x02;
	//Usart1_Txd_Tempdata[2] = PRINTER;
	//Usart1_Txd_Tempdata[3] = 0x00;
	//USART1_Tx_Chars(Usart1_Txd_Tempdata, 4);
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
	static uint8_t j = 0;
	if(Printer_State == TPSTATE_IDLE)
	{
		for (i = 0; i < 2; i ++)
		{
			printer_data_out((uint8_t *)&ZIMO_000[j * (LINEDOT / 8)], LINEDOT/8, i);
			LATCH_LOW();
			LATCH_HIGH();
			printer_start();
		}
		if(++j >= 24)
		{
			j=0;
		}
		Printer_State = TPSTATE_FEED;
	  Motor_Feed_Step += 0x02;
	}
	else
	{
			//对象忙碌
			Usart1_Txd_Tempdata[0] = 0x00;
			Usart1_Txd_Tempdata[1] = 0x02;
			Usart1_Txd_Tempdata[2] = PRINTER | 0x80;
			Usart1_Txd_Tempdata[3] = 0x20;
			USART1_Tx_Chars(Usart1_Txd_Tempdata, 4);
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
		TIM_Cmd(TIM2, DISABLE);
		Printer_State = TPSTATE_HEAT12Stop;
		STROBE_12_OFF();
		Printer_State = TPSTATE_FEED;
		Motor_Feed_Step += 2;	
 	}
}

/*
*********************************************************************************************************
*	函 数 名: printer_Init
*	功能说明: 热敏打印模块的驱动接口初始化。包含1.各驱动信号IO初始化  2.SPI初始化 3.定时器初始化
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

	/* 打印机电源控制引脚 */
	RCC_APB2PeriphClockCmd(RCC_PRINTER_PWR, ENABLE);
	PRINTER_PWR_OFF();//关闭打印机总电源

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;

	GPIO_InitStructure.GPIO_Pin = GPIO_PRINTER_PWR_PIN;
	GPIO_Init(GPIO_PRINTER_PWR_PORT, &GPIO_InitStructure);

	/* 步进电机电源控制引脚 */
	RCC_APB2PeriphClockCmd(RCC_PRINTER_MOTOR_PWR, ENABLE);
	PRINTER_MOTOR_PWR_OFF();//关闭步进电机电源

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;

	GPIO_InitStructure.GPIO_Pin = GPIO_PRINTER_MOTOR_PWR_PIN;
	GPIO_Init(GPIO_PRINTER_MOTOR_PWR_PORT, &GPIO_InitStructure);

	/* 
	*	MOTOR 四线 1~4 
	*	其中PB4为jtag接口引脚需要禁用jtag功能，还要开启AFIO的时钟
	*/
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_PRINTER_MOTOR, ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable , ENABLE);//禁用jtag
	
	MOTOR_PHASE_DISABLE();//开始设置步进电机4线都为低
	GPIO_InitStructure.GPIO_Pin = GPIO_PRINTER_MOTOR_1A_PIN | GPIO_PRINTER_MOTOR_1B_PIN | GPIO_PRINTER_MOTOR_2A_PIN | GPIO_PRINTER_MOTOR_2B_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIO_PRINTER_MOTOR_PORT, &GPIO_InitStructure);
	
	PRINTER_PWR_ON();	
	PRINTER_MOTOR_PWR_ON();
	
	/* 打印机纸光电检测引脚 */
	RCC_APB2PeriphClockCmd(RCC_PRINTER_DETECT, ENABLE);

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;

	GPIO_InitStructure.GPIO_Pin = GPIO_PRINTER_DETECT_PIN;
	GPIO_Init(GPIO_PRINTER_DETECT_PORT, &GPIO_InitStructure);
	
	
	/* 打印机加热使能引脚 */
	RCC_APB2PeriphClockCmd(RCC_PRINTER_HEAT_ENABLE, ENABLE);
	STROBE_12_OFF();//低电平使能，上电设置为高

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;

	GPIO_InitStructure.GPIO_Pin = GPIO_PRINTER_HEAT_ENABLE_PIN_0 | GPIO_PRINTER_HEAT_ENABLE_PIN_1;
	GPIO_Init(GPIO_PRINTER_HEAT_ENABLE_PORT, &GPIO_InitStructure);
	
	/* 打印机Latch锁存信号引脚 */
	RCC_APB2PeriphClockCmd(RCC_PRINTER_LATCH, ENABLE);
	LATCH_HIGH();//上升沿锁存，上电设置为高

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_InitStructure.GPIO_Pin = GPIO_PRINTER_LATCH_PIN;
	GPIO_Init(GPIO_PRINTER_LATCH_PORT, &GPIO_InitStructure);
	
	/* 打印机SPI通信引脚 */

	RCC_APB2PeriphClockCmd(RCC_PRINTER_INTERFACE_GPIO, ENABLE);	
	RCC_APB1PeriphClockCmd(RCC_PRINTER_INTERFACE_SPI, ENABLE);
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
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_8;  //定义波特率预分频的值:波特率预分频值为8
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;									//指定数据传输从MSB位还是LSB位开始:数据传输从MSB位开始

  SPI_Init(SPI2, &SPI_InitStructure);  																//根据SPI_InitStruct中指定的参数初始化外设SPIx寄存器
  SPI_Cmd(SPI2, ENABLE);

	SPI_SSOutputCmd(SPI2, ENABLE);

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); //时钟使能
	TIM_DeInit(TIM2);
	TIM_InternalClockConfig(TIM2);
	TIM_TimeBaseStructure.TIM_Period = 30-1; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	 计数到30为3ms
	TIM_TimeBaseStructure.TIM_Prescaler =36000000L/10000L-1;	 //设置用来作为TIMx时钟频率除数的预分频值  10Khz的计数频率  
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位


	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;  //TIM2中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  //抢占优先级1级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;  //从优先级0级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure);  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器
	
	TIM_ClearFlag(TIM2,TIM_FLAG_Update);
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE); // 使能TIM2更新中断

	Printer_State = TPSTATE_IDLE;
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
		case CESHI:
			//测试命令
			if (length == 2)
			{
				if(*(databuf + 1) == 0x00)
				{
					printer_ceshi();
				}
				else if(*(databuf + 1) == 0x01)
				{
					printer_moter_feed();
				}
				else
				{
					//对象命令参数错误
					Usart1_Txd_Tempdata[0] = 0x00;
					Usart1_Txd_Tempdata[1] = 0x02;
					Usart1_Txd_Tempdata[2] = PRINTER | 0x80;
					Usart1_Txd_Tempdata[3] = 0x21;
					USART1_Tx_Chars(Usart1_Txd_Tempdata, 4);
				}
			}
			else
			{
				//对象命令参数长度错误
				Usart1_Txd_Tempdata[0] = 0x00;
				Usart1_Txd_Tempdata[1] = 0x02;
				Usart1_Txd_Tempdata[2] = PRINTER | 0x80;
				Usart1_Txd_Tempdata[3] = 0x11;
				USART1_Tx_Chars(Usart1_Txd_Tempdata, 4);
			}
			break;
		case FEED:
			//步进电机给纸
			if (length == 2)
			{
				printer_moter_cut_feed(databuf+1);
			}
			else
			{
				//对象命令参数长度错误
				Usart1_Txd_Tempdata[0] = 0x00;
				Usart1_Txd_Tempdata[1] = 0x02;
				Usart1_Txd_Tempdata[2] = PRINTER | 0x80;
				Usart1_Txd_Tempdata[3] = 0x11;
				USART1_Tx_Chars(Usart1_Txd_Tempdata, 4);			
			}
			break;
		case PRINT:
			
			break;
		default :
				//对象不支持该命令
				Usart1_Txd_Tempdata[0] = 0x00;
				Usart1_Txd_Tempdata[1] = 0x02;
				Usart1_Txd_Tempdata[2] = PRINTER | 0x80;
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
  const uint32_t work_time_max = 2;
	uint32_t offset_time_ticks = 0;
	uint8_t timeout_flag = 0;
	static uint16_t Cycletime = 5000;
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

			if (is_detect_ok())
			{
				if (1)//此处检测温度是否超过正常值
				{
					switch (Printer_State)
					{
						case TPSTATE_IDLE:
							break;
						case TPSTATE_CUT_FEED:
							printer_moter_feed_step(TPSTATE_CUT_FEED);
							break;
						case TPSTATE_HEAT1:
							break;
						case TPSTATE_HEAT1Stop:
							break;
						case TPSTATE_HEAT2:
							break;
						case TPSTATE_HEAT2Stop:
							break;
						case TPSTATE_HEAT12:
							break;
						case TPSTATE_HEAT12Stop:
							break;
						case TPSTATE_FEED:
							printer_moter_feed_step(TPSTATE_FEED);
							break;
						case TPSTATE_END:
							Printer_State = TPSTATE_IDLE;
							printer_ceshi();
							break;
						default:
							break;

					}
					Cycletime = 5000;
				}
				else
				{
					if(++ Cycletime >= 5000)
					{
						Cycletime = 0;
						Motor_Feed_Step = 0;
						STROBE_12_OFF();
						MOTOR_PHASE_DISABLE();
						//打印机温度过高
						Usart1_Txd_Tempdata[0] = 0x00;
						Usart1_Txd_Tempdata[1] = 0x02;
						Usart1_Txd_Tempdata[2] = PRINTER | 0x80;
						Usart1_Txd_Tempdata[3] = 0x32;
						USART1_Tx_Chars(Usart1_Txd_Tempdata, 4);				
					}					
				}
			}
			else
			{
				if(++ Cycletime >= 5000)
				{
					Cycletime = 0;
					Motor_Feed_Step = 0;
					STROBE_12_OFF();
					MOTOR_PHASE_DISABLE();
					//打印纸位置检测错误
					Usart1_Txd_Tempdata[0] = 0x00;
					Usart1_Txd_Tempdata[1] = 0x02;
					Usart1_Txd_Tempdata[2] = PRINTER | 0x80;
					Usart1_Txd_Tempdata[3] = 0x31;
					//USART1_Tx_Chars(Usart1_Txd_Tempdata, 4);				
				}
			}
		}
	}
}
