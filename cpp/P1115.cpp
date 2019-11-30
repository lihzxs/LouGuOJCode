/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-26 16:26
//	Comment		:	OJ(P1115)
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
#include <list>
#include <map>

using namespace std;
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

bool IsTrue(BOOL* pbFlag, int nNum)
{
	while (nNum != 0)
	{
		if (!pbFlag[nNum % 10])
			return false;
		nNum /= 10;
	}
	return true;
}




int main(int argc, char* argv[])
{
	int							nInputN;
	int							nMaxSum			= 0;
	int							nNowSum			= 0;
	int*						pnSeq			= NULL;
	BOOL						pIsAllNeg		= true;

	scanf("%d", &nInputN);
	pnSeq = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", pnSeq + i);
		if (pnSeq[i] >= 0)
			pIsAllNeg = false;
	}
	if (pIsAllNeg)
	{
		nMaxSum = pnSeq[0];
		for (int i = 1; i < nInputN; i++)
			if (pnSeq[i] > nMaxSum)
				nMaxSum = pnSeq[i];
	}
	else
	{
		for (int i = 0; i < nInputN; i++)
		{
			nNowSum += pnSeq[i];
			if (nNowSum > nMaxSum)
				nMaxSum = nNowSum;
			if (nNowSum < 0)
				nNowSum = 0;
		}
	}

	

	printf("%d", nMaxSum);



Exit0:

	return 0;
}