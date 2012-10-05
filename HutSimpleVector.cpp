#include "stdafx.h"
#include "HutSimpleVector.h"


HutSimpleVector::HutSimpleVector()
:	_size(0),
	_fullsize(0),
	_vector(NULL)
{
}

HutSimpleVector::~HutSimpleVector()
{
}

UInt HutSimpleVector::size()
{
	return _size;
}
