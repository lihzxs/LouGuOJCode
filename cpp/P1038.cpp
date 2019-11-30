/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-23 22:08
//	Comment		:	OJ(P1038)
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
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;



int main(int argc, char* argv[])
{
	queue<int>			qTopu;
	int					nInputN;
	int					nInputP;
	int					nStrat;
	int					nEnd;
	int					nLong;
	int					nTemp;
	vector<pair<int, int> >*		vecMat = NULL;
	int*				pnEnter = NULL;
	int*				pnNow = NULL;
	int*				pnU = NULL;

	scanf("%d%d", &nInputN, &nInputP);

	vecMat = new vector<pair<int, int> >[nInputN + 1];
	pnEnter = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnEnter, 0, (nInputN + 1) * sizeof(int));
	pnNow = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnNow, 0, (nInputN + 1) * sizeof(int));
	pnU = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnU, 0, (nInputN + 1) * sizeof(int));

	for (int i = 1; i <= nInputN; i++)
	{
		scanf("%d%d", pnNow + i, pnU + i);
		pnU[i] = -pnU[i];
	}


	for (int i = 0; i < nInputP; i++)
	{
		scanf("%d%d%d", &nStrat, &nEnd, &nLong);
		vecMat[nStrat].push_back({ nEnd, nLong });
		pnEnter[nEnd]++;
	}

	for (int i = 1; i <= nInputN; i++)
		if (pnEnter[i] == 0 && pnNow[i])
			qTopu.push(i);



	while (!qTopu.empty())
	{
		nTemp = qTopu.front();
		qTopu.pop();
		for (int i = 0; i < vecMat[nTemp].size(); i++)
		{
			pnU[nTemp] = 0;
			pnEnter[vecMat[nTemp][i].first]--;

			pnU[vecMat[nTemp][i].first] += vecMat[nTemp][i].second * pnNow[nTemp];

			if (pnEnter[vecMat[nTemp][i].first] == 0 &&
				pnU[vecMat[nTemp][i].first] > 0)
			{
				qTopu.push(vecMat[nTemp][i].first);
				pnNow[vecMat[nTemp][i].first] = pnU[vecMat[nTemp][i].first];
			}

		}

	}
	int nFlag = 1;
	if (nInputP == 0)
	{
		for (int i = 1; i <= nInputN; i++)
		{
			if (pnNow[i] > 0)
			{
				nFlag = 0;
				printf("%d %d\n", i, pnNow[i]);
			}
		}
	}
	else
		for (int i = 1; i <= nInputN; i++)
		{
			if (pnU[i] > 0)
			{
				nFlag = 0;
				printf("%d %d\n", i, pnU[i]);
			}
		}
	if (nFlag)
		printf("NULL");



Exit0:
	return 0;
}