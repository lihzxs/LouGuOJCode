/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-25 23:17
//	Comment		:	OJ(P1342)
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




long long SPFA(int nStart, int nN,
	vector<pair<int, int> >* ppnMat)
{
	queue<int>	qSPFA;
	int			nTemp;
	int*		pnDis;
	int*		pnFlag;
	long long	nReAns;
	pnDis = (int*)malloc((nN + 1) * sizeof(int));
	pnFlag = (int*)malloc((nN + 1) * sizeof(int));

	for (int i = 0; i <= nN; i++)
		pnDis[i] = 2147483647;
	memset(pnFlag, 0, (nN + 1) * sizeof(int));

	pnDis[nStart] = 0;
	qSPFA.push(nStart);
	pnFlag[nStart] = 1;

	while (!qSPFA.empty())
	{
		nTemp = qSPFA.front();
		qSPFA.pop();
		pnFlag[nTemp] = 0;

		for (int i = 0; i < ppnMat[nTemp].size(); i++)
		{
			if (pnDis[nTemp] + ppnMat[nTemp][i].second < pnDis[ppnMat[nTemp][i].first])
			{
				pnDis[ppnMat[nTemp][i].first] = pnDis[nTemp] + ppnMat[nTemp][i].second;
				if (!pnFlag[ppnMat[nTemp][i].first])
				{
					qSPFA.push(ppnMat[nTemp][i].first);
					pnFlag[ppnMat[nTemp][i].first] = 1;
				}
			}
		}
	}

	nReAns = 0;

	for (int i = 1; i <= nN; i++)
		nReAns += pnDis[i];
	return nReAns;
}


int main(int argc, char* argv[])
{
	int					nN;
	int					nM;
	int					nK;
	int					nStart;
	int					nEnd;
	int					nLong;
	int					nTemp;
	long long			llAns = 0;
	int					nNum;

	scanf("%d%d", &nN, &nM);

	vector<pair<int, int> >* ppnMat1;

	ppnMat1 = new vector<pair<int, int> >[nN + 1];
	vector<pair<int, int> >* ppnMat2;

	ppnMat2 = new vector<pair<int, int> >[nN + 1];

	for (int i = 0; i < nM; i++)
	{
		scanf("%d%d%d", &nStart, &nEnd, &nLong);
		ppnMat1[nStart].push_back({ nEnd, nLong });
		ppnMat2[nEnd].push_back({ nStart, nLong });
	}

	llAns += SPFA(1, nN, ppnMat1);
	llAns += SPFA(1, nN, ppnMat2);

	printf("%lld", llAns);

Exit0:

	return 0;
}