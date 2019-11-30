/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-4 14:57
//	Comment		:	OJ(P2096)
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



int main(int argc, char* argv[])
{
	int					nInputN;
	int					nInputM;
	int					nMax;
	int					nTemp;
	int					nAns			= 0;
	int					nSum			= 0;
	int*				pnSeq			= NULL;

	scanf("%d%d", &nInputN, &nInputM);

	pnSeq = (int*)malloc(nInputM * sizeof(int));

	for (int i = 0; i < nInputM; i++)
		scanf("%d", pnSeq + i);

	for (int j = 1; j < nInputN; j++)
		for (int i = 0; i < nInputM; i++)
		{
			scanf("%d", &nTemp);
			pnSeq[i] = max(pnSeq[i], nTemp);
		}
	nMax = 0;
	for (int i = 0; i < nInputM; i++)
	{
		if (nSum + pnSeq[i] > 0)
		{
			nSum += pnSeq[i];
			nMax = max(nMax, nSum);
		}
		else
			nSum = 0;
	}

	printf("%d", nMax);

	
			

Exit0:
	return 0;
}