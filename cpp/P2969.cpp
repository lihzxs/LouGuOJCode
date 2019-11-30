/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-27 17:19
//	Comment		:	OJ(P2969)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
#include <set>
#include <queue>
#include <list>
#include <map>

using namespace std;
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;






int main(int argc, char* argv[])
{
	int								nInputN;
	int								nInputQ;
	int								nPreInput			= 0;
	int								nRecord				= 0;
	int*							pnSeq				= NULL;
	int								nInputTemp;
	
	scanf("%d%d", &nInputN, &nInputQ);
	pnSeq = (int*)malloc((nInputN  + 1)* sizeof(int));

	pnSeq[0] = 0;
	for (int i = 1; i <= nInputN; i++)
	{
		scanf("%d", &nInputTemp);
		pnSeq[i] = pnSeq[i - 1] + nInputTemp;
	}

	for (int i = 1; i <= nInputQ; i++)
	{
		scanf("%d", &nInputTemp);
		printf("%d\n", upper_bound(pnSeq, pnSeq + nInputN + 1, nInputTemp) - pnSeq);
	}
Exit0:

	return 0;
}