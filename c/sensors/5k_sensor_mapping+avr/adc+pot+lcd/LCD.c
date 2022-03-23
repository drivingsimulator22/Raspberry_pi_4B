/*

Code created by "LANKASH"
  @2/10/2021

File Contents : 'LCD' implementation Functions

*/

#include "LCD.h"
#include "LCD_config.h"
#define F_CPU 8000000UL
#include <util/delay.h>


static void LCD_send_falling_edge ()
{
	DIO_write_pin(ctrl_port, EN, 1);
	_delay_ms(2);
	
	DIO_write_pin(ctrl_port, EN, 0);
	_delay_ms(2);
} 

//.......................................................................

void LCD_send_cmd (unsigned char cmd)  
{
  #if defined eight_bit_mode                     //@ 8-Bit mode
	DIO_write_port(data_port, cmd);
	DIO_write_pin(ctrl_port, RS, 0);
	LCD_send_falling_edge();
	_delay_ms(1);

  #elif defined four_bit_mode                    //@ 4-Bit mode
	DIO_write_nibble(data_port, cmd>>4, nibble);
	DIO_write_pin(ctrl_port, RS, 0);
	LCD_send_falling_edge();
	
	DIO_write_nibble(data_port, cmd, nibble);
	DIO_write_pin(ctrl_port, RS, 0);
	LCD_send_falling_edge();
	_delay_ms(1);

  #endif
}

//.......................................................................

void LCD_init()     
{

#if defined eight_bit_mode           //@ 8-Bit mode
    _delay_ms(50);
    DIO_set_port_dir(data_port, 1);
    DIO_set_pin_dir(ctrl_port, EN, 1);    //Set the 'ENABLE' Pin as 'O/P'
    DIO_set_pin_dir(ctrl_port, RS, 1);    //Set the 'RESET' Pin as 'O/P'
    DIO_set_pin_dir(ctrl_port, RW, 1);    //Set the 'READ/WRITE' Pin as 'O/P'
  
    DIO_write_pin(ctrl_port, RW, 0);
	
	LCD_send_cmd(rtn_home);
	_delay_ms(10);
  
    LCD_send_cmd(eight_bit_2_line_5x7);
    _delay_ms(1);
  
    LCD_send_cmd(disp_on_curs_on_blink);
    _delay_ms(1);

    LCD_send_cmd(clr_disp);
    _delay_ms(10);  

    LCD_send_cmd(entry_DDRAM_inc_dis_right);
    _delay_ms(1);
	
#elif defined four_bit_mode     //@ 4-Bit mode
    _delay_ms(50);
    DIO_set_pin_dir(data_port, D4, 1);
    DIO_set_pin_dir(data_port, D5, 1);
    DIO_set_pin_dir(data_port, D6, 1);
    DIO_set_pin_dir(data_port, D7, 1);
    DIO_set_pin_dir(ctrl_port, EN, 1);    //Set the 'ENABLE' Pin as 'O/P'
    DIO_set_pin_dir(ctrl_port, RS, 1);    //Set the 'RESET' Pin as 'O/P'
    DIO_set_pin_dir(ctrl_port, RW, 1);    //Set the 'READ/WRITE' Pin as 'O/P'
  
    DIO_write_pin(ctrl_port, RW, 0);
	
	LCD_send_cmd(rtn_home);
	_delay_ms(10);
  
    LCD_send_cmd(four_bit_2_line_5x7);
    _delay_ms(1);
  
    LCD_send_cmd(disp_on_curs_off_solid);
    _delay_ms(1);
  
    LCD_send_cmd(clr_disp);
    _delay_ms(10);
  
    LCD_send_cmd(entry_DDRAM_inc_dis_right);
    _delay_ms(1);
	

#endif
}

//.......................................................................

