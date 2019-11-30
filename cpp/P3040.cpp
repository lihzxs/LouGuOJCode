/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-3 21:38
//	Comment		:	OJ(P3040)
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

void DFS(int* pnSeq, int nIndex, int nN,
	int nSumA, int nSumB, int nSumC, int& nAns)
{
	if (nSumA >= nAns)
		return;
	if (nSumB >= nAns)
		return;
	if (nSumC >= nAns)
		return;

	if (nIndex == nN)
	{
		nSumB = max(nSumA, nSumB);
		nSumC = max(nSumB, nSumC);
		nAns = min(nAns, nSumC);
		return;
	}
	DFS(pnSeq, nIndex + 1, nN,
		nSumA + pnSeq[nIndex], nSumB, nSumC, nAns);
	DFS(pnSeq, nIndex + 1, nN,
		nSumA, nSumB + pnSeq[nIndex], nSumC, nAns);
	DFS(pnSeq, nIndex + 1, nN,
		nSumA, nSumB, nSumC + pnSeq[nIndex], nAns);
}
bool Cmp(int a, int b)
{
	return a > b;
}
int main(int argc, char* argv[])
{
	int				nInputN;
	int*			pnSeq				= NULL;
	int				nLeft				= 2000;
	int				nRight				= 0;
	int				nMid;
	int				nAns				= 200000;
	int				nMax				= 0;
	int				nSum;
	scanf("%d", &nInputN);

	pnSeq = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeq + i);

	sort(pnSeq, pnSeq + nInputN, Cmp);
	DFS(pnSeq, 0, nInputN, 0, 0, 0, nAns);
	printf("%d", nAns);

Exit0:
	return 0;
}