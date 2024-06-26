#include "uart.h"


#define UART_BAUDRATE 115200
void uart1_tx_init(void);
void uart1_write(int ch);
static void uart_set_baundrate(USART_TypeDef *UARTx, uint32_t PeriphClk, uint32_t Baundrate);
static uint16_t compute_uart_div(uint32_t PeriphClk, uint32_t Baundrate);
int __io_putchar(int ch)
{
	uart1_write(ch);
	return ch;
}


void uart1_tx_rx_init(void)
{
	/******************Config uart gpio pin**************
	*Enable clock access to gpioa
	*Set PA9 mode to AF mode
	*Set PA9 AF type to UART_TX (AF07)*/

	RCC->AHB1ENR |= GPIOAEN;

	GPIOA ->MODER &=~ (1U<<18);
	GPIOA ->MODER |= (1U<<19);
	//MODER9->10
	GPIOA ->AFR[1] |= (1U<<4);
	GPIOA ->AFR[1] |= (1U<<5);
	GPIOA ->AFR[1] |= (1U<<6);
	GPIOA ->AFR[1] &=~ (1U<<7);
	//AF7



	//Set PA10 AF type to UART_RX
	GPIOA ->MODER &=~ (1U<<20);
	GPIOA ->MODER |= (1U<<21);
	//MODER10->10
	GPIOA ->AFR[1] |= (1U<<8);
	GPIOA ->AFR[1] |= (1U<<9);
	GPIOA ->AFR[1] |= (1U<<10);
	GPIOA ->AFR[1] &=~ (1U<<11);
	//AF7

	RCC->APB2ENR |= UART1EN; //enable uart1
	uart_set_baundrate(USART1, APB2_CLK, UART_BAUDRATE); //config baudrate
	USART1->CR1 = (CR1_TE|CR1_RE); //config transfer/reveive direction

	USART1->CR1 |= CR1_UE;//Enable USART


}

void uart1_rx_interrupt_init(void)
{
	/******************Config uart gpio pin**************
	*Enable clock access to gpioa
	*Set PA9 mode to AF mod
	*Set PA9 AF type to UART_TX (AF07)*/

	RCC->AHB1ENR |= GPIOAEN;

	//MODER9->10
	GPIOA ->AFR[1] |= (1U<<4);
	GPIOA ->AFR[1] |= (1U<<5);
	GPIOA ->AFR[1] |= (1U<<6);
	GPIOA ->AFR[1] &=~ (1U<<7);
	//AF7



	//Set PA10 AF type to UART_RX
	GPIOA ->MODER &=~ (1U<<20);
	GPIOA ->MODER |= (1U<<21);
	//MODER10->10
	GPIOA ->AFR[1] |= (1U<<8);
	GPIOA ->AFR[1] |= (1U<<9);
	GPIOA ->AFR[1] |= (1U<<10);
	GPIOA ->AFR[1] &=~ (1U<<11);
	//AF7

	RCC->APB2ENR |= UART1EN; //enable uart1
	uart_set_baundrate(USART1, APB2_CLK, UART_BAUDRATE); //config baudrate
	USART1->CR1 = (CR1_TE|CR1_RE); //config transfer/reveive direction
	//Enable RXBE Interrupt
	USART1->CR1 |= CR1_RXNEIE;
	//Enable UART2 interrput in NVIC
	NVIC_EnableIRQ(USART1_IRQn);

	USART1->CR1 |= CR1_UE;//Enable USART
	NVIC_SetPriority(USART1_IRQn, 0);


}
char uart1_read(void)
{
	//Make sure the receive data is not empty
	while (!(USART1->SR & SR_RNXE));
	return (USART1->DR);
}

void uart1_write(int ch)
{
	while (!(USART1->SR & SR_TXE)); //STATUS REG
	USART1 -> DR = (ch & 0xFF);  //DR: Data Register, write to transmit data reg

}
static void uart_set_baundrate(USART_TypeDef *UARTx, uint32_t PeriphClk, uint32_t Baudrate)
{
	UARTx->BRR = compute_uart_div(PeriphClk, Baudrate);
}
static uint16_t compute_uart_div(uint32_t PeriphClk, uint32_t Baudrate)
{
	return ((PeriphClk +(Baudrate/2U))/Baudrate);
}
