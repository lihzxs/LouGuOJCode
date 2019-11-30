/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-11 23:11
//	Comment		:	OJ(P1158)
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

int			nX1, nX2, nY1, nY2;

bool Cmp(pair<int, int>& pFirst, pair<int, int>& pSecond)
{
	int nDisFirst;
	int nDisSecond;
	nDisFirst = (nX1 - pFirst.first) * (nX1 - pFirst.first) + (nY1 - pFirst.second) * (nY1 - pFirst.second);
	nDisSecond = (nX1 - pSecond.first) * (nX1 - pSecond.first) + (nY1 - pSecond.second) * (nY1 - pSecond.second);
	return nDisFirst < nDisSecond;
}



int main(int argc, char* argv[])
{
	int				nInputN;
	int				nAns			 = 0;
	pair<int, int>*	prSeq			 = NULL;
	int				nDis;
	int*			pnDis			 = NULL;
	int				nTemp;
	scanf("%d%d%d%d", &nX1, &nY1, &nX2, &nY2);
	scanf("%d", &nInputN);
	prSeq = new pair<int, int>[nInputN];
	pnDis = (int*)malloc((nInputN + 1) * sizeof(int));
	pnDis[nInputN] = 0;
	for (int i = 0; i < nInputN; i++)
		scanf("%d%d", &prSeq[i].first, &prSeq[i].second);

	sort(prSeq, prSeq + nInputN, Cmp);

	for (int i = nInputN - 1; i >= 0; i--)
	{
		nDis = (nX2 - prSeq[i].first) * (nX2 - prSeq[i].first) +
			(nY2 - prSeq[i].second) * (nY2 - prSeq[i].second);

		pnDis[i] = max(pnDis[i + 1], nDis);
	}
	nAns = pnDis[0];

	for (int i = 0; i < nInputN; i++)
	{
		nTemp = 0;
		nTemp = (nX1 - prSeq[i].first) * (nX1 - prSeq[i].first) +
			(nY1 - prSeq[i].second) * (nY1 - prSeq[i].second);
		nTemp += pnDis[i + 1];
		nAns = min(nAns, nTemp);
	}

	nAns = min(nAns, pnDis[0]);

	printf("%d", nAns);
Exit0:

	return 0;
}