void LCD_send_char (unsigned char data)  
{
	
#if defined eight_bit_mode           //@ 8-Bit mode
    DIO_write_port(data_port, data);
    DIO_write_pin(ctrl_port, RS, 1);
    LCD_send_falling_edge();
	_delay_ms(1);
	
#elif defined four_bit_mode          //@ 4-Bit mode
    DIO_write_nibble(data_port, data>>4, nibble);   //Low Nibble
    DIO_write_pin(ctrl_port, RS, 1);
    LCD_send_falling_edge();
  
    DIO_write_nibble(data_port, data, nibble);     //Low Nibble
    DIO_write_pin(ctrl_port, RS, 1);
    LCD_send_falling_edge();
    _delay_ms(1);

#endif
}

//.......................................................................

void LCD_send_string (unsigned char *data)
{
  while((*data) != '\0')
  {
	  LCD_send_char(*data);
	  data++;
  }
}

//.......................................................................

void LCD_clear_screen ()
{
  LCD_send_cmd(clr_disp);
  _delay_ms(10);
}

//.......................................................................

void LCD_move_cursor (unsigned char row, unsigned char coloumn)
{
  unsigned char data;
  
  if((row>2) || (row<1) || (coloumn>16) || (coloumn<1))
  {
	  data = 0x80;
  }
  
  else if(1==row)
  {
	  data = 0x80 + (coloumn-1);
  }
  
  else if(2==row)
  {
	  data = 0xc0 + (coloumn-1);
  }
  
  LCD_send_cmd(data);
  _delay_ms(1);
}

//.......................................................................

