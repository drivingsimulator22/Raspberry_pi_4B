/*

Code created by "LANKASH"
  @2/10/2021

File Contents : 'LCD' Configuration header file

*/


#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

#define clr_disp                         0x001    //Clear LCD Display
#define rtn_home                         0x002    //Return Home in LCD

#define entry_DDRAM_inc_dis_left         0x007    //Entry set point: DDRAM increase, Display shift left
#define entry_DDRAM_inc_dis_right        0x006    //Entry set point: DDRAM increase, Display shift right
#define entry_DDRAM_dec_dis_left         0x005    //Entry set point: DDRAM decrease, Display shift left
#define entry_DDRAM_dec_dis_right        0x004    //Entry set point: DDRAM decrease, Display shift right

#define disp_on_curs_on_blink            0x00F    //Display: ON,  Cursor: ON & Blink
#define disp_on_curs_on_solid            0x00E    //Display: ON,  Cursor: ON & Solid
#define disp_on_curs_off_blink           0x00D    //Display: ON,  Cursor: OFF & Blink
#define disp_on_curs_off_solid           0x00C    //Display: ON,  Cursor: OFF & Solid
#define disp_off_curs_on_blink           0x00B    //Display: OFF, Cursor: ON & Blink
#define disp_off_curs_on_solid           0x00A    //Display: OFF, Cursor: ON & Solid
#define disp_off_curs_off_blink          0x009    //Display: OFF, Cursor: OFF & Blink
#define disp_off_curs_off_solid          0x008    //Display: OFF, Cursor: OFF & Solid

#define shift_curs_left                  0x010    //Shift Cursor right 1 location
#define shift_curs_right                 0x014    //Shift Cursor left 1 location
#define shift_disp_left                  0x018    //Shift Display right 1 location
#define shift_disp_right                 0x01C    //Shift Display left 1 location

#define four_bit_1_line_5x7              0x020    //4-Bit Mode + 1 Line Display + 5*10 dot
#define four_bit_1_line_5x10             0x024    //4-Bit Mode + 1 Line Display + 5*7 dot
#define four_bit_2_line_5x7              0x028    //4-Bit Mode + 2 Line Display + 5*10 dot

#define eight_bit_1_line_5x7             0x030    //8-Bit Mode + 1 Line Display + 5*7 dot
#define eight_bit_1_line_5x10            0x034    //8-Bit Mode + 1 Line Display + 5*10 dot
#define eight_bit_2_line_5x7             0x038    //8-Bit Mode + 2 Line Display + 5*7 dot

//..............................................................................................

#define four_bit_mode
//#define eight_bit_mode

//..............................................................................................

#define data_port 'C'      //The Data/Command port.
#define D4 4             
#define D5 5
#define D6 6
#define D7 7

#define ctrl_port 'D'     //Control Pins port.
#define EN 5              //Enable Pin.
#define RW 6              //Register Selection Pin.
#define RS 7              //Read/Write Pin.

//.............................................................................................

#define nibble 1 // High Nibble @1, Low Nibble @0.

//.............................................................................................

#define alf   1 
#define ba2   2
#define ta2   3
#define tha2  4
#define gem   5 
#define ha2   6
#define kha2  7
#define dal   8
#define zal   9
#define reh   10
#define zen   11
#define sen   12
#define shen  13
#define sad   14
#define dad   15
#define tah   16
#define zah   17
#define aen   18
#define ghen  19
#define feh   20
#define qaf   21
#define kaf   22
#define lam   23
#define mem   24
#define non   25
#define heh   26 
#define waw   27
#define yeh   28

//.............................................................................................
#endif