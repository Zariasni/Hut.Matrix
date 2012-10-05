#pragma once

#ifndef HUT_RAW_H
#define HUT_RAW_H

class HutSimpleMatrix;

class HutRaw
{
public:
	HutRaw();
	~HutRaw();

	Logical open( const Int08* filename );
	void read( void* data, const UInt32 width, const UInt32 height, const UInt32 type );
	void read( HutSimpleMatrix& matrix );

	void write( const void* data, const UInt32 width, const UInt32 height, const UInt32 type );
	void write( const Int08* filename, const void* data, const UInt32 width, const UInt32 height, const UInt32 type ) const;
	void write( const HutSimpleMatrix& matrix );
	void write( const Int08* filename, const HutSimpleMatrix& matrix ) const;
	void close();

private:
//	std::fstream _file;
	FILE* _cfile;
};

#endif
