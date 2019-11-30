/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-27 21:38
//	Comment		:	OJ(P2959)
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


void DFS(int& nCount, map<int, pair<int, int> >& mapRoad, int nNowPoint, int nSum)
{
	if (nNowPoint == 0)
	{
		if (nCount < nSum)
			nCount = nSum;
		return;
	}
		
	nSum++;

	DFS(nCount, mapRoad, mapRoad[nNowPoint].first, nSum);
	DFS(nCount, mapRoad, mapRoad[nNowPoint].second, nSum);
}





int main(int argc, char* argv[])
{
	int								nInputP;
	int								nInputC;
	int								nInputD1;
	int								nInputD2;
	int								nAns			 = 0;
	map<int, pair<int, int> >		mapRoad;


	scanf("%d", &nInputP);

	for (int i = 0; i < nInputP - 1; i++)
	{
		scanf("%d%d%d", &nInputC, &nInputD1, &nInputD2);
		mapRoad[nInputC].first = nInputD1;
		mapRoad[nInputC].second = nInputD2;
	}

	DFS(nAns, mapRoad, 1, 0);

	printf("%d", nAns);




Exit0:

	return 0;
}