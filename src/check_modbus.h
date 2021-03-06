#ifndef _CHECK_MODBUS_H_
#define _CHECK_MODBUS_H_

#include "variant.h"
#include "modbus/modbus.h"

	
#if LIBMODBUS_VERSION_MAJOR >= 3
#define SERIAL_PARITY_DEFAULT 'N'
#endif

enum
{
    RESULT_OK   =   0,
    RESULT_WARNING,
    RESULT_CRITICAL,
    RESULT_ERROR,
    RESULT_UNKNOWN,
    RESULT_PRINT_HELP,
    RESULT_WRONG_ARG,
    RESULT_ERROR_CONNECT,
    RESULT_ERROR_READ,
    RESULT_UNSUPPORTED_FUNCTION,
    RESULT_UNSUPPORTED_FORMAT
};

typedef struct
{
    char*   mport; 		                // Port number
    int     devnum;		                // Device modbus address 
    int     sad;		                // register/bit address
    int     nf;			                // Number of function
    double  warn_range;		            // Warning range
    double  crit_range;		            // Critical range
    char    *host; 		                // IP address or host name
    
#if LIBMODBUS_VERSION_MAJOR >= 3
    char    *serial;				    // serial port name
    int     serial_mode;			    // serial port mode (RS232/RS485)
    int     serial_bps;				    // serial port speed
    char    serial_parity;			    // serial port parity mode
    int     serial_data_bits;			// serial port data bits
    int     serial_stop_bits;			// serial port stop bit
#endif
	char*   file;                       // input binary dump file
	
    int     nc;			                // Null flag
    int     nnc;		                // No null flag
    int     tries;		                // tries 
    int     format;		                // data format 
    int     swap_bytes;		            // bytes order
    int     inverse_words;		        // words order
    int     verbose;		            // verbose

    int     perf_min_en;
    int     perf_max_en;

    double  perf_min;                   // min value for performance data
    double  perf_max;                   // max value for performance data
    int     perf_data;		            // enable performance data
    char*   perf_label;                 // label for performance data

	int     dump;                       // enable dump mode
	int     dump_format;                // output format of the dump
	int     dump_size;                  // number of input registers/bits included in the dump
}   modbus_params_t;



enum  
{
    MBF_MIN_SUPPORTED= 0,
    MBF001_READ_COIL_STATUS,            // 0x01 <- STD CODES
    MBF002_READ_INPUT_STATUS,           // 0x02
    MBF003_READ_HOLDING_REGISTERS,      // 0x03
    MBF004_READ_INPUT_REGISTERS,        // 0x04
    MBF_MAX_SUPPORTED
};

enum
{
	DUMP_FMT_MIN_SUPPORTED=0,
	DUMP_FMT_BIN,
	DUMP_FMT_HEX,
	DUMP_FMT_DEC,
	DUMP_FMT_MAX_SUPPORTED
};

#endif

