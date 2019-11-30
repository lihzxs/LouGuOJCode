/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-17 13:57
//	Comment		:	OJ(P1652)
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
#define	MAXNUM		10000
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

	int					nInputN;
	int					nInputX1;
	int					nInputY1;
	int					nInputX2;
	int					nInputY2;
	int					nFlag1			= 0;
	int					nFlag2			= 0;
	int					nAns			= 0;
	int*				pnSeqX			= NULL;
	int*				pnSeqY			= NULL;
	int*				pnSeqR			= NULL;

	scanf("%d", &nInputN);

	pnSeqX = (int*)malloc(nInputN * sizeof(int));
	pnSeqY = (int*)malloc(nInputN * sizeof(int));
	pnSeqR = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeqX + i);
	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeqY + i);
	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeqR + i);
	
	scanf("%d%d%d%d", &nInputX1, &nInputY1, &nInputX2, &nInputY2);

	for (int i = 0; i < nInputN; i++)
	{
		if ((pnSeqX[i] - nInputX1) * (pnSeqX[i] - nInputX1) +
			(pnSeqY[i] - nInputY1) * (pnSeqY[i] - nInputY1) < 
			pnSeqR[i] * pnSeqR[i])
			nFlag1 = 1;
		if ((pnSeqX[i] - nInputX2) * (pnSeqX[i] - nInputX2) +
			(pnSeqY[i] - nInputY2) * (pnSeqY[i] - nInputY2) <
			pnSeqR[i] * pnSeqR[i])
			nFlag2 = 1;

		if (nFlag1 != nFlag2)
			nAns++;

		nFlag1 = 0;
		nFlag2 = 0;
	}


	printf("%d", nAns);


Exit0:

	return 0;
}



