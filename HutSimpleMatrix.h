#pragma once

#ifndef HUT_SIMPLE_MATRIX_H
#define HUT_SIMPLE_MATRIX_H

class HutSimpleMatrix
{
public:
	HutSimpleMatrix();
	~HutSimpleMatrix();

	const UInt width() const;
	const UInt height() const;
	const UInt size() const;
	const UInt* size2D() const;

private:
	UInt _size[3];
	UInt _fullsize[3];

	void** _matrix;
	void* _vector;
};

#endif
/*
�� �� 
1.iswt2 ���� �Ϸ���� �ʾҽ��ϴ�
2.DampedRL_TV �Լ����� �ι�° �������� fft ���� null �� �������.
3.blind_deconv
���ϰ� �����١���� ���ΰ��������� 2�ð��� �ɸ���.(��Ʈ���� �� 3-4��)
ss_blind_deconv.m �� �ʹ� ������ ���ư���. conv2 �Լ��� ������ ���δ�.
����� ��Ʈ���Լ� imresize ���� �ٸ��� ���ͼ� �׽�Ʈ �Ұ�.


algorithms
o	1.	destripe
	2.	hyper laplacian deconvolution
	3.	hyper laplacian deconvolution (kari)
	4.	wiener filter
o	5.	deconv sparse
o	6.	progressive switched median filter
o	7.	hyper median filter
	8.	non-linear mean filter* ��ȯ�� �ʿ� ��� ����/������ ���ľ� �ǰ���?
o	9.	blind deconv **���� ����.
o	10.	deconv outlier
o	11.	damped RL Total variation **��������.
	11.	CPBD	**���� ���� �����µ� �߰� ������ �ٸ�.
o	12.	Metric Q

low-level transform
o	13.	fft (fftw) fast fourier transform
o		fft utils fftconv..etc
o		dft (opencv) discrete fourier transform
o		dst	discrete sine transform
	14.	dwt discrete wavelet transform 
		swt discrete stationary wavelet transform

data type
o	15.	complex (stl)
o		complex utils
?	16.	matrix
?		matrix utils
o	17.	image (opencv)
o		image utils

misc
?	18.	samples

platform
	opencl
*/

