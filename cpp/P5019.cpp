/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-8 23:33
//	Comment		:	OJ(P5019)
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

using namespace std;
#define	MAXNUM		150
#define	EPS         0.0001
#define MODNUM		1006


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;




int main(int argc, char* argv[])
{
	int							nInputN;
	int*						pnSeq;
	int							nAns = 0;
	scanf("%d", &nInputN);

	pnSeq = (int*)malloc((nInputN + 1) * sizeof(int));
	pnSeq[0] = 0;
	for (int i = 1; i <= nInputN; i++)
	{
		scanf("%d", pnSeq + i);
	}

	for (int i = 1; i <= nInputN; i++)
	{
		if (pnSeq[i - 1] < pnSeq[i])
			nAns += pnSeq[i] - pnSeq[i - 1];
	}

	printf("%d", nAns);



Exit0:

	return 0;
}