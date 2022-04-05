/*
 * screen.h
 *
 *  Created on: Mar 1, 2022
 *      Author: johnc
 */

#ifndef INC_SCREEN_H_
#define INC_SCREEN_H_






HAL_StatusTypeDef printFourScreen(char *dataField, uint16_t value, UART_HandleTypeDef *uartADDR);
HAL_StatusTypeDef switchScreen(uint16_t screen, UART_HandleTypeDef *uartADDR);

#endif /* INC_SCREEN_H_ */
