/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-29 22:43
//	Comment		:	OJ(P1142)
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
#define	MAXNUM		201
#define	EPS         0.0001
#define MODNUM		2e31


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int					nInputN;
	int*				pnSeqX				= NULL;
	int*				pnSeqY				= NULL;
	int					nAns				= 0;
	map<double, int>	mpCount;

	scanf("%d", &nInputN);

	pnSeqX = (int*)malloc(nInputN * sizeof(int));
	pnSeqY = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
		scanf("%d%d", pnSeqX + i, pnSeqY + i);

	for (int i = 0; i < nInputN; i++)
	{
		for (int j = 0; j < nInputN; j++)
		{
			if (i == j)
				continue;
			if (pnSeqX[i] == pnSeqX[j])
				mpCount[10000000]++;
			else
				mpCount[(pnSeqY[i] - pnSeqY[j]) * 1.0 /
				(pnSeqX[i] - pnSeqX[j])]++;
		}
		for (map<double, int>::iterator iter = mpCount.begin();
			iter != mpCount.end(); iter++)
			nAns = max(nAns, (*iter).second);
		mpCount.clear();
	}
	printf("%d", nAns + 1);


Exit0:

	return 0;
}