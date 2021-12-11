#include "spi_flash.h"
#include <string.h>


#define SECTOR_SIZE 4096
#define SECTORS_PER_BLOCK 16
#define NOF_BLOCKS 16

uint8_t flashmem[NOF_BLOCKS * SECTORS_PER_BLOCK * SECTOR_SIZE];

void sFLASH_WriteEnable(void)
{
    
}


void sFLASH_EraseBulk(void)
{
    memset(flashmem, 0xff, sizeof(flashmem));
}


void sFLASH_WritePage(uint8_t* pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite)
{

}

void sFLASH_WriteBuffer(uint8_t* pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite)
{

}

void sFLASH_ReadBuffer(uint8_t* pBuffer, uint32_t ReadAddr, uint16_t NumByteToRead)
{

}
