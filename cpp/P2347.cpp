/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-27 23:41
//	Comment		:	OJ(P2347)
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
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{

	int					nAns = 0;
	int					nSum = 0;
	int					nCount				= 0;
	int					nTemp;
	int*				pnSeq				= NULL;
	int*				pnFlag				= NULL;
	int*				pnA					= NULL;

	pnA = (int*)malloc(6 * sizeof(int));

	for (int i = 0; i < 6; i++)
	{
		scanf("%d", pnA + i);
		nCount += pnA[i];
	}

	pnSeq = (int*)malloc(nCount * sizeof(int));
	nCount = 0;
	for (int i = 0; i < 6; i++)
	{
		if (i < 3)
			nTemp = i + 1;
		if (i == 3)
			nTemp = 5;
		if (i == 4)
			nTemp = 10;
		if (i == 5)
			nTemp = 20;
		for (int j = 0; j < pnA[i]; j++)
			pnSeq[nCount++] = nTemp;
	}



	pnFlag = (int*)malloc(2000 * sizeof(int));
	memset(pnFlag, false, 2000 * sizeof(int));
	pnFlag[0] = true;

	for (int i = 0; i < nCount; i++)
	{
		for (int j = 1999; j >= 0; j--)
			if (pnFlag[j])
				pnFlag[j + pnSeq[i]] = true;
	}
		
			
	for (int i = 1; i < 2000; i++)
		if (pnFlag[i])
			nAns++;

	printf("Total=%d", nAns);




Exit0:

	return 0;
}