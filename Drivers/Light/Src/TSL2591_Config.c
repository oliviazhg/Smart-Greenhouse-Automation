#include <TSL2591_Config.h>
#include "main.h"

// uint8_t TSL2591_SPI_Device = 0;
uint8_t TSL2591_I2C_Device = 0;
uint8_t I2C_ADDR;

/******************************************************************************
function:	GPIO Function initialization and transfer
parameter:
Info:
******************************************************************************/
void TSL2591_GPIO_Mode(GPIO_TypeDef* GPIO_Port, UWORD Pin, UWORD mode)
{
    /*
        0:  INPT   
        1:  OUTP
    */
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = Pin;
	if(mode == GPIO_MODE_INPUT || mode == 0){
		GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	}else if(mode == GPIO_MODE_OUTPUT_PP || mode == 1){
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	}else{
		GPIO_InitStruct.Mode = mode;
	}
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIO_Port, &GPIO_InitStruct);
}

/**
 * delay x ms
**/
void TSL2591_Delay_ms(UDOUBLE xms)
{
	HAL_Delay(xms);
}

void GPIO_Config(void)
{
    //TSL2591_GPIO_Mode(INT_PIN, 0);
}

/******************************************************************************
function:	SPI Function initialization and transfer
parameter:
Info:

void TSL2591_SPI_Init()
{
#if TSL2591_SPI
	TSL2591_SPI_Device = 1;
#endif
}

void TSL2591_SPI_WriteByte(uint8_t Value)
{
#if TSL2591_SPI
	
#endif
}

void TSL2591_SPI_Write_nByte(uint8_t *pData, uint32_t Len)
{
#if TSL2591_SPI
	
#endif
}
******************************************************************************/

/******************************************************************************
function:	I2C Function initialization and transfer
parameter:
Info:
******************************************************************************/
void TSL2591_I2C_Init(uint8_t Add)
{
#if TSL2591_I2C
	TSL2591_I2C_Device = 1;
	I2C_ADDR =  Add;
#endif
}

void I2C_Write_Byte(uint8_t Cmd, uint8_t value)
{
#if TSL2591_I2C
	UBYTE Buf[1] = {0};
	Buf[0] = value;
	HAL_I2C_Mem_Write(&hi2c1, I2C_ADDR, Cmd, I2C_MEMADD_SIZE_8BIT, Buf, 1, 0x20);
#endif
}

int I2C_Read_Byte(uint8_t Cmd)
{
#if TSL2591_I2C
	UBYTE Buf[1]={0};
	HAL_I2C_Mem_Read(&hi2c1, I2C_ADDR+1, Cmd, I2C_MEMADD_SIZE_8BIT, Buf, 1, 0x20);
	return Buf[0];
#endif
}

int I2C_Read_Word(uint8_t Cmd)
{
#if TSL2591_I2C
	UBYTE Buf[2]={0, 0};
	HAL_I2C_Mem_Read(&hi2c1, I2C_ADDR+1, Cmd, I2C_MEMADD_SIZE_8BIT, Buf, 2, 0x20);
	return ((Buf[1] << 8) | (Buf[0] & 0xff));
#endif
}

/******************************************************************************
function:	Module Initialize, the library and initialize the pins, SPI protocol
parameter:
Info:
******************************************************************************/
UBYTE TSL2591_ModuleInit(void)
{
		GPIO_Config();
    TSL2591_I2C_Init(0x29<<1);
    return 0;
}

/******************************************************************************
function:	Module exits, closes SPI and BCM2835 library
parameter:
Info:
******************************************************************************/
void TSL2591_ModuleExit(void)
{
	
}