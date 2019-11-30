/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-23 23:31
//	Comment		:	OJ(P2307)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
#include <set>
#include <queue>
#include <list>
#include <map>

using namespace std;
#define	MAXNUM		100000000
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int Fin(int* pnSet, int nNum)
{
	if (pnSet[nNum] == nNum)
		return pnSet[nNum];
	else
		return pnSet[nNum] =
		Fin(pnSet, pnSet[nNum]);
}
int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int*			pnSet = NULL;
	int*			pnFlag = NULL;
	int				nInputA;
	int				nInputB;
	int				nInputC;
	int				nFA;
	int				nFB;
	int				nSum = 0;
	int				nF = 0;

	nInputN = 100005;

	pnSet = (int*)malloc((nInputN + 1) * sizeof(int));
	pnFlag = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnFlag, 0, (nInputN + 1) * sizeof(int));

	for (int i = 1; i <= nInputN; i++)
		pnSet[i] = i;

	while (scanf("%d%d", &nInputA, &nInputB))
	{
		if (nInputA == -1 && nInputB == -1)
			break;
		if (nInputA == 0 && nInputB == 0)
		{
			if (!nF && nSum == 1)
				printf("1\n");
			else
				printf("0\n");

			memset(pnFlag, 0, (nInputN + 1) * sizeof(int));

			for (int i = 1; i <= nInputN; i++)
				pnSet[i] = i;
			nSum = 0;
			nF = 0;
			continue;

		}
		if (!pnFlag[nInputA])
			nSum++;
		if (!pnFlag[nInputB])
			nSum++;
		pnFlag[nInputA] = 1;
		pnFlag[nInputB] = 1;
		nFA = Fin(pnSet, nInputA);
		nFB = Fin(pnSet, nInputB);
		if (nFA == nFB)
			nF = 1;
		else
		{
			nSum--;
			pnSet[nFA] = nFB;
		}
	}

Exit0:
	return 0;
}