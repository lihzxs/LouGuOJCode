/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-13 00:57
//	Comment		:	OJ(P1821)
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
	vector<pair<int, int> > *		ppnMatF;
	vector<pair<int, int> > *		ppnMatS;
	int*		pnDisF = NULL;
	int*		pnDisS = NULL;
	int*		pnFlag = NULL;
	int			nStart;
	int			nEnd;
	int			nLong;
	int			nMin;
	int			nPoint;
	int			nS;
	scanf("%d%d%d", &nInputN, &nInputM, &nS);

	ppnMatF = new vector<pair<int, int> >[nInputN + 1];
	ppnMatS = new vector<pair<int, int> >[nInputN + 1];
	pnDisF = (int*)malloc((nInputN + 1) * sizeof(int));
	for (int i = 0; i <= nInputN; i++)
		pnDisF[i] = 2147483647;
	pnDisS = (int*)malloc((nInputN + 1) * sizeof(int));
	for (int i = 0; i <= nInputN; i++)
		pnDisS[i] = 2147483647;

	pnFlag = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnFlag, 0, (nInputN + 1) * sizeof(int));

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d%d", &nStart, &nEnd, &nLong);
		ppnMatF[nStart].push_back({ nEnd, nLong });
		ppnMatS[nEnd].push_back({ nStart, nLong });
	}



	nStart = nS;
	pnDisF[nStart] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	q.push({ 0, nStart });

	while (!q.empty())
	{
		int nIndex;
		int	nDis;
		nDis = q.top().first;
		nIndex = q.top().second;
		q.pop();
		if (pnFlag[nIndex])
			continue;
		pnFlag[nIndex] = 1;

		for (int j = 0; j < ppnMatF[nIndex].size(); j++)
		{
			if (pnDisF[ppnMatF[nIndex][j].first] > pnDisF[nIndex] + ppnMatF[nIndex][j].second)
			{
				pnDisF[ppnMatF[nIndex][j].first] = pnDisF[nIndex] + ppnMatF[nIndex][j].second;
				if (!pnFlag[ppnMatF[nIndex][j].first])
					q.push({ pnDisF[ppnMatF[nIndex][j].first], ppnMatF[nIndex][j].first });
			}
		}

	}
	memset(pnFlag, 0, (nInputN + 1) * sizeof(int));
	pnDisS[nStart] = 0;
	q.push({ 0, nStart });

	while (!q.empty())
	{
		int nIndex;
		int	nDis;
		nDis = q.top().first;
		nIndex = q.top().second;
		q.pop();
		if (pnFlag[nIndex])
			continue;
		pnFlag[nIndex] = 1;

		for (int j = 0; j < ppnMatS[nIndex].size(); j++)
		{
			if (pnDisS[ppnMatS[nIndex][j].first] > pnDisS[nIndex] + ppnMatS[nIndex][j].second)
			{
				pnDisS[ppnMatS[nIndex][j].first] = pnDisS[nIndex] + ppnMatS[nIndex][j].second;
				if (!pnFlag[ppnMatS[nIndex][j].first])
					q.push({ pnDisS[ppnMatS[nIndex][j].first], ppnMatS[nIndex][j].first });
			}
		}

	}

	int nAns = 0;
	for (int i = 1; i <= nInputN; i++)
		nAns = max(nAns, pnDisF[i] + pnDisS[i]);

	printf("%d", nAns);

Exit0:

	return 0;
}