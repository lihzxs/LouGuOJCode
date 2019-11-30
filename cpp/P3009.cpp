/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-20 10:59
//	Comment		:	OJ(P3009)
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
#define	MAXNUM		20000
#define	EPS         0.0001
#define DIRNUM		4
#define ERROR_ID    0

typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;




int main(int argc, char* argv[])
{
	int				nInputN;
	int				nSumMax			= 0;
	int				nAns			= 0;
	BOOL			bIsAllNeg		= true;
	int*			pnSeq			= NULL;
	
	scanf("%d", &nInputN);

	pnSeq = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", pnSeq + i);
		if (pnSeq[i] >= 0)
			bIsAllNeg = false;
	}
		

	for (int i = 0; i < nInputN; i++)
	{
		nSumMax += pnSeq[i];
		if (nAns < nSumMax)
			nAns = nSumMax;
		else if (nSumMax < 0)
			nSumMax = 0;
	}

	if (bIsAllNeg)
	{
		sort(pnSeq, pnSeq + nInputN);
		printf("%d", pnSeq[nInputN - 1]);
	}
	else
		printf("%d", nAns);

	

Exit0:

	return 0;
}

