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

#ifndef PORT
#define PORT PORT
#endif

#ifndef PIN
#define PIN PIN
#endif

#ifndef DDR
#define DDR DDR
#endif

/**
 * Macro to concat define
 */
#ifndef CONCAT
#define CONCAT2( a, b ) a ## b
#define CONCAT( a, b ) CONCAT2( a, b )
#define CONCAT_32(a, b, c) a ## b ## c
#define CONCAT_3(a, b, c) CONCAT_32(a, b, c)
#endif

typedef void (*voidFuncPtr)(void);

#endif