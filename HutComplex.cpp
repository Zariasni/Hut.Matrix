#include "stdafx.h"
#include "HutComplex.h"


#ifdef __WINDOWS__

#define IMPL_HUT_COMPLEX(R,C)\
HUT_FLOAT_COMPLEX(C)::HUT_FLOAT_COMPLEX(C)( const R real, const R imag )\
{\
	_Val[_RE] = real;\
	_Val[_IM] = imag;\
}\
\
HUT_FLOAT_COMPLEX(C)::HUT_FLOAT_COMPLEX(C)( const std::complex<R>& complex )\
{\
	_Val[_RE] = complex._Val[_RE];\
	_Val[_IM] = complex._Val[_IM];\
}\
\
HUT_FLOAT_COMPLEX(C)::HUT_FLOAT_COMPLEX(C)( const HUT_FLOAT_COMPLEX(C)& complex )\
{\
	_Val[_RE] = complex._Val[_RE];\
	_Val[_IM] = complex._Val[_IM];\
}\
\
HUT_FLOAT_COMPLEX(C)::~HUT_FLOAT_COMPLEX(C)( void )\
{\
}\
\
HUT_FLOAT_COMPLEX(C)& HUT_FLOAT_COMPLEX(C)::operator = ( const std::complex<R>& complex )\
{\
	_Val[_RE] = complex.real();\
	_Val[_IM] = complex.imag();\
\
	return *this;\
}\
\
HUT_FLOAT_COMPLEX(C)& HUT_FLOAT_COMPLEX(C)::operator = ( const HUT_FLOAT_COMPLEX(C)& complex )\
{\
	_Val[_RE] = complex[_RE];\
	_Val[_IM] = complex[_IM];\
\
	return *this;\
}\
\
HUT_FLOAT_COMPLEX(C) HUT_FLOAT_COMPLEX(C)::operator ! ( void )\
{\
	HUT_FLOAT_COMPLEX(C) c(*this);\
\
	c[_RE] = !this->real();\
	c[_IM] = !this->imag();\
	\
	return c;\
}\
\
const Logical HUT_FLOAT_COMPLEX(C)::operator || ( const std::complex<R>& complex )\
{\
	return ( !this->isZero() || complex._Val[_RE] || complex._Val[_IM] );\
}\
\
const Logical HUT_FLOAT_COMPLEX(C)::operator || ( const HUT_FLOAT_COMPLEX(C)& complex )\
{\
	return ( !this->isZero() || !complex.isZero() );\
}\
\
const Logical HUT_FLOAT_COMPLEX(C)::operator && ( const std::complex<R>& complex )\
{\
	return ( !this->isZero() && complex._Val[_RE] && complex._Val[_IM] );\
}\
\
const Logical HUT_FLOAT_COMPLEX(C)::operator && ( const HUT_FLOAT_COMPLEX(C)& complex )\
{\
	return ( !this->isZero() && !complex.isZero() );\
}\
\
const Logical HUT_FLOAT_COMPLEX(C)::isZero( void ) const\
{\
	return (!_Val[_RE] && !_Val[_IM]);\
}\
\
const R &HUT_FLOAT_COMPLEX(C)::operator[] (UInt index) const\
{\
	return _Val[index];\
}\
\
R &HUT_FLOAT_COMPLEX(C)::operator[] (UInt index)\
{\
	return _Val[index];\
}

#elif __APPLE__

#define IMPL_HUT_COMPLEX(R,C)\
HUT_FLOAT_COMPLEX(C)::HUT_FLOAT_COMPLEX(C)( const R real, const R imag )\
:	std::complex<R>(real,imag)\
{\
}\
\
HUT_FLOAT_COMPLEX(C)::HUT_FLOAT_COMPLEX(C)( const std::complex<R>& complex )\
:	std::complex<R>(complex)\
{\
}\
\
HUT_FLOAT_COMPLEX(C)::HUT_FLOAT_COMPLEX(C)( const HUT_FLOAT_COMPLEX(C)& complex )\
:	std::complex<R>(complex)\
{\
}\
\
HUT_FLOAT_COMPLEX(C)::~HUT_FLOAT_COMPLEX(C)( void )\
{\
}\
\
HUT_FLOAT_COMPLEX(C)& HUT_FLOAT_COMPLEX(C)::operator = ( const std::complex<R>& complex )\
{\
	(*this) = complex;\
\
	return *this;\
}\
\
HUT_FLOAT_COMPLEX(C)& HUT_FLOAT_COMPLEX(C)::operator = ( const HUT_FLOAT_COMPLEX(C)& complex )\
{\
	(*this) = complex;\
\
	return *this;\
}\
\
HUT_FLOAT_COMPLEX(C) HUT_FLOAT_COMPLEX(C)::operator ! ( void )\
{\
	HUT_FLOAT_COMPLEX(C) c(*this);\
\
	c.real() = !(this->real());\
	c.imag() = !(this->imag());\
	\
	return c;\
}\
\
const Logical HUT_FLOAT_COMPLEX(C)::operator || ( const std::complex<R>& complex )\
{\
	return ( !this->isZero() || complex.real() || complex.imag() );\
}\
\
const Logical HUT_FLOAT_COMPLEX(C)::operator || ( const HUT_FLOAT_COMPLEX(C)& complex )\
{\
	return ( !this->isZero() || !complex.isZero() );\
}\
\
const Logical HUT_FLOAT_COMPLEX(C)::operator && ( const std::complex<R>& complex )\
{\
	return ( !this->isZero() && complex.real() && complex.imag() );\
}\
\
const Logical HUT_FLOAT_COMPLEX(C)::operator && ( const HUT_FLOAT_COMPLEX(C)& complex )\
{\
	return ( !this->isZero() && !complex.isZero() );\
}\
\
const Logical HUT_FLOAT_COMPLEX(C)::isZero( void ) const\
{\
	return (!real() && !imag());\
}\
\
const R &HUT_FLOAT_COMPLEX(C)::operator[] (UInt index) const\
{\
	if( index )\
		return imag();\
	else\
		return real();\
}\
\
R &HUT_FLOAT_COMPLEX(C)::operator[] (UInt index)\
{\
	if( index )\
		return imag();\
	else\
		return real();\
}

#endif


IMPL_HUT_COMPLEX(Float32,64)
IMPL_HUT_COMPLEX(Float64,128)
IMPL_HUT_COMPLEX(Float128,256)

//GLUE(HRSIPComplex,X)::GLUE(HRSIPComplex,X)( const FFTW_T& complex)
//{
//	_Val[_RE] = complex[_RE]{}
//	_Val[_IM] = complex[_IM]{}
//}
//const Logical GLUE(HRSIPComplex,X)::operator || ( const FFTW_T& complex )
//{
//	return ( !this->isZero() || complex[_RE] || complex[_IM] ){}
//}
//const Logical GLUE(HRSIPComplex,X)::operator && ( const FFTW_T& complex )
//{
//	return ( !this->isZero() && complex[_RE] && complex[_IM] );
//}
