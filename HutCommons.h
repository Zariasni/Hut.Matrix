/*
	Hutsori Matrix Lib.
	common macros

	@date 20120902
	@author daegung kim

	@remark
		- usually used macros
*/
#pragma once

#ifndef HUT_COMMON_MACROS_H
#define HUT_COMMON_MACROS_H

/******************************************************************************
 * define macro
 ******************************************************************************/
/*============================================================================*
 * PREFIX/POSTFIX DEFINE MACRO
 *============================================================================*/
#define PREFIX( name )			Hut ## name
#define GLUE( prefix, name )	prefix ## name
#define CONCAT( prefix, name )	prefix ## name
#define MATRIX( name )			PREFIX( name ) ## Matrix
#define COMPLEX( name )			PREFIX( name ) ## Complex


/*============================================================================*
 * CONSTANTS:
 *============================================================================*/
#define HUT_EPSILON 2.2204460492503131E-16
#define HUT_PI		3.14159265358979323846264338327950
#define HUT_E1		2.71828182845904523536028747135266
#define HUT_LOG2	0.69314718055994530941723212145818
#define HUT_SQRT2	1.41421356237309504880168872420969

/*============================================================================*
 * MACRO FUNCTIONS:
 *============================================================================*/
#define result(exp)		cout << #exp << "=" << exp << endl

#define sqr(x)			((x)*(x))
#define SQR(x)			((x)*(x))
#define copysign(a,b)	_copysign((Float64)a,(Float64)b)
#define COPYSIGN(a,b)	_copysign((Float64)a,(Float64)b)
#define sign(a)			_copysign((1.0),(Float64)a)
#define SIGN(a)			_copysign((1.0),(Float64)a)
#define log2(a)			log((Float64)a)/LOG2
#define Log2(a)			log((Float64)a)/LOG2
#define ln(a)			log((Float64)a)
#define pythagorean(a,b) hypot((Float64)a,(Float64)b)
#define BITSWAP(a, b) (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b)))
#define BITSWAPF(a, b) (((*(UInt32*)(&a)) ^= (*(UInt32*)&b)), ((*(UInt32*)&b) ^= (*(UInt32*)&a)), ((*(UInt32*)&a) ^= (*(UInt32*)&b)))

/*============================================================================*
 * Min and Max:
 *============================================================================*/
#define MAX_INT08		((Int08)(127))
#define MIN_INT08		((Int08)(-128))
#define MAX_UINT08		((UInt08)(255))
#define MIN_UINT08		((UInt08)(0))
#define MAX_INT16		((Int16)(32767))
#define MIN_INT16		((Int16)(-32768))
#define MAX_UINT16		((UInt16)(65535))
#define MIN_UINT16		((UInt16)(0))
#define MAX_INT32		((Int32)(2147483647))
#define MIN_INT32		((Int32)(-2147483647-1))
#define MAX_UINT32		((UInt32)(0xFFFFFFFFU))
#define MIN_UINT32		((UInt32)(0))
#define MAX_FLOAT32		3.40282347e+38F
#define MIN_FLOAT32		1.17549435e-38F
#define MAX_FLOAT64		1.7976931348623157e+308F
#define MIN_FLOAT64		2.2250738585072014e-308F

/*============================================================================*
 * OPEN CL:
 *============================================================================*/
#define OPENCL_NULL		cl_mem(0)
#define OPENCL_DEVICES	16

//inline functions for reference kernel
typedef unsigned char (uchar4)[4];


#endif


