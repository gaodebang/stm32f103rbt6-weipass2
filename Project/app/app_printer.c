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

volatile uint8_t Motor_Port_Map = 0;

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

//步进电机电源
#define RCC_PRINTER_MOTOR_PWR 						(RCC_APB2Periph_GPIOC)
#define GPIO_PRINTER_MOTOR_PWR_PORT 			(GPIOC)
#define GPIO_PRINTER_MOTOR_PWR_PIN 				(GPIO_Pin_11)

#define PRINTER_MOTOR_PWR_ON()	do{	\
	GPIO_SetBits(GPIO_PRINTER_MOTOR_PWR_PORT, GPIO_PRINTER_MOTOR_PWR_PIN); \
}while(0)

#define PRINTER_MOTOR_PWR_OFF() do{	\
	GPIO_ResetBits(GPIO_PRINTER_MOTOR_PWR_PORT, GPIO_PRINTER_MOTOR_PWR_PIN); \
}while(0)

//马达相位信号
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

//光电检测引脚（用于检测打印纸是否正常）
#define RCC_PRINTER_DETECT 						(RCC_APB2Periph_GPIOC)
#define GPIO_PRINTER_DETECT_PORT 			(GPIOC)
#define GPIO_PRINTER_DETECT_PIN 			(GPIO_Pin_6)





#define MOTOR_STEP_FOUR()	do{ \
	MOTOR_PHASE_A_REVERSE(); \
	MOTOR_PHASE_B_FORWARD(); \
}while(0)

//Latch信号
#define LATCH_HIGH()	do{	\
	GPIO_SetBits(GPIOB, GPIO_Pin_14);	\
	}while(0)

#define LATCH_LOW()	do{	\
	GPIO_ResetBits(GPIOB, GPIO_Pin_14);	\
	}while(0)

//STROBE加热选通信号
#define STROBE_0_ON()	do{	\
	GPIO_ResetBits(GPIOB, GPIO_Pin_10);	\
	}while(0)
#define STROBE_0_OFF()	do{	\
	GPIO_SetBits(GPIOB, GPIO_Pin_10);	\
	}while(0)

#define STROBE_1_ON()	do{	\
	GPIO_ResetBits(GPIOB, GPIO_Pin_11);	\
	}while(0)
#define STROBE_1_OFF()	do{	\
	GPIO_SetBits(GPIOB, GPIO_Pin_11);	\
	}while(0)

#define STROBE_2_ON()	do{	\
	GPIO_ResetBits(GPIOB, GPIO_Pin_12);	\
	}while(0)
#define STROBE_2_OFF()	do{	\
	GPIO_SetBits(GPIOB, GPIO_Pin_12);	\
	}while(0)

#define STROBE_12_ON()	do{	\
	GPIO_ResetBits(GPIOB, GPIO_Pin_11 | GPIO_Pin_12);	\
	}while(0)
#define STROBE_12_OFF()	do{	\
	GPIO_SetBits(GPIOB, GPIO_Pin_11 | GPIO_Pin_12);	\
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
*	函 数 名: Printer_Init
*	功能说明: 热敏打印模块的驱动接口初始化。包含1.各驱动信号IO初始化  2.SPI模块初始化 3.定时器初始化
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
void Printer_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

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
}

void printer_SERVER_TASK(void)
{
  static uint32_t sys_time, time_ms = 0, time_add_up = 0;
  const uint32_t work_time_max = 3;
	uint32_t offset_time_ticks = 0;
	uint8_t timeout_flag = 0;
	
	static uint8_t motor_state = 0;
	
	DISABLE_INT();
	sys_time = Sys_Time;
	ENABLE_INT();
	
	if(time_ms != sys_time)
	{
		if(time_ms < sys_time)
		{
			offset_time_ticks = sys_time - time_ms;
			time_ms = sys_time;
			if(((uint64_t)offset_time_ticks  + (uint64_t)time_add_up) > UINT_LEAST32_MAX)
			{
				timeout_flag = 1;
				time_add_up = 0;
			}
			else if((offset_time_ticks  + time_add_up) > work_time_max)
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
			if(((uint64_t)offset_time_ticks  + (uint64_t)time_add_up) > UINT_LEAST32_MAX)
			{
				timeout_flag = 1;
				time_add_up = 0;
			}
			else if((offset_time_ticks  + time_add_up) > work_time_max)
			{
				timeout_flag = 1;
				time_add_up = 0;
			}
			else
			{
				time_add_up += offset_time_ticks;
			}
		}
		if(timeout_flag == 1)
		{
			timeout_flag = 0;
			if(IsDetect_Ok())
			{
				switch(motor_state)
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
				if(++motor_state >=4)
				{
					motor_state = 0;
				}
			}
			else
			{
				MOTOR_PHASE_DISABLE();
			}
		}
	}
}
