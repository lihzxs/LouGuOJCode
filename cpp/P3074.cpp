/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-15 23:47
//	Comment		:	OJ(P1960)
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
	int					nInputM;
	int					nStrat;
	int					nEnd;
	int					nTemp;
	vector<int>*		vecMat = NULL;
	int*				pnEnter = NULL;
	int*				pnTime = NULL;
	int*				pnUse = NULL;
	int*				pnBefore = NULL;
	int					nAns = 0;

	scanf("%d%d", &nInputN, &nInputM);

	vecMat = new vector<int>[nInputN + 1];
	pnEnter = (int*)malloc((nInputN + 1) * sizeof(int));
	pnTime = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnEnter, 0, (nInputN + 1) * sizeof(int));
	memset(pnTime, 0, (nInputN + 1) * sizeof(int));
	pnUse = (int*)malloc((nInputN + 1) * sizeof(int));
	pnBefore = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnUse, 0, (nInputN + 1) * sizeof(int));
	memset(pnBefore, 0, (nInputN + 1) * sizeof(int));

	for (int i = 1; i <= nInputN; i++)
		scanf("%d", pnTime + i);

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d", &nStrat, &nEnd);
		vecMat[nStrat].push_back(nEnd);
		pnEnter[nEnd]++;
	}

	for (int i = 1; i <= nInputN; i++)
	if (pnEnter[i] == 0)
		qTopu.push(i);

	while (!qTopu.empty())
	{
		nTemp = qTopu.front();
		qTopu.pop();
		pnUse[nTemp] = pnBefore[nTemp] + pnTime[nTemp];
		nAns = max(pnUse[nTemp], nAns);
		for(int i = 0; i < vecMat[nTemp].size(); i++)
		{
			pnEnter[vecMat[nTemp][i]]--;
			pnBefore[vecMat[nTemp][i]] = max(pnBefore[vecMat[nTemp][i]], pnUse[nTemp]);
			if(pnEnter[vecMat[nTemp][i]] == 0)
				qTopu.push(vecMat[nTemp][i]);
		}

	}

	printf("%d", nAns);

Exit0:
	return 0;
}