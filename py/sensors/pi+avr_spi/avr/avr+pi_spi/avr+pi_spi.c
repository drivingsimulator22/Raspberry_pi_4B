/*
 * avr_pi_spi.c
 *
 * Created: 3/15/2022 12:43:11 AM
 *  Author: "Lankash"
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "SPI.h"
#include "ADC.h"
#include "UART.h"

#define sensor_1 0     // ADC pin of Sensor_1 
#define sensor_2 1     // ADC pin of Sensor_2
#define sensor_3 2     // ADC pin of Sensor_3
#define sensor_4 3     // ADC pin of Sensor_4
#define sensor_5 4     // ADC pin of Sensor_5
#define sensor_6 5     // ADC pin of Sensor_6

unsigned int dist = 0;
unsigned char pi = 0;
unsigned char serial = 0;

int main(void)
{
	SPI_slave_init();
	ADC_init();
	//UART_init(9600);
	
	//UART_send_string("Car X Simulator");
	//UART_send_char(0x0D);   //Print New Line on Serial Monitor
	
	
    while(1)
    {
		pi = SPI_slave_receive_char(pi);
		
		switch (pi)
		{
			case 1 :
			ADC_pin(sensor_1);
			dist = (0.45 * ADC_read());
			SPI_slave_send_char(dist);
			/*UART_send_string("Sensor 1 = ");
			serial = (((dist/100)%10) + 48);
			UART_send_char (serial);
			serial = (((dist/10)%10) + 48);
			UART_send_char (serial);
			serial = ((dist%10) + 48);
			UART_send_char (serial);
			UART_send_string(" mm");
			UART_send_char(0x0D);*/           //Send new line to the terminal.
			break;
			
			//_delay_ms(1000);
			
		    case 2 :
			ADC_pin(sensor_2);
			dist = (0.45 * ADC_read());
			SPI_slave_send_char(dist);
			/*UART_send_string("Sensor 2 = ");
			serial = (((dist/100)%10) + 48);
			UART_send_char (serial);
			serial = (((dist/10)%10) + 48);
			UART_send_char (serial);
			serial = ((dist%10) + 48);
			UART_send_char (serial);
			UART_send_string(" mm");
			UART_send_char(0x0D);*/           //Send new line to the terminal.
		    break;
			
			//_delay_ms(1000);
			
		    case 3 :
			ADC_pin(sensor_3);
			dist = (0.45 * ADC_read());
			SPI_slave_send_char(dist);
			/*UART_send_string("Sensor 3 = ");
			serial = (((dist/100)%10) + 48);
			UART_send_char (serial);
			serial = (((dist/10)%10) + 48);
			UART_send_char (serial);
			serial = ((dist%10) + 48);
			UART_send_char (serial);
			UART_send_string(" mm");
			UART_send_char(0x0D);*/           //Send new line to the terminal.
			break;
			
		    //_delay_ms(1000);
			
		    case 4 :
			ADC_pin(sensor_4);
			dist = (0.45 * ADC_read());
			SPI_slave_send_char(dist);
			/*UART_send_string("Sensor 4 = ");
			serial = (((dist/100)%10) + 48);
			UART_send_char (serial);
			serial = (((dist/10)%10) + 48);
			UART_send_char (serial);
			serial = ((dist%10) + 48);
			UART_send_char (serial);
			UART_send_string(" mm");
			UART_send_char(0x0D);*/           //Send new line to the terminal.
			break;
			
		    //_delay_ms(1000);
			
		    case 5 :
			ADC_pin(sensor_5);
			dist = (0.45 * ADC_read());
			SPI_slave_send_char(dist);
			/*UART_send_string("Sensor 5 = ");
			serial = (((dist/100)%10) + 48);
			UART_send_char (serial);
			serial = (((dist/10)%10) + 48);
			UART_send_char (serial);
			serial = ((dist%10) + 48);
			UART_send_char (serial);
			UART_send_string(" mm");
			UART_send_char(0x0D);*/           //Send new line to the terminal.
			break;
			
		    //_delay_ms(1000);
			
		    case 6 :
			ADC_pin(sensor_6);
			dist = (0.45 * ADC_read());
			SPI_slave_send_char(dist);
			/*UART_send_string("Sensor 6 = ");
			serial = (((dist/100)%10) + 48);
			UART_send_char (serial);
			serial = (((dist/10)%10) + 48);
			UART_send_char (serial);
			serial = ((dist%10) + 48);
			UART_send_char (serial);
			UART_send_string(" mm");
			UART_send_char(0x0D);*/           //Send new line to the terminal.
			break;
	     	//_delay_ms(1000);
			 
           default :
		    break;
		}
    }
}