#pragma once

#ifndef HUT_SIMPLE_RECT_H
#define HUT_SIMPLE_RECT_H

#define HUT_RECT(T) Hut##T##Rect

#include "HutSimplePoint.h"


#define _P1 0U
#define _P2 1U

#define DECL_HUT_SIMPLE_RECT(T)\
class HUT_RECT(T)\
{\
public:\
	HUT_RECT(T)( const T x1, const T y1, const T x2, const T y2 );\
	HUT_RECT(T)( const T* p1, const T* p2 );\
	HUT_RECT(T)( const T* points );\
	HUT_RECT(T)( const HUT_POINT(T)& p1, const HUT_POINT(T)& p2 );\
	HUT_RECT(T)( const HUT_POINT(T)* points );\
	HUT_RECT(T)( const HUT_RECT(T)& rect );\
\
	const T x1() const;\
	const T y1() const;\
	const T x2() const;\
	const T y2() const;\
	const T size() const;\
\
	T x1();\
	T y1();\
	T x2();\
	T y2();\
\
	const HUT_POINT(T) start() const;\
	const HUT_POINT(T) end() const;\
\
	HUT_POINT(T) start();\
	HUT_POINT(T) end();\
\
	const T* startPoints() const;\
	const T* endPoints() const;\
\
	T* startPoints();\
	T* endPoints();\
\
	const T* points() const;\
	T* points();\
\
	HUT_RECT(T)& operator = ( const T* points );\
	HUT_RECT(T)& operator = ( const HUT_POINT(T)* points );\
	HUT_RECT(T)& operator = ( const HUT_RECT(T)& points );\
\
	Logical operator == ( const T* points );\
	Logical operator == ( const HUT_POINT(T)* points );\
	Logical operator == ( const HUT_RECT(T)& rect );\
	Logical operator != ( const T* points );\
	Logical operator != ( const HUT_POINT(T)* points );\
	Logical operator != ( const HUT_RECT(T)& rect );\
\
	const HUT_POINT(T) &operator[] (const UInt index) const;\
	HUT_POINT(T) &operator[] (const UInt index);\
\
private:\
	HUT_POINT(T) _points[2];\
};


DECL_HUT_SIMPLE_RECT(UInt32)
DECL_HUT_SIMPLE_RECT(UInt64)

//const T &operator[] (const Int index) const;
//T &operator[] (const Int index);


#endif

