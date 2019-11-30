/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-13 16:43
//	Comment		:	OJ(P5051)
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
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputK;
	int				nInputM;
	int*			pnSeq				= NULL;

	scanf("%d%d%d", &nInputN, &nInputK, &nInputM);
	pnSeq = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnSeq, 0, (nInputN + 1) * sizeof(int));
	while (nInputM > 0)
	{
		for (int i = 1; i <= nInputN; i++)
		{
			if (nInputM <= 0)
				break;
			pnSeq[i] += min(nInputM, nInputK);
			nInputM -= nInputK;
		}
		for (int i = nInputN - 1; i >= 2; i--)
		{
			if (nInputM <= 0)
				break;
			pnSeq[i] += min(nInputM, nInputK);
			nInputM -= nInputK;
		}
	}
	for (int i = 1; i <= nInputN; i++)
		printf("%d ", pnSeq[i]);



Exit0:

	return 0;
}