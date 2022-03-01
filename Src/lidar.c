/*
 * lidar.c
 *
 *  Created on: Mar 1, 2022
 *      Author: johnc
 */



#include <stm32g0xx.h>

uint16_t getSpeedLidar(I2C_HandleTypeDef * I2C){
	  uint8_t I2C_data = 0x04;
	  uint8_t I2C_readL;
	  uint8_t I2C_readH;

	  //reset low and high byte to 0
	  I2C_readL = 0;
	  I2C_readH = 0;
	  while((I2C_readL & 0x01) != 0x01){
		  HAL_I2C_Mem_Write(I2C, 0X00C4, 0x00,1, &I2C_data, 1, 100);
		  //Read

		  HAL_I2C_Mem_Read(I2C, 0X00C5, 0x01,1, &I2C_readL, 1, 100);


	  }
	  HAL_I2C_Mem_Read(I2C, 0X00C5, 0x0f,1, &I2C_readH, 1, 100);
	  HAL_I2C_Mem_Read(I2C, 0X00C5, 0x10,1, &I2C_readL, 1, 100);
	  uint16_t finalNumber = (((uint16_t)I2C_readH) << 8) | ((uint16_t)I2C_readL);
	  return finalNumber;
}
