/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-14 00:36
//	Comment		:	OJ(P2855)
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

int Check(int* pnSeq, int nN, int nX)
{
	int nPre = -1;
	int	nC = 0;
	int	nTemp;

	for (int i = 0; i <= nN; i++)
	{
		if (nPre == -1)
			nTemp = 0;
		else
			nTemp = pnSeq[nPre];
		if (pnSeq[i] - nTemp < nX)
			nC++;
		else
			nPre = i;
	}
	return nC;
}




int main(int argc, char* argv[])
{
	int				nN;
	int				nM;
	int				nL;
	int*			pnSeq				= NULL;
	int				nLeft;
	int				nRight;
	int				nMid;
	scanf("%d%d%d", &nL, &nN, &nM);

	pnSeq = (int*)malloc((nN + 1) * sizeof(int));

	for (int i = 0; i < nN; i++)
		scanf("%d", pnSeq + i);

	sort(pnSeq, pnSeq + nN);

	pnSeq[nN] = nL;

	nLeft = 1;
	nRight = nL;

	while (nLeft <= nRight)
	{
		nMid = (nLeft + nRight) / 2;
		if (Check(pnSeq, nN, nMid) <= nM)
			nLeft = nMid + 1;
		else
			nRight = nMid - 1;
	}

	printf("%d", nLeft - 1);
Exit0:

	return 0;
}