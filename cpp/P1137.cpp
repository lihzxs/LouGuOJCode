/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-22 23:25
//	Comment		:	OJ(P1137)
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
#define MODNUM		2e64


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
	int*				pnFlag = NULL;


	scanf("%d%d", &nInputN, &nInputM);

	vecMat = new vector<int>[nInputN + 1];
	pnEnter = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnEnter, 0, (nInputN + 1) * sizeof(int));
	pnFlag = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnFlag, 0, (nInputN + 1) * sizeof(int));


	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d", &nStrat, &nEnd);
		vecMat[nStrat].push_back(nEnd);
		pnEnter[nEnd]++;
	}

	for (int i = 1; i <= nInputN; i++)
		if (pnEnter[i] == 0)
		{
			qTopu.push(i);
			pnFlag[i] = 1;
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
				pnFlag[vecMat[nTemp][i]] = pnFlag[nTemp] + 1;
				qTopu.push(vecMat[nTemp][i]);
			}
				
		}
	}

	for (int i = 1; i <= nInputN; i++)
		printf("%d\n", pnFlag[i]);

Exit0:
	return 0;
}