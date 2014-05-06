/*
*********************************************************************************************************
*
*	模块名称 : APP模块
*	文件名称 : app.h
*	版    本 : V1.0
*	说    明 :
*
*********************************************************************************************************
*/
#ifndef _ASP_H_
#define _ASP_H_

#include "bsp.h"

#include "app_uart.h"
#include "app_printer.h"

/* 定义系统状态 */
typedef enum
{
	SYS_POWER_ON = 0,

}WORK_MODE;

extern WORK_MODE Sys_Work_Mode;

void App_Init(void);
void App_Task(void);
#endif
