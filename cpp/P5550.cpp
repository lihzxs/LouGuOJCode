/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-25 17:10
//	Comment		:	OJ(P5530)
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


void MatMult(int** ppnMatA, int** ppnMatB, int nN)
{
	int**			ppnAns			= NULL;
	ppnAns = (int**)malloc((nN + 1) * sizeof(int*));

	for (int i = 1; i <= nN; i++)
	{
		ppnAns[i] = (int*)malloc((nN + 1) * sizeof(int));
		memset(ppnAns[i], 0, (nN + 1) * sizeof(int));
	}
	for (int i = 1; i <= nN; i++)
		for (int j = 1; j <= nN; j++)
			for (int k = 1; k <= nN; k++)
				ppnAns[i][j] += ppnMatA[k][j] * ppnMatB[i][k];

	for (int i = 1; i <= nN; i++)
		for (int j = 1; j <= nN; j++)
			ppnMatB[i][j] = ppnAns[i][j];

	for (int i = 1; i <= nN; i++)
		free(ppnAns[i]);

	free(ppnAns);

}

int** FastPower(int** ppnMat, long long nK, int nN)
{
	int**			ppnAns				= NULL;
	ppnAns = (int**)malloc((nN + 1) * sizeof(int*));

	for (int i = 1; i <= nN; i++)
	{
		ppnAns[i] = (int*)malloc((nN + 1) * sizeof(int));
		memset(ppnAns[i], 0, (nN + 1) * sizeof(int));
		ppnAns[i][i] = 1;
	}

	while (nK > 0)
	{
		if (nK & 1)
			MatMult(ppnMat, ppnAns, nN);
		nK >>= 1;
		MatMult(ppnMat, ppnMat, nN);
	}
	return ppnAns;
}





int main(int argc, char* argv[])
{
	int					nInputN;
	int					nInputS;
	int					nInputM;
	long long			llInputK;
	long long			llTemp;
	long long*			pllSeq					= NULL;
	int**				pnChangMat				= NULL;
	int**				pnMoveMat				= NULL;
	int**				pnFinMat					= NULL;
	

	scanf("%d%d%d%lld", &nInputN, &nInputM, &nInputS, &llInputK);

	pnChangMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	pnMoveMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	for (int i = 1; i <= nInputN; i++)
	{
		pnChangMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		pnMoveMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		memset(pnChangMat[i], 0, (nInputN + 1) * sizeof(int));
		memset(pnMoveMat[i], 0, (nInputN + 1) * sizeof(int));
	}
	
	pllSeq = (long long*)malloc((nInputN + 1) * sizeof(long long));

	for (int i = 1; i <= nInputN; i++)
		scanf("%lld", &pllSeq[i]);

	for (int i = 1; i <= nInputN; i++)
		if (i != nInputS && i != nInputM)
			pnChangMat[i][i] = 1;

	pnChangMat[nInputM][nInputS] = 1;
	pnChangMat[nInputS][nInputM] = 1;

	for (int i = 1; i < nInputN; i++)
		pnMoveMat[i][i + 1] = 1;
	pnMoveMat[nInputN][1] = 1;

	MatMult(pnChangMat, pnMoveMat, nInputN);

	pnFinMat = FastPower(pnMoveMat, llInputK, nInputN);

		
	for (int i = 1; i <= nInputN; i++)
	{
		llTemp = 0;
		for (int j = 1; j <= nInputN; j++)
			llTemp += pnFinMat[i][j] * pllSeq[j];
		printf("%lld ", llTemp);
	}




Exit0:
	return 0;
}