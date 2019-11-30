/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-18 23:36
//	Comment		:	OJ(P3078)
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
#include <list>
#include <float.h>

using namespace std;
#define	MAXNUM		1000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int					nInputN;
	int*				pnSeq			= NULL;
	int*				pnDis			= NULL;
	long long			llAns			= 0;
	
	scanf("%d", &nInputN);

	pnSeq = (int*)malloc((nInputN + 1) * sizeof(int));
	pnDis = (int*)malloc((nInputN + 1) * sizeof(int));
	pnSeq[0] = 0;
	for (int i = 1; i <= nInputN; i++)
		scanf("%d", pnSeq + i);

	for (int i = 1; i <= nInputN; i++)
		pnDis[i] = pnSeq[i] - pnSeq[i - 1];
	for (int i = 1; i <= nInputN; i++)
		if (pnDis[i] > 0)
			llAns += pnDis[i];

	printf("%lld", llAns);

Exit0:

	return 0;
}