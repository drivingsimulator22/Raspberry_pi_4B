/*

Code created by "LANKASH"
  @10/9/2021

File Contents : 10 'DIO' impelimentation Functions

*/
 
#include <avr/io.h> 
#include "my_macros.h"      //My standard  bit macros impelimentation.

void DIO_set_pin_dir(unsigned char port, unsigned char pin, unsigned char direction)    //Function to set a specific pin direction 'I/P'(@direction=0) or 'O/P'(@direction=1).
{
  switch (port)
  {
    case 'A':                     // @Port 'A'.
    case 'a':                     // @Port 'a'.
    if (1== direction)            // '1' is for 'I/P'.
    {
      SET_BIT(DDRA, pin);         // Set the pin 'PIN' in port 'A' as 'O/P'.
    }
    else
    {
      CLR_BIT(DDRA, pin);        // Set the pin 'PIN' in port 'A' as 'I/P'.
    } 
    break;

    case 'B':                    // @Port 'B'.
    case 'b':                    // @Port 'b'.
    if (1==direction)            // '1' is for 'I/P'.
    {
      SET_BIT(DDRB, pin);        // Set the pin 'PIN' in port 'B' as 'I/P'.
    }
    else
    {
      CLR_BIT(DDRB, pin);        // Set the pin 'PIN' in port 'B' as 'O/P'.
    }
    break;

    case 'C':                    // @Port 'C'.
    case 'c':                    // @Port 'c'. 
    if (1==direction)            // '1' is for 'I/P'.
    {
      SET_BIT(DDRC, pin);        // Set the pin 'PIN' in port 'C' as 'I/P'. 
    }
    else
    {
      CLR_BIT(DDRC, pin);        // Set the pin 'PIN' in port 'C' as 'O/P'. 
    }
    break;

    case 'D':                    // @Port 'D'.
    case 'd':                    // @Port 'd'. 
    if (1==direction)            // '1' is for 'I/P'.
    {
      SET_BIT(DDRD, pin);        // Set the pin 'PIN' in port 'D' as 'I/P'. 
    }
    else
    {
      CLR_BIT(DDRD, pin);        // Set the pin 'PIN' in port 'D' as 'O/P'.
    }
    break;
  
    default:                     // If nothing from the above, Break.
    break;
  }
}

//..................................................................................

void DIO_set_port_dir(unsigned char port, unsigned char direction)    //Function to set a specific pin direction 'I/P' or 'O/P'.
{
  switch (port)
  {
    case 'A':                    // @Port 'A'.
    case 'a':                    // @Port 'a'.
    DDRA = direction;            // Set the whole port as 'direction', (1>>'I/P') or (0>>'O/P').
    break;

    case 'B':                    // @Port 'B'.
    case 'b':                    // @Port 'b'.
    DDRB = direction;            // Set the whole port as 'direction', (1>>'I/P') or (0>>'O/P').
    break;

    case 'C':                    // @Port 'C'.
    case 'c':                    // @Port 'c'. 
    DDRC = direction;             // Set the whole port as 'direction', (1>>'I/P') or (0>>'O/P').
    break;

    case 'D':                    // @Port 'D'.
    case 'd':                    // @Port 'd'. 
    DDRD = direction;            // Set the whole port as 'direction', (1>>'I/P') or (0>>'O/P').
    break;
  
    default:                     // If nothing from the above, Break.
    break;
  }
}

//..................................................................................


