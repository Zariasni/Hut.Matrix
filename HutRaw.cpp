#include "stdafx.h"
#include "HutRaw.h"
#include "HutMatrix.h"

using namespace std;

HutRaw::HutRaw()
:	//_file(),
	_cfile(NULL)
{
}

HutRaw::~HutRaw()
{
	close();
}

Logical HutRaw::open( const Int08* filename )
{
	_cfile = fopen( filename, "rb" );

	if ( !_cfile )
	{
		return false;
	}
	return true;
//	_file.open( filename, (ios_base::in&ios_base::out) );
//	if(_file.fail())
//		return false;
//	return true;
}

void HutRaw::read( void* data, const UInt32 width, const UInt32 height, const UInt32 type )
{
	fread( data, type, width*height, _cfile );
//	_file.read( (Int08*)data, width*height*type );
//	file = fopen( "cameraman.png", "r" );
//	fread( data, type, width*height, file );
//	fclose( file );

}

void HutRaw::read( HutSimpleMatrix& matrix )
{
//	read( matrix.getVoidVector(), matrix.getWidth(), matrix.getHeight(), matrix.getType() );
}


void HutRaw::write( const void* data, const UInt32 width, const UInt32 height, const UInt32 type )
{
	fwrite( data, type, width*height, _cfile );
//	_file.write( (Int08*)data, width*height*type );
}

void HutRaw::write( const Int08* filename, const void* data, const UInt32 width, const UInt32 height, const UInt32 type ) const
{
	FILE* cfile;
	cfile = fopen( filename, "wb" );

	if( !cfile )
		return;

	fwrite( data, type, width*height, cfile );

	fclose( cfile );

//	ofstream file;
//	file.open( filename, ios_base::out );
//	if( file.fail() )
//		return;
//	file.write( (Int08*)data, width*height*type );
//	file.close();
}

void HutRaw::write( const HutSimpleMatrix& matrix )
{
//	write( matrix.getVoidVector(), matrix.getWidth(), matrix.getHeight(), matrix.getType() );
}

void HutRaw::write( const Int08* filename, const HutSimpleMatrix& matrix ) const
{
//	write( filename, matrix.getVoidVector(), matrix.getWidth(), matrix.getHeight(), matrix.getType() );
}

void HutRaw::close()
{
//	_file.close();
	if( _cfile )
		fclose( _cfile );
}
