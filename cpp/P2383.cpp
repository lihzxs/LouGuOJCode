/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-14 20:43
//	Comment		:	OJ(P2383)
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
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		2e31


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

bool DFS(int* pnSeq, int nM, int nSum, int nNow, 
	int nA, int nB, int nC, int nD)
{
	if (nNow == nM)
	{
		if (nA == nSum && nB == nSum && nC == nSum && nD == nSum)
			return true;
	}
	if (nA > nSum || nB > nSum || nC > nSum || nD > nSum)
		return false;
	if (DFS(pnSeq, nM, nSum, nNow + 1,
		nA + pnSeq[nNow], nB, nC, nD))
		return true;
	if (DFS(pnSeq, nM, nSum, nNow + 1,
		nA, nB + pnSeq[nNow], nC, nD))
		return true;
	if (DFS(pnSeq, nM, nSum, nNow + 1,
		nA, nB, nC + pnSeq[nNow], nD))
		return true;
	if (DFS(pnSeq, nM, nSum, nNow + 1,
		nA, nB, nC, nD + pnSeq[nNow]))
		return true;
	return false;
}


int main(int argc, char* argv[])
{
	int					nInputT;
	int					nInputM;
	int*				pnSeq				= NULL;
	int					nSum				= 0;
	pnSeq = (int*)malloc(25 * sizeof(int));
	scanf("%d", &nInputT);
	while (nInputT--)
	{
		nSum = 0;
		scanf("%d", &nInputM);
		for (int i = 0; i < nInputM; i++)
		{
			scanf("%d", pnSeq + i);
			nSum += pnSeq[i];
		}
		if (nSum % 4 != 0)
		{
			printf("no\n");
			continue;
		}
		else
			nSum /= 4;
		sort(pnSeq, pnSeq + nInputM);
		if (DFS(pnSeq, nInputM, nSum, 0,
			0, 0, 0, 0))
			printf("yes\n");
		else
			printf("no\n");
	}

Exit0:

	return 0;
}