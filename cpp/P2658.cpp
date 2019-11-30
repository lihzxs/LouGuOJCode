/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-21 00:30
//	Comment		:	OJ(P2658)
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


bool Check(int** ppnMat, int** ppnF, int** ppnGuide, int nN, int nM, 
	int nX, int nStartX, int nStartY, int nCountF)
{
	 int**				ppnFlag				= NULL;
	 ppnFlag = (int**)malloc((nN + 1) * sizeof(int*));
	 for (int i = 1; i <= nN; i++)
	 {
		 ppnFlag[i] = (int*)malloc((nM + 1) * sizeof(int));
		 memset(ppnFlag[i], 0, (nM + 1) * sizeof(int));
	 }
	 queue<pair<int, int> >		qBFS;
	 pair<int, int>				prTemp;
	 int						nNewX;
	 int						nNewY;
	 int						nSum = 1;
	 ppnFlag[nStartX][nStartY] = 1;
	 qBFS.push({ nStartX, nStartY });
	 while (!qBFS.empty())
	 {
		 prTemp = qBFS.front();
		 qBFS.pop();

		 for (int i = 0; i < 4; i++)
		 {
			 nNewX = prTemp.first + ppnGuide[i][0];
			 nNewY = prTemp.second + ppnGuide[i][1];
			 if (nNewX < 1 || nNewX > nN)
				 continue;
			 if (nNewY < 1 || nNewY > nM)
				 continue;
			 if (ppnFlag[nNewX][nNewY])
				 continue;
			 if (abs(ppnMat[nNewX][nNewY] - ppnMat[prTemp.first][prTemp.second]) > nX)
				 continue;

			 ppnFlag[nNewX][nNewY] = 1;

			 nSum += ppnF[nNewX][nNewY];
			 qBFS.push({ nNewX, nNewY });
			 if (nSum == nCountF)
				 return true;
		 }
	 }

	 return false;

}


int main(int argc, char* argv[])
{
	int					nInputN;
	int					nInputM;
	int**				ppnMat				= NULL;
	int**				ppnF				= NULL;
	int					nLeft				= 0;
	int					nRight				= 0;
	int					nMid;
	int					nCountF				= 0;
	int					nStartX;
	int					nStartY;
	int**				ppnGuide = NULL;
	ppnGuide = (int**)malloc(4 * sizeof(int*));

	for (int i = 0; i < 4; i++)
		ppnGuide[i] = (int*)malloc(2 * sizeof(int));

	ppnGuide[0][0] = 1; ppnGuide[0][1] = 0;
	ppnGuide[1][0] = 0; ppnGuide[1][1] = 1;
	ppnGuide[2][0] = -1; ppnGuide[2][1] = 0;
	ppnGuide[3][0] = 0; ppnGuide[3][1] = -1;

	scanf("%d%d", &nInputN, &nInputM);

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	ppnF = (int**)malloc((nInputN + 1) * sizeof(int*));
	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputM + 1) * sizeof(int));
		memset(ppnMat[i], 0, (nInputM + 1) * sizeof(int));
		ppnF[i] = (int*)malloc((nInputM + 1) * sizeof(int));
		memset(ppnF[i], 0, (nInputM + 1) * sizeof(int));
	}

	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputM; j++)
		{
			scanf("%d", &ppnMat[i][j]);
			nRight = max(nRight, ppnMat[i][j]);
		}
			

	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputM; j++)
		{
			scanf("%d", &ppnF[i][j]);
			if (ppnF[i][j])
			{
				nCountF++;
				if (nCountF == 1)
				{
					nStartX = i;
					nStartY = j;
				}
			}
		}

	while (nLeft <= nRight)
	{
		nMid = (nLeft + nRight) / 2;
		if (Check(ppnMat, ppnF, ppnGuide, nInputN, nInputM,
			nMid, nStartX, nStartY, nCountF))
		{
			nRight = nMid - 1;
		}
		else
			nLeft = nMid + 1;
	}
			
	printf("%d", nRight + 1);



Exit0:

	return 0;
}