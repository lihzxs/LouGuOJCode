/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-27 16:38
//	Comment		:	OJ(P2782)
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
	int				nAns;
	int				nMax				= 0;
	int				nTemp;
	int*			pnCount				= NULL;
	pair<int, int>*	pprSeq				= NULL;

	scanf("%d", &nInputN);

	pnCount = (int*)malloc(nInputN * sizeof(int));
	memset(pnCount, 0, nInputN * sizeof(int));

	pprSeq = new pair<int, int>[nInputN];

	for (int i = 0; i < nInputN; i++)
		scanf("%d%d", &pprSeq[i].first, &pprSeq[i].second);

	sort(pprSeq, pprSeq + nInputN);

	pnCount[0] = pprSeq[0].second;
	for (int i = 1; i < nInputN; i++)
	{
		nTemp = upper_bound(pnCount, pnCount + nMax + 1, pprSeq[i].second) - pnCount;
		pnCount[nTemp] = pprSeq[i].second;
		if (nTemp > nMax)
			nMax++;
	}

	printf("%d", nMax + 1);
Exit0:

	return 0;
}