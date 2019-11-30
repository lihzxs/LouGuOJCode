/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-23 10:24
//	Comment		:	OJ(P1003)
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
	int				nInputN;
	int*			pnInputA;
	int*			pnInputB;
	int*			pnInputG;
	int*			pnInputK;
	int				nInputX;
	int				nInputY;


	scanf("%d", &nInputN);

	pnInputA = (int*)malloc(nInputN * sizeof(int));
	pnInputB = (int*)malloc(nInputN * sizeof(int));
	pnInputG = (int*)malloc(nInputN * sizeof(int));
	pnInputK = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
		scanf("%d%d%d%d", pnInputA + i, pnInputB + i,
			pnInputG + i, pnInputK + i);

	scanf("%d%d", &nInputX, &nInputY);

	for (int i = nInputN - 1; i >= 0; i--)
	{
		if (nInputX >= pnInputA[i] && nInputX <= pnInputA[i] + pnInputG[i] &&
			nInputY >= pnInputB[i] && nInputY <= pnInputB[i] + pnInputK[i])
		{
			printf("%d", i + 1);
			return 0;
		}
	}
	printf("-1");








Exit0:

	return 0;
}