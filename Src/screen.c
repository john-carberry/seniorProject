


#include <stm32g0xx.h>

HAL_StatusTypeDef printFourScreen(char *dataField, uint16_t value, UART_HandleTypeDef *uartADDR){
	 uint8_t screenData[16];


	 for (int i = 0; i < 3; i++){
		 screenData[i] = 0xFF;
	 }
	 for(int i = 3; i < 10; i++){
		 screenData[i] = dataField[i-3];
	 }
	  screenData[10] = 0x22;
	  screenData[11] = (value / 1000) + 48;
	  screenData[12] = ((value % 1000) / 100) + 48;
	  screenData[13] = ((value % 100) / 10) + 48;
	  screenData[14] = (value % 10) + 48;
	  screenData[15] = 0x22;
	  return HAL_UART_Transmit(uartADDR, screenData, 16,500);

}


HAL_StatusTypeDef switchScreen(uint16_t screen, UART_HandleTypeDef *uartADDR){
	uint8_t screenData[13];
	for (int i = 0; i < 3; i++){
			 screenData[i] = 0xFF;
		 }
	screenData[4] = "p";
	screenData[5] = "a";
	screenData[6] = "g";
	screenData[7] = "e";
	screenData[8] = " ";
	screenData[9] = screen + 48;
	for (int i = 10; i < 13; i++){
			 screenData[i] = 0xFF;
		 }
	return HAL_UART_Transmit(uartADDR, screenData, 10,500);

}
