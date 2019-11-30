/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-10 17:13
//	Comment		:	OJ(P3131)
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

using namespace std;
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		2000001


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;





int main(int argc, char* argv[])
{
	int			nInputN;
	int*		pnSeq				= NULL;
	int			nMax				= 0;
	int*		pnFirst				= NULL;
	scanf("%d", &nInputN);

	pnSeq = (int*)malloc((nInputN + 1) * sizeof(int));
	pnSeq[0] = 0;
	pnFirst = (int*)malloc(7 * sizeof(int));
	memset(pnFirst, 0, 7 * sizeof(int));
	for (int i = 1; i <= nInputN; i++)
	{
		scanf("%d", pnSeq + i);
		pnSeq[i] += pnSeq[i - 1];
		pnSeq[i] %= 7;
	}
	for (int i = nInputN; i >= 1; i--)
	{
		if (!pnFirst[pnSeq[i]])
			pnFirst[pnSeq[i]] = i;
	}
	for (int i = 1; i <= nInputN; i++)
	{
		if (pnFirst[pnSeq[i]] && pnFirst[pnSeq[i]] != i)
		{
			if (pnFirst[pnSeq[i]] - i > nMax)
				nMax = pnFirst[pnSeq[i]] - i;
		}
	}

	printf("%d", nMax);





Exit0:

	return 0;
}