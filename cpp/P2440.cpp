/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-20 19:02
//	Comment		:	OJ(P2440)
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

bool Check(int* pnSeqL, int nN, int nX, int nTarget)
{
	int nCount = 0;
	for (int i = 0; i < nN; i++)
	{
		nCount += pnSeqL[i] / nX;
		if (nCount >= nTarget)
			return true;
	}
	return false;
}



int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputK;
	long long		llSum				= 0;
	int*			pnSeqL				= NULL;

	int				nLeft;
	int				nRight;
	int				nMid;
	
	scanf("%d%d", &nInputN, &nInputK);

	pnSeqL = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", pnSeqL + i);
		llSum += pnSeqL[i];
	}

	nLeft = 0;
	nRight = llSum / nInputN;

	while (nLeft + 1 < nRight)
	{
		nMid = (nLeft + nRight) / 2;
		if (nMid == 0)
		{
			nLeft = 0;
			printf("0");
			return 0;
		}
		if (Check(pnSeqL, nInputN, nMid, nInputK))
			nLeft = nMid;
		else
			nRight = nMid - 1;

	}
	
	if (nRight == 0)
	{
		nLeft = 0;
		printf("0");
		return 0;
	}
	

	if (Check(pnSeqL, nInputN, nRight, nInputK))
		printf("%d", nRight);
	else
		printf("%d", nLeft);

		






Exit0:
	return 0;
}