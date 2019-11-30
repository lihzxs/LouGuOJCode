/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-25 16:39
//	Comment		:	OJ(P2384)
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
	int			nInputM;
	vector<pair<int, int> > *		ppnMat;
	long long*	pnDis = NULL;
	int*		pnFlag = NULL;
	int			nStart;
	int			nEnd;
	int			nLong;
	int			nMin;
	int			nPoint;
	int			nS;
	scanf("%d%d", &nInputN, &nInputM);
	ppnMat = new vector<pair<int, int> >[nInputN + 2];

	pnDis = (long long*)malloc((nInputN + 1) * sizeof(long long));
	for (int i = 0; i <= nInputN; i++)
		pnDis[i] = INT64_MAX;

	pnFlag = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnFlag, 0, (nInputN + 1) * sizeof(int));

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d%d", &nStart, &nEnd, &nLong);
		ppnMat[nStart].push_back({ nEnd, nLong });
		ppnMat[nEnd].push_back({ nStart, nLong });
	}



	nStart = 1;
	pnDis[nStart] = 1;
	priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > q;
	q.push({ 0, nStart });

	while (!q.empty())
	{
		int nIndex;
		long long	nDis;
		nDis = q.top().first;
		nIndex = q.top().second;
		q.pop();
		if (pnFlag[nIndex])
			continue;
		pnFlag[nIndex] = 1;

		for (int j = 0; j < ppnMat[nIndex].size(); j++)
		{
			if (pnDis[ppnMat[nIndex][j].first] > pnDis[nIndex] * ppnMat[nIndex][j].second)
			{
				pnDis[ppnMat[nIndex][j].first] = pnDis[nIndex] * ppnMat[nIndex][j].second % 9987;
				if (!pnFlag[ppnMat[nIndex][j].first])
					q.push({ -pnDis[ppnMat[nIndex][j].first], ppnMat[nIndex][j].first });
			}
		}

	}
	printf("%lld ", pnDis[nInputN]);

Exit0:

	return 0;
}