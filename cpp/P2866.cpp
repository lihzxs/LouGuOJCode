/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-19 21:40
//	Comment		:	OJ(P2866)
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
	int					nInputN;
	int*				pnSeq					= NULL;
	int*				pnNext					= NULL;
	int					nTemp;
	long long			llAns					= 0;
	
	scanf("%d", &nInputN);

	pnSeq = (int*)malloc((nInputN + 2) * sizeof(int));
	pnNext = (int*)malloc((nInputN + 2) * sizeof(int));
	memset(pnSeq, 0, (nInputN + 2) * sizeof(int));
	memset(pnNext, 0, (nInputN + 2) * sizeof(int));

	for (int i = 1; i <= nInputN; i++)
		scanf("%d", pnSeq + i);

	pnSeq[nInputN + 1] = INT32_MAX;

	for (int i = nInputN; i > 0; i--)
	{
		nTemp = i + 1;
		while (pnSeq[i] > pnSeq[nTemp] && nTemp != 0)
			nTemp = pnNext[nTemp];
		pnNext[i] = nTemp;
		llAns += nTemp - i - 1;
	}

	printf("%lld", llAns);

Exit0:

	return 0;
}