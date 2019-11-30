/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-29 18:28
//	Comment		:	OJ(P1480)
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

int**				ppnGuide			= NULL;

int BFS(int nStartX, int nStartY)
{
	queue<pair<int, int> >	qBFS;
	pair<int, int>			prTemp;
	pair<int, int>			prNew;
	int						nQSize;
	int						nCount				= 0;
	int						nNewX;
	int						nNewY;
	int**					ppnFlag				= NULL;

	ppnFlag = (int**)malloc(21 * sizeof(int));

	for (int i = 1; i <= 20; i++)
	{
		ppnFlag[i] = (int*)malloc(21 * sizeof(int));
		memset(ppnFlag[i], 0, 21 * sizeof(int));
	}

	prTemp.first = nStartX;
	prTemp.second = nStartY;
	ppnFlag[nStartX][nStartY] = 1;
	qBFS.push(prTemp);

	while (true)
	{
		nQSize = qBFS.size();
		while (nQSize--)
		{
			prTemp = qBFS.front();
			qBFS.pop();
			for (int i = 0; i < 12; i++)
			{
				nNewX = prTemp.first + ppnGuide[i][0];
				nNewY = prTemp.second + ppnGuide[i][1];

				if (nNewX < 1 || nNewX > 20)
					continue;

				if (nNewY < 1 || nNewY > 20)
					continue;

				if (nNewX == 1 && nNewY == 1)
					return nCount + 1;
					

				prNew.first = nNewX;
				prNew.second = nNewY;

				if (!ppnFlag[nNewX][nNewY])
				{
					ppnFlag[nNewX][nNewY] = 1;
					qBFS.push(prNew);
				}
			}

		}///while (nQSize--)
		nCount++;
	}///while (true)


}


int main(int argc, char* argv[])
{
	int				nInputX1;
	int				nInputX2;
	int				nInputY1;
	int				nInputY2;

	ppnGuide = (int**)malloc(12 * sizeof(int*));

	for (int i = 0; i < 12; i++)
		ppnGuide[i] = (int*)malloc(2 * sizeof(int));

	ppnGuide[0][0] = 2; ppnGuide[0][1] = 2;
	ppnGuide[1][0] = 2; ppnGuide[1][1] = -2;
	ppnGuide[2][0] = -2; ppnGuide[2][1] = 2;
	ppnGuide[3][0] = -2; ppnGuide[3][1] = -2;
	ppnGuide[4][0] = -1; ppnGuide[4][1] = -2;
	ppnGuide[5][0] = -1; ppnGuide[5][1] = 2;
	ppnGuide[6][0] = 1; ppnGuide[6][1] = -2;
	ppnGuide[7][0] = 1; ppnGuide[7][1] = 2;
	ppnGuide[8][0] = -2; ppnGuide[8][1] = 1;
	ppnGuide[9][0] = -2; ppnGuide[9][1] = -1;
	ppnGuide[10][0] = 2; ppnGuide[10][1] = 1;
	ppnGuide[11][0] = 2; ppnGuide[11][1] = -1;


	cin >> nInputX1 >> nInputY1 >> nInputX2 >> nInputY2;

	cout << BFS(nInputX1, nInputY1) << endl;
	cout << BFS(nInputX2, nInputY2) << endl;

Exit0:
	return 0;
}