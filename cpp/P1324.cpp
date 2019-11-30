/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-12 14:49
//	Comment		:	OJ(P1324)
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
#include <list>

using namespace std;
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		2000001


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

typedef struct SCost
{
	int		nNum;
	int		nFlag;
}SCost;

bool Cmp(const SCost& sFirst, const SCost& sSecond)
{
	return sFirst.nNum > sSecond.nNum;
}



int main(int argc, char* argv[])
{
	int					nInputN;
	int					nInputM;
	SCost*				psCost			= NULL;
	int*				nCountFlag		= NULL;
	long long					nAns			= 0;
	int					nTemp;
	int					nTempIndex;
	scanf("%d%d", &nInputN, &nInputM);

	psCost = (SCost*)malloc((nInputM + nInputN) * sizeof(SCost));
	nCountFlag = (int*)malloc(3 * sizeof(int));
	nCountFlag[1] = 1;
	nCountFlag[0] = 1;
	nCountFlag[2] = 0;
	for (int i = 0; i < nInputN - 1; i++)
	{
		scanf("%d", &psCost[i].nNum);
		psCost[i].nFlag = 0;
	}

	for (int i = nInputN - 1; i < nInputN + nInputM - 2; i++)
	{
		scanf("%d", &psCost[i].nNum);
		psCost[i].nFlag = 1;
	}

	sort(psCost, psCost + nInputM + nInputN - 2, Cmp);


	for (int i = 0; i < nInputN + nInputM - 2; i++)
	{
		if (psCost[i].nNum == -1)
			continue;
		nTempIndex = -1;
		for (int j = i + 1; j < nInputM + nInputN - 2 && 
			psCost[j].nNum == psCost[i].nNum; j++)
		{
			if (psCost[j].nFlag != psCost[i].nFlag)
				nTempIndex = j;
		}

		if (nCountFlag[!psCost[i].nFlag] <=
			nCountFlag[!psCost[nTempIndex].nFlag] || nTempIndex == -1)
			nTempIndex = i;
		else
			i--;

		nAns += psCost[nTempIndex].nNum * 
			nCountFlag[!psCost[nTempIndex].nFlag];

		nCountFlag[psCost[nTempIndex].nFlag]++;
		psCost[nTempIndex].nNum = -1;
	}

	printf("%lld", nAns);


Exit0:

	return 0;
}