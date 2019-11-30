/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-16 14:49
//	Comment		:	OJ(P2077)
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

	int					nInputN;
	int					nInputM;
	int					nAns				= 0;
	int*				pnSeqDis			= NULL;
	int*				pnSeqR				= NULL;
	int*				pnSeqG				= NULL;

	scanf("%d%d", &nInputN, &nInputM);

	pnSeqDis = (int*)malloc((nInputN + 1) * sizeof(int));
	pnSeqR = (int*)malloc((nInputN + 1) * sizeof(int));
	pnSeqG = (int*)malloc((nInputN + 1) * sizeof(int));

	for (int i = 1; i < nInputN; i++)
		scanf("%d", pnSeqDis + i);

	for (int i = 1; i <= nInputN; i++)
		scanf("%d", pnSeqR + i);

	for (int i = 1; i <= nInputN; i++)
		scanf("%d", pnSeqG + i);

	nAns += nInputM;
	for (int i = 1; i <= nInputN; i++)
	{
		if (nAns % (pnSeqG[i] + pnSeqR[i]) > pnSeqG[i])
			nAns += pnSeqG[i] + pnSeqR[i] - nAns % 
			(pnSeqG[i] + pnSeqR[i]);
		printf("%d\n", nAns);
		nAns += pnSeqDis[i];
	}


	



Exit0:

	return 0;
}



