/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-15 22:43
//	Comment		:	OJ(P2360)
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
#include <float.h>

using namespace std;
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;
queue<int>		qX;
queue<int>		qY;
queue<int>		qZ;

void BFS(int*** pppnMat, int nX, int nY, int nZ,
	int** ppnGuide, int nCount, int* pnEnd, int& nMin, 
	int nL, int nR, int nC)
{
	while (!qX.empty())
	{
		int qSize = qX.size();
		while (qSize--)
		{
			nX = qX.front();
			nY = qY.front();
			nZ = qZ.front();
			qX.pop();
			qY.pop();
			qZ.pop();
			int		nNewX;
			int		nNewY;
			int		nNewZ;
			for (int i = 0; i < 6; i++)
			{
				nNewX = nX + ppnGuide[i][2];
				nNewY = nY + ppnGuide[i][1];
				nNewZ = nZ + ppnGuide[i][0];
				if (nNewX < 1 || nNewX > nL)
					continue;
				if (nNewY < 1 || nNewY > nR)
					continue;
				if (nNewZ < 1 || nNewZ > nC)
					continue;
				if (!pppnMat[nNewX][nNewY][nNewZ])
					continue;

				if (nNewX == pnEnd[0] && nNewY == pnEnd[1] && nNewZ == pnEnd[2])
				{
					nMin = nCount + 1;
					return;
				}

				pppnMat[nNewX][nNewY][nNewZ] = 0;
				qX.push(nNewX);
				qY.push(nNewY);
				qZ.push(nNewZ);
			}
		}
		nCount++;
	}

}


int main(int argc, char* argv[])
{
	int				nInputL;
	int				nInputR;
	int				nInputC;
	int*			pnStart			= NULL;
	int*			pnEnd			= NULL;
	int***			pppnMat			= NULL;
	int**			ppnGuide		= NULL;
	int				nMin;
	string			szInput;

	ppnGuide = (int**)malloc(6 * sizeof(int*));
	for (int i = 0; i < 6; i++)
		ppnGuide[i] = (int*)malloc(3 * sizeof(int));

	ppnGuide[0][0] = 0; ppnGuide[0][1] = 0; ppnGuide[0][2] = 1;
	ppnGuide[1][0] = 0; ppnGuide[1][1] = 0; ppnGuide[1][2] = -1;
	ppnGuide[2][0] = 1; ppnGuide[2][1] = 0; ppnGuide[2][2] = 0;
	ppnGuide[3][0] = 0; ppnGuide[3][1] = 1; ppnGuide[3][2] = 0;
	ppnGuide[4][0] = -1; ppnGuide[4][1] = 0; ppnGuide[4][2] = 0;
	ppnGuide[5][0] = 0; ppnGuide[5][1] = -1; ppnGuide[5][2] = 0;

	scanf("%d%d%d", &nInputL, &nInputR, &nInputC);

	nMin = nInputL * nInputC * nInputR + 1;

	pnStart = (int*)malloc(3 * sizeof(int));
	pnEnd = (int*)malloc(3 * sizeof(int));
	pppnMat = (int***)malloc((nInputL + 1) * sizeof(int**));
	for (int i = 1; i <= nInputL; i++)
	{
		pppnMat[i] = (int**)malloc((nInputR + 1) * sizeof(int*));
		for (int j = 1; j <= nInputR; j++)
		{
			pppnMat[i][j] = (int*)malloc((nInputC + 1) * sizeof(int));
		}	
	}

	for (int i = 1; i <= nInputL; i++)
	{
		for (int j = 1; j <= nInputR; j++)
		{
			cin >> szInput;
			for (int k = 0; k < szInput.length(); k++)
			{
				if (szInput[k] == 'S')
					pnStart[0] = i, pnStart[1] = j, pnStart[2] = k + 1;
				if (szInput[k] == 'E')
					pnEnd[0] = i, pnEnd[1] = j, pnEnd[2] = k + 1;
				if (szInput[k] == '#')
					pppnMat[i][j][k + 1] = 0;
				else
					pppnMat[i][j][k + 1] = 1;
			}
		}
	}


	qX.push(pnStart[0]);
	qY.push(pnStart[1]);
	qZ.push(pnStart[2]);
	BFS(pppnMat, pnStart[0], pnStart[1], pnStart[2],
		ppnGuide, 0, pnEnd, nMin, nInputL, nInputR, nInputC);

	if (nMin == nInputL * nInputC * nInputR + 1)
		printf("Trapped!");
	else
		printf("Escaped in %d minute(s).", nMin);




Exit0:

	return 0;
}