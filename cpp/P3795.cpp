/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-30 16:20
//	Comment		:	OJ(P3795)
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
#define MODNUM		14233333


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int main(int argc, char* argv[])
{
	int				nInputN;
	int*			pnSeq			= NULL;
	long long		nPre;
	long long		nPrePre;
	int				nCount			= 2;
	long long		nAns			= 0;
	scanf("%d", &nInputN);

	nPre = 1;
	nPrePre = 1;

	while (nCount <= nInputN)
	{
		nAns = (nPre + (nCount - 1) * nPrePre) % MODNUM;
		nPrePre = nPre;
		nPre = nAns;
		nCount++;
	}


	printf("%lld", nAns);

Exit0:

	return 0;
}