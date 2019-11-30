/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-21 01:01
//	Comment		:	OJ(P1561)
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
	int					nInputN;
	int*				pnU;
	int*				pnD;
	int					nMinU = 1000000000;
	int					nMinD = 1000000000;
	int					nSumU = 0;
	int					nSumD = 0;
	scanf("%d", &nInputN);

	pnU = (int*)malloc((nInputN + 1) * sizeof(int));
	pnD = (int*)malloc((nInputN + 1) * sizeof(int));

	for (int i = 1; i <= nInputN; i++)
	{
		scanf("%d%d", pnU + i, pnD + i);
		nSumU += pnU[i];
		nSumD += pnD[i];
		nMinD = min(nMinD, pnD[i]);
		nMinU = min(nMinU, pnU[i]);
	}
	if (nSumU + nMinD > nSumD + nMinU)
		printf("%d", nSumU + nMinD);
	else
		printf("%d", nSumD + nMinU);
		


Exit0:

	return 0;
}