void LCD_char_ar (unsigned char alpha)
{
	switch (alpha)
	{
		case 1 :  //ALF
		LCD_send_char(0x06);
		LCD_send_char(0x0E);
		LCD_send_char(0x00);
		LCD_send_char(0x04);
		LCD_send_char(0x04);
		LCD_send_char(0x04);
		LCD_send_char(0x04);
		LCD_send_char(0x00);
		
		case 2 :  //Ba2
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		LCD_send_char(0x01);
		LCD_send_char(0x01);
		LCD_send_char(0x1F);
		LCD_send_char(0x00);
		LCD_send_char(0x04);
		
		case 3 :  //Ta2
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		LCD_send_char(0x0C);
		LCD_send_char(0x01);
		LCD_send_char(0x01);
		LCD_send_char(0x1F);
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		
		case 4 :  //Tha2
		LCD_send_char(0x00);
		LCD_send_char(0x08);
		LCD_send_char(0x0C);
		LCD_send_char(0x01);
		LCD_send_char(0x01);
		LCD_send_char(0x1F);
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		
		case 5 :  //Gem
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		LCD_send_char(0x18);
		LCD_send_char(0x04);
		LCD_send_char(0x02);
		LCD_send_char(0x1F);
		LCD_send_char(0x00);
		LCD_send_char(0x04);
		
		case 6 :  //ha2
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		LCD_send_char(0x18);
		LCD_send_char(0x04);
		LCD_send_char(0x02);
		LCD_send_char(0x1F);
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		
		case 7 :  //kha2
		LCD_send_char(0x00);
		LCD_send_char(0x02);
		LCD_send_char(0x18);
		LCD_send_char(0x04);
		LCD_send_char(0x02);
		LCD_send_char(0x1F);
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		
		case 8 :  //dal
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		LCD_send_char(0x0E);
		LCD_send_char(0x01);
		LCD_send_char(0x01);
		LCD_send_char(0x1F);
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		
		case 9 :  //zal
		LCD_send_char(0x04);
		LCD_send_char(0x00);
		LCD_send_char(0x0E);
		LCD_send_char(0x01);
		LCD_send_char(0x01);
		LCD_send_char(0x1F);
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		
		case 10 :  //raeh
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		LCD_send_char(0x02);
		LCD_send_char(0x03);
		LCD_send_char(0x04);
		LCD_send_char(0x08);
		LCD_send_char(0x10);
		
		case 11 : //zein
		LCD_send_char(0x00);
		LCD_send_char(0x02);
		LCD_send_char(0x00);
		LCD_send_char(0x02);
		LCD_send_char(0x03);
		LCD_send_char(0x04);
		LCD_send_char(0x08);
		LCD_send_char(0x10);
		
		case 12 :  //sen
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		LCD_send_char(0x15);
		LCD_send_char(0x15);
		LCD_send_char(0x1F);
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		
		case 13 : //shen
		LCD_send_char(0x04);
		LCD_send_char(0x0A);
		LCD_send_char(0x00);
		LCD_send_char(0x15);
		LCD_send_char(0x15);
		LCD_send_char(0x1F);
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		
		case 14 :  //sad
		LCD_send_char(0x00);
		LCD_send_char(0x01);
		LCD_send_char(0x03);
		LCD_send_char(0x15);
		LCD_send_char(0x19);
		LCD_send_char(0x1F);
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		
		case 15 :  //dad
		LCD_send_char(0x04);
		LCD_send_char(0x01);
		LCD_send_char(0x03);
		LCD_send_char(0x15);
		LCD_send_char(0x19);
		LCD_send_char(0x1F);
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		
		case 16  :  //tah
		LCD_send_char(0x08);
		LCD_send_char(0x09);
		LCD_send_char(0x0B);
		LCD_send_char(0x0D);
		LCD_send_char(0x09);
		LCD_send_char(0x1F);
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		
		case 17  :  //zah
		LCD_send_char(0x0A);
		LCD_send_char(0x09);
		LCD_send_char(0x0B);
		LCD_send_char(0x0D);
		LCD_send_char(0x09);
		LCD_send_char(0x1F);
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		
		case 18  :  //aen
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		LCD_send_char(0x0E);
		LCD_send_char(0x08);
		LCD_send_char(0x1F);
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		
		case 19  :  //ghen
		LCD_send_char(0x00);
		LCD_send_char(0x04);
		LCD_send_char(0x00);
		LCD_send_char(0x0E);
		LCD_send_char(0x08);
		LCD_send_char(0x1F);
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		
		case 20  :  //feh
		LCD_send_char(0x00);
		LCD_send_char(0x04);
		LCD_send_char(0x00);
		LCD_send_char(0x0E);
		LCD_send_char(0x0A);
		LCD_send_char(0x1F);
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		
		case 21 :  //qaf
		LCD_send_char(0x00);
		LCD_send_char(0x0A);
		LCD_send_char(0x00);
		LCD_send_char(0x0E);
		LCD_send_char(0x0A);
		LCD_send_char(0x1F);
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		
		case 22 :  //kaf
		LCD_send_char(0x02);
		LCD_send_char(0x04);
		LCD_send_char(0x08);
		LCD_send_char(0x04);
		LCD_send_char(0x02);
		LCD_send_char(0x1F);
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		
		case 23 : //lam
		LCD_send_char(0x00);
		LCD_send_char(0x04);
		LCD_send_char(0x04);
		LCD_send_char(0x04);
		LCD_send_char(0x04);
		LCD_send_char(0x1F);
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		
		case 24 :  //mem
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		LCD_send_char(0x04);
		LCD_send_char(0x0A);
		LCD_send_char(0x11);
		LCD_send_char(0x09);
		LCD_send_char(0x06);
		LCD_send_char(0x00);
		
		case  25 : //non
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		LCD_send_char(0x04);
		LCD_send_char(0x01);
		LCD_send_char(0x1F);
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		
		case  26 : //heh
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		LCD_send_char(0x06);
		LCD_send_char(0x09);
		LCD_send_char(0x15);
		LCD_send_char(0x1F);
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		
		case 27 : //waw
		LCD_send_char(0x00);
		LCD_send_char(0x04);
		LCD_send_char(0x00);
		LCD_send_char(0x0E);
		LCD_send_char(0x0A);
		LCD_send_char(0x1F);
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		
		case 28 : //yeh
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		LCD_send_char(0x00);
		LCD_send_char(0x03);
		LCD_send_char(0x12);
		LCD_send_char(0x11);
		LCD_send_char(0x1F);
	}
}

//.......................................................................

