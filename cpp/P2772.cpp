/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-2 23:11
//	Comment		:	OJ(P2772)
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

bool Cmp(pair<int, int> prOne, pair<int, int> prTwo)
{
	if (prOne.second == prTwo.second)
		return prOne.first > prTwo.first;
	else
		return prOne.second > prTwo.second;
}




int main(int argc, char* argv[])
{
	pair<int, int>*			pprLocal		= NULL;
	int						nY;
	int						nX;
	int						nInputN;
	int						nPreX;
	int						nFlag			= 0;

	scanf("%d", &nInputN);

	pprLocal = new pair<int, int>[nInputN];

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d", &nX, &nY);
		pprLocal[i].first = nX;
		pprLocal[i].second = nY;
	}
	sort(pprLocal, pprLocal + nInputN, Cmp);

	nPreX = -1;
	for (int i = 0; i < nInputN; i++)
	{
		if (pprLocal[i].first > nPreX)
		{
			if (!nFlag)
				nFlag = 1;
			else
				printf(",");
			nPreX = pprLocal[i].first;
			printf("(%d,%d)", pprLocal[i].first, pprLocal[i].second);
		}	
	}


Exit0:
	return 0;
}