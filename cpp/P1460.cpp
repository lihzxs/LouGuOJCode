/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-16 19:35
//	Comment		:	OJ(P1460)
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

bool Check(int* pnNeed, int* pnSum, int nN)
{
	for (int i = 0; i < nN; i++)
		if (pnSum[i] < pnNeed[i])
			return false;
	return true;
}


void DFS(int** ppnEat, int* pnSum, int* pnNeed,
	int nN, int nK, int nStart, int* pnOutput,int* pnAns, int nCount, int& nMin)
{
	if (nMin > nCount && Check(pnNeed, pnSum, nN))
	{
		nMin = nCount;
		for (int i = 0; i < nMin; i++)
			pnOutput[i] = pnAns[i];
		return;
	}
	if (nCount >= nMin)
		return;
	for (int i = nStart; i < nK; i++)
	{
		for (int j = 0; j < nN; j++)
			pnSum[j] += ppnEat[i][j];
		pnAns[nCount] = i;
		DFS(ppnEat, pnSum, pnNeed,
			nN, nK, i + 1, pnOutput, pnAns, nCount + 1, nMin);
		for (int j = 0; j < nN; j++)
			pnSum[j] -= ppnEat[i][j];
	}
}



int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputK;
	int*			pnNeed				= NULL;
	int*			pnSum				= NULL;
	int*			pnAns				= NULL;
	int*			pnOutput			= NULL;
	int**			ppnEat				= NULL;
	int				nMin;

	scanf("%d", &nInputN);
	nMin = nInputN + 1;
	pnNeed = (int*)malloc(nInputN * sizeof(int));
	pnSum = (int*)malloc(nInputN * sizeof(int));
	pnAns = (int*)malloc(nInputN * sizeof(int));
	pnOutput = (int*)malloc(nInputN * sizeof(int));
	memset(pnSum, 0, nInputN * sizeof(int));


	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnNeed + i);

	scanf("%d", &nInputK);

	ppnEat = (int**)malloc(nInputK * sizeof(int*));

	for (int i = 0; i < nInputK; i++)
		ppnEat[i] = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputK; i++)
	{
		for (int j = 0; j < nInputN; j++)
			scanf("%d", &ppnEat[i][j]);
	}

	DFS(ppnEat, pnSum, pnNeed,
		nInputN, nInputK, 0, pnOutput, pnAns, 0, nMin);

	printf("%d", nMin);
	for (int i = 0; i < nMin; i++)
		printf(" %d", pnOutput[i] + 1);


Exit0:

	return 0;
}