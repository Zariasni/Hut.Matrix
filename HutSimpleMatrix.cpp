#include "stdafx.h"
#include "HutSimpleMatrix.h"

HutSimpleMatrix::HutSimpleMatrix()
:	_size(),
 	_fullsize(),
 	_matrix(NULL),
 	_vector(NULL)
{
}

HutSimpleMatrix::~HutSimpleMatrix()
{
	if(_matrix)
		delete[] _matrix;
}

const UInt HutSimpleMatrix::width() const
{
	return	_size[0];
}

const UInt HutSimpleMatrix::height() const
{
	return _size[1];
}

const UInt HutSimpleMatrix::size() const
{
	return _size[2];
}

const UInt* HutSimpleMatrix::size2D() const
{
	return _size;
}
