#pragma once

#ifndef HUT_SIMPLE_VECTOR_H
#define HUT_SIMPLE_VECTOR_H

class HutSimpleVector
{
public:
	HutSimpleVector();
	~HutSimpleVector();

	UInt size();

private:
	void doubling();
	void resize();

	UInt _size;
	UInt _fullsize;

	void* _vector;
};

#endif
