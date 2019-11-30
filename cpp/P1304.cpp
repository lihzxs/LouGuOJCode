/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-16 11:24
//	Comment		:	OJ(P1304)
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
#define	MAXNUM		20000
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
	BYTE*				pbyIsPrime = NULL;
	unsigned int*		punSeq = NULL;
	int					nInputN;
	int					nIndex			= 0;

	scanf("%d", &nInputN);



	pbyIsPrime = (BYTE*)malloc(MAXNUM * sizeof(BYTE));

	punSeq = (unsigned int*)malloc(MAXNUM * sizeof(unsigned int));

	nIndex = PrimeInit(punSeq, pbyIsPrime);

	for (int i = 4; i <= nInputN; i += 2)
	{
		for (int j = 0; j < nIndex; j++)
			if (i - punSeq[j] >=2 && pbyIsPrime[i - punSeq[j]])
			{
				printf("%d=%d+%d\n", i, punSeq[j], i - punSeq[j]);
				break;
			}
	}














Exit0:

	if (punSeq)
		free(punSeq);
	if (pbyIsPrime)
		free(pbyIsPrime);




	return 0;
}



