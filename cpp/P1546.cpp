/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-29 23:48
//	Comment		:	OJ(P1546)
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


int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int**			ppnMat = NULL;
	unsigned int*	pnDis = 0;
	int*			pnFlag = NULL;
	int				nTemp;
	int				nX;
	int				nY;
	int				nW;
	int				nMin;
	int				nPoint = 1;
	int				nSum = 0;

	scanf("%d", &nInputN);

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	pnFlag = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnFlag, 0, (nInputN + 1) * sizeof(int));
	pnDis = (unsigned int*)malloc((nInputN + 1) * sizeof(unsigned int));
	memset(pnDis, 127, (nInputN + 1) * sizeof(int));
	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		memset(ppnMat[i], 0, (nInputN + 1) * sizeof(int));
	}

	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputN; j++)
		{
			scanf("%d", &nTemp);
			ppnMat[i][j] = nTemp;
		}

	for (int i = 2; i <= nInputN; i++)
	{
		if (ppnMat[1][i] != 0)
			pnDis[i] = ppnMat[1][i];
	}

	pnFlag[1] = true;

	for (int i = 2; i <= nInputN; i++)
	{
		nMin = pnDis[0];
		for (int j = 1; j <= nInputN; j++)
		{
			if (pnDis[j] < nMin && pnFlag[j] == false)
			{
				nMin = pnDis[j];
				nPoint = j;
			}
		}

		pnFlag[nPoint] = true;

		for (int j = 1; j <= nInputN; j++)
		{
			if (ppnMat[nPoint][j] != 0)
			{
				if (pnDis[j] > ppnMat[nPoint][j] && pnFlag[j] == false)
					pnDis[j] = ppnMat[nPoint][j];
			}
		}
	}

	for (int i = 2; i <= nInputN; i++)
		nSum += pnDis[i];

	printf("%d", nSum);

Exit0:

	return 0;
}