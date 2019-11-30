/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-11 0:23
//	Comment		:	OJ(P5116)
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
	int*		pnSeqC = NULL;
	int*		pnSeqM = NULL;
	int			nTemp1;
	int			nTemp2;
	int			nMin;
	pnSeqC = (int*)malloc(4 * sizeof(int));
	pnSeqM = (int*)malloc(4 * sizeof(int));
	for (int i = 1; i <= 3; i++)
	{
		scanf("%d", pnSeqC + i);
		scanf("%d", pnSeqM + i);
	}

	for (int i = 0; i < 100; i++)
	{
		nTemp1 = i % 3 + 1;
		if (nTemp1 == 3)
			nTemp2 = 1;
		else
			nTemp2 = nTemp1 + 1;
		nMin = min(pnSeqC[nTemp2] - pnSeqM[nTemp2], pnSeqM[nTemp1]);
		pnSeqM[nTemp1] -= nMin;
		pnSeqM[nTemp2] += nMin;
	}

	for (int i = 1; i <= 3; i++)
		printf("%d\n", pnSeqM[i]);

Exit0:

	return 0;
}