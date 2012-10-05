#include "stdafx.h"
#include "HutSimplePoint.h"

#define IMPL_HUT_SIMPLE_POINT(T)\
HUT_POINT(T)::HUT_POINT(T)( const T _x, const T _y )\
:	_point()\
{\
	_point[_X] = _x;\
	_point[_Y] = _y;\
}\
\
HUT_POINT(T)::HUT_POINT(T)( const T* points )\
:	_point()\
{\
	_point[_X] = points[_X];\
	_point[_Y] = points[_Y];\
}\
\
HUT_POINT(T)::HUT_POINT(T)( const HUT_POINT(T)& point )\
:	_point()\
{\
	_point[_X] = point[_X];\
	_point[_Y] = point[_Y];\
}\
\
const T HUT_POINT(T)::x() const\
{\
	return _point[_X];\
}\
\
const T HUT_POINT(T)::y() const\
{\
	return _point[_Y];\
}\
\
T HUT_POINT(T)::x()\
{\
	return _point[_X];\
}\
\
T HUT_POINT(T)::y()\
{\
	return _point[_Y];\
}\
\
const T* HUT_POINT(T)::points() const\
{\
	return _point;\
}\
\
T* HUT_POINT(T)::points()\
{\
	return _point;\
}\
\
HUT_POINT(T)& HUT_POINT(T)::operator = ( const T* points )\
{\
	_point[_X] = points[_X];\
	_point[_Y] = points[_Y];\
\
	return *this;\
}\
\
HUT_POINT(T)& HUT_POINT(T)::operator = ( const HUT_POINT(T)& point )\
{\
	_point[_X] = point[_X];\
	_point[_Y] = point[_Y];\
\
	return *this;\
}\
\
Logical HUT_POINT(T)::operator == ( const T* points )\
{\
	return ( (_point[_X] == points[_X]) && (_point[_Y] == points[_Y]) );\
}\
\
Logical HUT_POINT(T)::operator == ( const HUT_POINT(T)& point )\
{\
	return ( (_point[_X] == point[_X]) && (_point[_Y] == point[_Y]) );\
}\
\
Logical HUT_POINT(T)::operator != ( const T* points )\
{\
	return !( (*this) == points );\
}\
\
Logical HUT_POINT(T)::operator != ( const HUT_POINT(T)& point )\
{\
	return !( (*this) == point );\
}\
\
HUT_POINT(T) HUT_POINT(T)::operator ! ( void )\
{\
	HUT_POINT(T) t(*this);\
\
	t[_X] = !_point[_X];\
	t[_Y] = !_point[_Y];\
	\
	return t;\
}\
\
const T &HUT_POINT(T)::operator[] (UInt index) const\
{\
	return _point[index];\
}\
\
T &HUT_POINT(T)::operator[] (UInt index)\
{\
	return _point[index];\
}



IMPL_HUT_SIMPLE_POINT(UInt32)
IMPL_HUT_SIMPLE_POINT(UInt64)
