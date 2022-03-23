/*
  Created by : "Lankash"
  @22/2/2022
  Content: "DIO" functions implementations.

*/

// Header Files
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int open_file(char *dest, unsigned char mode)
{
  int fd;

  switch (mode)
  {
  case 0:                      // Read-Only
    fd = open(dest, O_RDONLY); // export: Write Only file

  case 1:                      // Write-Only
    fd = open(dest, O_WRONLY); // export: Write Only file

  case 2:                    // Read+Write
    fd = open(dest, O_RDWR); // export: Write Only file
  }

  /*
      Check if Cannot open the file from the "fd"
      print error message
    */
  if (-1 == fd)
  {
    printf("ERROR: Cannot open file \'Export\'\n");
  }

  return fd;
}

