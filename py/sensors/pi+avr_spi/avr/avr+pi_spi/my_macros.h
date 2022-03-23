/*

Code Created By "LANKASH"
  @30/8/2021

File contents  :  Standard Bit-Operation Macros 
*/

#define REG_SIZE 8    //Set the Register size.

#define SHIFT_LEFT(x, y)     x=(x<<y)|(x>>(REG_SIZE-y))    //Left Circular Shift.
#define SHIFT_RIGHT(x, y)    x=(x>>y)|(x<<(REG_SIZE-y))    //Right Circular Shift.
#define SET_BIT(x, y)        x|=(1<<y)                     //Set Specific Bit to "1".
#define TOG_BIT(x, y)        x^=(1<<y)                     //Toggle Specific Bit.
#define CLR_BIT(x, y)        x&=(~(1<<y))                  //Clear Specific Bit.
#define READ_BIT(x, y)       ((x&(1<<y))>>y)               //Read Specific bit, Assigned in variable.
#define IS_BIT_SET(x, y)     (x&(1<<y))>>y                 //Get '1' if Specific bit is "1".
#define IS_BIT_CLR(x, y)     !(x&(1<<y))>>y                 //Get '1' if Specific bit is "0".
