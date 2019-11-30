/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-17 16:15
//	Comment		:	OJ(P2165)
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
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		2e31


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;




int main(int argc, char* argv[])
{

	int				nInputN;
	int*			pnSeq			= NULL;
	int*			pnSum			= NULL;
	int				nSum			= 0;
	int				nAns			= 0;
	scanf("%d", &nInputN);
	pnSeq = (int*)malloc((nInputN + 1) * sizeof(int));
	pnSum = (int*)malloc((nInputN + 1) * sizeof(int));
	pnSum[0] = 0;

	for (int i = 1; i <= nInputN; i++)
	{
		scanf("%d", pnSeq + i);
		pnSum[i] = pnSum[i - 1] + pnSeq[i];
		nSum += pnSeq[i];
	}

	for (int i = 1; i <= nInputN; i++)
		for (int j = i + 1; j <= nInputN; j++)
			if (pnSum[j] - pnSum[i] == nSum / 2)
				nAns++;

	printf("%d", nAns * (nAns - 1) / 2);

		



Exit0:

	return 0;
}