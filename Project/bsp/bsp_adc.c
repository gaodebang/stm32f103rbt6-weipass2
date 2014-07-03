/*
*********************************************************************************************************
*
*	模块名称 : ADC模块
*	文件名称 : bsp_adc.c
*	版    本 : V1.0
*	说    明 : 
*
*********************************************************************************************************
*/

#include "bsp.h"
/*
*********************************************************************************************************
*	函 数 名: bsp_InitAdc
*	功能说明: 初始化串口硬件，并对全局变量赋初值.
*	形    参:  无
*	返 回 值: 无
*********************************************************************************************************
*/
void bsp_InitAdc(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
	ADC_InitTypeDef  ADC_InitStructure;
	
  //PC0 作为模拟通道输入引脚    
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	ADC_DeInit(ADC1);  //将外设 ADC1 的全部寄存器重设为缺省值
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);   //72M/6=12,ADC最大时间不能超过14M
	
  ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;                    // ADC1 在独立模式
  ADC_InitStructure.ADC_ScanConvMode = DISABLE;                         // ENABLE-ADC多通道扫描, DISABLE-ADC单通道扫描
  ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;                    // ENABLE--ADC连续转化模式 DISABLE--ADC单次转化模式
  ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;   // 由软件触发
  ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;                // 数据向右对齐
  ADC_InitStructure.ADC_NbrOfChannel = 1;                               // 连续转化1个AD通道值
  ADC_Init(ADC1, &ADC_InitStructure);

  /* ADC1 通道10采样时间设置 */ 
  ADC_RegularChannelConfig(ADC1, ADC_Channel_10, 1, ADC_SampleTime_13Cycles5);
 
  ADC_Cmd(ADC1, ENABLE); // 使能 ADC1
  
  ADC_ResetCalibration(ADC1);	//重置指定的ADC1的校准寄存器
	 
	while(ADC_GetResetCalibrationStatus(ADC1));	//获取ADC1重置校准寄存器的状态,设置状态则等待
	
	ADC_StartCalibration(ADC1);		//开始指定ADC1的校准状态
 
	while(ADC_GetCalibrationStatus(ADC1));		//获取指定ADC1的校准程序,设置状态则等待
 
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);		//使能指定的ADC1的软件转换启动功能
}
/*
//ADC1_value = ADC_GetConversionValue(ADC1); 

热敏电阻 75 摄氏度 最大值为4.9K

则 adc值 为 4.9	（4.9+30）*4095

// 575
*/
