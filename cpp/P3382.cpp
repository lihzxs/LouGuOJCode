/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-17 16:02
//	Comment		:	OJ(P3382)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
#include <set>
#include <queue>
#include <map>

using namespace std;
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		2e31


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

double Ans(double* pfSeq, int nN, double nX)
{
	double fSum = 0;
	for (int i = nN; i >= 0; i--)
		fSum = fSum * nX + pfSeq[i];
	return fSum;
}


int main(int argc, char* argv[])
{

	int				nInputN;
	double			fLeft;
	double			fRight;
	double			fTemp;
	double			fMidL;
	double			fMidR;
	double*			pfSeq				= NULL;


	scanf("%d%lf%lf", &nInputN, &fLeft, &fRight);

	pfSeq = (double*)malloc((nInputN + 1) * sizeof(double));
	memset(pfSeq, 0, (nInputN + 1) * sizeof(double));

	for (int i = nInputN; i >= 0; i--)
		scanf("%lf", pfSeq + i);


	while (fRight - fLeft >= 0.000001)
	{
		fTemp = (fRight - fLeft) / 3.0;
		fMidL = fLeft + fTemp;
		fMidR = fRight - fTemp;
		if (Ans(pfSeq, nInputN, fMidL) > Ans(pfSeq, nInputN, fMidR))
			fRight = fMidR;
		else
			fLeft = fMidL;
	}

	printf("%.5f\n", fLeft);




Exit0:

	return 0;
}