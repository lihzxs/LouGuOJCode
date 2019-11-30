/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-15 19:55
//	Comment		:	OJ(P1614)
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
#define	MAXNUM		2000
#define	EPS         1e-8

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
	int			nInputN;
	int			nInputM;
	int			nMinSum			= 300001;
	int			nSum			= 0;
	int*		pnInputNum		= NULL;

	scanf("%d%d", &nInputN, &nInputM);

	pnInputNum = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnInputNum + i);

	for (int i = 0; i <= nInputN - nInputM; i++)
	{
		for (int j = i; j < i + nInputM; j++)
		{
			nSum += pnInputNum[j];
		}
		if (nSum < nMinSum)
			nMinSum = nSum;
		nSum = 0;
	}

	printf("%d", nMinSum);


Exit0:

	return 0;
}




