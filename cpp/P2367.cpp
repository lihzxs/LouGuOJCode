/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-2 16:31
//	Comment		:	OJ(P2367)
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
int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputQ;
	int				nLeft;
	int				nRight;
	int				nVal;
	int				nMin				= 1000;
	int*			pnDis				= NULL;
	int*			pnSeq				= NULL;

	scanf("%d%d", &nInputN, &nInputQ);

	pnDis = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnDis, 0, (nInputN + 1) * sizeof(int));
	pnSeq = (int*)malloc((nInputN + 1) * sizeof(int));
	for (int i = 1; i <= nInputN; i++)
		scanf("%d", pnSeq + i);
	pnSeq[0] = 0;

	for (int i = nInputN; i > 1; i--)
		pnSeq[i] = pnSeq[i] - pnSeq[i - 1];

	while (nInputQ--)
	{
		scanf("%d%d%d", &nLeft, &nRight, &nVal);
		pnSeq[nLeft] += nVal;
		pnSeq[nRight + 1] -= nVal;
	}
	nMin = pnSeq[1];
	for (int i = 2; i <= nInputN; i++)
	{
		pnSeq[i] += pnSeq[i - 1];
		nMin = min(nMin, pnSeq[i]);
	}

	printf("%d", nMin);

Exit0:

	return 0;
}