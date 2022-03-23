// Header Files
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "DIO.h"

// Macros
#define led_pin "26"
#define led_dir "out"

#define fan_pin "21"
#define fan_dir "out"

#define sevenSeg_dir "out"
#define sevenSeg1_a "2"
#define sevenSeg1_b "3"
#define sevenSeg1_c "4"
#define sevenSeg1_d "14"
#define sevenSeg2_a "17"
#define sevenSeg2_b "27"
#define sevenSeg2_c "22"
#define sevenSeg2_d "18"

#define pin_high "1"
#define pin_low "0"

#define dest "/sys/class/gpio/export"

//....................................................
// Mani Code
int main()
{
    // LED_Initialization
    /*
    Defining the file descriptor @which the GPIO pin file is.
    */
    int fd;
    fd = open("/sys/class/gpio/export", O_WRONLY); // export: Write Only file

    /*
    Check if Cannot open the file from the "fd"
    print error message
    */
    if (-1 == fd)
    {
        printf("ERROR: Cannot open file \'Export\'\n");
    }

    /*
    Arguments:-
    1) File Descriptor
    2) Buffer: the pin you want to write in
    3) size of the buffer: (Data Type)
    */
    ssize_t ret_val = write(fd, led_pin, strlen(led_pin)); // Buffer:

    /*
    Check if Written Successfuly on the pin.
    */
    if (0 == ret_val)
    {
        printf("ERROR: Zero Byte is Written on Export_26 @LED\n");
    }
    close(fd);

    fd = open("/sys/class/gpio/gpio26/direction", O_RDWR); // direction: Read_Write file

    /*
    Check if Cannot open the file from the "fd"
    print error message
    */

    if (-1 == fd)
    {
        printf("ERROR: Cannot open file Direction_gpio26 @LED\n");
    }

    /*
    Arguments:-
    1) File Descriptor
    2) Buffer: the pin you want to write in
    3) size of the buffer: (Data Type)
    */
    ret_val = write(fd, led_dir, strlen(led_dir)); // Buffer:

    /*
    Check if Written Successfuly on the pin.
    */
    if (0 == ret_val)
    {
        printf("ERROR: Zero Byte is Written on Direction_26 @LED\n");
    }
    close(fd);

    //...................................................................................................................................................
    // Relay_Initialization
    /*
    Defining the file descriptor @which the GPIO pin file is.
    */
    fd = open("/sys/class/gpio/export", O_WRONLY); // export: Write Only file

    /*
    Check if Cannot open the file from the "fd"
    print error message
    */
    if (-1 == fd)
    {
        printf("ERROR: Cannot open file Export_21 @Fan\n");
    }

    /*
    Arguments:-
    1) File Descriptor
    2) Buffer: the pin you want to write in
    3) size of the buffer: (Data Type)
    */
    ret_val = write(fd, fan_pin, strlen(fan_pin)); // Buffer:

    /*
    Check if Written Successfuly on the pin.
    */
    if (0 == ret_val)
    {
        printf("ERROR: Zero Byte is Written Export_21 @Fan\n");
    }
    close(fd);

    fd = open("/sys/class/gpio/gpio21/direction", O_RDWR); // direction: Read_Write file

    /*
    Check if Cannot open the file from the "fd"
    print error message
    */

    if (-1 == fd)
    {
        printf("ERROR: Cannot open file Export_21 @Fan\n");
    }

    /*
    Arguments:-
    1) File Descriptor
    2) Buffer: the pin you want to write in
    3) size of the buffer: (Data Type)
    */
    ret_val = write(fd, fan_dir, strlen(fan_dir)); // Buffer:

    /*
    Check if Written Successfuly on the pin.
    */
    if (0 == ret_val)
    {
        printf("ERROR: Zero Byte is Written on direction_21\n");
    }
    close(fd);

    //....................................................................................................................................................

    while (1)
    {
        // LED_Blink
        fd = open("/sys/class/gpio/gpio26/value", O_RDWR); // Value: Read_Write file

        if (-1 == fd)
        {
            printf("ERROR: Cannot open file Value_26 @High\n");
        }

        /*
        Arguments:-
        1) File Descriptor
        2) Buffer: the pin you want to write in
        3) size of the buffer: (Data Type)
        */
        ret_val = write(fd, pin_high, strlen(pin_high)); // Buffer:

        /*
        Check if Written Successfuly on the pin.
        */
        if (0 == ret_val)
        {
            printf("ERROR: Zero Byte is Written on value_26 @High\n");
        }

        sleep(1);

        /*
        Arguments:-
        1) File Descriptor
        2) Buffer: the pin you want to write in
        3) size of the buffer: (Data Type)
        */
        ret_val = write(fd, pin_low, strlen(pin_low)); // Buffer:

        /*
        Check if Written Successfuly on the pin.
        */
        if (0 == ret_val)
        {
            printf("ERROR: Zero Byte is Written on Value_26 @Low\n");
        }

        sleep(1);

        close(fd);

        //.....................................

        // FAN_Blink
        fd = open("/sys/class/gpio/gpio21/value", O_RDWR); // Value: Read_Write file

        if (-1 == fd)
        {
            printf("ERROR: Cannot open file Value_21 @Fan\n");
        }

        /*
        Arguments:-
        1) File Descriptor
        2) Buffer: the pin you want to write in
        3) size of the buffer: (Data Type)
        */
        ret_val = write(fd, pin_high, strlen(pin_high)); // Buffer:

        /*
        Check if Written Successfuly on the pin.
        */
        if (0 == ret_val)
        {
            printf("ERROR: Zero Byte is Written on Value_21 @HIGH");
        }

        sleep(1);

        /*
        Arguments:-
        1) File Descriptor
        2) Buffer: the pin you want to write in
        3) size of the buffer: (Data Type)
        */
        ret_val = write(fd, pin_low, strlen(pin_low)); // Buffer:

        /*
        Check if Written Successfuly on the pin.
        */
        if (0 == ret_val)
        {
            printf("ERROR: Zero Byte is Written on Value_21 @LOW");
        }

        sleep(1);

        close(fd);
    }
}
