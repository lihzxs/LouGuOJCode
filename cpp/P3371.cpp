/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-6 22:55
//	Comment		:	OJ(P3371)
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
	map<int, vector<pair<int, int> > >		ppnMat;
	int*		pnDis = NULL;
	int*		pnFlag = NULL;
	int			nStart;
	int			nEnd;
	int			nLong;
	int			nMin;
	int			nPoint;
	int			nS;
	scanf("%d%d%d", &nInputN, &nInputM, &nS);


	pnDis = (int*)malloc((nInputN + 1) * sizeof(int));
	for (int i = 0; i <= nInputN; i++)
		pnDis[i] = 2147483647;

	pnFlag = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnFlag, 0, (nInputN + 1) * sizeof(int));

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d%d", &nStart, &nEnd, &nLong);
		ppnMat[nStart].push_back({ nEnd, nLong });
	}

	

	nStart = nS;
	pnDis[nStart] = 0;

	for (int i = 1; i <= nInputN; i++)
	{

		nMin = pnDis[0];
		for (int j = 1; j <= nInputN; j++)
		{
			if (pnDis[j] < nMin && pnFlag[j] == false)
			{
				nMin = pnDis[j];
				nPoint = j;
			}
		}

		pnFlag[nPoint] = true;

		for (int j = 0; j < ppnMat[nPoint].size(); j++)
		{
			if (pnDis[ppnMat[nPoint][j].first] > pnDis[nPoint] + ppnMat[nPoint][j].second &&
				pnFlag[ppnMat[nPoint][j].first] == false)
				pnDis[ppnMat[nPoint][j].first] = pnDis[nPoint] + ppnMat[nPoint][j].second;
		}
	}


	for (int i = 1; i <= nInputN; i++)
		printf("%d ", pnDis[i]);

Exit0:

	return 0;
}