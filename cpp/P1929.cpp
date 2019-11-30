/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-9 23:52
//	Comment		:	OJ(P1929)
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
	int				nInputN;
	int*			pnSeq				= NULL;
	int**			ppnFlag				= NULL;
	int				nCount;
	int				nQsize;
	pair<int, int>	prTemp;
	queue<pair<int, int> >		qBFS;

	scanf("%d", &nInputN);
	pnSeq = (int*)malloc((nInputN + 1) * sizeof(int));
	
	ppnFlag = (int**)malloc((nInputN + 1) * sizeof(int*));
	for (int i = 0; i <= nInputN; i++)
	{
		ppnFlag[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		memset(ppnFlag[i], 0, (nInputN + 1) * sizeof(int));
	}
	for (int i = 1; i <= nInputN; i++)
		scanf("%d", pnSeq + i);

	qBFS.push({ 1, 0 });
	ppnFlag[1][0] = 1;
	nCount = 0;
	while (!qBFS.empty())
	{
		nQsize = qBFS.size();
		nCount++;
		while (nQsize--)
		{
			prTemp = qBFS.front();
			qBFS.pop();
			if (prTemp.first == nInputN)
			{
				printf("%d\n", nCount - 1);
				return 0;
			}
			if (prTemp.first != 1 && !ppnFlag[prTemp.first - 1][prTemp.second + 1])
			{
				ppnFlag[prTemp.first - 1][prTemp.second + 1] = 1;
				qBFS.push({ prTemp.first - 1 ,prTemp.second + 1 });
			}
			for (int i = prTemp.first + 1; i <= nInputN; i++)
			{
				if (pnSeq[i] <= pnSeq[prTemp.first] + pow(2, prTemp.second) && !ppnFlag[i][0])
				{
					ppnFlag[i][0] = 1;
					qBFS.push({ i , 0 });
				}
			}
		}
	}
	printf("-1");

Exit0:

	return 0;
}