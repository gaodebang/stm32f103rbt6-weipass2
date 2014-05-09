/*
*********************************************************************************************************
*
*	ģ������ : ��ӡ��ģ��
*	�ļ����� : app_printer.c
*	��    �� : V1.0
*	˵    �� : 
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

#define LINEDOT		(384)	// �����оΪ384�� 

uint8_t Motor_Feed_Step = 0;
static TPSTATE_T Printer_State;
static uint8_t Printer_Dot[16][LINEDOT/8+1];
/* �������ź궨�� */

//��ӡ����Դ
#define RCC_PRINTER_PWR 						(RCC_APB2Periph_GPIOA)
#define GPIO_PRINTER_PWR_PORT 			(GPIOA)
#define GPIO_PRINTER_PWR_PIN 				(GPIO_Pin_8)

#define PRINTER_PWR_ON()	do{	\
	GPIO_SetBits(GPIO_PRINTER_PWR_PORT, GPIO_PRINTER_PWR_PIN); \
}while(0)

#define PRINTER_PWR_OFF() do{	\
	GPIO_ResetBits(GPIO_PRINTER_PWR_PORT, GPIO_PRINTER_PWR_PIN); \
}while(0)

//��ӡ�����������Դ
#define RCC_PRINTER_MOTOR_PWR 						(RCC_APB2Periph_GPIOC)
#define GPIO_PRINTER_MOTOR_PWR_PORT 			(GPIOC)
#define GPIO_PRINTER_MOTOR_PWR_PIN 				(GPIO_Pin_11)

#define PRINTER_MOTOR_PWR_ON()	do{	\
	GPIO_SetBits(GPIO_PRINTER_MOTOR_PWR_PORT, GPIO_PRINTER_MOTOR_PWR_PIN); \
}while(0)

#define PRINTER_MOTOR_PWR_OFF() do{	\
	GPIO_ResetBits(GPIO_PRINTER_MOTOR_PWR_PORT, GPIO_PRINTER_MOTOR_PWR_PIN); \
}while(0)

//��ӡ��������λ�ź�
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

//��ӡ����������ţ����ڼ���ӡֽ�Ƿ�������
#define RCC_PRINTER_DETECT 						(RCC_APB2Periph_GPIOC)
#define GPIO_PRINTER_DETECT_PORT 			(GPIOC)
#define GPIO_PRINTER_DETECT_PIN 			(GPIO_Pin_6)


//��ӡ������ʹ�����ţ�ʹ��1��2��pin0���ƣ�ʹ��3��4��pin1���ƣ�
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


//��ӡ������ͨ�ţ�SPI_MOSI��SPI_MISO��SPI_SCK
#define RCC_PRINTER_INTERFACE_GPIO				(RCC_APB2Periph_GPIOB)
#define RCC_PRINTER_INTERFACE_SPI 				(RCC_APB1Periph_SPI2)
#define GPIO_PRINTER_INTERFACE_PORT 			(GPIOB)
#define GPIO_PRINTER_INTERFACE_SPI_SCK		(GPIO_Pin_13)
#define GPIO_PRINTER_INTERFACE_SPI_MISO		(GPIO_Pin_14)
#define GPIO_PRINTER_INTERFACE_SPI_MOSI		(GPIO_Pin_15)


