/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-11 23:33
//	Comment		:	OJ(P1577)
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

bool Check(double* pfSeq, int nN, int nK,double fX)
{
	int nCount = 0;
	for (int i = 0; i < nN; i++)
	{
		nCount += (int)(pfSeq[i] / fX);
		if (nCount >= nK)
			return true;
	}
	return false;
}


int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputK;
	double			fLeft;
	double			fRight;
	double			fMid;
	double*			pfSeq				= NULL;

	scanf("%d%d", &nInputN, &nInputK);
	pfSeq = (double*)malloc(nInputN * sizeof(double));

	for (int i = 0; i < nInputN; i++)
		scanf("%lf", pfSeq + i);
	fLeft = 0;
	fRight = 1000000;

	while (fRight - fLeft > 0.0001)
	{
		fMid = (fRight + fLeft) / 2;
		if (Check(pfSeq, nInputN, nInputK, fMid))
			fLeft = fMid;
		else
			fRight = fMid;
	}

    char szAns[100];
	sprintf(szAns, "%.3f", fLeft);
	szAns[strlen(szAns) - 1] = '\0';
	printf("%s", szAns);


Exit0:

	return 0;
}