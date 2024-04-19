#include "HAL_ESP8266.h"

void UART_SendString(const char* str) {
    HAL_UART_Transmit(&huart2, (uint8_t*)str, strlen(str), HAL_MAX_DELAY);
}
void UART_ReceiveString(char* buffer, uint16_t buffer_size, uint32_t timeout) {
    HAL_UART_Receive(&huart2, (uint8_t*)buffer, buffer_size, timeout);
}
void GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  __HAL_RCC_GPIOD_CLK_ENABLE();


  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_14, GPIO_PIN_RESET);


  GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_14;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);


}
void UART2_Init(void)
{
	huart2.Instance = USART2;
	huart2.Init.BaudRate = 115200;
	huart2.Init.WordLength = UART_WORDLENGTH_8B;
	huart2.Init.StopBits = UART_STOPBITS_1;
	huart2.Init.Parity = UART_PARITY_NONE;
	huart2.Init.Mode = UART_MODE_TX_RX;
	huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;

	if (HAL_UART_Init(&huart2) != HAL_OK) {
	        Error_Handler();
	 }
}
char esp8266_init(void)
{
	char result[20];
	UART2_Init();
	char response[100];
	char ip[110];
	UART_SendString("AT+RST\r\n");
	HAL_Delay(3000);
	UART_SendString("AT\r\n");
	UART_ReceiveString(response, sizeof(response),500);

	if (strstr(response, "OK") != NULL) {
		strcpy(result, "OK");
	}
	else
	{
		strcpy(result, "ERROR");
		goto RS;
	}
	UART_SendString("AT+CWMODE=3\r\n");
	UART_ReceiveString(response, sizeof(response),500);

	if (strstr(response, "OK") != NULL) {
		strcpy(result, "OK");
	}
	else
	{
		strcpy(result, "ERROR");
		goto RS;
	}
	UART_SendString("AT+CIPMUX=1\r\n");
	UART_ReceiveString(response, sizeof(response),500);

	if (strstr(response, "OK") != NULL) {
		strcpy(result, "OK");
	}
	else
	{
		strcpy(result, "ERROR");
		goto RS;
	}

	UART_SendString("AT+CIPSERVER=1,80\r\n");
	UART_ReceiveString(response, sizeof(response),500);


	if (strstr(response, "OK") != NULL) {
		strcpy(result, "OK");
	}
	else
	{
		strcpy(result, "ERROR");
		goto RS;
	}
	UART_SendString("AT+CIFSR\r\n");
	UART_ReceiveString(response, sizeof(response), 1000);
	strcat(ip, "");
	strcat(ip, "IP: ");
	strcat(ip, response);

	RS:
	return *result;


}

char esp8266_conect(char* SSID, char* PASSWORD)
{
	GPIO_Init();
	char response[20];
	char result[20];
	char cmd[100];
	char reco[20];
	sprintf(cmd, "AT+CWJAP=\"%s\",\"%s\"\r\n", SSID, PASSWORD);
    UART_SendString(cmd);
    HAL_Delay(7000);
	UART_ReceiveString(response, sizeof(response),10000);
	scs:
	if (strstr(response, "OK") != NULL) {
		UART_SendString("CONNECTED.");
		for (int i=0; i<6; i++)
		{
			HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
			HAL_Delay(300);
		}

		strcpy(result, "OK");
	}
	else
	{
		strcpy(result, "FAIL");
		for (int i=0; i<3; i++)
		{
		for (int j=0; j<6; j++)
		{
			HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
			HAL_Delay(300);
		}
		strcpy(response, "");
		sprintf(reco, "RECONECTING...(%d)\n", i+1);
		UART_SendString(reco);
		UART_SendString(cmd);
		HAL_Delay(4500);
		UART_ReceiveString(response, sizeof(response),15000);
		UART_ReceiveString(response, sizeof(response),15000);
		if (strstr(response, "OK") != NULL)
			goto scs;
		}

		UART_SendString("CONNECTION FAILED, PLEASE PRESS THE RST BUTTON TO TRY AGAIN...!");
		return *result;
	}
	return *result;
}
char esp8266_changesever(char* SSID, char* PASSWORD)
{
	char response[100];
	char result[50];


	char cmd[100];
	sprintf(cmd,"AT+CWSAP=\"%s\",\"%s\",5,3\r\n", SSID, PASSWORD);
	UART_SendString(cmd);
	UART_ReceiveString(response, sizeof(response),100);

	if (strstr(response, "OK") != NULL) {
		strcpy(result, "OK");
	}
	else
	{
		strcpy(result, "ERROR");
		return *result;
	}
	return *result;
}