//burnable trash block
/*

using namespace std;


int main(int argc, char **argv)
{	
	cout << __TIME__ << endl;
	// load image
	KOMPSATImage image;
	KOMPSATImage psfimage;

	//char *infilename	=	new char[ 255 ];
	//memset( infilename, 0 , 255 );
	//strcpy( infilename, argv[1] );

	//char *t = strtok( argv[1], "." );
	//
	//char *maskfilename	=	new char[ 255 ];
	//char *peakfilename	=	new char[ 255 ];
	//char *outfilename	=	new char[ 255 ];

	//strcpy( maskfilename, t );
	//strcpy( peakfilename, t );
	//strcpy( outfilename, t );

	//strcat( maskfilename, "_mask.tif" );
	//strcat( peakfilename, "_peak.tif" );
	//strcat( outfilename, "_deno.tif" );

	//image.openImage( infilename );
	image.openImage( "blurred.png" );
	psfimage.openImage( "psf.png" );

	// go to the memory
	unsigned char* raster = new unsigned char[ image.getX() * image.getY() ];
	double* doubleraster = new double[ image.getX() * image.getY() ];
	image.getRasterImage( image.getX(), image.getY(), 1 , raster );

	unsigned char* psfraster = new unsigned char[ psfimage.getX() * psfimage.getY() ];
	double* doublepsfraster = new double[ psfimage.getX() * psfimage.getY() ];
	psfimage.getRasterImage( psfimage.getX(), psfimage.getY(), 1 , psfraster );


	int size[2] = { image.getX(), image.getY() };
	int psfsize[2] = { psfimage.getX(), psfimage.getY() };
	int masksize[2] = { 512, 512 };

	KOMPSATInt08Matrix psf( (char*)psfraster, psfsize );

	int psfnorm = 0;

	for( int i = 0 ; i < psfsize[0]*psfsize[1] ; i ++ )
	{
		psfnorm += psfraster[i];
	}

	normalizeRaster( raster, doubleraster, image.getArea() , 255 );
	normalizeRaster( psfraster, doublepsfraster, psfimage.getArea() , psfnorm );

	double* peakpoint = new double[ 512*512*sizeof(double) ];
	double* mask = new double[ 512*512*sizeof(double) ];

//	fprintm( doublepsfraster, (unsigned*)psfsize, "out1.txt" );

	

	//----------------
	// do something
	//----------------
	double sigma = 5.0/255.0;
	double reg_str = 0.003;
	outlierDeconvolution( doubleraster, doubleraster, doublepsfraster, (unsigned*)size, (unsigned*)psfsize, sigma, reg_str );
//	startDestripe( doubleraster, doubleraster, size, peakpoint, mask );

	imageScaling( peakpoint, masksize, 255 );
	imageScaling( mask, masksize, 255 );

	denormalizeRaster( doubleraster, raster, image.getArea(), 255 );

	for( int i = 0 ; i < image.getBands() ; i ++ )
		image.setRasterImage( size[0],size[1], i+1, raster );
	image.saveImage( "deconv.tif" );
	//image.saveImage( outfilename );

	//denormalizeRaster( peakpoint, raster, image.getArea(), 1 );

	//for( int i = 0 ; i < image.getBands() ; i ++ )
	//	image.setRasterImage( masksize[0],masksize[1], i+1, raster );
	//image.saveImage( peakfilename );

	//denormalizeRaster( mask, raster, image.getArea(), 1 );

	//for( int i = 0 ; i < image.getBands() ; i ++ )
	//	image.setRasterImage( masksize[0],masksize[1], i+1, raster );
	//image.saveImage( maskfilename );

	delete[] peakpoint;
	delete[] mask;
	delete[] doubleraster;
	delete[] raster;

	return 0;
}


	KOMPSATFFT fft;
	KOMPSATImage testimage;
	testimage.openImage( "out3.tif" );

	UInt08* imageraster = new UInt08[ testimage.getArea() ];
	Float64* out = new Float64[ testimage.getArea() ];
	KOMPSATComplex* fftout = new KOMPSATComplex[ testimage.getArea() ];
	
	testimage.getRasterImage( testimage.getX(), testimage.getY(), 1, imageraster );

	normalizeRaster( imageraster, out, testimage.getArea(), 255 );

	UInt32 testsize[] = { testimage.getX(), testimage.getY() };

	fft.fft2_r2c( out, (signed*)testsize, fftout );

	fprintm( out, testsize, "out1.txt" );
	iprintm( out, testsize, "out.tif", "out1.tif" );

	fprintm( fftout, testsize, "out3.txt" );

	fft.ifft2_c2r( fftout, (signed*)testsize, out );

	fprintm( out, testsize, "out2.txt" );
	iprintm( out, testsize, "out.tif", "out2.tif" );

	
//	fft.ifft2_c2r( fftout, (signed*)size, out );
	delete[] imageraster;
	delete[] fftout;
	delete[] out;


	return 0;	double a[] = {	 1,     2,     3,     4,     5,     6,     7,
					 8,     9,    10,    11,    12,    13,    14,
					15,    16,    17,    18,    19,    20,    21,
					22,    23,    24,    25,    26,    27,    28,
					29,    30,    31,    32,    33,    34,    35,
					36,    37,    38,    39,    40,    41,    42,
					43,    44,    45,    46,    47,    48,    49,
					50,    51,    52,    53,    54,    55,    56,
					57,    58,    59,    60,    61,    62,    63,
					64,    65,    66,    67,    68,    69,    70,
					71,    72,    73,    74,    75,    76,    77};



	//double b[] = { 1,     2,     3,     4,     5,     6,     7,		8,     9};
	int asize[] = {7,11};

	double* ret = new double[ 77 ];

	dst( a, ret, asize );
//	double* ret = dst( a, asize );

	KOMPSATFloat64Matrix c( ret, asize );

	cout << c << endl;

	return 0 ;	KOMPSATComplexMatrix a(2,2);

	a[0][0][0] = 7;
	a[0][1][0] = 8;
	a[1][0][0] = 1;
	a[1][1][0] = 2;

	cout << a << endl;

	int asize[2] = {2,2};
//	int padsize[2] = {3,3};
	int padsize[2] = {1,1};
//	int padsize[2] = {2,2};

	KOMPSATComplex* pada = (KOMPSATComplex *)padarray( a._array, asize, padsize, sizeof(KOMPSATComplex), PAD_CIRCULAR, PAD_BOTH );
//	KOMPSATComplex* pada = (KOMPSATComplex *)padarray( a._array, asize, padsize, sizeof(KOMPSATComplex), PAD_CIRCULAR, PAD_PRE );
//	KOMPSATComplex* pada = (KOMPSATComplex *)padarray( a._array, asize, padsize, sizeof(KOMPSATComplex), PAD_CIRCULAR, PAD_POST );

//	KOMPSATComplexMatrix b( pada, 8,8);
//	KOMPSATComplexMatrix b( pada, 6,6);
	KOMPSATComplexMatrix b( pada, 4,4);
//	KOMPSATComplexMatrix b( pada, 3,3);

	cout << b << endl;
*/
