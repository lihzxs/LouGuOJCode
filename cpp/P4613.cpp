/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-16 23:10
//	Comment		:	OJ(P4613)
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
#define	MAXNUM		200000001
#define	EPS         0.0001


#define ERROR_ID    0

#define PROCESS_ERROR(Condition)    \
{                                   \
        if (!(Condition))           \
        {                           \
            goto Exit0;             \
        }                           \
}


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int PrimeInit(unsigned int* punSeq, BYTE* pbyIsPrime)
{
	int		nIndex = 0;
	memset(pbyIsPrime, 1, MAXNUM * sizeof(BYTE));
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
	int				nInputN;
	int				nInputTemp;
	int*			pnSeqA;
	int*			pnSeqB;

	scanf("%d", &nInputN);

	pnSeqA = (int*)malloc(nInputN * sizeof(int));
	pnSeqB = (int*)malloc(nInputN * sizeof(int));
	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeqA + i);
	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeqB + i);

	sort(pnSeqA, pnSeqA + nInputN);
	sort(pnSeqB, pnSeqB + nInputN);
	for (int i = 0; i < nInputN; i++)
	{
		if (pnSeqA[i] > pnSeqB[i])
		{
			printf("NE");
			goto Exit0;
		}
	}
	printf("DA");


Exit0:

	return 0;
}



