/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-16 15:05
//	Comment		:	OJ(P4086)
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
	int					nInputN;
	int*				pnSeq				= NULL;
	int*				pnAns				= NULL;
	int					nMin;
	int					nSum;
	double				fAvg				= 0;
	int					nAns				= 0;
	scanf("%d", &nInputN);
	pnSeq = (int*)malloc((nInputN + 1) * sizeof(int));
	pnAns = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnAns, 0, (nInputN + 1) * sizeof(int));
	for (int i = 1; i <= nInputN; i++)
		scanf("%d", pnSeq + i);

	pnSeq[0] = 0;

	nMin = pnSeq[nInputN];
	nSum = pnSeq[nInputN];

	for (int i = nInputN - 1; i >= 2; i--)
	{
		nMin = min(nMin, pnSeq[i]);
		nSum += pnSeq[i];
		if ((nSum - nMin) * 1.0 / (nInputN - i) > fAvg)
		{
			nAns = 1;
			pnAns[nAns] = i - 1;
			fAvg = (nSum - nMin) * 1.0 / (nInputN - i);
		}
		else if ((nSum - nMin) * 1.0 / (nInputN - i) == fAvg)
		{
			pnAns[++nAns] = i - 1;
		}
	}
	for (int i = nAns; i >= 1; i--)
		printf("%d\n", pnAns[i]);


Exit0:

	return 0;
}