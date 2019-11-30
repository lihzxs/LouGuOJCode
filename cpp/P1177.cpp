/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-22 22:25
//	Comment		:	OJ(P1177)
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

int n = 5;

void QuickSort(int* pnSeq, int nStart, int nEnd)
{
	if (nStart > nEnd)
		return;
	int			nTemp;
	int i, j;
	i = nStart;
	j = nEnd;
	nTemp = pnSeq[nStart];

	while (i != j)
	{
		while (pnSeq[j] >= nTemp && j > i)
			j--;
		while (pnSeq[i] <= nTemp && i < j)
			i++;
		if (i < j)
			swap(pnSeq[i], pnSeq[j]);
	}
	swap(pnSeq[i], pnSeq[nStart]);
	QuickSort(pnSeq, nStart, i - 1);
	QuickSort(pnSeq, i + 1, nEnd);
}





int main(int argc, char* argv[])
{
	int				nInputN;
	int*			pnSeq			= NULL;
	scanf("%d", &nInputN);

	pnSeq = (int*)malloc((nInputN + 1) * sizeof(int));


	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeq + i + 1);

	QuickSort(pnSeq, 1, nInputN);

	for (int i = 1; i < nInputN + 1; i++)
		printf("%d ", pnSeq[i]);







Exit0:

	return 0;
}