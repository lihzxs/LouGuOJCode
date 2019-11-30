/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-16 15:17
//	Comment		:	OJ(P1089)
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

	int					nInputNum;
	int					nPreMonth			= 0;
	int					nSave				= 0;

	for (int i = 0; i < 12; i++)
	{
		scanf("%d", &nInputNum);
		if (300 + nPreMonth - nInputNum < 0)
		{
			printf("-%d", i + 1);
			return 0;
		}
		else
		{
			nSave += (300 + nPreMonth - nInputNum) -
				(300 + nPreMonth - nInputNum) % 100;
			nPreMonth = (300 + nPreMonth - nInputNum) % 100;
		}
			
	}

	printf("%d", (int)(nSave * 1.2) + nPreMonth);




	



Exit0:

	return 0;
}



