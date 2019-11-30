/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-17 21:04
//	Comment		:	OJ(P1807)
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

void SPFA(int* pnDis, int* pnFlag, int nStart, int nN,
	vector<pair<int, int> >* ppnMat)
{
	queue<int>	qSPFA;
	int			nTemp;
	memset(pnFlag, 0, (nN + 1) * sizeof(int));
	memset(pnDis, 0, (nN + 1) * sizeof(int));

	pnDis[nStart] = 0;
	qSPFA.push(nStart);

	while (!qSPFA.empty())
	{
		nTemp = qSPFA.front();
		qSPFA.pop();
		for (int i = 0; i < ppnMat[nTemp].size(); i++)
		{
			if (pnDis[nTemp] + ppnMat[nTemp][i].second > pnDis[ppnMat[nTemp][i].first])
			{
				pnDis[ppnMat[nTemp][i].first] = pnDis[nTemp] + ppnMat[nTemp][i].second;
				qSPFA.push(ppnMat[nTemp][i].first);

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
		ppnMat[nStart].push_back({ nEnd, nLong });
	}
	SPFA(pnDis, pnFlag, 1, nInputN, ppnMat);

	if (pnDis[nInputN] == 0)
		printf("-1");
	else
		printf("%d", pnDis[nInputN]);

Exit0:

	return 0;
}