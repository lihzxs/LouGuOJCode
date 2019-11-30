/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-21 16:40
//	Comment		:	OJ(P1135)
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
#define	EPS         0.001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int BFS(int nStart, int nEnd,
	int nN, int* pnSeq, int* pnFlag)
{
	queue<int>	qBFS;
	int						nTemp;
	int						nNew;
	int						nQSize;
	int						nCount = 0;
	int						nNewX;
	int						nNewY;

	qBFS.push(nStart);
	pnFlag[nStart] = 1;
	while (!qBFS.empty())
	{
		nQSize = qBFS.size();
		while (nQSize--)
		{
			nTemp = qBFS.front();
			qBFS.pop();

			if (nTemp == nEnd)
				return nCount;

			if (nTemp + pnSeq[nTemp] >= 1 && nTemp + pnSeq[nTemp] <= nN)
			{
				if (!pnFlag[nTemp + pnSeq[nTemp]])
				{
					pnFlag[nTemp + pnSeq[nTemp]] = 1;
					qBFS.push(nTemp + pnSeq[nTemp]);
				}
				
			}
			if (nTemp - pnSeq[nTemp] >= 1 && nTemp - pnSeq[nTemp] <= nN)
			{
				if (!pnFlag[nTemp - pnSeq[nTemp]])
				{
					pnFlag[nTemp - pnSeq[nTemp]] = 1;
					qBFS.push(nTemp - pnSeq[nTemp]);
				}
			}
		}///while (nQSize--)
		nCount++;
	}///while (true)
	return -1;
}

int main(int argc, char* argv[])
{
	int			nInputN;
	int			nInputA;
	int			nInputB;
	int*		pnSeq				= NULL;
	int*		pnFlag				= NULL;
	int			nCount				= 0;
	int			nTemp;
	scanf("%d%d%d", &nInputN, &nInputA, &nInputB);


	pnSeq = (int*)malloc((nInputN + 1) * sizeof(int));
	pnFlag = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnFlag, 0, (nInputN + 1) * sizeof(int));


	for (int i = 1; i <= nInputN; i++)
		scanf("%d", pnSeq + i);

	cout <<  BFS(nInputA, nInputB,
		nInputN, pnSeq, pnFlag);

		


Exit0:
	return 0;
}