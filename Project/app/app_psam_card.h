/*
*********************************************************************************************************
*
*	模块名称 : PSAM CARD模块
*	文件名称 : app_psam_card.h
*	版    本 : V1.0
*	说    明 : 头文件
*
*********************************************************************************************************
*/

#ifndef __APP_PSAM_CARD_H
#define __APP_PSAM_CARD_H

void psam_card_Init(void);
void psam_card_CMD_DEAL(uint8_t *databuf, uint16_t length);
void psam_card_SERVER_TASK(void);

#endif


