/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-19 23:07
//	Comment		:	OJ(P2678)
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

bool Check(int* pnSeq, int nN, int nM, int nX)
{
	int nCount = 0;
	int nPre = 0;
	for (int i = 1; i <= nN + 1; i++)
	{
		if (pnSeq[i] - nPre < nX)
			nCount++;
		else
			nPre = pnSeq[i];
		if (nCount > nM)
			return false;
	}
	return true;
	
}


int main(int argc, char* argv[])
{
	int				nInputL;
	int				nInputN;
	int				nInputM;
	int				nLeft;
	int				nRight;
	int				nMid;
	int*			pnSeq				= NULL;

	scanf("%d%d%d", &nInputL, &nInputN, &nInputM);

	pnSeq = (int*)malloc((nInputN + 2) * sizeof(int));

	for (int i = 1; i <= nInputN; i++)
		scanf("%d", pnSeq + i);
	pnSeq[0] = 0;
	pnSeq[nInputN + 1] = nInputL;

	nLeft = 1;
	nRight = nInputL;

	while (nLeft <= nRight)
	{
		nMid = (nLeft + nRight) / 2;
		if (Check(pnSeq, nInputN, nInputM, nMid))
			nLeft = nMid + 1;
		else
			nRight = nMid - 1;
	}


	printf("%d", nLeft - 1);

Exit0:

	return 0;
}