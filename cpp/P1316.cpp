/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-3 14:40
//	Comment		:	OJ(P1316)
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

bool Check(int* pnSeq, int nA, int nB, int nX)
{
	int nCount = 0;
	int nPre = pnSeq[0];
	for (int i = 1; i < nA; i++)
	{
		if (pnSeq[i] - nPre < nX)
			nCount++;
		else
			nPre = pnSeq[i];
		if (nCount > nA - nB)
			return false;
	}
	return true;
}




int main(int argc, char* argv[])
{
	int			nInputA;
	int			nInputB;
	int*		pnSeq			= NULL;
	int			nLeft;
	int			nRight;
	int			nMid;

	scanf("%d%d", &nInputA, &nInputB);

	pnSeq = (int*)malloc(nInputA * sizeof(int));

	for (int i = 0; i < nInputA; i++)
		scanf("%d", pnSeq + i);

	sort(pnSeq, pnSeq + nInputA);
	nLeft = 1;
	nRight = pnSeq[nInputA - 1] - pnSeq[0];

	while(nLeft <= nRight)
	{
		nMid = (nLeft + nRight) / 2;
		if (Check(pnSeq, nInputA, nInputB, nMid))
			nLeft = nMid + 1;
		else
			nRight = nMid - 1;
	}

	if (Check(pnSeq, nInputA, nInputB, nMid))
		printf("%d", nMid);
	else if (Check(pnSeq, nInputA, nInputB, nRight))
		printf("%d", nRight);
	else
		printf("%d", nLeft - 1);


Exit0:
	return 0;
}