//��ӡ������ͨ��Latch�����ź�
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
*	�� �� ��: IsDetect_Ok
*	����˵��: �жϴ�ӡֽ�Ƿ�����
*	��    ��: ��
*	�� �� ֵ: ����ֵ1��ʾ��ӡֽ���� ��0��ʾ�޴�ӡֽ
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
*	�� �� ��: printer_moter_feed_step
*	����˵��: ��ӡ����ֽ����
*	��    �Σ�mode: 0-��ʾ�Ǵ�ӡ��ֽ��1-��ʾֻ��ֽ
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void printer_moter_feed_step(uint8_t mode)
{
	static uint16_t Rxdtime = 0;
	static uint8_t motor_state = 0;
	if (Motor_Feed_Step)
	{
		Rxdtime = 32;//ÿ4ms timeout_flag��λ,С��(32 + 1) * 3 = 99ms Rxdtime��ʱ
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
		if (mode == TPSTATE_CUT_FEED)//ֻ��ֽ����ֽ��ֹͣ������� ����
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
*	�� �� ��: printer_moter_cut_feed
*	����˵��: ��ӡ����ֽ����
*	��    �Σ�step_num:�����Ĳ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void printer_moter_cut_feed(uint8_t * step_num)
{
	if(Printer_State == TPSTATE_IDLE)
	{
		if(*step_num == 0xFF)
		{
			//���������������
			Usart1_Txd_Tempdata[0] = 0x00;
			Usart1_Txd_Tempdata[1] = 0x02;
			Usart1_Txd_Tempdata[2] = 0x11 | 0x80;
			Usart1_Txd_Tempdata[3] = 0x21;
			USART1_Tx_Chars(Usart1_Txd_Tempdata, 4);		
		}
		else
		{
			Motor_Feed_Step += *step_num;
			Printer_State = TPSTATE_CUT_FEED;
			//��������ִ�гɹ�
			Usart1_Txd_Tempdata[0] = 0x00;
			Usart1_Txd_Tempdata[1] = 0x01;
			Usart1_Txd_Tempdata[2] = 0x11;
			USART1_Tx_Chars(Usart1_Txd_Tempdata, 3);
		}
	}
	else
	{
		//����æµ
		Usart1_Txd_Tempdata[0] = 0x00;
		Usart1_Txd_Tempdata[1] = 0x02;
		Usart1_Txd_Tempdata[2] = 0x11 | 0x80;
		Usart1_Txd_Tempdata[3] = 0x20;
		USART1_Tx_Chars(Usart1_Txd_Tempdata, 4);		
	}
}

/*
*********************************************************************************************************
*	�� �� ��: printer_moter_feed
*	����˵��: ��ӡ����ֽ����
*	��    �Σ�void
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void printer_moter_feed(void)
{
	if(Printer_State == TPSTATE_IDLE)
	{
		Motor_Feed_Step += 2;
		Printer_State = TPSTATE_FEED;
		//��������ִ�гɹ�
		Usart1_Txd_Tempdata[0] = 0x00;
		Usart1_Txd_Tempdata[1] = 0x01;
		Usart1_Txd_Tempdata[2] = 0x11;
		USART1_Tx_Chars(Usart1_Txd_Tempdata, 3);
	}
	else
	{
		//����æµ
		Usart1_Txd_Tempdata[0] = 0x00;
		Usart1_Txd_Tempdata[1] = 0x02;
		Usart1_Txd_Tempdata[2] = 0x11 | 0x80;
		Usart1_Txd_Tempdata[3] = 0x20;
		USART1_Tx_Chars(Usart1_Txd_Tempdata, 4);		
	}
}

/*
*********************************************************************************************************
*	�� �� ��: printer_data_out
*	����˵��: ��ӡ����ֽ
*	��    �Σ���
*	�� �� ֵ: ��
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
*	�� �� ��: printer_start
*	����˵��: ��ӡ����ʼ��ӡ
*	��    �Σ���
*	�� �� ֵ: ��
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
	
	//���
	//Usart1_Txd_Tempdata[0] = 0x00;
	//Usart1_Txd_Tempdata[1] = 0x02;
	//Usart1_Txd_Tempdata[2] = 0x11;
	//Usart1_Txd_Tempdata[3] = 0x00;
	//USART1_Tx_Chars(Usart1_Txd_Tempdata, 4);
}

/*
*********************************************************************************************************
*	�� �� ��: printer_ceshi
*	����˵��: ��ӡ����ֽ
*	��    �Σ���
*	�� �� ֵ: ��
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
			//����æµ
			Usart1_Txd_Tempdata[0] = 0x00;
			Usart1_Txd_Tempdata[1] = 0x02;
			Usart1_Txd_Tempdata[2] = 0x11 | 0x80;
			Usart1_Txd_Tempdata[3] = 0x20;
			USART1_Tx_Chars(Usart1_Txd_Tempdata, 4);			
	}
}

/*
*********************************************************************************************************
*	�� �� ��: TIM2_ISR
*	����˵��: ��ʱ��2���жϷ������
*	��    �Σ���
*	�� �� ֵ: ��
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
*	�� �� ��: printer_Init
*	����˵��: ������ӡģ��������ӿڳ�ʼ��������1.�������ź�IO��ʼ��  2.SPIģ���ʼ�� 3.��ʱ����ʼ��
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void printer_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	SPI_InitTypeDef  SPI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
	uint8_t i,j;

	/* ��ӡ����Դ�������� */
	RCC_APB2PeriphClockCmd(RCC_PRINTER_PWR, ENABLE);
	PRINTER_PWR_OFF();//�رմ�ӡ���ܵ�Դ

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_InitStructure.GPIO_Pin = GPIO_PRINTER_PWR_PIN;
	GPIO_Init(GPIO_PRINTER_PWR_PORT, &GPIO_InitStructure);

	/* ���������Դ�������� */
	RCC_APB2PeriphClockCmd(RCC_PRINTER_MOTOR_PWR, ENABLE);
	PRINTER_MOTOR_PWR_OFF();//�رղ��������Դ

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_InitStructure.GPIO_Pin = GPIO_PRINTER_MOTOR_PWR_PIN;
	GPIO_Init(GPIO_PRINTER_MOTOR_PWR_PORT, &GPIO_InitStructure);

	/* 
	*	MOTOR ���� 1~4 
	*	����PB4Ϊjtag�ӿ�������Ҫ����jtag���ܣ���Ҫ����AFIO��ʱ��
	*/
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_PRINTER_MOTOR, ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable , ENABLE);//����jtag
	
	MOTOR_PHASE_DISABLE();//��ʼ���ò������4�߶�Ϊ��
	GPIO_InitStructure.GPIO_Pin = GPIO_PRINTER_MOTOR_1A_PIN | GPIO_PRINTER_MOTOR_1B_PIN | GPIO_PRINTER_MOTOR_2A_PIN | GPIO_PRINTER_MOTOR_2B_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIO_PRINTER_MOTOR_PORT, &GPIO_InitStructure);
	
	PRINTER_PWR_ON();	
	PRINTER_MOTOR_PWR_ON();
	
	/* ��ӡ��ֽ��������� */
	RCC_APB2PeriphClockCmd(RCC_PRINTER_DETECT, ENABLE);

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_InitStructure.GPIO_Pin = GPIO_PRINTER_DETECT_PIN;
	GPIO_Init(GPIO_PRINTER_DETECT_PORT, &GPIO_InitStructure);
	
	
	/* ��ӡ������ʹ������ */
	RCC_APB2PeriphClockCmd(RCC_PRINTER_HEAT_ENABLE, ENABLE);
	STROBE_12_OFF();//�͵�ƽʹ�ܣ��ϵ�����Ϊ��

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_InitStructure.GPIO_Pin = GPIO_PRINTER_HEAT_ENABLE_PIN_0 | GPIO_PRINTER_HEAT_ENABLE_PIN_1;
	GPIO_Init(GPIO_PRINTER_HEAT_ENABLE_PORT, &GPIO_InitStructure);
	
	/* ��ӡ��Latch�����ź����� */
	RCC_APB2PeriphClockCmd(RCC_PRINTER_LATCH, ENABLE);
	LATCH_HIGH();//���������棬�ϵ�����Ϊ��

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_InitStructure.GPIO_Pin = GPIO_PRINTER_LATCH_PIN;
	GPIO_Init(GPIO_PRINTER_LATCH_PORT, &GPIO_InitStructure);
	
	/* ��ӡ��SPIͨ������ */

	RCC_APB2PeriphClockCmd(RCC_PRINTER_INTERFACE_GPIO, ENABLE);	
	RCC_APB1PeriphClockCmd(RCC_PRINTER_INTERFACE_SPI, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_PRINTER_INTERFACE_SPI_MOSI | GPIO_PRINTER_INTERFACE_SPI_SCK;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//����Ϊ�������칦��
	GPIO_Init(GPIO_PRINTER_INTERFACE_PORT, &GPIO_InitStructure);
	
	
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;  //����SPI�������˫�������ģʽ:SPI����Ϊ˫��˫��ȫ˫��
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;												//����SPI����ģʽ:����Ϊ��SPI
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;										//����SPI�����ݴ�С:SPI���ͽ���8λ֡�ṹ
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;													//ѡ���˴���ʱ�ӵ���̬:����ʱΪ��
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;												//���ݲ����ڵ�һ��ʱ����
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;														//NSS�ź���Ӳ����NSS�ܽţ�����������ʹ��SSIλ������:�ڲ�NSS�ź���SSIλ����
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_8;  //���岨����Ԥ��Ƶ��ֵ:������Ԥ��ƵֵΪ8
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;									//ָ�����ݴ����MSBλ����LSBλ��ʼ:���ݴ����MSBλ��ʼ
	SPI_InitStructure.SPI_CRCPolynomial = 7;														//CRCֵ����Ķ���ʽ

  SPI_Init(SPI2, &SPI_InitStructure);  																//����SPI_InitStruct��ָ���Ĳ�����ʼ������SPIx�Ĵ���
  SPI_Cmd(SPI2, ENABLE);


	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); //ʱ��ʹ��
	TIM_DeInit(TIM2);
	TIM_InternalClockConfig(TIM2);
	TIM_TimeBaseStructure.TIM_Period = 30-1; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	 ������30Ϊ3ms
	TIM_TimeBaseStructure.TIM_Prescaler =36000000L/10000L-1;	 //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ  10Khz�ļ���Ƶ��  
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;  //TIM2�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  //��ռ���ȼ�1��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;  //�����ȼ�0��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
	NVIC_Init(&NVIC_InitStructure);  //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���
	
	TIM_ClearFlag(TIM2,TIM_FLAG_Update);
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE); // ʹ��TIM2�����ж�
	
	for (i = 0; i < 16; i ++)
	{
		for (j = 0; j < (LINEDOT/8+1); j ++)
		{
			if (j%8 == 0)
			{Printer_Dot[i][j] = 0xFF;}
			else
			{Printer_Dot[i][j] = 0x00;}
		}
	}
	Printer_State = TPSTATE_IDLE;
}



