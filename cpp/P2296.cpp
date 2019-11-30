/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-24 16:10
//	Comment		:	OJ(P2296)
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
#define	MAXNUM		100000000
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int main(int argc, char* argv[])
{
	int				nN;
	int				nM;
	int				nStart;
	int				nEnd;
	int				nTemp;
	queue<int>		qBFS;
	vector<int>*	vecMat = NULL;
	int*			pnFlag = NULL;
	int*			pnAnsF = NULL;
	int*			pnAns = NULL;
	scanf("%d%d", &nN, &nM);

	pnFlag = (int*)malloc((nN + 1) * sizeof(int));
	memset(pnFlag, 0, (nN + 1) * sizeof(int));
	pnAnsF = (int*)malloc((nN + 1) * sizeof(int));
	pnAns = (int*)malloc((nN + 1) * sizeof(int));
	memset(pnAns, 0, (nN + 1) * sizeof(int));

	vecMat = new vector<int>[nN + 1];

	for (int i = 0; i < nM; i++)
	{
		scanf("%d%d", &nStart, &nEnd);
		vecMat[nEnd].push_back(nStart);
	}

	scanf("%d%d", &nStart, &nEnd);
	qBFS.push(nEnd);
	pnFlag[nEnd] = 1;

	while (!qBFS.empty())
	{
		nTemp = qBFS.front();
		qBFS.pop();
		for (int i = 0; i < vecMat[nTemp].size(); i++)
		{
			if (pnFlag[vecMat[nTemp][i]])
				continue;
			qBFS.push(vecMat[nTemp][i]);
			pnFlag[vecMat[nTemp][i]] = 1;
		}
	}
	memcpy(pnAnsF, pnFlag, (nN + 1) * sizeof(int));

	for (int i = 1; i <= nN; i++)
	{
		if (pnFlag[i])
			continue;
		for (int j = 0; j < vecMat[i].size(); j++)
			if (pnAnsF[vecMat[i][j]])
				pnAnsF[vecMat[i][j]] = 0;
	}

	qBFS.push(nEnd);
	while (!qBFS.empty())
	{
		nTemp = qBFS.front();
		qBFS.pop();
		for (int i = 0; i < vecMat[nTemp].size(); i++)
		{
			if (!pnAnsF[vecMat[nTemp][i]])
				continue;
			qBFS.push(vecMat[nTemp][i]);
			pnAnsF[vecMat[nTemp][i]] = 0;
			pnAns[vecMat[nTemp][i]] = pnAns[nTemp] + 1;
		}
	}
	if (pnAns[nStart] == 0)
		printf("-1");
	else
		printf("%d", pnAns[nStart]);




Exit0:
	return 0;
}