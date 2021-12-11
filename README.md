# spi_flash_simulation

KVstore uses underlying implementation spi_flash.c
Assuming here https://github.com/offchooffcho/STM32-1/blob/master/DFUBootloader/spi_flash.c
is correct implementation, one can see that SPI_FLASH_BufferWrite
uses SPI_FLASH_PageWrite and does not call any other HW specific calls.

we need to implement
void SPI_FLASH_Init(void)  ... doing nothing
void SPI_FLASH_SectorErase(uint32_t SectorAddr)  .. set sector to 0xff
void SPI_FLASH_BulkErase(void) .. set entire chip to 0xff
void SPI_FLASH_PageWrite(uint8_t* pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite)  write data into simulated page
void SPI_FLASH_BufferRead(uint8_t* pBuffer, uint32_t ReadAddr, uint16_t NumByteToRead)  read data .. no page based restrictions
uint32_t SPI_FLASH_ReadID(void)  return data
void SPI_FLASH_WriteEnable(void) can be empty

Cmocka library could be used to mock in embedded environment as well !
However this implementation is quite memory hungry and suitable for PC.
It uses at least as much RAM as the complete EEPROM chip size.
Different implentation allocating only memory blocks used (written) on heap would be neded in system with smaller RAM.