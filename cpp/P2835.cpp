/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-23 00:32
//	Comment		:	OJ(P2835)
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
#include <list>
#include <float.h>

using namespace std;
#define	MAXNUM		1000001
#define	EPS         0.0001
#define MODNUM		100000007


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
	int*			pnSet = NULL;
	int*			pnFat = NULL;
	int				nTemp;
	int				nIn;
	int				nFa;
	int				nAns	= 0;
	scanf("%d", &nInputN);

	pnSet = (int*)malloc((nInputN + 1) * sizeof(int));
	pnFat = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnFat, 0, (nInputN + 1) * sizeof(int));
	for (int i = 1; i <= nInputN; i++)
		pnSet[i] = i;

	for (int i = 1; i <= nInputN; i++)
	{
		nTemp = Fin(pnSet, i);
		while (true)
		{
			scanf("%d", &nIn);
			if (nIn == 0)
				break;
			pnFat[nIn] = 1;
			nFa = Fin(pnSet, nIn);
			if (nFa != nTemp)
				pnSet[nFa] = nTemp;
		}
	}

	for (int i = 1; i <= nInputN; i++)
	{
		if (pnSet[i] == i || pnFat[i] == 0)
			nAns++;
	}

	printf("%d", nAns);

Exit0:

	return 0;
}