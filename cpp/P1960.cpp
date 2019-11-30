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
	int*				pnCount = NULL;
	int*				pnQuit = NULL;
	int					nC;
	int					nFlag			= 0;

	scanf("%d%d", &nInputN, &nInputM);

	vecMat = new vector<int>[nInputN + 1];
	pnEnter = (int*)malloc((nInputN + 1) * sizeof(int));
	pnQuit = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnEnter, 0, (nInputN + 1) * sizeof(int));
	memset(pnQuit, 0, (nInputN + 1) * sizeof(int));
	pnCount = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnCount, 0, (nInputN + 1) * sizeof(int));

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d", &nStrat, &nEnd);
		vecMat[nStrat].push_back(nEnd);
		pnEnter[nEnd]++;
		pnQuit[nStrat]++;
	}

	nC = 0;
	for (int i = 1; i <= nInputN; i++)
		if (pnEnter[i] == 0)
		{
			nC++;
			qTopu.push(i);
		}

	nFlag = nC > 1;



	while (!qTopu.empty())
	{
		nTemp = qTopu.front();
		qTopu.pop();
		printf("%d\n", nTemp);
		nC = 0;
		for (int i = 0; i < vecMat[nTemp].size(); i++)
		{
			pnEnter[vecMat[nTemp][i]]--;
			if (pnEnter[vecMat[nTemp][i]] == 0)
			{
				qTopu.push(vecMat[nTemp][i]);
				nC++;
			}	
		}
		if (!nFlag)
			nFlag = nC > 1;
	}
	printf("%d", nFlag);

Exit0:
	return 0;
}