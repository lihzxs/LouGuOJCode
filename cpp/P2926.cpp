/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-12 16:10
//	Comment		:	OJ(P2926)
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



int main(int argc, char* argv[])
{
	int*			pnCount			= NULL;
	int*			pnAns			= NULL;
	int*			pnSeq			= NULL;
	int				nInputN;
	int				nTemp;
	pnCount = (int*)malloc(1000005 * sizeof(int));
	memset(pnCount, 0, 1000005 * sizeof(int));
	pnAns = (int*)malloc(1000005 * sizeof(int));
	memset(pnAns, 0, 1000005 * sizeof(int));

	scanf("%d", &nInputN);

	pnSeq = (int*)malloc(nInputN * sizeof(int));
	memset(pnSeq, 0, nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", pnSeq + i);
		pnCount[pnSeq[i]]++;
	}

	for (int i = 1; i <= 1000000; i++)
	{
		if (!pnCount[i])
			continue;
		for (int j = 1; j <= 1000000 / i; j++)
		{
			if (pnCount[i * j])
				pnAns[i * j] += pnCount[i];
			if (i * j == i)
				pnAns[i]--;
		}
	}

	for (int i = 0; i < nInputN; i++)
		printf("%d\n", pnAns[pnSeq[i]]);


	


Exit0:

	return 0;
}