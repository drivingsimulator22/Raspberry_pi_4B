/*
  Created by : "Lankash"
  @22/2/2022
  Content: "DIO" functions decleration.

*/

/*
    Function name         :  open_file
    Function Returns      :  int fd;
    Function Arguments    :  char *dest, unsigned char mode
    Function Description  :  mode=0: Read-Only
                             mode=1: Write-Only
                             mode=2: Read+Write
*/
int open_file(char *dest, unsigned char mode);

/*
    Function name         :  open_file
    Function Returns      :  void
    Function Arguments    :  char *dest, unsigned char mode
    Function Description  :  Open the file destination.
*/

