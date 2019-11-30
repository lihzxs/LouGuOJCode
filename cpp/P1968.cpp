/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-30 19:06
//	Comment		:	OJ(P1968)
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

int CalcGCD(int a, int b)
{
	if (a%b == 0)
		return b;
	return CalcGCD(b, a%b);
}

int main(int argc, char* argv[])
{
	int					nInputN;
	int*				pnSeq				= NULL;
	int					nMax				= 0;
	int					nMin				= 0;
	int					nMaxIndex;
	double				nD					= 100;
	double				nM					= 0;
	double				nTemp;


	scanf("%d", &nInputN);

	pnSeq = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeq + i);

	for (int i = 0; i < nInputN; i++)
	{
		nTemp = nM;
		nM = max(nM, nD * pnSeq[i]);
		nD = max(nD, nTemp / pnSeq[i]);
	}

	printf("%.2f", nD);




Exit0:

	return 0;
}