/*
*********************************************************************************************************
*	�� �� ��: printer_CMD_DEAL
*	����˵��: ������ӡ���������
*	��    �Σ�databuf	�����ڽ��յ������ݰ������ֽڵ�ַ
						length	: ���ݰ�����
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void printer_CMD_DEAL(uint8_t *databuf, uint16_t length)
{
	switch (*databuf)
	{
		case 0x10:
			//��������
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
					//���������������
					Usart1_Txd_Tempdata[0] = 0x00;
					Usart1_Txd_Tempdata[1] = 0x02;
					Usart1_Txd_Tempdata[2] = 0x11 | 0x80;
					Usart1_Txd_Tempdata[3] = 0x21;
					USART1_Tx_Chars(Usart1_Txd_Tempdata, 4);
				}
			}
			else
			{
				//��������������ȴ���
				Usart1_Txd_Tempdata[0] = 0x00;
				Usart1_Txd_Tempdata[1] = 0x02;
				Usart1_Txd_Tempdata[2] = 0x11 | 0x80;
				Usart1_Txd_Tempdata[3] = 0x11;
				USART1_Tx_Chars(Usart1_Txd_Tempdata, 4);
			}
			break;
		case 0x11:
			//���������ֽ
			if (length == 2)
			{
				printer_moter_cut_feed(databuf+1);
			}
			else
			{
				//��������������ȴ���
				Usart1_Txd_Tempdata[0] = 0x00;
				Usart1_Txd_Tempdata[1] = 0x02;
				Usart1_Txd_Tempdata[2] = 0x11 | 0x80;
				Usart1_Txd_Tempdata[3] = 0x11;
				USART1_Tx_Chars(Usart1_Txd_Tempdata, 4);			
			}
			break;
		default :
				//����֧�ָ�����
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
*	�� �� ��: printer_SERVER_TASK
*	����˵��: ��ӡ����ط�����
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void printer_SERVER_TASK(void)
{
  static uint32_t sys_time, time_ms = 0, time_add_up = 0;
  const uint32_t work_time_max = 2;
	uint32_t offset_time_ticks = 0;
	uint8_t timeout_flag = 0;
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
				if (1)//�˴�����¶��Ƿ񳬹�����ֵ
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
						//��ӡ���¶ȹ���
						Usart1_Txd_Tempdata[0] = 0x00;
						Usart1_Txd_Tempdata[1] = 0x02;
						Usart1_Txd_Tempdata[2] = 0x11 | 0x80;
						Usart1_Txd_Tempdata[3] = 0x31;
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
					//��ӡֽλ�ü�����
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