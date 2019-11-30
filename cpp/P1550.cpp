/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-23 20:05
//	Comment		:	OJ(P1550)
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
	int					nInputN;
	int*				pnW;
	int**				ppnMat					= NULL;
	int*				pnDis = NULL;
	int*				pnFlag = NULL;
	int					nMin;
	int					nPoint;
	int					nSum = 0;

	scanf("%d", &nInputN);

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	for (int i = 0; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		memset(ppnMat[i], 0, (nInputN + 1) * sizeof(int));
	}

	pnDis = (int*)malloc((nInputN + 1) * sizeof(int));
	for (int i = 0; i <= nInputN; i++)
		pnDis[i] = 2000000000;

	pnFlag = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnFlag, 0, (nInputN + 1) * sizeof(int));

	for (int i = 1; i <= nInputN; i++)
	{
		scanf("%d", &ppnMat[0][i]);
		ppnMat[i][0] = ppnMat[0][i];
	}

	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputN; j++)
			scanf("%d", &ppnMat[i][j]);

	pnDis[0] = 0;
	for (int i = 0; i <= nInputN; i++)
	{

		nMin = 2000000000;
		for (int j = 0; j <= nInputN; j++)
		{
			if (pnDis[j] < nMin && pnFlag[j] == false)
			{
				nMin = pnDis[j];
				nPoint = j;
			}
		}

		pnFlag[nPoint] = true;

		for (int j = 0; j <= nInputN; j++)
		{
			if (ppnMat[nPoint][j] != 0)
			{
				if (pnDis[j] > ppnMat[nPoint][j] && pnFlag[j] == false)
					pnDis[j] = ppnMat[nPoint][j];
			}
		}
	}

	for (int i = 0; i <= nInputN; i++)
		nSum += pnDis[i];

	printf("%d", nSum);

		
Exit0:

	return 0;
}