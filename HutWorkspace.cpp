#include "stdafx.h"
#include "HutWorkspace.h"
#include "HutMatrix.h"

HutWorkspace::HutWorkspace()
:	_workspace(NULL),
	_data(NULL),
	_count(0),
	_num(0)
{
}

HutWorkspace::HutWorkspace( const UInt32 width, const UInt32 height, const UInt32 type, const UInt32 num )
:	_workspace(NULL),
	_data(NULL),
	_count(0),
	_num(0)
{
	initWorkspace( width, height, type, num );
}

HutWorkspace::HutWorkspace( const HutSimpleMatrix* matrixes, const UInt32 num )
:	_workspace(NULL),
	_data(NULL),
	_count(0),
	_num(0)
{
	initWorkspace( matrixes, num );
}

HutWorkspace::~HutWorkspace()
{
	if( _workspace )
		delete[] _workspace;
}

void HutWorkspace::initWorkspace( const UInt32 width, const UInt32 height, const UInt32 type, const UInt32 num )
{
}

void HutWorkspace::initWorkspace( const HutSimpleMatrix* matrixes, const UInt32 num )
{
	//if( _workspace )
	//	delete[] _workspace;

	//_num		= num;
	//_data		= new Int08( width*height*type*num );
	//_workspace	= new HutSimpleMatrix[num];

	//for( UInt32 i = 0 ; i < num ; i ++ )
	//	_workspace[i] = matrixes[i];
}

const HutSimpleMatrix* HutWorkspace::getWorkspace( const UInt32 index ) const
{
//	_workspace[index].zeros();
	return &(_workspace[index]);
}

HutSimpleMatrix* HutWorkspace::getWorkspace( const UInt32 index )
{
//	_workspace[index].zeros();
	return &(_workspace[index]);
}

const void* HutWorkspace::getWorkspace( const Int32 index ) const
{
	return NULL;
//	_workspace[index].zeros();
//	return _workspace[index].getVoidVector();
}

void* HutWorkspace::getWorkspace( const Int32 index )
{
//	_workspace[index].zeros();
//	return _workspace[index].getVoidVector();

	return NULL;
}

const HutSimpleMatrix* &HutWorkspace::operator []( const UInt32 index ) const
{
//	_workspace[index].zeros();
	return (const HutSimpleMatrix* &)(_workspace[index]);
//	return 0;
}

HutSimpleMatrix* &HutWorkspace::operator []( const UInt32 index )
{
//	_workspace[index].zeros();
	return (HutSimpleMatrix* &)(_workspace[index]);

//	return 0;
}

//const void* &HutWorkspace::operator []( const Int32 index ) const
//{
//	workspace[index].zeros();
//	return (const void*)getWorkspace(index);
//}
//
//void* &HutWorkspace::operator []( const Int32 index )
//{
//	workspace[index].zeros();
//	return getWorkspace(index);
//}

HutSimpleMatrix* HutWorkspace::getWorkspace()
{
	if( _count > _num )
		return NULL;

//	_workspace[_count].zeros();
	return &(_workspace[_count++]);
}

void HutWorkspace::initCount()
{
	_count = 0;
}

UInt32 HutWorkspace::getCount()
{
	return _count;
}

UInt32 HutWorkspace::getNum()
{
	return _num;
}
