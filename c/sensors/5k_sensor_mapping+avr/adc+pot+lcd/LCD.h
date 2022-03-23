/*

Code created by "LANKASH"
  @2/10/2021

File Contents : 'LCD' implementation Functions

*/

#ifndef LCD_H_
#define LCD_H_


/*
    Function name         :  LCD_send_cmd
    Function Returns      :  void
    Function Arguments    :  unsigned char.
    Function Description  :  Sends the commands to the LCD.
*/
void LCD_send_cmd (unsigned char cmd);

/*
    Function name         :  LCD_init
    Function Returns      :  void
    Function Arguments    :  
    Function Description  :  Initializes the LCD Connections and Mode (by Macros above).
*/
void LCD_init();

/*
    Function name         :  LCD_send_char
    Function Returns      :  void
    Function Arguments    :  unsigned char port, unsigned char data.
    Function Description  :  Type a Character on the LCD.
*/
void LCD_send_char (unsigned char data);

/*
    Function name         :  LCD_send_string
    Function Returns      :  void
    Function Arguments    :  unsigned char *data.
    Function Description  :  Type String on the LCD.
*/
void LCD_send_string (unsigned char* data);


/*
    Function name         :  LCD_clear_screen
    Function Returns      :  void
    Function Arguments    :  
    Function Description  :  Clear the Display on the LCD.
*/
void LCD_clear_screen ();

/*
    Function name         :  LCD_move_cursor
    Function Returns      :  void
    Function Arguments    :  unsigned char row, unsigned char coloumn.
    Function Description  :  Select the Cursor position on the LCD.
*/
void LCD_move_cursor (unsigned char row, unsigned char coloumn);      


#endif /* LCD_H_ */


