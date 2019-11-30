/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-4 22:57
//	Comment		:	OJ(P2374)
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

void DFS(int* pnSeqA, int* pnSeqB, int* pnSeqC, 
	int nA, int nB, int nC, int nNowSum, int nSumBook, int& nMax)
{
	if (nA == 0 && nB == 0 && nC == 0)
	{
		if (nNowSum > nMax)
			nMax = nNowSum;
		return;
	}
	if (nA > 0)
	{
		nNowSum += pnSeqA[nA] * (nSumBook - nA - nB - nC);
		DFS(pnSeqA, pnSeqB, pnSeqC,
			nA - 1, nB, nC, nNowSum, nSumBook, nMax);
		nNowSum -= pnSeqA[nA] * (nSumBook - nA - nB - nC);
	}
	if (nB > 0)
	{
		nNowSum += pnSeqB[nB] * (nSumBook - nA - nB - nC);
		DFS(pnSeqA, pnSeqB, pnSeqC,
			nA, nB - 1, nC, nNowSum, nSumBook, nMax);
		nNowSum -= pnSeqB[nB] * (nSumBook - nA - nB - nC);
	}
	if (nC > 0)
	{
		nNowSum += pnSeqC[nC] * (nSumBook - nA - nB - nC);
		DFS(pnSeqA, pnSeqB, pnSeqC,
			nA, nB, nC - 1, nNowSum, nSumBook, nMax);
		nNowSum -= pnSeqC[nC] * (nSumBook - nA - nB - nC);
	}




}




int main(int argc, char* argv[])
{
	int				nInputA;
	int				nInputB;
	int				nInputC;
	int*			pnSeqA			= NULL;
	int*			pnSeqB			= NULL;
	int*			pnSeqC			= NULL;
	int				nMax			= 0;
	scanf("%d%d%d", &nInputA, &nInputB, &nInputC);
	pnSeqA = (int*)malloc((nInputA + 1) * sizeof(int));
	pnSeqB = (int*)malloc((nInputB + 1) * sizeof(int));
	pnSeqC = (int*)malloc((nInputC + 1)* sizeof(int));
	for (int i = 1; i <= nInputA; i++)
		scanf("%d", pnSeqA + i);

	for (int i = 1; i <= nInputB; i++)
		scanf("%d", pnSeqB + i);

	for (int i = 1; i <= nInputC; i++)
		scanf("%d", pnSeqC + i);


	DFS(pnSeqA, pnSeqB, pnSeqC,
		nInputA, nInputB, nInputC, 0, 
		nInputA + nInputB + nInputC + 1, nMax);

	printf("%d", nMax);




Exit0:
	return 0;
}