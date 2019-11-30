/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-15 00:20
//	Comment		:	OJ(P1638)
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
#define	MAXNUM		100000000
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int main(int argc, char* argv[])
{
	int					nInputN;
	int					nInputM;
	int*				pnSeq			 = NULL;
	int*				pnFlag			 = NULL;
	int					nLeft;
	int					nRight;
	int					nPeople;
	int					nAnsL;
	int					nAnsR;
	int					nMin			 = 1000000000;

	scanf("%d%d", &nInputN, &nInputM);

	pnFlag = (int*)malloc(2005 * sizeof(int));
	memset(pnFlag, 0, 2005 * sizeof(int));
	pnSeq = (int*)malloc((nInputN + 10) * sizeof(int));
	for (int i = 1; i <= nInputN; i++)
		scanf("%d", &pnSeq[i]);

	pnSeq[nInputN + 1] = 0;

	nLeft = 1;
	nRight = 1;
	pnFlag[pnSeq[1]] = 1;
	nPeople = 1;
	while (nLeft <= nRight && nRight <= nInputN)
	{
		if (nPeople == nInputM)
		{
			if (nMin > nRight - nLeft + 1)
			{
				nMin = nRight - nLeft + 1;
				nAnsL = nLeft;
				nAnsR = nRight;
			}
			pnFlag[pnSeq[nLeft]]--;
			if (pnFlag[pnSeq[nLeft]] == 0)
				nPeople--;
			nLeft++;
		}
		else
		{
			nRight++;
			pnFlag[pnSeq[nRight]]++;
			if (pnFlag[pnSeq[nRight]] == 1)
				nPeople++;
		}
	}
	printf("%d %d", nAnsL, nAnsR);



	
Exit0:
	return 0;
}