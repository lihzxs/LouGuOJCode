/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-16 20:51
//	Comment		:	OJ(P1296)
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
	int				nInputN;
	int				nInputD;
	int				nAnsSum			= 0;
	int*			pnSeq			= NULL;

	scanf("%d%d", &nInputN, &nInputD);

	pnSeq = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeq + i);
		
	sort(pnSeq, pnSeq + nInputN);

	for (int i = 0; i < nInputN; i++)
		for (int j = i + 1; j < nInputN; j++)
			if (pnSeq[j] - pnSeq[i] <= nInputD)
				nAnsSum++;
			else
			    break;

	printf("%d", nAnsSum);



Exit0:

	return 0;
}



