#include "stdafx.h"
#include "HutSimpleRect.h"

#define IMPL_HUT_SIMPLE_RECT(T)\
HUT_RECT(T)::HUT_RECT(T)( const T x1, const T x2, const T y1, const T y2 )\
:	_points()\
{\
	_points[_P1][_X] = x1;\
	_points[_P1][_Y] = x2;\
	_points[_P2][_X] = y1;\
	_points[_P2][_Y] = y2;\
}\
\
HUT_RECT(T)::HUT_RECT(T)( const T* p1, const T* p2 )\
:	_points()\
{\
	_points[_P1][_X] = p1[_X];\
	_points[_P1][_Y] = p1[_Y];\
	_points[_P2][_X] = p2[_X];\
	_points[_P2][_Y] = p2[_Y];\
}\
\
HUT_RECT(T)::HUT_RECT(T)( const T* points )\
:	_points()\
{\
	_points[_P1][_X] = points[0];\
	_points[_P1][_Y] = points[1];\
	_points[_P2][_X] = points[2];\
	_points[_P2][_Y] = points[3];\
}\
\
HUT_RECT(T)::HUT_RECT(T)( const HUT_POINT(T)& p1, const HUT_POINT(T)& p2 )\
:	_points()\
{\
	_points[_P1] = p1;\
	_points[_P2] = p2;\
}\
\
HUT_RECT(T)::HUT_RECT(T)( const HUT_POINT(T)* points )\
:	_points()\
{\
	_points[_P1] = points[_P1];\
	_points[_P2] = points[_P2];\
}\
\
HUT_RECT(T)::HUT_RECT(T)( const HUT_RECT(T)& rect )\
:	_points()\
{\
	_points[_P1] = rect[_P1];\
	_points[_P2] = rect[_P2];\
}\
\
const T HUT_RECT(T)::x1() const\
{\
	return _points[_P1][_X];\
}\
\
const T HUT_RECT(T)::y1() const\
{\
	return _points[_P1][_Y];\
}\
\
const T HUT_RECT(T)::x2() const\
{\
	return _points[_P2][_X];\
}\
\
const T HUT_RECT(T)::y2() const\
{\
	return _points[_P2][_Y];\
}\
\
const T HUT_RECT(T)::size() const\
{\
	return abs((_points[_P2][_Y]-_points[_P1][_Y])*(_points[_P2][_X]-_points[_P1][_X]));\
}\
\
T HUT_RECT(T)::x1()\
{\
	return _points[_P1][_X];\
}\
\
T HUT_RECT(T)::y1()\
{\
	return _points[_P1][_Y];\
}\
\
T HUT_RECT(T)::x2()\
{\
	return _points[_P2][_X];\
}\
\
T HUT_RECT(T)::y2()\
{\
	return _points[_P2][_Y];\
}\
\
const HUT_POINT(T) HUT_RECT(T)::start() const\
{\
	return _points[_P1];\
}\
\
const HUT_POINT(T) HUT_RECT(T)::end() const\
{\
	return _points[_P2];\
}\
\
HUT_POINT(T) HUT_RECT(T)::start()\
{\
	return _points[_P1];\
}\
\
HUT_POINT(T) HUT_RECT(T)::end()\
{\
	return _points[_P2];\
}\
\
const T* HUT_RECT(T)::startPoints() const\
{\
	return _points[_P1].points();\
}\
\
const T* HUT_RECT(T)::endPoints() const\
{\
	return _points[_P2].points();\
}\
\
T* HUT_RECT(T)::startPoints()\
{\
	return _points[_P1].points();\
}\
\
T* HUT_RECT(T)::endPoints()\
{\
	return _points[_P2].points();\
}\
\
const T* HUT_RECT(T)::points() const\
{\
	return _points[_P1].points();\
}\
\
T* HUT_RECT(T)::points()\
{\
	return _points[_P1].points();\
}\
\
HUT_RECT(T)& HUT_RECT(T)::operator = ( const T* points )\
{\
	_points[_P1][_X] = points[0];\
	_points[_P1][_Y] = points[1];\
	_points[_P2][_X] = points[2];\
	_points[_P2][_Y] = points[3];\
\
	return *this;\
}\
\
HUT_RECT(T)& HUT_RECT(T)::operator = ( const HUT_POINT(T)* points )\
{\
	_points[_P1] = points[_P1];\
	_points[_P2] = points[_P2];\
\
	return *this;\
}\
\
HUT_RECT(T)& HUT_RECT(T)::operator = ( const HUT_RECT(T)& rect )\
{\
	_points[_P1] = rect[_P1];\
	_points[_P2] = rect[_P2];\
\
	return *this;\
}\
\
Logical HUT_RECT(T)::operator == ( const T* points )\
{\
	return ( (_points[_P1][_X] == points[0]) &&\
			(_points[_P1][_Y] == points[1]) &&\
			(_points[_P2][_X] == points[2]) &&\
			(_points[_P2][_Y] == points[3]) );\
}\
\
Logical HUT_RECT(T)::operator == ( const HUT_POINT(T)* points )\
{\
	return ( (_points[_P1] == points[_P1]) &&\
			(_points[_P2] == points[_P2]) );\
}\
\
Logical HUT_RECT(T)::operator == ( const HUT_RECT(T)& rect )\
{\
	return ( (_points[_P1] == rect[_P1]) &&\
			(_points[_P2] == rect[_P2]) );\
}\
\
Logical HUT_RECT(T)::operator != ( const T* points )\
{\
	return !((*this) == points);\
}\
\
Logical HUT_RECT(T)::operator != ( const HUT_POINT(T)* points )\
{\
	return !((*this) == points);\
}\
\
Logical HUT_RECT(T)::operator != ( const HUT_RECT(T)& point )\
{\
	return !((*this) == point);\
}\
\
const HUT_POINT(T) &HUT_RECT(T)::operator[] ( const UInt index ) const\
{\
	return _points[index];\
}\
\
HUT_POINT(T) &HUT_RECT(T)::operator[] ( const UInt index )\
{\
	return _points[index];\
}

IMPL_HUT_SIMPLE_RECT( UInt32 )
IMPL_HUT_SIMPLE_RECT( UInt64 )


//const T &HUT_RECT(T)::operator[] ( const Int index ) const
//{
//	return _points[_P1][index];
//}
//
//T &HUT_RECT(T)::operator[] ( const Int index )
//{
//	return _points[_P1][index];
//}


