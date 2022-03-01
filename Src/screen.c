


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
