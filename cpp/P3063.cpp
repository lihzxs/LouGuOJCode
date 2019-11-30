/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-24 00:07
//	Comment		:	OJ(P3063)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
#include <set>
#include <queue>
#include <list>
#include <map>

using namespace std;
#define	MAXNUM		100000000
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int SPFA(int nN, int nX, int nW,
	vector<pair<int, pair<int, int> > >* ppnMat)
{
	queue<int>	qSPFA;
	int			nTemp;
	int*		pnFlag;
	int*		pnDis;


	pnFlag = (int*)malloc((nN + 1) * sizeof(int));
	pnDis = (int*)malloc((nN + 1) * sizeof(int));
	memset(pnFlag, 0, (nN + 1) * sizeof(int));
	for (int i = 0; i <= nN; i++)
		pnDis[i] = 2000000000;


	pnDis[1] = 0;
	qSPFA.push(1);
	pnFlag[1] = 1;

	while (!qSPFA.empty())
	{
		nTemp = qSPFA.front();
		qSPFA.pop();
		pnFlag[nTemp] = 0;
		for (int i = 0; i < ppnMat[nTemp].size(); i++)
		{
			if (pnDis[nTemp] + ppnMat[nTemp][i].second.first < 
				pnDis[ppnMat[nTemp][i].first] && ppnMat[nTemp][i].second.second >= nW)
			{
				pnDis[ppnMat[nTemp][i].first] = pnDis[nTemp] + ppnMat[nTemp][i].second.first;
				if (!pnFlag[ppnMat[nTemp][i].first])
				{
					qSPFA.push(ppnMat[nTemp][i].first);
					pnFlag[ppnMat[nTemp][i].first] = 1;
				}
			}
		}
	}

	return (pnDis[nN] + nX / nW);
}

int main(int argc, char* argv[])
{
	int				nN;
	int				nM;
	int				nX;
	int				nStart;
	int				nEnd;
	int				nL;
	int				nC;
	int*			pnC;
	int				nMin					= 2000000000;
	vector<pair<int, pair<int, int> > >*		ppnMat;

	scanf("%d%d%d", &nN, &nM, &nX);

	ppnMat = new vector<pair<int, pair<int, int> > >[nN + 1];
	pnC = (int*)malloc((nM + 1) * sizeof(int));
	for (int i = 1; i <= nM; i++)
	{
		scanf("%d%d%d%d", &nStart, &nEnd, &nL, &nC);
		pnC[i] = nC;
		ppnMat[nStart].push_back({ nEnd, {nL, nC} });
		ppnMat[nEnd].push_back({ nStart, {nL, nC} });
	}

	for (int i = 1; i <= nM; i++)
	{
		int nTemp = SPFA(nN, nX, pnC[i], ppnMat);
		nMin = min(nMin, nTemp);
	}
		

	printf("%d", nMin);


Exit0:
	return 0;
}