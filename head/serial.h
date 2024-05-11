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
#ifndef _SERIAL_H_   					// Re-include guard
#define _SERIAL_H_	    				// Re-include guard


//-------------------------------------------------------------------------
/**
 * \def	
 * \brief	
 */
//-------------------------------------------------------------------------


//-------------------------------------------------------------------------
/**
 * \enum PARITY
 * \brief Serial check mode
 */
//-------------------------------------------------------------------------
enum PARITY
{
	None=0, Odd, Even
};

//-------------------------------------------------------------------------
/**
 * \struct Serial
 * \brief the parameters of the serial
 */
//-------------------------------------------------------------------------
typedef struct
{
	char port[30];
	unsigned int baudRate;
	unsigned char dataBits;
	unsigned char stopBits;
	enum PARITY parity; 
} Serial;



//-------------------------------------------------------------------------
/**
 * \fn init Serial_init(Serial serial);
 *
 * \brief Open and initialize serial port parameters
 *
 * \param serial parameters of the serial
 *
 * \return file descriptor of the serial port, or -1 if invalid
 */
//-------------------------------------------------------------------------
int Serial_init(Serial serial);


//-------------------------------------------------------------------------
/**
 * \fn int Serial_read(Serial serial, char *buffer, int size);
 *
 * \brief read data from the serial port and return the number of bytes read
 *
 * \param serial Serial to read from the serial port.
 * \param buffer Buffer to save the data.
 * \param size Number of bytes to read.
 *
 * \return the number of bytes.
 */
//-------------------------------------------------------------------------
int Serial_read(Serial serial, char *buffer, int size);


//-------------------------------------------------------------------------
/**
 * \fn int Serial_write(Serial serial, char *buffer, int size);
 *
 * \brief write data to the serial port and return the number of bytes written
 *
 * \param serial Serial to write from the serial port.
 * \param buffer the data to write.
 * \param size Number of bytes to write.
 *
 * \return 
 */
//-------------------------------------------------------------------------
int Serial_write(Serial serial, char *buffer, int size);



void Serial_test(void);
#endif                                      // re-include guard
