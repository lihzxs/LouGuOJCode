/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-15 16:26
//	Comment		:	OJ(P1824)
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
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

bool Check(int nNum, int* pnSeq, int nN, int nC)
{
	int nPre = pnSeq[0];
	int nCount = 0;
	for (int i = 1; i < nN; i++)
	{
		if (pnSeq[i] - nPre < nNum)
			nCount++;
		else
			nPre = pnSeq[i];
		if (nCount > nN - nC)
			return false;
	}
	return true;
}





int main(int argc, char* argv[])
{
	int			nInputN;
	int			nInputC;
	int*		pnSeq				= NULL;
	int			nMin;
	int			nLeft;
	int			nRight;
	int			nMid;
	scanf("%d%d", &nInputN, &nInputC);

	pnSeq = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeq + i);

	sort(pnSeq, pnSeq + nInputN);

	nMin = pnSeq[nInputN - 1] - pnSeq[0];

	for (int i = 1; i < nInputN; i++)
		nMin = min(pnSeq[i - 1] - pnSeq[i], nMin);

	nLeft = nMin;
	nRight = pnSeq[nInputN - 1] - pnSeq[0];

	while (nLeft + 1 < nRight)
	{
		nMid = (nLeft + nRight) / 2;
		if (Check(nMid, pnSeq, nInputN, nInputC))
			nLeft = nMid;
		else
			nRight = nMid;
	}
	if (Check(nLeft, pnSeq, nInputN, nInputC))
		printf("%d", nLeft);
	else
		printf("%d", nRight);

Exit0:

	return 0;
}