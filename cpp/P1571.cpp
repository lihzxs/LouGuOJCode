/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-27 22:04
//	Comment		:	OJ(P1571)
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
	int								nInputN;
	int								nInputM;
	int								nInputTemp;
	set<int>						setNum;
	int*							pnSeq			= NULL;
	int								nCount			= 0;
	int								nBlankFlag		= 0;



	scanf("%d%d", &nInputN, &nInputM);

	pnSeq = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeq + i);

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d", &nInputTemp);
		setNum.insert(nInputTemp);
	}



	for (int i = 0; i < nInputN; i++)
	{

		if (setNum.count(pnSeq[i]))
		{
			if (nBlankFlag)
				printf(" ");
			else
				nBlankFlag = 1;
			printf("%d", pnSeq[i]);
		}
			
	}



Exit0:

	return 0;
}