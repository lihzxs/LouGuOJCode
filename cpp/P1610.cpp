/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-22 19:53
//	Comment		:	OJ(P1610)
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
	int			nDis;
	int*		pnSeq		= NULL;
	int			nAns		= 0;

	scanf("%d%d", &nInputN, &nDis);

	pnSeq = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeq + i);

	sort(pnSeq, pnSeq + nInputN);

	for (int i = 1; i < nInputN - 1; i++)
	{
		if (pnSeq[i - 1] && pnSeq[i + 1] - pnSeq[i - 1] <= nDis)
		{
			pnSeq[i] = 0;
			nAns++;
		}
		else
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (pnSeq[j] && pnSeq[i + 1] - pnSeq[j] <= nDis)
				{
					pnSeq[i] = 0;
					nAns++;
				}
				if (pnSeq[j])
					break;
			}
		}
	}
	printf("%d", nAns);


Exit0:

	return 0;
}