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

extern FRAME_STATE uart_FRAME_STATE;

uint8_t uart_SERVER_TASK(void);

#endif


