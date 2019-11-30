/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-15 18:44
//	Comment		:	OJ(P1656)
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
#include <list>
#include <queue>
#include <map>

using namespace std;
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		2e31


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int Fin(int* pnSet, int nNum)
{
	if (pnSet[nNum] == nNum)
		return pnSet[nNum];
	else
		return pnSet[nNum] =
		Fin(pnSet, pnSet[nNum]);
}

int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int*			pnSet				= NULL;
	int				nCount;
	pair<int, int>*	prTemp				= NULL;

	scanf("%d%d", &nInputN, &nInputM);

	pnSet = (int*)malloc((nInputN + 1) * sizeof(int));
	prTemp = new pair<int, int>[nInputM];

	

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d", &prTemp[i].first, &prTemp[i].second);
		if (prTemp[i].first > prTemp[i].second)
			swap(prTemp[i].first, prTemp[i].second);
	}
	sort(prTemp, prTemp + nInputM);
	for (int i = 0; i < nInputM; i++)
	{
		nCount = 0;
		for (int j = 1; j <= nInputN; j++)
			pnSet[j] = j;
		for (int j = 0; j < nInputM; j++)
		{
			if (i == j)
				continue;
			pnSet[Fin(pnSet, prTemp[j].first)] = 
				Fin(pnSet, prTemp[j].second);
		}
		for (int j = 1; j <= nInputN; j++)
			if (pnSet[j] == j)
				nCount++;
		if (nCount >= 2)
			printf("%d %d\n", prTemp[i].first, prTemp[i].second);
	}



Exit0:

	return 0;
}