/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-20 00:17
//	Comment		:	OJ(P2525)
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

int**				ppnFlag;

int BFS(queue<pair<int,int> >& qBFS)
{
	int nCount = 0;
	int	nNewX;
	int nNewY;
	int nQsize;
	pair<int, int>		prTemp;
	while (true)
	{
		nCount++;
		nQsize = qBFS.size();
		while (nQsize--)
		{
			nNewX = qBFS.front().first;
			nNewY = qBFS.front().second;
			if (nNewX == 1 && nNewY == 1)
				return nCount;
			qBFS.pop();

			if (nNewX - 1 > 0)
			{
				if (nNewY - 2 > 0)
				{
					prTemp.first = nNewX - 1;
					prTemp.second = nNewY - 2;
					if (!ppnFlag[prTemp.first][prTemp.second])
					{
						ppnFlag[prTemp.first][prTemp.second] = 1;
						qBFS.push(prTemp);
					}
					
				}
				if (nNewY + 2 < 30)
				{
					prTemp.first = nNewX - 1;
					prTemp.second = nNewY + 2;

					if (!ppnFlag[prTemp.first][prTemp.second])
					{
						ppnFlag[prTemp.first][prTemp.second] = 1;
						qBFS.push(prTemp);
					}
				}
				
			}
			if (nNewX - 2 > 0)
			{
				if (nNewY - 2 > 0)
				{
					prTemp.first = nNewX - 2;
					prTemp.second = nNewY - 2;
					if (!ppnFlag[prTemp.first][prTemp.second])
					{
						ppnFlag[prTemp.first][prTemp.second] = 1;
						qBFS.push(prTemp);
					}
				}
				if (nNewY + 2 < 30)
				{
					prTemp.first = nNewX - 2;
					prTemp.second = nNewY + 2;
					if (!ppnFlag[prTemp.first][prTemp.second])
					{
						ppnFlag[prTemp.first][prTemp.second] = 1;
						qBFS.push(prTemp);
					}
				}

			}
		}

	}
}

int main(int argc, char* argv[])
{
	int				nInputN;
	int*			pnSeq		= NULL;


	scanf("%d", &nInputN);

	pnSeq = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeq + i);

	if (prev_permutation(pnSeq, pnSeq + nInputN))
	{
		for (int i = 0; i < nInputN; i++)
			printf("%d ", pnSeq[i]);
	}
	else
		printf("ERROR");




Exit0:
	return 0;
}