/*
	Hutsori Matrix Lib.
	Complex Class

	@date 20120902
	@author daegung kim

	@remark
		- complex by real type (arithmatic)operation is working only same type.
		- then, please type casting.
*/
#pragma once

#ifndef HUT_COMPLEX_H
#define HUT_COMPLEX_H

//typedef Float32 CSComplex[2];
//typedef Float64	CDComplex[2];
//typedef Float128 CLComplex[2];

#include <complex>

#define HUT_FLOAT_COMPLEX(T) HutFloatComplex##T

#define DECL_HUT_COMPLEX(R,C)\
class HUT_FLOAT_COMPLEX(C) : public std::complex<R>\
{\
public:\
\
	HUT_FLOAT_COMPLEX(C)( const R real = 0, const R imag = 0 );\
	HUT_FLOAT_COMPLEX(C)( const std::complex<R>& complex );\
	HUT_FLOAT_COMPLEX(C)( const HUT_FLOAT_COMPLEX(C)& complex );\
	~HUT_FLOAT_COMPLEX(C)( void );\
\
	HUT_FLOAT_COMPLEX(C)& operator = ( const std::complex<R>& complex );\
	HUT_FLOAT_COMPLEX(C)& operator = ( const HUT_FLOAT_COMPLEX(C)& complex );\
\
	HUT_FLOAT_COMPLEX(C) operator ! ( void );\
	const Logical operator || ( const std::complex<R>& complex );\
	const Logical operator || ( const HUT_FLOAT_COMPLEX(C)& complex );\
\
	const Logical operator && ( const std::complex<R>& complex );\
	const Logical operator && ( const HUT_FLOAT_COMPLEX(C)& complex );\
\
	const Logical isZero( void ) const;\
	const R &operator[] (UInt index) const;\
	R &operator[] (UInt index);\
};

DECL_HUT_COMPLEX(Float32,64)
DECL_HUT_COMPLEX(Float64,128)
DECL_HUT_COMPLEX(Float128,256)

// set default type. current=(Float64/double)
typedef HutFloatComplex64 HutComplex;

#endif

