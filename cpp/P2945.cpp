/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-19 20:25
//	Comment		:	OJ(P2945)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <stack>
#include <string>
#include <string.h>
using namespace std;
#define	MAXNUM		20000
#define	EPS         0.0001
#define ERROR_ID    0

typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;




int main(int argc, char* argv[])
{
	int			nInputN;
	int			nInputX;
	int			nInputY;
	int			nSum1			= 0;
	int			nSum2			= 0;
	int*		pnInputB		= NULL;
	int*		pnInputM		= NULL;
	scanf("%d%d%d", &nInputN, &nInputX, &nInputY);


	pnInputB = (int*)malloc(nInputN * sizeof(int));
	pnInputM = (int*)malloc(nInputN * sizeof(int));
	for (int i = 0; i < nInputN; i++)
		scanf("%d%d", pnInputM + i, pnInputB + i);

	sort(pnInputB, pnInputB + nInputN);
	sort(pnInputM, pnInputM + nInputN);

	for (int i = 0; i < nInputN; i++)
	{
		if (pnInputB[i] > pnInputM[i])
			nSum1 += (pnInputB[i] - pnInputM[i]) * nInputX;
		else
			nSum1 += (pnInputM[i] - pnInputB[i]) * nInputY;
	}


	printf("%d", nSum1);


Exit0:

	return 0;
}


