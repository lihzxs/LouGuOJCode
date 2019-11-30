/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-23 20:07
//	Comment		:	OJ(P1513)
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






int main(int argc, char* argv[])
{
	int			nInputN;
	double		fR;
	double*		pfX;
	double*		pfY;
	double		fAns			= 0;
	scanf("%d%lf", &nInputN, &fR);
	pfX = (double*)malloc(nInputN * sizeof(double));
	pfY = (double*)malloc(nInputN * sizeof(double));

	for (int i = 0; i < nInputN; i++)
		scanf("%lf%lf", pfX + i, pfY + i);

	for (int i = 0; i < nInputN - 1; i++)
		fAns += sqrt((pfX[i] - pfX[i + 1]) * (pfX[i] - pfX[i + 1]) +
		(pfY[i] - pfY[i + 1]) * (pfY[i] - pfY[i + 1]));

	fAns += sqrt((pfX[0] - pfX[nInputN - 1]) * (pfX[0] - pfX[nInputN - 1]) +
		(pfY[0] - pfY[nInputN - 1]) * (pfY[0] - pfY[nInputN - 1]));

	fAns += 2 * 3.1415926535897932384626433 * fR;


	printf("%.2f", fAns);






		




Exit0:

	return 0;
}