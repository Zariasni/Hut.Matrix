#pragma once

#ifndef HUT_SIMPLE_POINT_H
#define HUT_SIMPLE_POINT_H

#define HUT_POINT(T)	Hut##T##Point
#define _X	0
#define _Y	1

#define DECL_HUT_SIMPLE_POINT(T)\
class HUT_POINT(T)\
{\
public:\
	HUT_POINT(T)( const T x = 0, const T y = 0 );\
	HUT_POINT(T)( const T* points );\
	HUT_POINT(T)( const HUT_POINT(T)& point );\
\
	const T x() const;\
	const T y() const;\
\
	T x();\
	T y();\
\
	const T* points() const;\
	T* points();\
\
	HUT_POINT(T)& operator = ( const T* points );\
	HUT_POINT(T)& operator = ( const HUT_POINT(T)& point );\
\
	Logical operator == ( const T* points );\
	Logical operator == ( const HUT_POINT(T)& point );\
	Logical operator != ( const T* points );\
	Logical operator != ( const HUT_POINT(T)& point );\
\
	HUT_POINT(T) operator ! ( void );\
	const T &operator[] (UInt index) const;\
	T &operator[] (UInt index);\
\
private:\
	T _point[2];\
};

DECL_HUT_SIMPLE_POINT(UInt32)
DECL_HUT_SIMPLE_POINT(UInt64)

#endif
