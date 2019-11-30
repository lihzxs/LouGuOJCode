/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-11 15:14
//	Comment		:	OJ(P1256)
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
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		2000001


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


void BFS(int** ppnMat, int** ppnGuide, queue<pair<int, int>>& qBFS,
	int** ppnFlag,int nN, int nM, int nCount)
{

	pair<int, int> pairTemp;
	pair<int, int> pairPush;
	int		nNewX;
	int		nNewY;
	int		nSize = qBFS.size();

	while (nSize--)
	{
		pairTemp = qBFS.front();
		qBFS.pop();
		if (!ppnFlag[pairTemp.first][pairTemp.second])
		{
			ppnMat[pairTemp.first][pairTemp.second] =
				min(nCount, ppnMat[pairTemp.first][pairTemp.second]);
			ppnFlag[pairTemp.first][pairTemp.second] = 1;
			for (int i = 0; i < 4; i++)
			{
				
				nNewX = pairTemp.first + ppnGuide[i][0];
				nNewY = pairTemp.second + ppnGuide[i][1];
				if (nNewX < 1 || nNewX > nN)
					continue;
				if (nNewY < 1 || nNewY > nM)
					continue;
				if (ppnMat[nNewX][nNewY] == 0)
					continue;
				pairPush.first = nNewX;
				pairPush.second = nNewY;
				qBFS.push(pairPush);
			}
		}

	}
	if (!qBFS.empty())
		BFS(ppnMat, ppnGuide, qBFS,
			ppnFlag, nN, nM, nCount + 1);
}



int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int				nAnsX;
	int				nAnsY;
	int**			ppnMat				= NULL;
	queue<pair<int, int>>		qBFS;
	pair<int, int>				pairTemp;
	int**			ppnFlag				= NULL;
	string			szInput;
	int**			ppnGuide			= NULL;
	int				nMin;
	int				nAns				= 0;
	ppnGuide = (int**)malloc(4 * sizeof(int*));
	for (int i = 0; i < 4; i++)
		ppnGuide[i] = (int*)malloc(2 * sizeof(int));

	ppnGuide[0][0] = 1; ppnGuide[0][1] = 0;
	ppnGuide[1][0] = 0; ppnGuide[1][1] = 1;
	ppnGuide[2][0] = -1; ppnGuide[2][1] = 0;
	ppnGuide[3][0] = 0; ppnGuide[3][1] = -1;


	scanf("%d%d", &nInputN, &nInputM);
	
	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	ppnFlag = (int**)malloc((nInputN + 1) * sizeof(int*));
	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputM + 1) * sizeof(int));
		ppnFlag[i] = (int*)malloc((nInputM + 1) * sizeof(int));
	}
		

	for (int i = 1; i <= nInputN; i++)
	{
		cin >> szInput;
		for (int j = 0; j < szInput.length(); j++)
		{
			if (szInput[j] == '1')
				ppnMat[i][j + 1] = 0;
			else
				ppnMat[i][j + 1] = 500;
		}
	}



	for (int i = 1; i <= nInputN; i++)
	{
		for (int j = 1; j <= nInputM; j++)
		{
			if (ppnMat[i][j] == 0)
			{
				for (int k = 1; k <= nInputN; k++)
					memset(ppnFlag[k], 0, (nInputM + 1) * sizeof(int));
				pairTemp.first = i;
				pairTemp.second = j;
				qBFS.push(pairTemp);
				BFS(ppnMat, ppnGuide, qBFS,
					ppnFlag, nInputN, nInputM, 0);
			}
				
		}

	}

	for (int i = 1; i <= nInputN; i++)
	{
		for (int j = 1; j <= nInputM; j++)
		{
			printf("%d ", ppnMat[i][j]);
		}
		printf("\n");
	}




Exit0:

	return 0;
}