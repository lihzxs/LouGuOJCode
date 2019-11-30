/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-24 18:55
//	Comment		:	OJ(P1983)
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
	int					nN;
	int					nM;
	int**				ppnMat			= NULL;
	int*				pnFlag			= NULL;
	int**				ppnLink			= NULL;
	int*				pnEnter			= NULL;
	vector<int>*		vecMat			= NULL;
	int					nTemp;
	scanf("%d%d", &nN, &nM);
	vecMat = new vector<int>[nN + 1];
	ppnMat = (int**)malloc((nM + 1) * sizeof(int*));
	ppnLink = (int**)malloc((nN + 1) * sizeof(int*));
	pnFlag = (int*)malloc((nN + 1) * sizeof(int));
	pnEnter = (int*)malloc((nN + 1) * sizeof(int));
	memset(pnEnter, 0, (nN + 1) * sizeof(int));
	for (int i = 0; i <= nN; i++)
	{
		ppnLink[i] = (int*)malloc((nN + 1) * sizeof(int));
		memset(ppnLink[i], 0, (nN + 1) * sizeof(int));
	}
	
	for (int i = 0; i <= nM; i++)
		ppnMat[i] = (int*)malloc((nN + 1) * sizeof(int));
		

	for (int i = 1; i <= nM; i++)
	{
		scanf("%d", &ppnMat[i][0]);
		memset(pnFlag, 0, (nN + 1) * sizeof(int));

		for (int j = 1; j <= ppnMat[i][0]; j++)
		{
			scanf("%d", &ppnMat[i][j]);
			pnFlag[ppnMat[i][j]] = 1;
		}

		for (int j = ppnMat[i][1]; j <= ppnMat[i][ppnMat[i][0]]; j++)
		{
			if (pnFlag[j])
				continue;

			for (int k = 1; k <= ppnMat[i][0]; k++)
			{
				if (ppnLink[j][ppnMat[i][k]])
					continue;
				pnEnter[ppnMat[i][k]]++;
				vecMat[j].push_back(ppnMat[i][k]);
				ppnLink[j][ppnMat[i][k]] = 1;
			}
		}
			
	}

	for (int i = 1; i <= nN; i++)
		if (pnEnter[i] == 0)
			qTopu.push(i);


	int nCount = 0;
	int	nQsize;
	while (!qTopu.empty())
	{
		nQsize = qTopu.size();
		nCount++;
		while (nQsize--)
		{
			nTemp = qTopu.front();
			qTopu.pop();
			for (int i = 0; i < vecMat[nTemp].size(); i++)
			{
				pnEnter[vecMat[nTemp][i]]--;
				if (pnEnter[vecMat[nTemp][i]] == 0)
					qTopu.push(vecMat[nTemp][i]);
			}
		}
	}

	printf("%d", nCount);






Exit0:
	return 0;
}