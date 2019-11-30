/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-18 15:46
//	Comment		:	OJ(P2640)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <stack>
#include <string>
#include <string.h>
#include <set>
using namespace std;
#define	MAXNUM		10010
#define	EPS         0.0001

typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int PrimeInit(unsigned int* punSeq, BYTE* pbyIsPrime)
{
	int		nIndex = 0;
	memset(pbyIsPrime, true, MAXNUM * sizeof(BYTE));
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
	BYTE*				pbyIsPrime				= NULL;
	unsigned int*		punSeq					= NULL;
	int					nInputN;
	int					nInputK;
	BOOL				bFlag					= false;
	int					nIndex					= 0;

	scanf("%d%d", &nInputN, &nInputK);

	pbyIsPrime = (BYTE*)malloc(MAXNUM * sizeof(BYTE));

	punSeq = (unsigned int*)malloc(MAXNUM * sizeof(unsigned int));


	nIndex = PrimeInit(punSeq, pbyIsPrime);

	for (int i = 0; i < nIndex && 
		punSeq[i] + nInputK <= nInputN; i++)
	{
		if (pbyIsPrime[punSeq[i] + nInputK])
		{
			bFlag = true;
			printf("%d %d\n", punSeq[i],
				punSeq[i] + nInputK);
		}
	}

	if (!bFlag)
		printf("empty\n");







	


Exit0:

	return 0;
}