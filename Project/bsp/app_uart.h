/*
*********************************************************************************************************
*
*	模块名称 : 串口模块
*	文件名称 : app_uart.h
*	版    本 : V1.0
*	说    明 : 头文件
*
*********************************************************************************************************
*/

#ifndef __APP_UART_H
#define __APP_UART_H

typedef enum
{
	frame_idle = 0, 
	frame_sof, 
	frame_normal,
	frame_mark,
	frame_eof
}FRAME_STATE;

extern FRAME_STATE uart_FRAME_STATE;

void uart_SERVER_TASK(void);

#endif


