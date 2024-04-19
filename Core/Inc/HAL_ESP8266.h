#ifndef __HAL_ESP8266_H_
#define __HAL_ESP8266_H_
#include "stm32f4xx_hal.h"
#include "string.h"
#include "stdio.h"
extern UART_HandleTypeDef huart2;
char esp8266_init(void);
char esp8266_conect(char* SSID, char* PASSWORD);
char esp8266_changesever(char* SSID, char* PASSWORD);
void Error_Handler(void);

#endif
