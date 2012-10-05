#pragma once

#ifndef Hut_WORKSPACE_H
#define Hut_WORKSPACE_H

class HutSimpleMatrix;

class HutWorkspace
{
public:
	HutWorkspace();
	HutWorkspace( const UInt32 width, const UInt32 height, const UInt32 type, const UInt32 num );
	HutWorkspace( const HutSimpleMatrix* matrixes, const UInt32 num );
	~HutWorkspace();

	void initWorkspace( const UInt32 width, const UInt32 height, const UInt32 type, const UInt32 num );
	void initWorkspace( const HutSimpleMatrix* matrixes, const UInt32 num );

	const HutSimpleMatrix* getWorkspace( const UInt32 index ) const;
	HutSimpleMatrix* getWorkspace( const UInt32 index );
	HutSimpleMatrix* getWorkspace( void );

	const void* getWorkspace( const Int32 index ) const;
	void* getWorkspace( const Int32 index );

	const HutSimpleMatrix* &operator []( const UInt32 index ) const;
	HutSimpleMatrix* &operator []( const UInt32 index );


	void initCount();
	UInt32 getCount();
	UInt32 getNum();

private:
	HutSimpleMatrix* _workspace;
	Int08* _data;

	UInt32 _count;
	UInt32 _num;
};


#endif