void DIO_write_pin(unsigned char port, unsigned char pin, unsigned char value)  //Set the 'O/P' pin as 'HIGH' or 'LOW'
{
  switch (port)
  {
    case 'A':                  // @Port 'A'.
    case 'a':                  // @Port 'a'.
    if (1==value)             
    {
      SET_BIT(PORTA, pin);     // Set pin 'PIN' in port 'A' as 'HIGH'.
    }
    else
    {
      CLR_BIT(PORTA, pin);     // Set pin 'PIN' in port 'A' as 'LOW'.
    }
    break;
  
    case 'B':                  // @Port 'B'.
    case 'b':                  // @Port 'b'.
    if (1==value)             
    {
      SET_BIT(PORTB, pin);    // Set pin 'PIN' in port 'B' as 'HIGH'.
    }
    else
    {
      CLR_BIT(PORTB, pin);    // Set pin 'PIN' in port 'B' as 'LOW'.
    }
    break;

    case 'C':                  // @Port 'C'.
    case 'c':                  // @Port 'c'.
    if (1==value)             
    {
      SET_BIT(PORTC, pin);    // Set pin 'PIN' in port 'C' as 'HIGH'.
    }
    else
    {
      CLR_BIT(PORTC, pin);    // Set pin 'PIN' in port 'C' as 'LOW'.
    }
    break;
  
    case 'D':                // @Port 'D'.
    case 'd':                // @Port 'd'.
    if (1==value)             
    {
      SET_BIT(PORTD, pin);   // Set pin 'PIN' in port 'D' as 'HIGH'.
    }
    else
    {
      CLR_BIT(PORTD, pin);   // Set pin 'PIN' in port 'D' as 'LOW'.
    }
    break;

    default:                   // If nothing from the above, Break.
      break;
  }
}

//..................................................................................

void DIO_write_port(unsigned char port, unsigned char value)  //Set the 'O/P' Port as 'HIGH' or 'LOW'
{
  switch (port)
  {
    case 'A':                  // @Port 'A'.
    case 'a':                  // @Port 'a'.
    PORTA = value;             // Set the whole port value as 'value'.
    break;
  
    case 'B':                  // @Port 'B'.
    case 'b':                  // @Port 'b'.
    PORTB = value;             // Set the whole port value as 'value'.
    break;

    case 'C':                  // @Port 'C'.
    case 'c':                  // @Port 'c'.
    PORTC = value;             // Set the whole port value as 'value'.
    break;
  
    case 'D':                  // @Port 'D'.
    case 'd':                  // @Port 'd'.
    PORTD = value;             // Set the whole port value as 'value'.
    break;

    default:                   // If nothing from the above, Break.
      break;
  }
}

//..................................................................................

unsigned char DIO_read_pin(unsigned char port, unsigned char pin)  //Read the value from 'I/P' pin
{
  unsigned char value;
  
  switch (port)
  {
    case 'A':                      // @Port 'A'.
    case 'a':                      // @Port 'a'.
    value = READ_BIT(PINA, pin);   // Read the value of pin 'pin', assigned to 'value'.
    break;

    case 'B':                      // @Port 'B'.
    case 'b':                      // @Port 'b'.
    value = READ_BIT(PINB, pin);   // Read the value of pin 'pin', assigned to 'value'.
    break;

    case 'C':                      // @Port 'C'.
    case 'c':                      // @Port 'c'.
    value = READ_BIT(PINC, pin);   // Read the value of pin 'pin', assigned to 'value'.
    break;

    case 'D':                      // @Port 'D'.
    case 'd':                      // @Port 'd'.
    value = READ_BIT(PIND, pin);   // Read the value of pin 'pin', assigned to 'value'.
    break;

    default:                       // If nothing from the above, Break.
      break;
  }
  return value;
}

//..................................................................................

unsigned char DIO_read_port(unsigned char port)  //Read the value from 'I/P' port
{
  unsigned char value=0;

  switch (port)
  {
    case 'A':            // @Port 'A'.
    case 'a':            // @Port 'a'.
    value = PINA;        // Assign the value of I/P 'PINA' register to 'value'. 
    break;

    case 'B':            // @Port 'B'.
    case 'b':            // @Port 'b'.
    value = PINB;        // Assign the value of I/P 'PINB' register to 'value'. 
    break;

    case 'C':            // @Port 'C'.
    case 'c':            // @Port 'c'.
    value = PINC;        // Assign the value of I/P 'PINC' register to 'value'. 
    break;

    case 'D':            // @Port 'D'.
    case 'd':            // @Port 'd'.
    value = PIND;        // Assign the value of I/P 'PIND' register to 'value'. 
    break;

    default:             // If nothing from the above, Break.
      break;
  }
  return value;
}

//..................................................................................

