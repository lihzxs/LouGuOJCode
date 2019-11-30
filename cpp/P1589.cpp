/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-2 19:51
//	Comment		:	OJ(P1589)
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
	int				nInputN;
	int				nInputL;
	int*			pnSeq					= NULL;
	int				nStart					= 0;
	int				nCount					= 0;
	int				nNum;
	scanf("%d%d", &nInputN, &nInputL);

	pnSeq = (int*)malloc(2 * nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
		scanf("%d%d", &pnSeq[2 * i], &pnSeq[2 * i + 1]);

	sort(pnSeq, pnSeq + 2 * nInputN);
	nStart = 0;
	for (int i = 0; i < nInputN; i++)
	{
		nStart = max(nStart, pnSeq[2 * i]);
		while (nStart < pnSeq[2 * i + 1])
		{
			nStart += nInputL;
			nCount++;
		}
	}

	printf("%d", nCount);




Exit0:

	return 0;
}