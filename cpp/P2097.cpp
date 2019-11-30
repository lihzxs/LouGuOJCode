/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-24 20:54
//	Comment		:	OJ(P2097)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
#include <set>
#include <queue>
#include <map>

using namespace std;
#define	MAXNUM		1000000001
#define	EPS         0.0001
#define MODNUM		2e31


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int Fin(int* pnSeq,int item)
{
	if (pnSeq[item] != item)
		pnSeq[item] = Fin(pnSeq, pnSeq[item]);
	return pnSeq[item];
		
}


int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int				nSideFirst;
	int				nSideSecond;
	int				nAns			= 0;
	int*			pnSeq			= NULL;
	
	scanf("%d%d", &nInputN, &nInputM);


	pnSeq = (int*)malloc((nInputN + 1)* sizeof(int));

	for (int i = 1; i <= nInputN; i++)
		pnSeq[i] = i;

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d", &nSideFirst, &nSideSecond);
		pnSeq[Fin(pnSeq, nSideFirst)] = Fin(pnSeq, nSideSecond);
	}

	for (int i = 1; i <= nInputN; i++)
		if (pnSeq[i] == i)
			nAns++;

	printf("%d", nAns);






			

Exit0:

	return 0;
}