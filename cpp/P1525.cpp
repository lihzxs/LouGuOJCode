
/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-25 00:50
//	Comment		:	OJ(P1525)
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


int Fin(int* pnSet, int nNum)
{
	if (pnSet[nNum] == nNum)
		return pnSet[nNum];
	else
		return pnSet[nNum] =
		Fin(pnSet, pnSet[nNum]);
}

bool Cmp(pair<pair<int, int>, int>& pA, pair<pair<int, int>, int>& pB)
{
	return pA.second > pB.second;
}

int main(int argc, char* argv[])
{
	int						nN;
	int						nM;
	int*					pnSet = NULL;
	int*					pnFlag = NULL;
	int						nFa;
	int						nFb;
	pair<pair<int, int>, int>*	prTemp;

	scanf("%d%d", &nN, &nM);

	pnSet = (int*)malloc((nN + 1) * sizeof(int));
	pnFlag = (int*)malloc((nN + 1) * sizeof(int));
	memset(pnFlag, 0, (nN + 1) * sizeof(int));
	prTemp = new pair<pair<int, int>, int>[nM + 1];
	for (int i = 1; i <= nN; i++)
		pnSet[i] = i;

	for (int i = 0; i < nM; i++)
	{
		scanf("%d%d%d", &prTemp[i].first.first,
			&prTemp[i].first.second, &prTemp[i].second);
	}

	sort(prTemp, prTemp + nM, Cmp);

	int nF = 1;
	for (int i = 0; i < nM; i++)
	{
		nFa = Fin(pnSet, prTemp[i].first.first);
		nFb = Fin(pnSet, prTemp[i].first.second);
		if (nFa == nFb)
		{
			nF = 0;
			printf("%d", prTemp[i].second);
			break;
		}
		else
		{
			if (!pnFlag[prTemp[i].first.first])
				pnFlag[prTemp[i].first.first] = prTemp[i].first.second;
			else
				pnSet[Fin(pnSet, pnFlag[prTemp[i].first.first])] = Fin(pnSet, prTemp[i].first.second);
			
			if (!pnFlag[prTemp[i].first.second])
				pnFlag[prTemp[i].first.second] = prTemp[i].first.first;
			else
				pnSet[Fin(pnSet, pnFlag[prTemp[i].first.second])] = Fin(pnSet, prTemp[i].first.first);
		}
	}


	if (nF)
		printf("0");

Exit0:

	return 0;
}