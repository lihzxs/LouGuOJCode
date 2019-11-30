/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-21 16:28
//	Comment		:	OJ(P2677)
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
#define	MAXNUM		150
#define	EPS         0.0001
#define MODNUM		1000000007ll


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

void DFS(int* pnSeq, int nNum, BYTE* pbyIsUse,int nSum, int nInputB, int& nMin)
{
	if (nSum >= nInputB)
	{
		if (nMin > nSum - nInputB)
			nMin = nSum - nInputB;
		return;
	}

	for (int i = 0; i < nNum; i++)
	{
		if (!pbyIsUse[i])
		{
			pbyIsUse[i] = true;
			DFS(pnSeq, nNum, pbyIsUse, nSum + pnSeq[i], nInputB, nMin);
			pbyIsUse[i] = false;
		}
	}

	
}



int main(int argc, char* argv[])
{
	int					nInputN;
	int					nInputB;

	int*				pnSeq				= NULL;
	BYTE*				pbySeq				= NULL;
	int					nMin				= 1e7;
	scanf("%d%d", &nInputN, &nInputB);

	pnSeq = (int*)malloc(nInputN * sizeof(int));
	pbySeq = (BYTE*)malloc(nInputN * sizeof(BYTE));
	memset(pbySeq, 0, nInputN * sizeof(BYTE));
	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeq + i);

	DFS(pnSeq, nInputN, pbySeq, 0, nInputB, nMin);

	printf("%d", nMin);




Exit0:

	return 0;
}