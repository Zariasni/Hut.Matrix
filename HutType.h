#pragma once

/******************************************************************************
 * TYPE DEFINE
 ******************************************************************************/

#ifndef HUT_TYPE_H
#define HUT_TYPE_H

// using long double. if it is not included, long double is equal to double
#include <float.h>


typedef bool Logical;
typedef char Int08;
typedef short Int16;
typedef int Int32;
#ifdef __WINDOWS__
typedef __int64					Int64;
#else
typedef long long int Int64;
#endif

typedef unsigned char UInt08;
typedef unsigned short UInt16;
typedef unsigned int UInt32;
#ifdef __WINDOWS__
typedef unsigned __int64		UInt64;
#else
typedef unsigned long long int UInt64;
#endif

typedef float Float32;
typedef double Float64;
typedef long double Float128;

// alias
typedef Int64 Int;
typedef UInt64 UInt;
typedef Float32 Float;

#endif
