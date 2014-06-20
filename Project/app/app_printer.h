/*
*********************************************************************************************************
*
*	模块名称 : 打印机模块
*	文件名称 : app_printer.h
*	版    本 : V1.0
*	说    明 : 头文件
*
*********************************************************************************************************
*/

#ifndef __APP_PRINTER_H
#define __APP_PRINTER_H

void printer_Init(void);
void TIM2_ISR(void);
void TIM2_ISR_HIGH(void);
void printer_CMD_DEAL(uint8_t *databuf, uint16_t length);
void printer_SERVER_TASK(void);

#endif


