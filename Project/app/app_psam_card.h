/*
*********************************************************************************************************
*
*	ģ������ : PSAM CARDģ��
*	�ļ����� : app_psam_card.h
*	��    �� : V1.0
*	˵    �� : ͷ�ļ�
*
*********************************************************************************************************
*/

#ifndef __APP_PSAM_CARD_H
#define __APP_PSAM_CARD_H

void psam_card_Init(void);
void psam_card_CMD_DEAL(uint8_t *databuf, uint16_t length);
void psam_card_SERVER_TASK(void);

#endif

