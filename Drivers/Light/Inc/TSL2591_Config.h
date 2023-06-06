#ifndef _TSL2591_CONFIG_H_
#define _TSL2591_CONFIG_H_

#include "stm32f4xx_hal.h"
#include "main.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>

// #define TSL2591_SPI 0
#define TSL2591_I2C 1

/**
 * data
**/
#define UBYTE   uint8_t
#define UWORD   uint16_t
#define UDOUBLE uint32_t

//#define INT_PIN INT_GPIO_Port,INT_Pin

/**
 * GPIO read and write
**/
#define TSL2591_Digital_Write(_pin, _value)		HAL_GPIO_WritePin(_pin, _value == 0? GPIO_PIN_RESET:GPIO_PIN_SET)
#define TSL2591_Digital_Read(_pin)						HAL_GPIO_ReadPin(_pin)

/*------------------------------------------------------------------------------------------------------*/
uint8_t TSL2591_ModuleInit(void);
void    TSL2591_ModuleExit(void);

void TSL2591_I2C_Init(uint8_t Add);
void I2C_Write_Byte(uint8_t Cmd, uint8_t value);
int I2C_Read_Byte(uint8_t Cmd);
int I2C_Read_Word(uint8_t Cmd);

void TSL2591_GPIO_Mode(GPIO_TypeDef* GPIO_Port, UWORD Pin, UWORD mode);
// void TSL2591_Digital_Write(UWORD Pin, UBYTE Value);
// UBYTE TSL2591_Digital_Read(UWORD Pin);

void TSL2591_Delay_ms(UDOUBLE xms);

// void TSL2591_SPI_WriteByte(UBYTE Value);
// void TSL2591_SPI_Write_nByte(uint8_t *pData, uint32_t Len);

#endif