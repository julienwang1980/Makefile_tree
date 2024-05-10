//*************************************************************************
//*************************************************************************
/**
 * \file		
 *
 * \brief		
 *
 * \copyright	
 *
 * \author		Julien Wang
*/
//*************************************************************************
//*************************************************************************
#include "serial.h"
#include <termios.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include "timer.h"


//-------------------------------------------------------------------------
/**
 * \fn ;
 *
 * \brief 
 *
 * \param 
 *
 * \return 
 */
//-------------------------------------------------------------------------
int Serial_init(Serial serial)
{
    struct termios options;
    int fd;
    fd = open(serial.port, O_RDWR | O_NOCTTY);
    if (fd == -1)
    {
        perror("open port: Unable to open port - ");
        return(-1);
    }

    tcgetattr(fd, &options);
    // baudrate set
    switch (serial.baudRate)
    {
    case 9600:
        cfsetispeed(&options, B9600);
        cfsetospeed(&options, B9600);
        break;
    case 115200:
        cfsetispeed(&options, B115200);
        cfsetospeed(&options, B115200);
        break;
    default:
        perror("set baud rate error");
        return(-1);
        break;
    }
    // data bits set
    options.c_cflag &= ~CSIZE; // Clear all bits that set the data size
    switch (serial.dataBits)
    {
    case 5:
        options.c_cflag |= CS5; // 5 bits per byte
        break;
    case 6:
        options.c_cflag |= CS6; // 6 bits per byte
        break;
    case 7:
        options.c_cflag |= CS7; // 7 bits per byte
        break;
    case 8:
        options.c_cflag |= CS8; // 8 bits per byte
        break;
    default:
        perror("set data bits error");
        return(-1);
        break;
    }
    // data bits set
    switch (serial.stopBits)
    {
    case 1:
        options.c_cflag &= ~CSTOPB; // Clear stop field, only one stop bit used in communication
        break;
    case 2:
        options.c_cflag |= CSTOPB; // Clear stop field, two stop bits used in communication
        break;   
    default:
        perror("set data bits error");
        return(-1);
        break;
    }
    // set parity check
    switch (serial.parity)
    {
    case None:
        options.c_cflag &= ~PARENB;// Clear parity bit, disabling parity
        break;
    case Odd:
        options.c_cflag |= PARENB;
        options.c_cflag |= PARODD;
        break;
    case Even:
        options.c_cflag |= PARENB;
        options.c_cflag &= ~PARODD;
        break; 
    default:
        perror("set parity check error");
        return(-1);
        break;
    }
    options.c_cflag |= (CLOCAL | CREAD);
    tcsetattr(fd, TCSANOW, &options);
    return fd;
}


//-------------------------------------------------------------------------
/**
 * \fn ;
 *
 * \brief 
 *
 * \param 
 *
 * \return 
 */
//-------------------------------------------------------------------------
int Serial_read(Serial serial, char *buffer, int size)
{
    int fd = Serial_init(serial);
    int n = read(fd, buffer, size);
    close(fd);
    return n;
}


//-------------------------------------------------------------------------
/**
 * \fn ;
 *
 * \brief 
 *
 * \param 
 *
 * \return 
 */
//-------------------------------------------------------------------------
int Serial_write(Serial serial, char *buffer, int size)
{
    int fd = Serial_init(serial);
    int n = write(fd, buffer, size);
    close(fd);
    return n;
}



void Serial_stes(void)
{
    char buffer[1024];
    Serial serial = {
        .baudRate = 115200,
        .dataBits = 8,
        .stopBits = 1,
        .parity = None,
        .port = "/dev/ttyUSB0"
    };
    buffer[1] = 100;
    for (;;)
    {

        Serial_write(serial, buffer, 100);

        printf("data: %d\n", buffer[0]);
        msleep(500);
    }
    
}
