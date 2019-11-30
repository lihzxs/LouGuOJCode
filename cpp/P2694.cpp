/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-3 23:25
//	Comment		:	OJ(P2694)
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




bool Cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first > b.first;
}



int main(int argc, char* argv[])
{

	int			nInputG;
	int			nInputT;
	int			nX;
	int			nY;
	int			nNowX		= 0;
	int			nPre		= 0;
	bool		bIsPrint    = 0;
	pair<int, int> pairCion[51];
	scanf("%d", &nInputG);
	while (nInputG--)
	{
		scanf("%d", &nInputT);
		for (int i = 0; i < nInputT; i++)
		{
			scanf("%d%d", &nX, &nY);
			pairCion[i].first = nY;
			pairCion[i].second = nX;
		}
		pairCion[nInputT].first = 0;
		pairCion[nInputT].second = 0;
		sort(pairCion, pairCion + nInputT + 1, Cmp);

		for (int i = 0; i < nInputT; i++)
		{
			if (abs(pairCion[i].first - pairCion[i + 1].first) <
				abs(pairCion[i].second - pairCion[i + 1].second))
			{
				printf("Notabletocatch\n");
				bIsPrint = 1;
				break;
			}
		}
		if (!bIsPrint)
			printf("Abletocatch\n");
		nNowX = 0;
		nPre = 0;
		bIsPrint = 0;
	}

Exit0:
	return 0;
}