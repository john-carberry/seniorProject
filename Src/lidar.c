/*
 * lidar.c
 *
 *  Created on: Mar 1, 2022
 *      Author: johnc
 */



#include <stm32g0xx.h>


static int pastSpeed[4];
static int pastDistance = 0;
static uint32_t beginTime = 0;



uint16_t getDistanceLidar(I2C_HandleTypeDef * I2C){
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

uint16_t getSpeedLidar(uint16_t distance){

	uint32_t sumVal;
	uint32_t uDelta;




	int delta = pastDistance - (int)distance;
	if(distance < 0){
		distance = distance * -1;
	}
	if(delta < 0){
		delta = delta * -1;
	}
	pastDistance = distance;
	uDelta = (uint32_t)delta;
	uint32_t speed = uDelta * 100 / (uint32_t)(HAL_GetTick()- beginTime);

	sumVal = 0;
	for(int i = 0; i < 4; i++){
		sumVal = pastSpeed[i] + sumVal;
	}
	sumVal = sumVal + speed;



	pastSpeed[3] = pastSpeed[2];
	pastSpeed[2] = pastSpeed[1];
	pastSpeed[1] = pastSpeed[0];
	pastSpeed[0] = speed;
	speed = sumVal / 5;



	beginTime = HAL_GetTick();
	return (speed);



}
