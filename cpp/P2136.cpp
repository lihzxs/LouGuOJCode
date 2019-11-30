/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-12 00:56
//	Comment		:	OJ(P2136)
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

void SPFA(int* pnDis, int* pnCount,int* pnFlag,int nStart, int nN,
	vector<pair<int, int> >* ppnMat)
{
	queue<int>	qSPFA;
	int			nTemp;
	for (int i = 0; i <= nN; i++)
		pnDis[i] = 2147483647;
	memset(pnFlag, 0, (nN + 1) * sizeof(int));
	memset(pnCount, 0, (nN + 1) * sizeof(int));

	pnDis[nStart] = 0;
	qSPFA.push(nStart);
	pnFlag[nStart] = 1;

	while (!qSPFA.empty())
	{
		nTemp = qSPFA.front();
		qSPFA.pop();
		pnFlag[nTemp] = 0;
		if (pnCount[nTemp] > nN)
		{
			printf("Forever love");
			exit(0);
		}
		for (int i = 0; i < ppnMat[nTemp].size(); i++)
		{
			if (pnDis[nTemp] + ppnMat[nTemp][i].second < pnDis[ppnMat[nTemp][i].first])
			{
				pnDis[ppnMat[nTemp][i].first] = pnDis[nTemp] + ppnMat[nTemp][i].second;
				if (!pnFlag[ppnMat[nTemp][i].first])
				{
					qSPFA.push(ppnMat[nTemp][i].first);
					pnCount[ppnMat[nTemp][i].first]++;
					pnFlag[ppnMat[nTemp][i].first] = 1;
				}
			}
		}
	}


}

int main(int argc, char* argv[])
{
	int			nInputN;
	int			nInputM;
	vector<pair<int, int> >	ppnMat[1005];
	int*		pnDis = NULL;
	int*		pnFlag = NULL;
	int*		pnCount = NULL;
	int			nStart;
	int			nEnd;
	int			nLong;
	int			nMin;
	int			nPoint;
	int			nS;
	int			nE;

	scanf("%d%d", &nInputN, &nInputM);

	pnDis = (int*)malloc((nInputN + 1) * sizeof(int));
	

	pnFlag = (int*)malloc((nInputN + 1) * sizeof(int));
	pnCount = (int*)malloc((nInputN + 1) * sizeof(int));
	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d%d", &nStart, &nEnd, &nLong);
		ppnMat[nStart].push_back({ nEnd, -nLong });
	}
	SPFA(pnDis, pnCount, pnFlag, 1, nInputN, ppnMat);
	nMin = pnDis[nInputN];
	SPFA(pnDis, pnCount, pnFlag, nInputN, nInputN, ppnMat);
	nMin = min(nMin, pnDis[1]);
	printf("%d", nMin);
Exit0:

	return 0;
}