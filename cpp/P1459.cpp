/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-11 22:48
//	Comment		:	OJ(P1459)
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


int main(int argc, char* argv[])
{
	int						nInputN;
	int*					pnSeq				= NULL;
	int*					pnSort				= NULL;
	int						nCount_1			= 0;
	int						nCount1				= 0;
	int						nCount_2			= 0;
	int						nCount2				= 0;
	int						nAns				= 0;
	int						nTemp;
	scanf("%d", &nInputN);

	pnSeq = (int*)malloc(nInputN * sizeof(int));
	pnSort = (int*)malloc(nInputN * sizeof(int));
	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeq + i);

	memcpy(pnSort, pnSeq, nInputN * sizeof(int));

	sort(pnSort, pnSort + nInputN);

	for (int i = 0; i < nInputN; i++)
	{
		if (pnSeq[i] - pnSort[i] == -1)
			nCount_1++;
		if (pnSeq[i] - pnSort[i] == 1)
			nCount1++;
		if (pnSeq[i] - pnSort[i] == -2)
			nCount_2++;
		if (pnSeq[i] - pnSort[i] == 2)
			nCount2++;
	}

	nAns += nCount1;
	nAns += min(nCount_2, nCount2);
	nAns += (nCount2 - min(nCount_2, nCount2)) * 2;
	printf("%d", nAns);

Exit0:

	return 0;
}