/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-16 15:06
//	Comment		:	OJ(P1138)
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
#define	MAXNUM		10010
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
	unsigned int*		punSeq			= NULL;
	int					nInputN;
	int					nInputK;
	int					nCount			= 1;

	scanf("%d%d", &nInputN, &nInputK);
	if (nInputN < nInputK)
	{
		printf("NO RESULT");
		return 0;
	}
		
	punSeq = (unsigned int*)malloc(nInputN * sizeof(unsigned int));
	
	for (int i = 0; i < nInputN; i++)
		scanf("%d", punSeq + i);
	sort(punSeq, punSeq + nInputN);

	for (int i = 1; i < nInputN; i++)
	{
		if (punSeq[i] > punSeq[i - 1])
			nCount++;
		if (nCount == nInputK)
		{
			printf("%d", punSeq[i]);
			return 0;
		}
	}
	if (nInputN == 1)
	{
		printf("%d", punSeq[0]);
		return 0;
	}
	printf("NO RESULT");













Exit0:




	return 0;
}



