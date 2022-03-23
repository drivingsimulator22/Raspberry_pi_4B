/*
*
* Code created by "LANKASH"
*  @10/9/2021
*
* File Contents : 'USART' implementation Functions
*
*/

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO.h"
#include "UART.h"
#include "my_macros.h"

//.......................................................

void UART_init (unsigned long baud)
{
	//Choose the baud rate that will be used by sender and receiver.
	unsigned short UBRR;                 //Initializing UBRR variable.
	UBRR = (F_CPU / (16*baud))-1;        //Calculating the UBRR value.
	UBRRH = (unsigned char)(UBRR>>8);    //Write the higher bits to UBRRH.
	UBRRL = (unsigned char)UBRR;         //Write the lowest bits to UBRRL.
	
	//Enable USART Sender & Receiver.
	SET_BIT (UCSRB, TXEN);               //Enable the Transmitting TX pin.
	SET_BIT (UCSRB, RXEN);               //Enable the Receiving RX pin.
	
	/*Choosing no. of bits in the word of the data frame.
	UMSEL:     @0=Asynchronous | @1=Synchronous.
	UPM(0-1):  @00=Disabled | @10=Even Parity | @11=Odd Parity.
	USBS:      @0=1-bit stop | @1=2-bit stop
	UCSZ(0-2): @000=5-bit word ... @111=9-bit word
	UCPOL:     @0=O/P rising edge | @1= O/P falling edge.
	*/
	UCSRC = (1<<URSEL)|(synchronization<<UMSEL)|(parity_1<<UPM1)|(parity_0<<UPM0)|(stop_bit<<USBS)|(size_0<<UCSZ0)|(size_1<<UCSZ1)|(polarity<<UCPOL);
	UCSRB |=  (size_2<<UCSZ2);
	
	//Choosing double speed mode ON/OFF
	#if defined double_on
	SET_BIT (UCSRA, U2X);
	#elif defined double_off
	CLR_BIT (UCSRA, U2X);
	#endif
	
}

//.......................................................

void UART_send_char (char data)
{
	//Wait for UDR transmit buffer to be empty.
	while (0 == READ_BIT(UCSRA, UDRE));
	
	//Write 'data' to UDR transmit buffer.
	UDR = data;
}

//.......................................................

char UART_receive (void)
{
	//Wait for UDR receive buffer to be filled with data
	while (0 == READ_BIT(UCSRA, RXC));
	
	//Receive data fro UDR receive buffer.
	return UDR;
}

//.......................................................

void UART_send_string (char *str)
{
	while (*str != 0)
	{
		UART_send_char(*str);
		str++;
		//_delay_ms(10);     //Wait till the transmit buffer is finished.
	}
}

//.......................................................