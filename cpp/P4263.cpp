/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-11 00:19
//	Comment		:	OJ(P4263)
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
	int				nInputT;
	int				nTemp;
	int				nCount;
	pair<int, int>*	prSeq;
	map<int, int>	mpCount;
	scanf("%d", &nInputT);
	while (nInputT--)
	{
		scanf("%d", &nInputN);
		nCount = 0;
		for (int i = 0; i < nInputN; i++)
		{
			scanf("%d", &nTemp);
			mpCount[nTemp]++;
		}
		map<int, int>::iterator iter;
		nTemp = mpCount.size();
		prSeq = new pair<int, int>[nTemp];
		for (iter = mpCount.begin(); iter != mpCount.end(); iter++)
		{
			prSeq[nCount].first = (*iter).second;
			prSeq[nCount].second = (*iter).first;
			nCount++;
		}
			
		sort(prSeq, prSeq + nCount);
		if (prSeq[0].first == prSeq[nTemp - 1].first)
		{
			printf("-1\n");
			mpCount.clear();
			delete prSeq;
			continue;
		}
		nCount = 0;
		for (int i = 0; i < nTemp; i++)
		{
			if (prSeq[i].first == prSeq[nTemp - 1].first)
				nCount++;
		}
		printf("%d\n", nCount);
		for (int i = nTemp - nCount; i < nTemp; i++)
		{
			printf("%d ", prSeq[i].second);
		}
		printf("\n");
		mpCount.clear();
		delete prSeq;
	}

Exit0:

	return 0;
}