/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-25 14:33
//	Comment		:	OJ(P1599)
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
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		2e31


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;






int main(int argc, char* argv[])
{

	int				nInputN;
	int*			pnSeq = NULL;
	int				nSumPos = 0;
	int				nSumNeg = 0;
	int				nAns = 0;
	int				nBackSum = 0;
	int				nPreIndex;

	stack<int>		sNegNumIndex;

	scanf("%d", &nInputN);
	pnSeq = (int*)malloc((nInputN + 1) * sizeof(int));

	for (int i = 1; i < nInputN + 1; i++)
		scanf("%d", pnSeq + i);

	for (int i = 1; i < nInputN + 1; i++)
	{

		if (pnSeq[i] > 0)
		{
			nSumPos += pnSeq[i];
			pnSeq[i] = 0;
		}
		else
		{
			sNegNumIndex.push(i);
			nSumNeg -= pnSeq[i];
		}
		if (nSumPos >= nSumNeg)
		{
			while (!sNegNumIndex.empty())
			{
				if (abs(pnSeq[sNegNumIndex.top()]) > nSumPos)
					break;
				nSumNeg += pnSeq[sNegNumIndex.top()];
				nSumPos += pnSeq[sNegNumIndex.top()];
				nBackSum = i - sNegNumIndex.top();;
				sNegNumIndex.pop();
			}
		}

		nAns += 2 * nBackSum;
		nBackSum = 0;
	
		nAns++;
	}

	printf("%d", nAns);














Exit0:

	return 0;
}