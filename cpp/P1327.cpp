/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-13 23:25
//	Comment		:	OJ(P1327)
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
#include <float.h>

using namespace std;
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int				nInputN;
	map<int, int>	mpIndex;
	int*			pnSeq			= NULL;
	int*			pnSort			= NULL;
	int				nAns			= 0;
	int				nTempIndex;

	scanf("%d", &nInputN);

	pnSeq = (int*)malloc(nInputN * sizeof(int));
	pnSort = (int*)malloc(nInputN * sizeof(int));
	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", pnSeq + i);
		mpIndex[pnSeq[i]] = i;
	}
		

	memcpy(pnSort, pnSeq, nInputN * sizeof(int));

	sort(pnSort, pnSort + nInputN);

	for (int i = 0; i < nInputN; i++)
	{
		if (pnSeq[i] != pnSort[i])
		{
			nAns++;
			nTempIndex = mpIndex[pnSort[i]];
			mpIndex[pnSeq[i]] = nTempIndex;
			pnSeq[nTempIndex] = pnSeq[i];
		}
	}

	printf("%d", nAns);



Exit0:

	return 0;
}