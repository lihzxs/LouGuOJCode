/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-14 22:48
//	Comment		:	OJ(P2006)
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
#define	MAXNUM		30001
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



int main(int argc, char* argv[])
{
	long		lInputK;
	long		lInputM;
	long		lInputN;
	long		lInputMagicValue;
	long		lInputHurtValue;
	int			nCount				= -1;
	int*		pnAnsSeq;

	pnAnsSeq = (int*)malloc(MAXNUM * sizeof(int));

	scanf("%ld%ld%ld", &lInputK, &lInputM, &lInputN);


	for (int i = 0; i < lInputM; i++)
	{
		scanf("%ld%ld", &lInputMagicValue, &lInputHurtValue);
		if (lInputMagicValue == 0)
		{
			pnAnsSeq[++nCount] = i + 1;
			continue;
		}
		if (lInputK / lInputMagicValue * lInputHurtValue >= lInputN)
		{
			pnAnsSeq[++nCount] = i + 1;
		}
	}

	if(nCount == -1)
		printf("-1\n");
	else
	{
		printf("%d", pnAnsSeq[0]);
		for (int i = 1; i <= nCount; i++)
		{
			printf(" %d", pnAnsSeq[i]);
		}
	}






Exit0:

	return 0;
}






