/******************************************************************************
 *
 * Module: Common - Platform Types Abstraction
 *
 * File Name: std_types.h
 *
 * Description: General purpose types
 *
 * Author: Mohamed Ashraf
 *
 *******************************************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/*Boolean Data Type*/
typedef unsigned char boolean;

/*Boolean Values*/

#ifndef TRUE
#define TRUE 				(1u)
#endif
#ifndef FALSE
#define FALSE 				(0u)
#endif

#define LOGIC_HIGH  		(1u)
#define LOGIC_LOW  			(0u)

/*NULL*/
#define NULL_PTR 			((void*)0)


typedef unsigned char 			uint8;
typedef signed char 			sint8;
typedef unsigned short 			uint16;
typedef signed short 			sint16;
typedef unsigned long 			uint32;
typedef signed long 			sint32;
typedef unsigned long long 		uint64;
typedef signed long long 		sint64;
typedef float 					float32;
typedef double     				float64;


#endif /* STD_TYPES_H_ */
