/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-14 23:43
//	Comment		:	OJ(P2008)
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
	int*			pnSeq		= NULL;
	int*			pnCount		= NULL;
	int*			pnAns		= NULL;
	scanf("%d", &nInputN);
	pnSeq = (int*)malloc(nInputN * sizeof(int));
	
	pnCount = (int*)malloc(nInputN * sizeof(int));
	memset(pnCount, 0, nInputN * sizeof(int));
	pnAns = (int*)malloc(nInputN * sizeof(int));
	memset(pnAns, 0, nInputN * sizeof(int));
	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeq + i);

	for (int i = 0; i < nInputN; i++)
	{
		pnCount[i] = 1;
		for (int j = 0; j <= i - 1; j++)
		{
			if (pnSeq[j] <= pnSeq[i] && pnCount[j] + 1 > pnCount[i])
			{
				pnCount[i] = pnCount[j] + 1;
				pnAns[i] = pnAns[j];
			}
		}
		pnAns[i] += pnSeq[i];
	}
	for (int i = 0; i < nInputN; i++)
	{

		printf("%d ", pnAns[i]);
	}

Exit0:

	return 0;
}