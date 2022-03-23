/*

Code Created by "LANKASH" 
  @10/9/2021

File Contents : 10 'DIO' Function Prototypes. 

*/

#ifndef DIO_H_
#define DIO_H_


/*
    Function name         :  DIO_set_pin_dir
    Function Returns      :  void
    Function Arguments    :  unsigned char port, unsigned char pin, unsigned char direction.
    Function Description  :  Set the Pin direction 'I/P'(@direction=0) or 'O/P'(@direction=1).
*/
void DIO_set_pin_dir (unsigned char port, unsigned char pin, unsigned char direction);


/*
    Function name         :  DIO_set_port_dir
    Function Returns      :  void
    Function Arguments    :  unsigned char port, unsigned char direction
    Function Description  :  Set the port direction 'I/P' or 'O/P'.
*/
void DIO_set_port_dir (unsigned char port, unsigned char direction);


/*
    Function name         :  DIO_write_pin
    Function Returns      :  void
    Function Arguments    :  unsigned char port, unsigned char pin, unsigned char value
    Function Description  :  Set the 'O/P' pin as 'HIGH'(@value=1) or 'LOW'(@value=0)
*/
void DIO_write_pin (unsigned char port, unsigned char pin, unsigned char value);


/*
    Function name         :  DIO_write_port
    Function Returns      :  void
    Function Arguments    :  unsigned char port, unsigned char value
    Function Description  :  Set the 'O/P' Port as 'HIGH' or 'LOW'
*/
void DIO_write_port (unsigned char port, unsigned char value);


/*
    Function name         :  DIO_read_pin
    Function Returns      :  unsigned char
    Function Arguments    :  unsigned char port, unsigned char pin
    Function Description  :  Read the value from 'I/P' pin
*/
unsigned char DIO_read_pin (unsigned char port, unsigned char pin);


/*
    Function name         :  DIO_reaad_port
    Function Returns      :  unsigned char
    Function Arguments    :  unsigned char port
    Function Description  :  Read the value from 'I/P' port
*/
unsigned char DIO_read_port (unsigned char port);


/*
    Function name         :  DIO_toogle_pin_oput
    Function Returns      :  void
    Function Arguments    :  unsigned char port, unsigned char pin
    Function Description  :  Toogle the 'O/P' pin value 'HIGH' or 'LOW'
*/
void DIO_toogle(unsigned char port, unsigned char pin);


/*
    Function name         :  DIO_connect_pullup
    Function Returns      :  void
    Function Arguments    :  unsigned char port, unsigned char pin, unsigned char pullup
    Function Description  :  Set the pin Microcontroller's internal 'PULL-UP' connection 'ON'(@pullup=1) or 'OFF'(@pullup=0)
*/
void DIO_connect_pullup (unsigned char port, unsigned char pin, unsigned char pullup);


/*
    Function name         :  DIO_write_low_nibble
    Function Returns      :  void
    Function Arguments    :  unsigned char port, unsigned car value
    Function Description  :  Write a value (4-bits) on 'LOW'(@nibble=0) of 'port'
*/
void DIO_write_low_nibble (unsigned char port, unsigned char value);


/*
    Function name         :  IO_write_high_nibble
    Function Returns      :  void
    Function Arguments    :  unsigned char port, unsigned char value
    Function Description  :  Write a value (4-bits) on 'HIGH'(@nibble=1) of 'port'
*/
void DIO_write_high_nibble (unsigned char port, unsigned char value);


/*
    Function name         :  DIO_write_nibble
    Function Returns      :  void 
    Function Arguments    :  unsigned char port, unsigned char value, unsigned char nibble
    Function Description  :  Write a value (4-bits) on 'HIGH'(@nibble=1) or 'LOW'(@nibble=0) of 'port'
*/
void DIO_write_nibble (unsigned char port, unsigned char value, unsigned char nibble);


#endif


  