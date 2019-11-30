/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-24 19:16
//	Comment		:	OJ(P1376)
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




int main(int argc, char* argv[])
{
	int			nInputN;
	int			nInputS;
	int			nMin					= 6000;
	int*		pnSeq					= NULL;
	int*		pnNumM					= NULL;
	int			nNum					= 0;
	long long	nAns					= 0;

	scanf("%d%d", &nInputN, &nInputS);

	pnSeq = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d", pnSeq + i, &nNum);
		for (int j = 0; j < i; j++)
			if (pnSeq[j] + (i - j) * nInputS < nMin)
				nMin = pnSeq[j] + (i - j) * nInputS;

		if (nMin > pnSeq[i])
			nMin = pnSeq[i];

		nAns += nMin * nNum;
		nMin = 6000;


	}

	printf("%lld", nAns);



			

Exit0:

	return 0;
}