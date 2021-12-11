#include "spi_flash.h"
#include <string.h>


#define SECTOR_SIZE 4096
#define SECTORS_PER_BLOCK 16
#define NOF_BLOCKS 16

static uint8_t flashmem[NOF_BLOCKS * SECTORS_PER_BLOCK * SECTOR_SIZE];

void SPI_FLASH_Init(void)  {}
void SPI_FLASH_SectorErase(uint32_t SectorAddr)  /* set sector to 0xff */
{
    uint32_t SectorAddr1 = ((uint32_t)(SectorAddr / SECTOR_SIZE)) * SECTOR_SIZE;
    memset(flashmem + SectorAddr1 , 0xff, SECTOR_SIZE);
}

void SPI_FLASH_BulkErase(void) /* set entire chip to 0xff */
{
    memset(flashmem, 0xff, sizeof(flashmem));
}

uint32_t SPI_FLASH_ReadID(void)  
{
    return (0xef << 16) | 0x00; /* add devide id */
}

void sFLASH_WriteEnable(void) 
{

}


void sFLASH_EraseBulk(void)
{
    memset(flashmem, 0xff, sizeof(flashmem));
}


void sFLASH_WritePage(uint8_t* pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite)
 /* write data into simulated page*/
{
    memcpy(flashmem + WriteAddr, pBuffer, NumByteToWrite);
}

void sFLASH_ReadBuffer(uint8_t* pBuffer, uint32_t ReadAddr, uint16_t NumByteToRead)
 /*read data .. no page based restrictions*/
{
    memcpy(pBuffer, flashmem + ReadAddr, NumByteToRead);
}
