/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-16 19:23
//	Comment		:	OJ(P2669)
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
	int			nInputK;
	int			nSum		= 0;
	int			nCount		= 0;
	int			nAddItem	= 1;


	scanf("%d", &nInputK);

	while (true)
	{
		nSum += nAddItem * nAddItem;
		nCount += nAddItem;
		if (nCount > nInputK)
		{
			nSum -= (nCount - nInputK) * nAddItem;
		}
		if (nCount >= nInputK)
		{
			printf("%d\n", nSum);
			return 0;
		}
		nAddItem++;
	}

Exit0:




	return 0;
}



