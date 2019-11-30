/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-26 0:45
//	Comment		:	OJ(P2017)
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
	int					nP1;
	int					nP2;
	int					nC = 0;
	int*				pnCount = NULL;
	vector<int>*		vecMat = NULL;
	int*				pnEnter = NULL;


	scanf("%d%d%d", &nInputN, &nP1, &nP2);

	vecMat = new vector<int>[nInputN + 1];
	pnEnter = (int*)malloc((nInputN + 1) * sizeof(int));

	memset(pnEnter, 0, (nInputN + 1) * sizeof(int));
	pnCount = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnCount, 0, (nInputN + 1) * sizeof(int));


	for (int i = 0; i < nP1; i++)
	{
		scanf("%d%d", &nStrat, &nEnd);
		vecMat[nStrat].push_back(nEnd);
		pnEnter[nEnd]++;
	}

	for (int i = 1; i <= nInputN; i++)
		if (pnEnter[i] == 0)
		{
			qTopu.push(i);
			pnCount[i] = ++nC;
		}
			



	while (!qTopu.empty())
	{
		nTemp = qTopu.front();
		qTopu.pop();
		for (int i = 0; i < vecMat[nTemp].size(); i++)
		{
			pnEnter[vecMat[nTemp][i]]--;
			if (pnEnter[vecMat[nTemp][i]] == 0)
			{
				qTopu.push(vecMat[nTemp][i]);
				pnCount[vecMat[nTemp][i]] = ++nC;
			}
				
		}
	}

	for (int i = 0; i < nP2; i++)
	{
		scanf("%d%d", &nStrat, &nEnd);
		if (pnCount[nStrat] > pnCount[nEnd])
			printf("%d %d", nEnd, nStrat);
		else
			printf("%d %d", nStrat, nEnd);

		printf("\n");
	}

Exit0:
	return 0;
}