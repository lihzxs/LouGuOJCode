/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-16 00:02
//	Comment		:	OJ(P1865)
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
#define	MAXNUM		1000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;
int PrimeInit(unsigned int* punSeq, BYTE* pbyIsPrime)
{
	int		nIndex = 0;
	memset(pbyIsPrime, true, MAXNUM * sizeof(BYTE));
	pbyIsPrime[0] = false;
	pbyIsPrime[1] = false;//
	for (int i = 2; i < MAXNUM; i++)
	{
		if (pbyIsPrime[i])
		{
			punSeq[nIndex++] = i;
			for (int j = i * 2; j < MAXNUM; j += i)
				pbyIsPrime[j] = 0;
		}
	}
	return nIndex;
}

int main(int argc, char* argv[])
{
	BYTE*				pbyIsPrime = NULL;
	unsigned int*		punSeq = NULL;
	int					nTemp;
	int					nIndex = 0;
	pbyIsPrime = (BYTE*)malloc(MAXNUM * sizeof(BYTE));
	punSeq = (unsigned int*)malloc(MAXNUM * sizeof(unsigned int));
	nIndex = PrimeInit(punSeq, pbyIsPrime);



	int				nInputN;
	int				nInputM;
	int				nLeft;
	int				nRight;
	int				nAns			= 0;
	scanf("%d%d", &nInputN, &nInputM);

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d", &nLeft, &nRight);
		if (nLeft < 1 || nRight > nInputM)
		{
			printf("Crossing the line\n");
			continue;
		}
		nAns = 0;
		for (int i = nLeft; i <= nRight; i++)
			if (pbyIsPrime[i])
				nAns++;

		printf("%d\n", nAns);


	}

Exit0:

	return 0;
}