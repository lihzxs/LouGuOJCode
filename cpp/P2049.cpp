/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-3 17:36
//	Comment		:	OJ(P2049)
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
	int				nInputN;
	int				nInputM;
	int				nInputK;
	int**			ppnMat = NULL;
	int***			pppnFlag = NULL;
	int				nQsize;
	int				nNowX;
	int				nNowY;
	int				nAns;
	int				nCount			= 0;
	pair<pair<int, int>, int>			prTemp;
	queue<pair<pair<int, int>, int>>	qBFS;
	vector<int>		vecAns;

	scanf("%d%d%d", &nInputN, &nInputM, &nInputK);

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	pppnFlag = (int***)malloc((nInputN + 1) * sizeof(int**));
	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputM + 1) * sizeof(int));
		pppnFlag[i] = (int**)malloc((nInputM + 1) * sizeof(int*));
		for (int j = 1; j <= nInputM; j++)
		{
			pppnFlag[i][j] = (int*)malloc(105 * sizeof(int));
			memset(pppnFlag[i][j], 0, 105 * sizeof(int));
		}
		
	}

	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputM; j++)
			scanf("%d", &ppnMat[i][j]);

	qBFS.push({ {1, 1}, ppnMat[1][1] });
	pppnFlag[1][1][ppnMat[1][1]] = 1;
	while (!qBFS.empty())
	{
		nQsize = qBFS.size();
		while (nQsize--)
		{
			prTemp = qBFS.front();
			qBFS.pop();
			nNowX = prTemp.first.first;
			nNowY = prTemp.first.second;
			nAns = prTemp.second;
			if (nNowX + 1 <= nInputN)
			{
				prTemp.first.first = nNowX + 1;
				prTemp.first.second = nNowY;
				prTemp.second = nAns * ppnMat[nNowX + 1][nNowY] % nInputK;
				if (!pppnFlag[prTemp.first.first][prTemp.first.second][prTemp.second])
				{
					pppnFlag[prTemp.first.first][prTemp.first.second][prTemp.second] = 1;
					qBFS.push(prTemp);
				}
			}

			if (nNowY + 1 <= nInputM)
			{
				prTemp.first.first = nNowX;
				prTemp.first.second = nNowY + 1;
				prTemp.second = nAns * ppnMat[nNowX][nNowY + 1] % nInputK;
				if (!pppnFlag[prTemp.first.first][prTemp.first.second][prTemp.second])
				{
					pppnFlag[prTemp.first.first][prTemp.first.second][prTemp.second] = 1;
					qBFS.push(prTemp);
				}
			}
		}
	}
	for (int i = 0; i < 105; i++)
		if (pppnFlag[nInputN][nInputM][i])
			nCount++;

	printf("%d\n", nCount);
	for (int i = 0; i < 105; i++)
		if (pppnFlag[nInputN][nInputM][i])
			printf("%d ", i);


Exit0:
	return 0;
}