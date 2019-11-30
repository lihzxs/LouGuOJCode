/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-16 18:05
//	Comment		:	OJ(P1568)
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
using namespace std;
#define	MAXNUM		1000001
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
	int			nInputN;
	int			nInputM;
	int			nInputLong;
	int			nIputTime;
	int			nNBigerM		= 0;
	int			nSumTime		= 1;
	int			nIndex			= 1;
	int			nCount			= 0;
	int*		pnSeqN			= NULL;
	int*		pnSeqM			= NULL;

	pnSeqM = (int*)malloc(MAXNUM * sizeof(int));
	memset(pnSeqM, 0, MAXNUM * sizeof(int));
	pnSeqN = (int*)malloc(MAXNUM * sizeof(int));
	memset(pnSeqN, 0, MAXNUM * sizeof(int));

	scanf("%d%d", &nInputN, &nInputM);
	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d", &nInputLong, &nIputTime);
		for (int j = 0; j < nIputTime; j++)
			pnSeqN[nSumTime + j] = pnSeqN[nSumTime + j - 1] + nInputLong;
		nSumTime += nIputTime;
	}
	nSumTime = 1;
	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d", &nInputLong, &nIputTime);
		for (int j = 0; j < nIputTime; j++)
			pnSeqM[nSumTime + j] = pnSeqM[nSumTime + j - 1] + nInputLong;
		nSumTime += nIputTime;
	}


	for (int i = 1; i < nSumTime -1; i++)
	{
		if (pnSeqM[i] == pnSeqN[i] && pnSeqM[i] != pnSeqN[i])
		{
			nCount++;
		}
		else if((pnSeqM[i] > pnSeqN[i]) !=
			(pnSeqM[i + 1] > pnSeqN[i + 1]))
			nCount++;
	}

	printf("%d", nCount);

















Exit0:




	return 0;
}



