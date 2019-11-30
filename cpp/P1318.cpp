/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-28 21:42
//	Comment		:	OJ(P1318)
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
	int			nInputN;
	int*		pnSeq				= NULL;
	scanf("%d", &nInputN);
	int			nAns				= 0;
	pnSeq = (int*)malloc(nInputN * sizeof(int));
	int			nSum				= 0;
	int			nMax				= 0;
	int			nStart;
	int			nEnd;
	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", pnSeq + i);
		nMax = max(nMax, pnSeq[i]);
		nAns += pnSeq[i];
	}
		

	for (int i = 1; i <= nMax; i++)
	{
		nStart = 0;
		nEnd = nInputN - 1;
		while (pnSeq[nStart] < i)
			nStart++;
		while (pnSeq[nEnd] < i)
			nEnd--;
		nSum += nEnd - nStart + 1;
	}

	printf("%d", nSum - nAns);



Exit0:

	return 0;
}