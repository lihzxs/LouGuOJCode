/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-9 14:39
//	Comment		:	OJ(P2873)
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
#include <list>

using namespace std;
#define	MAXNUM		150
#define	EPS         0.0001
#define MODNUM		1006


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int BFS(queue<pair<int, int> >& qBFS, map<pair<int, int>, bool>& mapFlag, 
	int** ppnGuide, int nCount, const pair<int, int>& pairFin)
{
	pair<int, int>		pairTemp;
	pair<int, int>		pairNext;
	int					nQSize;
	nQSize = qBFS.size();
	while (nQSize--)
	{
		pairTemp = qBFS.front();
		qBFS.pop();
		mapFlag[pairTemp] = true;
		for (int i = 0; i < 4; i++)
		{
			pairNext.first = pairTemp.first + ppnGuide[i][0];
			pairNext.second = pairTemp.second + ppnGuide[i][1];
			if (pairNext == pairFin)
				return nCount + 1;
			if (!mapFlag[pairNext])
			{
			    mapFlag[pairNext] = true;
			    qBFS.push(pairNext);
			}
				
		}
	}
	return BFS(qBFS, mapFlag, ppnGuide, nCount + 1, pairFin);
}




int main(int argc, char* argv[])
{
	int							nInputX;
	int							nInputY;
	int							nInputN;
	int**						ppnGuide			= NULL;
	pair<int, int>				pairFin;
	pair<int, int>				pairTemp;
	queue<pair<int, int> >		qBFS;
	map<pair<int, int>, bool>	mapFlag;
	scanf("%d%d%d", &nInputX, &nInputY, &nInputN);
	pairFin.first = nInputX;
	pairFin.second = nInputY;
	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d", &nInputX, &nInputY);
		pairTemp.first = nInputX;
		pairTemp.second = nInputY;
		mapFlag[pairTemp] = true;
	}
	ppnGuide = (int**)malloc(4 * sizeof(int*));
	for (int i = 0; i < 4; i++)
		ppnGuide[i] = (int*)malloc(2 * sizeof(int));

	ppnGuide[0][0] = 1; ppnGuide[0][1] = 0;
	ppnGuide[1][0] = 0; ppnGuide[1][1] = 1;
	ppnGuide[2][0] = -1; ppnGuide[2][1] = 0;
	ppnGuide[3][0] = 0; ppnGuide[3][1] = -1;


	pairTemp.first = 0;
	pairTemp.second = 0;
	mapFlag[pairTemp] = true;
	qBFS.push(pairTemp);

	printf("%d", BFS(qBFS, mapFlag, ppnGuide, 0, pairFin));



Exit0:

	return 0;
}