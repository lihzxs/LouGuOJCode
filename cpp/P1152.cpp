/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-16 22:08
//	Comment		:	OJ(P1152)
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
#define	MAXNUM		2000001
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
	int				nInputTemp;
	int				nInputN;
	int				nPreNum;
	BOOL*			pbIsExist			= NULL;

	scanf("%d", &nInputN);

	if (nInputN == 1)
	{
		printf("Not jolly");
		return 0;
	}

	pbIsExist = (BOOL*)malloc(nInputN * sizeof(int));
	memset(pbIsExist, false, nInputN * sizeof(int));

	scanf("%d", &nPreNum);
	for (int i = 1; i < nInputN; i++)
	{
		scanf("%d", &nInputTemp);
		if (abs(nInputTemp - nPreNum) < nInputN)
			pbIsExist[abs(nInputTemp - nPreNum)] = true;
	
	    nPreNum = nInputTemp;
	}

	for (int i = 1; i < nInputN; i++)
	{
		if (!pbIsExist[i])
		{
			printf("Not jolly");
			return 0;
		}
	}

	printf("Jolly");




Exit0:

	return 0;
}



