/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-17 22:04
//	Comment		:	OJ(P2651)
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
#define	MAXNUM		10005
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

int CalcGCD(int a, int b)
{
	if (a%b == 0)
		return b;
	return CalcGCD(b, a%b);
}


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
	int				nInputN;
	int				nInputT;
	int*			pnSeq;

	pnSeq = (int*)malloc(MAXNUM * sizeof(int));
	scanf("%d", &nInputN);

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", &nInputT);
		for (int j = 0; j < nInputT; j++)
			scanf("%d", pnSeq + j);

		for (int j = 0; j < nInputT; j++)
		{
			if (j == 1)
				continue;
			else
				pnSeq[1] = pnSeq[1] / CalcGCD(pnSeq[1], pnSeq[j]);
		}
		if (pnSeq[1] == 1)
			printf("Yes\n");
		else
			printf("No\n");
	}


Exit0:

	return 0;
}



