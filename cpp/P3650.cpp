/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-29 21:49
//	Comment		:	OJ(P3650)
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
	int*			pnSeq			= NULL;
	int				nSum			= 0;

	int				nMin			= 10000000;

	scanf("%d", &nInputN);

	pnSeq = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeq + i);

	sort(pnSeq, pnSeq + nInputN);

	for (int i = pnSeq[nInputN - 1]; i >= pnSeq[0]; i--)
	{
		for (int j = 0; j < nInputN; j++)
		{
			if (pnSeq[j] > i)
				nSum += (pnSeq[j] - i) * (pnSeq[j] - i);
			else if (i - pnSeq[j] > 17)
				nSum += (i - pnSeq[j] - 17) * (i - pnSeq[j] - 17);
		}
		if (nSum < nMin)
			nMin = nSum;
		nSum = 0;

	}

	printf("%d", nMin);


Exit0:

	return 0;
}