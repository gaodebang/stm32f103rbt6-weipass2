/*
*********************************************************************************************************
*
*	模块名称 : NOR Flash驱动模块
*	文件名称 : bsp_nor_flash.h
*	版    本 : V1.0
*	说    明 : 头文件
*
*********************************************************************************************************
*/

#ifndef _BSP_NOR_FLASH_H
#define _BSP_NOR_FLASH_H

/*
	NOR Flash 型号 S29GL128P10TFI01
	容量16M字节，16Bit，100ns速度
	物理地址 : 0x6400 0000
*/

#define NOR_FLASH_ADDR  	((uint32_t)0x64000000)

#define NOR_SECTOR_SIZE		(128 * 1024)	/* 扇区大小 */
#define NOR_SECTOR_COUNT	128				/* 扇区个数 */
#define NOR_FLASH_SIZE		(NOR_SECTOR_SIZE * NOR_SECTOR_COUNT)

/*
	制造商ID：Spansion   0x01

	S29GL01GP	01 7E 28 01		1 Gigabit		128M字节
	S29GL512P	01 7E 23 01		512 Megabit		64M字节
	S29GL256P	01 7E 22 01		256 Megabit		32M字节
	S29GL128P	01 7E 21 01		128 Megabit		16M字节
*/
typedef enum
{
	S29GL128P = 0x017E2101,
	S29GL256P = 0x017E2201,
	S29GL512P = 0x017E2301
}NOR_CHIP_ID;

/* NOR Status */
typedef enum
{
	NOR_SUCCESS = 0,
	NOR_ONGOING = 1,
	NOR_ERROR   = 2,
	NOR_TIMEOUT = 3
}NOR_STATUS;

void bsp_InitNorFlash(void);
uint32_t NOR_ReadID(void);
uint8_t NOR_EraseChip(void);
uint8_t NOR_EraseSector(uint32_t _uiBlockAddr);
uint8_t NOR_ReadByte(uint32_t _uiWriteAddr);
void NOR_ReadBuffer(uint8_t *_pBuf, uint32_t _uiWriteAddr, uint32_t _uiBytes);
uint8_t NOR_WriteHalfWord(uint32_t _uiWriteAddr, uint16_t _usData);
uint8_t NOR_WriteByte(uint32_t _uiWriteAddr, uint8_t _ucByte);
uint8_t NOR_WriteInPage(uint16_t *pBuffer, uint32_t _uiWriteAddr,  uint16_t _usNumHalfword);
uint8_t NOR_WriteBuffer(uint8_t *_pBuf, uint32_t _uiWriteAddr, uint32_t _uiBytes);

#endif
