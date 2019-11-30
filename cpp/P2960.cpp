/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-5 21:02
//	Comment		:	OJ(P2960)
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
	int**					ppnGuide = NULL;
	int						nInputN;
	int						nInputM;
	int						nStartX;
	int						nStartY;
	int						nNewX;
	int						nNewY;
	int						nQsize;
	string					szTemp;
	int						nCountAns		= 1;
	int						nCount			= 0;		
	int						nSum			= 0;
	pair<int, int>			prTemp;
	int**					ppnMat			= NULL;
	queue<pair<int, int>>	qBFS;
	int**					ppnFlag			= 0;

	ppnGuide = (int**)malloc(8 * sizeof(int*));
	for (int i = 0; i < 8; i++)
		ppnGuide[i] = (int*)malloc(2 * sizeof(int));

	ppnGuide[0][0] = 1; ppnGuide[0][1] = 0;
	ppnGuide[1][0] = 0; ppnGuide[1][1] = 1;
	ppnGuide[2][0] = -1; ppnGuide[2][1] = 0;
	ppnGuide[3][0] = 0; ppnGuide[3][1] = -1;
	ppnGuide[4][0] = 1; ppnGuide[4][1] = 1;
	ppnGuide[5][0] = -1; ppnGuide[5][1] = -1;
	ppnGuide[6][0] = -1; ppnGuide[6][1] = 1;
	ppnGuide[7][0] = 1; ppnGuide[7][1] = -1;

	scanf("%d%d%d%d", &nInputN, &nInputM, &nStartX, &nStartY);

	ppnMat = (int**)malloc((nInputM + 1) * sizeof(int*));
	ppnFlag = (int**)malloc((nInputM + 1) * sizeof(int*));
	for (int i = 1; i <= nInputM; i++)
	{
		ppnMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		memset(ppnMat[i], 0, (nInputN + 1) * sizeof(int));
		ppnFlag[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		memset(ppnFlag[i], 0, (nInputN + 1) * sizeof(int));
	}

	for (int i = 1; i <= nInputM; i++)
	{
		cin >> szTemp;
		for (int j = 0; j < szTemp.length(); j++)
		{
			if (szTemp[j] == '.')
			{
				ppnMat[i][j + 1] = 1;
				nSum++;
			}
			else
				ppnMat[i][j + 1] = 0;
		}
	}
	swap(nStartX, nStartY);
	nStartX = nInputM - nStartX + 1;

	
	qBFS.push({nStartX, nStartY});
	ppnFlag[nStartX][nStartY] = 1;
	while (!qBFS.empty())
	{
		nQsize = qBFS.size();
		nCount++;
		while (nQsize--)
		{
			prTemp = qBFS.front();
			
			qBFS.pop();

			for (int i = 0; i < 8; i++)
			{
				nNewX = prTemp.first + ppnGuide[i][0];
				nNewY = prTemp.second + ppnGuide[i][1];

				if (nNewX < 1 || nNewX > nInputM)
					continue;
				if (nNewY < 1 || nNewY > nInputN)
					continue;

				if (ppnMat[nNewX][nNewY] && !ppnFlag[nNewX][nNewY])
				{
					qBFS.push({ nNewX, nNewY });
					ppnFlag[nNewX][nNewY] = 1;
					nCountAns++;
					if (nCountAns == nSum)
					{
						printf("%d", nCount);
						return 0;
					}
				}
			}
		}///while (nQsize--)
	}



Exit0:
	return 0;
}