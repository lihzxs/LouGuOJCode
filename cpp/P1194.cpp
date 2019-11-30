/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-13 00:03
//	Comment		:	OJ(P1194)
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
	int				nX;
	int				nY;
	int				nW;
	int				nMin;
	int				nPoint = 1;
	int				nSum = 0;
	scanf("%d%d", &nInputM, &nInputN);

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
			scanf("%d", &ppnMat[i][j]);
			if (ppnMat[i][j] == 0)
				ppnMat[i][j] = nInputM;
		}


	pnDis[1] = nInputM;
	for (int i = 1; i <= nInputN; i++)
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

	for (int i = 1; i <= nInputN; i++)
		nSum += pnDis[i];

	printf("%d", min(nSum, nInputN * nInputM));

Exit0:

	return 0;
}