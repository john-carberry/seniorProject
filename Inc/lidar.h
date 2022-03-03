/*
 * lidar.h
 *
 *  Created on: Mar 1, 2022
 *      Author: johnc
 */

#ifndef INC_LIDAR_H_
#define INC_LIDAR_H_

uint16_t getDistanceLidar(I2C_HandleTypeDef * I2C);
uint16_t getSpeedLidar(uint16_t distance);


#endif /* INC_LIDAR_H_ */
