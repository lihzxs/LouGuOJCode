/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-23 9:20
//	Comment		:	OJ(P1893)
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
#define	MAXNUM		100000
#define	EPS         0.0001
#define MODNUM		2e31


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;






int main(int argc, char* argv[])
{
	int			nInputN;
	int*		pnSeq		= NULL;
	int			nLeft;
	int			nRight;
	int			nAns		= 0;
	scanf("%d", &nInputN);
	pnSeq = (int*)malloc((nInputN + 1) * sizeof(int));
	pnSeq[0] = 0;
	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeq + i + 1);

	for (int i = 1; i < nInputN + 1; i++)
	{
		nLeft = i;
		nRight = i;

		while (nLeft > 1 && pnSeq[nLeft - 1] <= pnSeq[nLeft])
			nLeft--;
		while (nRight < nInputN && pnSeq[nRight + 1] <= pnSeq[nRight])
			nRight++;

		nAns = max(nAns, nRight - nLeft + 1);
	}

	printf("%d", nAns);





Exit0:

	return 0;
}