void DIO_toogle(unsigned char port, unsigned char pin)  //Toogle the 'O/P' pin value 'HIGH' or 'LOW'
{
  switch (port)
  {
    case 'A':
    case 'a':
    TOG_BIT(PORTA, pin);    //Toggle the value of the given pin in port 'A'.
    break;

    case 'B':
    case 'b':
    TOG_BIT(PORTB, pin);    //Toggle the value of the given pin in port 'B'.
    break;

    case 'C':
    case 'c':
    TOG_BIT(PORTC, pin);    //Toggle the value of the given pin in port 'C'.
    break;

    case 'D':
    case 'd':
    TOG_BIT(PORTD, pin);    //Toggle the value of the given pin in port 'D'.
    break;

    default:
    break;
  }
}

//..................................................................................

void DIO_connect_pullup (unsigned char port, unsigned char pin, unsigned char pullup)  //Set the pin Microcontroller's internal 'PULL-UP' connection 'ON'(@pullup=1) or 'OFF'(@pullup=0)
{
  switch(port)
  {
    case 'A':
    case 'a':
    if (1 == pullup)
    {
      SET_BIT(PORTA, pin);
    }
    
    case 'B':
    case 'b':
    if (1 == pullup)
    {
      SET_BIT(PORTB, pin);
    }

    case 'C':
    case 'c':
    if (1 == pullup)
    {
      SET_BIT(PORTC, pin);
    }

    case 'D':
    case 'd':
    if (1 == pullup)
    {
      SET_BIT(PORTD, pin);
    }
  }
}

//..................................................................................

void DIO_write_low_nibble (unsigned char port, unsigned char value)  //Write a value (4-bits) on 'LOW'(@nibble=0) of 'port'
{
  value &= 0x0f;

  switch (port)
  {
    case 'A':
    case 'a':
    PORTA &= 0xf0;
    PORTA |= value;
    break;

    case 'B':
    case 'b':
    PORTB &= 0xf0;
    PORTB |= value;
    break;
    
    case 'C':
    case 'c':
    PORTC &= 0xf0;
    PORTC |= value;
    break;
    
    case 'D':
    case 'd':
    PORTD &= 0xf0;
    PORTD |= value;
    break;
    
    default:
    break;
  }
}

//..................................................................................

void DIO_write_high_nibble (unsigned char port, unsigned char value)  //Write a value (4-bits) on 'HIGH'(@nibble=1) of 'port'
{
  value <<= 4;

  switch (port)
  {
    case 'A':
    case 'a':
    PORTA &= 0x0f;
    PORTA |= value;
    break;

    case 'B':
    case 'b':
    PORTB &= 0x0f;
    PORTB |= value;
    break;
    
    case 'C':
    case 'c':
    PORTC &= 0x0f;
    PORTC |= value;
    break;
    
    case 'D':
    case 'd':
    PORTD &= 0x0f;
    PORTD |= value;
    break;
    
    default:
    break;
  }
}

//..................................................................................

void DIO_write_nibble (unsigned char port, unsigned char value, unsigned char nibble)    //Write a value (4-bits) on 'HIGH'(@nibble=1) or 'LOW'(@nibble=0) of 'port' 
{
  if (0 == nibble)          // '0': write on low nibble pins in 'O/P' pins
  {
    value &= 0x0f;

    switch (port)
    {
      case 'A':
      case 'a':
      PORTA &= 0xf0;
      PORTA |= value;
      break;

      case 'B':
      case 'b':
      PORTB &= 0xf0;
      PORTB |= value;
      break;
    
      case 'C':
      case 'c':
      PORTC &= 0xf0;
      PORTC |= value;
      break;
    
      case 'D':
      case 'd':
      PORTD &= 0xf0;
      PORTD |= value;
      break;
    
      default:
      break;
    }
  }

  else if (1 == nibble)    // '1': write on 'HIGH' nibble pins in 'O/P' pins
  {
    value <<= 4;

    switch (port)
    {
      case 'A':
      case 'a':
      PORTA &= 0x0f;
      PORTA |= value;
      break;

      case 'B':
      case 'b':
      PORTB &= 0x0f;
      PORTB |= value;
      break;
     
      case 'C':
      case 'c':
      PORTC &= 0x0f;
      PORTC |= value;
      break;
    
      case 'D':
      case 'd':
      PORTD &= 0x0f;
      PORTD |= value;
      break;
    
      default:
      break;
    }
  }
} 

//..................................................................................



















