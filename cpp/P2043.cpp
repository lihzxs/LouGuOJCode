/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-17 20:29
//	Comment		:	OJ(P2043)
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
#define	MAXNUM		100010
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
	BYTE*				pbyIsPrime			= NULL;
	unsigned int*		punSeq				= NULL;
	unsigned int*		punCount			= NULL;
	int					nInputN;
	int					nTemp;
	int					nIndex = 0;

	scanf("%d", &nInputN);

	pbyIsPrime = (BYTE*)malloc(MAXNUM * sizeof(BYTE));

	punSeq = (unsigned int*)malloc(MAXNUM * sizeof(unsigned int));

	punCount = (unsigned int*)malloc(MAXNUM * sizeof(unsigned int));

	memset(punCount, 0, MAXNUM * sizeof(unsigned int));

	nIndex = PrimeInit(punSeq, pbyIsPrime);

	for (int i = 2; i <= nInputN; i++)
	{
		nTemp = i;
		for (int j = 0; punSeq[j] <= nTemp && nTemp != 1; j++)
		{
			while (nTemp % punSeq[j] == 0)
			{
				punCount[punSeq[j]]++;
				nTemp /= punSeq[j];
			}
		}
	}///for (int i = 2; i <= nInputN; i++)


	for (int j = 0; punSeq[j] <= nInputN; j++)
		if (punCount[punSeq[j]])
			printf("%d %d\n", punSeq[j], punCount[punSeq[j]]);



Exit0:

	return 0;
}



