/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-16 15:39
//	Comment		:	OJ(P1909)
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
	int			nHaveMoney;
	int			nAns			= 100000001;
	int			nNum;
	int			nPrice;

	scanf("%d", &nHaveMoney);
	for (int i = 0; i < 3; i++)
	{
		scanf("%d%d", &nNum, &nPrice);
		if (nHaveMoney / nNum * nPrice + 
			(nHaveMoney % nNum > 0 ? nPrice : 0) < nAns)
			nAns = nHaveMoney / nNum * nPrice + 
			(nHaveMoney % nNum > 0 ? nPrice : 0);
	}
	printf("%d", nAns);









Exit0:




	return 0;
}



