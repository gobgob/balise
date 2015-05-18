#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

/**
 * Macro to set bit in particular port
 */
#ifndef sbi
#define sbi(port, bit) (port) |= ( 1 << (bit) )
#endif

/**
 * Macro to clear bit in particular port
 */
#ifndef cbi
#define cbi(port, bit) (port) &= ~( 1 << (bit) )
#endif

/**
 * Macro to get bit in particular port
 */
#ifndef gbi
#define gbi(port, bit) (port) & ( 1 << (bit) )
#endif

/**
 * Macro to toggle bit
 */
#ifndef tbi
#define tbi(port, bit) (port) ^= (1 << (bit));
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#endif
