/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-16 21:33
//	Comment		:	OJ(P1469)
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
	unsigned int			unInputN;
	unsigned int			unInputNum;
	unsigned int			unPreInput;

	scanf("%u", &unInputN);

	scanf("%u", &unPreInput);

	for (int i = 1; i < unInputN; i++)
	{
		scanf("%u", &unInputNum);
		unPreInput = unPreInput ^ unInputNum;
	}

	printf("%u", unPreInput);




Exit0:

	return 0;
}



