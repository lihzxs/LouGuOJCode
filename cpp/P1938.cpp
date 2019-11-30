/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-23 17:33
//	Comment		:	OJ(P1938)
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
#include <float.h>

using namespace std;
#define	MAXNUM		1000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

void SPFA(int* pnDis, int nStart, int nN, int nD,
	vector<pair<int, int> >* ppnMat)
{
	queue<int>	qSPFA;
	int			nTemp;
	int*		pnFlag = NULL;
	int*		pnCount = NULL;
	

	pnFlag = (int*)malloc((nN + 1) * sizeof(int));
	pnCount = (int*)malloc((nN + 1) * sizeof(int));
	memset(pnFlag, 0, (nN + 1) * sizeof(int));
	memset(pnCount, 0, (nN + 1) * sizeof(int));
	memset(pnDis, 0, (nN + 1) * sizeof(int));
	pnDis[nStart] = nD;
	qSPFA.push(nStart);
	pnFlag[nStart] = 1;

	while (!qSPFA.empty())
	{
		nTemp = qSPFA.front();
		qSPFA.pop();
		pnFlag[nTemp] = 0;
		if (pnCount[nTemp] > nN)
		{
			printf("-1");
			exit(0);
		}
		for (int i = 0; i < ppnMat[nTemp].size(); i++)
		{
			if (pnDis[nTemp] + ppnMat[nTemp][i].second > pnDis[ppnMat[nTemp][i].first])
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
	int				nInputD;
	int				nInputP;
	int				nInputC;
	int				nInputF;
	int				nInputS;
	int				nStart;
	int				nEnd;
	int				nLong;
	int				nMax = 0;
	int*			pnDis = NULL;
	vector<pair<int, int> >*		vecMat;

	

	scanf("%d%d%d%d%d", &nInputD, &nInputP, 
		&nInputC, &nInputF, &nInputS);
	pnDis = (int*)malloc((nInputC + 1) * sizeof(int));
	memset(pnDis, 0, (nInputC + 1) * sizeof(int));
	vecMat = new vector<pair<int, int> >[nInputC + 1];

	for (int i = 1; i <= nInputP; i++)
	{
		scanf("%d%d", &nStart, &nEnd);
		vecMat[nStart].push_back({ nEnd, nInputD });
	}

	for (int i = 0; i < nInputF; i++)
	{
		scanf("%d%d%d", &nStart, &nEnd, &nLong);
		vecMat[nStart].push_back({ nEnd, nInputD - nLong });
	}

	SPFA(pnDis, nInputS, nInputC, nInputD,vecMat);

	for (int i = 1; i <= nInputC; i++)
		nMax = max(nMax, pnDis[i]);

	printf("%d", nMax);

Exit0:

	return 0;
}