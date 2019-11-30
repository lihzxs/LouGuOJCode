/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-10 23:05
//	Comment		:	OJ(P2793)
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
	int				nInputH;
	int				nInputN;
	int				nInputK;
	int				nDis				= 0;
	long long		llAns				= 0;
	int*			pnSeq				= NULL;

	scanf("%d%d%d", &nInputN, &nInputH, &nInputK);

	pnSeq = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeq + i);

	for (int i = 0; i < nInputN; i++)
	{
		if (nDis + pnSeq[i] > nInputH)
		{
			llAns++;
			nDis = pnSeq[i];
		}
		else
			nDis += pnSeq[i];
		llAns += nDis / nInputK;
		nDis %= nInputK;
	}
	if (nDis != 0)
		llAns++;
	printf("%lld", llAns);


Exit0:

	return 0;
}