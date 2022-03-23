/*
 * SPI.c
 *
 * Created: 3/8/2022 10:16:01 PM
 *  Author: Lankash
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO.h"
#include "my_macros.h"
#include "SPI.h"

//.............................................................

void SPI_master_init (void)
{
	/*
	  Set the SPI pins configuration.
	*/
	DIO_set_pin_dir('B', 4, 1);    //Set SS pin as O/P
	DIO_set_pin_dir('B', 5, 1);    //Set MOSI pin as O/P
	DIO_set_pin_dir('B', 6, 0);    //Set MISO pin as I/P
	DIO_set_pin_dir('B', 7, 1);    //Set SCK pin as O/P
	
	/*
	  Enable Master mode.
	*/
	SET_BIT(SPCR, MSTR);    //Set MSTR bit to 1 in SPCR Reg.
	
	/*
	  Set the clock of the SPI
	*/
	#if defined prescaler_2
	SET_BIT(SPSR, SPI2X);    //Enable double speed of SPI
	SET_BIT(SPCR, SPR1);     //Set the SPR1 bit to 1
	SET_BIT(SPCR, SPR0);     //Set the SPR1 bit to 1
	
	#elif defined prescaler_4
	CLR_BIT(SPSR, SPI2X);    //Disable double speed of SPI
	CLR_BIT(SPCR, SPR1);     //Clear the SPR1 bit to 0
	CLR_BIT(SPCR, SPR0);     //Clear the SPR1 bit to 0
	
	#elif defined prescaler_8
	SET_BIT(SPSR, SPI2X);    //Enable double speed of SPI
	CLR_BIT(SPCR, SPR1);     //Clear the SPR1 bit to 1
	SET_BIT(SPCR, SPR0);     //Set the SPR1 bit to 1
	
	#elif defined prescaler_16
	CLR_BIT(SPSR, SPI2X);    //Disable double speed of SPI
	CLR_BIT(SPCR, SPR1);     //Clear the SPR1 bit to 0
	SET_BIT(SPCR, SPR0);     //Set the SPR1 bit to 1
	
	#elif defined prescaler_32
	SET_BIT(SPSR, SPI2X);    //Enable double speed of SPI
	SET_BIT(SPCR, SPR1);     //Set the SPR1 bit to 1
	CLR_BIT(SPCR, SPR0);     //Clear the SPR1 bit to 0

    #elif defined prescaler_64
    CLR_BIT(SPSR, SPI2X);    //Disable double speed of SPI
    SET_BIT(SPCR, SPR1);     //Set the SPR1 bit to 1
    CLR_BIT(SPCR, SPR0);     //Clear the SPR1 bit to 0

    #elif defined prescaler_128
    CLR_BIT(SPSR, SPI2X);    //Disable double speed of SPI
    SET_BIT(SPCR, SPR1);     //Set the SPR1 bit to 1
    SET_BIT(SPCR, SPR0);     //Set the SPR1 bit to 1
	#endif
	
	/*
	  Set SS pin to high
	*/
	DIO_write_pin('B', 4, 1);
	
	/*
	  Enable SPI
	*/
	SET_BIT(SPCR, SPE);
}

//..............................................................

void SPI_slave_init(void)
{
	SET_BIT (SPCR, SPE);    //Enable SPI.
	
	/*
	  Configure the pins of SPI
	*/
	DIO_set_pin_dir('B', 6, 1);  //Set MISO pin as O/P
	DIO_set_pin_dir('B', 5, 0);  //Set MOSI pin as I/P
}

//..............................................................

unsigned char SPI_master_send_char(unsigned char data)
{
	DIO_write_pin('B', 4, 0);             //Clear SS pin to send data to the Slave.
	
	SPDR = data;                          //Put 'data' to the [SPDR] register.
	
	while (0 == READ_BIT(SPSR, SPIF));    //Hold till Transmission is finished.
	
	return SPDR;                          //Read the value in SPDR after transmission.
}

//..............................................................

unsigned char SPI_slave_receive_char (unsigned char data)
{
	SPDR = data;
	
	while (0 == READ_BIT(SPSR, SPIF));    //Hold till Data is received in SPI.

    return SPDR;                          //Read relieved data             
}

//..............................................................

void SPI_master_send_string (unsigned char *string)
{
	while ((*string) != 0)
	{
		SPI_master_send_char(*string);
		_delay_ms(300);
		string++;
	}
}

//..............................................................