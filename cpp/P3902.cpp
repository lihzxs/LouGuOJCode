/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-16 23:17
//	Comment		:	OJ(P3902)
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
	int				nInputN;
	int*			pnSeq					= NULL;
	int*			pnCount					= NULL;
	int				nCount					= 0;
	int				nTemp;
	int				nAns					= 0;
	scanf("%d", &nInputN);

	pnSeq = (int*)malloc(nInputN * sizeof(int));
	pnCount = (int*)malloc(nInputN * sizeof(int));
	pnSeq[0] = 0;
	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", &nTemp);
		if (nTemp > pnSeq[nCount])
			pnSeq[++nCount] = nTemp;
		else
		{
			*(lower_bound(pnSeq + 1, pnSeq + nCount + 1, nTemp)) = nTemp;
			nAns++;
		}
	}

	printf("%d", nAns);





Exit0:

	return 0;
}