/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-22 23:16
//	Comment		:	OJ(P1223)
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
#define	MAXNUM		100000
#define	EPS         0.0001
#define MODNUM		2e31


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


typedef struct SWaitTime
{
	int				nId;
	int				nTime;
}SWaitTime;

bool Cmp(const SWaitTime sFirst, const SWaitTime sSecond)
{
	if (sFirst.nTime == sSecond.nTime)
		return sFirst.nId < sSecond.nId;
	return sFirst.nTime < sSecond.nTime;
}




int main(int argc, char* argv[])
{

	SWaitTime*			psWaitTime				= NULL;
	int					nInputN;
	long long			nWaitSum				= 0;
	scanf("%d", &nInputN);

	psWaitTime = (SWaitTime*)malloc(nInputN * sizeof(SWaitTime));

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", &psWaitTime[i].nTime);
		psWaitTime[i].nId = i + 1;
	}

	sort(psWaitTime, psWaitTime + nInputN, Cmp);
	//nWaitSum = psWaitTime[0].nTime;
	printf("%d", psWaitTime[0].nId);
	for (int i = 1; i < nInputN; i++)
	{
		printf(" %d", psWaitTime[i].nId);
		nWaitSum += psWaitTime[i - 1].nTime * (nInputN - i);
	}
	printf("\n%.2f", nWaitSum * 1.0 / nInputN);




Exit0:

	return 0;
}