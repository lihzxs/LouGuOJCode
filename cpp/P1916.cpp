/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-22 16:08
//	Comment		:	OJ(P1916)
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
#define	MAXNUM		150
#define	EPS         0.0001
#define MODNUM		1000000007ll


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;








int main(int argc, char* argv[])
{
	int			nInputN;
	int			nInputM;
	int			nInputK;
	int			nInputW;
	int			nInputR;
	int*		pnSeq = NULL;
	int			nAns = 0;

	scanf("%d%d%d%d%d", &nInputN, &nInputM,
		&nInputK, &nInputW, &nInputR);

	pnSeq = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeq + i);

	sort(pnSeq, pnSeq + nInputN);

	pnSeq[0] = pnSeq[0] * 1.0 / (nInputM / nInputK * nInputW) + 1;

	if (pnSeq[0] > nInputR)
		printf("%d", nInputN - 1);
	else
	{
		for (int i = 1; i < nInputN; i++)
		{
			int t = int(pnSeq[i] * 1.0 / (nInputM / nInputK * nInputW) + 1);
			pnSeq[i] = pnSeq[i - 1] + t;
			if (pnSeq[i] > nInputR)
			{
				nAns = nInputN - i;
				break;
			}
		}

		printf("%d", nAns);

	}





Exit0:

	return 0;
}