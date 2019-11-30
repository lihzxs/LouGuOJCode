/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-5 21:05
//	Comment		:	OJ(P1678)
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
#include <sstream>

using namespace std;
#define	MAXNUM		100000000
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int Seach(int* pS, int nLen,int nNum)
{
	int nLow = 0;
	int nHigh = nLen;
	int nMid = (nLow + nHigh) / 2;
	while (nLow < nHigh)
	{
		if (pS[nMid] <= nNum)
			nLow = nMid + 1;
		else
			nHigh = nMid;
		nMid = (nLow + nHigh) / 2;
	}
	return nMid;
}



int main(int argc, char* argv[])
{
	int			nInputM;
	int			nInputN;
	int*		pnSeqSchool			 = NULL;
	int*		pnSeqStu			 = NULL;
	int			nSum				 = 0;
	int			nIndex;
	scanf("%d%d", &nInputM, &nInputN);
	pnSeqSchool = (int*)malloc(nInputM * sizeof(int));
	pnSeqStu = (int*)malloc(nInputN * sizeof(int));

	


	for (int i = 0; i < nInputM; i++)
		scanf("%d", pnSeqSchool + i);
	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeqStu + i);

	sort(pnSeqSchool, pnSeqSchool + nInputM);


	for (int i = 0; i < nInputN; i++)
	{
		if (pnSeqStu[i] < pnSeqSchool[0])
			nSum += pnSeqSchool[0] - pnSeqStu[i];
		else
		{
			nIndex = Seach(pnSeqSchool, nInputM - 1, pnSeqStu[i]);
			nSum += min(abs(pnSeqSchool[nIndex - 1] - pnSeqStu[i]),
				abs(pnSeqSchool[nIndex] - pnSeqStu[i]));
		}
	}

	printf("%d", nSum);

Exit0:
	return 0;
}