/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-5 22:40
//	Comment		:	OJ(P3383)
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
#define	MAXNUM		10000000
#define	EPS         0.0001

typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int PrimeInit(unsigned int* punSeq, BYTE* pbyIsPrime)
{
	int		nIndex = 0;
	memset(pbyIsPrime, true, MAXNUM * sizeof(BYTE));
	pbyIsPrime[0] = false;
	pbyIsPrime[1] = false;
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
	BYTE*				pbyIsPrime = NULL;
	unsigned int*		punSeq = NULL;
	unsigned int*		punCount = NULL;
	int					nInputN;
	int					nTemp;
	int					nIndex = 0;
	int					nInputM;


	pbyIsPrime = (BYTE*)malloc(MAXNUM * sizeof(BYTE));

	punSeq = (unsigned int*)malloc(MAXNUM * sizeof(unsigned int));


	nIndex = PrimeInit(punSeq, pbyIsPrime);


	scanf("%d%d", &nInputN, &nInputM);

	while (nInputM--)
	{
		scanf("%d", &nTemp);
		if (pbyIsPrime[nTemp])
			printf("Yes");
		else
			printf("No");
		printf("\n");
	}



Exit0:

	return 0;
}