/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-17 22:57
//	Comment		:	OJ(P1144)
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
	queue<int>					qBFS;
	vector<int>*				ppnMat = NULL;
	int							nInputN;
	int							nInputM;
	int							nA;
	int							nB;
	int							nTemp;
	int*						pnAns				= NULL;
	int*						pnDeep				= NULL;
	int*						pnFlag				= NULL;
	scanf("%d%d", &nInputN, &nInputM);

	pnAns = (int*)malloc((nInputN + 1) * sizeof(int));
	pnFlag = (int*)malloc((nInputN + 1) * sizeof(int));
	pnDeep = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnFlag, 0, (nInputN + 1) * sizeof(int));
	memset(pnAns, 0, (nInputN + 1) * sizeof(int));
	memset(pnDeep, 0, (nInputN + 1) * sizeof(int));

	ppnMat = new vector<int>[nInputN + 1];

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d", &nA, &nB);
		ppnMat[nA].push_back(nB);
		ppnMat[nB].push_back(nA);
	}

	qBFS.push(1);
	pnDeep[1] = 1;
	pnAns[1] = 1;
	pnFlag[1] = 1;

	while (!qBFS.empty())
	{
		nTemp = qBFS.front();
		qBFS.pop();
		for (int i = 0; i < ppnMat[nTemp].size(); i++)
		{
			if (!pnFlag[ppnMat[nTemp][i]])
			{
				pnFlag[ppnMat[nTemp][i]] = 1;
				pnDeep[ppnMat[nTemp][i]] = pnDeep[nTemp] + 1;
				qBFS.push(ppnMat[nTemp][i]);
			}
			if (pnDeep[ppnMat[nTemp][i]] == pnDeep[nTemp] + 1)
			{
				pnAns[ppnMat[nTemp][i]] =
					(pnAns[ppnMat[nTemp][i]] + pnAns[nTemp]) % 100003;
			}
		}
	}

	for (int i = 1; i <= nInputN; i++)
		printf("%d\n", pnAns[i]);
Exit0:

	return 0;
}