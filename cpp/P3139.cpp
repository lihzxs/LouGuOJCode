/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-12 20:46
//	Comment		:	OJ(P3139)
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
	int				nInputX;
	int				nInputY;
	int				nInputK;
	int				nInputM;
	int				nAns			= 10000000;
	pair<int, pair<int, int> >		prItem;
	queue<pair<int, pair<int, int> > > qBFS;
	bool***			pppbFlag			= NULL;
	scanf("%d%d%d%d", &nInputX, &nInputY, &nInputK, &nInputM);

	pppbFlag = (bool***)malloc(101 * sizeof(bool**));
	for (int i = 0; i < 101; i++)
	{
		pppbFlag[i] = (bool**)malloc(101 * sizeof(bool*));
		for (int j = 0; j < 101; j++)
		{
			pppbFlag[i][j] = (bool*)malloc(101 * sizeof(bool));
			memset(pppbFlag[i][j], 0, 101 * sizeof(bool));
		}
			
	}

	qBFS.push({ 0,{0, 0} });
	pppbFlag[0][0][0] = 1;

	while (!qBFS.empty())
	{
		prItem = qBFS.front();
		qBFS.pop();
		if (prItem.second.second == nInputK || prItem.first == 0 || prItem.second.first == 0)
		{
			nAns = min(nAns, abs(prItem.first + prItem.second.first - nInputM));
			if (prItem.second.second == nInputK)
				continue;
		}
		int nC = prItem.second.second + 1, nX = prItem.first, nY = prItem.second.first;

		if (!pppbFlag[nInputX][nY][nC])
		{
			qBFS.push({ nInputX,{nY, nC} });
			pppbFlag[nInputX][nY][nC] = 1;
		}
		if (!pppbFlag[nX][nInputY][nC])
		{
			qBFS.push({ nX,{nInputY, nC} });
			pppbFlag[nX][nInputY][nC] = 1;
		}
		if (!pppbFlag[0][nY][nC])
		{
			qBFS.push({ 0,{nY, nC} });
			pppbFlag[0][nY][nC] = 1;
		}
		if (!pppbFlag[nX][0][nC])
		{
			qBFS.push({ nX,{0, nC} });
			pppbFlag[nX][0][nC] = 1;
		}
		int nNewY = nX + nY;
		int nNewX = 0;
		if (nNewY > nInputY)
		{
			nNewX = nNewY - nInputY;
			nNewY = nInputY;
		}
		if (!pppbFlag[nNewX][nNewY][nC])
		{
			qBFS.push({ nNewX,{nNewY, nC} });
			pppbFlag[nNewX][nNewY][nC] = 1;
		}

		nNewX = nX + nY;
		nNewY = 0;
		if (nNewX > nInputX)
		{
			nNewY = nNewX - nInputX;
			nNewX = nInputX;
		}
		if (!pppbFlag[nNewX][nNewY][nC])
		{
			qBFS.push({ nNewX,{nNewY, nC} });
			pppbFlag[nNewX][nNewY][nC] = 1;
		}
	}
		

	printf("%d", nAns);


Exit0:

	return 0;
}