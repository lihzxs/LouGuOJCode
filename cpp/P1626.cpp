/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-19 11:37
//	Comment		:	OJ(P1626)
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
#define	MAXNUM		3
#define	EPS         0.0001
#define MODNUM		1000000007ll


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int g_nMin			= 100000000;


void DFS(int* pnSeq, int nNum, map<int, bool>& mapReduce,
	map<int, bool>& mapIsReduce, int nCount, int nSum, int nInputK)
{
	if (nCount >= nInputK - 1)
	{
		if(g_nMin > nSum )
			g_nMin = nSum;
		return;
	}
	for (int i = 0; i < nNum; i++)
		for (int j = 0; j < nNum; j++)
		{
			if (!mapIsReduce[pnSeq[i]] && !mapReduce[pnSeq[j]] &&
				pnSeq[i] != pnSeq[j])
			{
				mapIsReduce[pnSeq[i]] = true;
				mapReduce[pnSeq[j]] = true;
				nSum += abs(pnSeq[i] - pnSeq[j]);

				DFS(pnSeq, nNum, mapReduce, mapIsReduce, ++nCount, nSum, nInputK);
				mapIsReduce[pnSeq[i]] = false;
				mapReduce[pnSeq[j]] = false;
			}
		}


}

int main(int argc, char* argv[])
{

	map<int, bool>		mapReduce;
	map<int, bool>		mapIsReduce;

	int			nInputN;
	int			nInputK;
	int			nAns			= 0;
	int*		pnInputSeq		= NULL;
	int*		pnDiffSeq		= NULL;

	scanf("%d%d", &nInputN, &nInputK);

	pnInputSeq = (int*)malloc(nInputN * sizeof(int));

	pnDiffSeq = (int*)malloc((nInputN - 1) * sizeof(int));

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", pnInputSeq + i);
		mapIsReduce[pnInputSeq[i]] = false;
		mapReduce[pnInputSeq[i]] = false;
	}

	sort(pnInputSeq, pnInputSeq + nInputN);

	for (int i = 1; i < nInputN; i++)
		pnDiffSeq[i - 1] = pnInputSeq[i] - pnInputSeq[i - 1];

	sort(pnDiffSeq, pnDiffSeq + nInputN - 1);

	for (int i = 0; i < nInputK; i++)
		nAns += pnDiffSeq[i];

	
	printf("%d", nAns);
		







Exit0:

	return 0;
}