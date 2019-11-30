/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-16 16:50
//	Comment		:	OJ(P1684)
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
	int					nInputN;
	int*				pnSeq			= NULL;
	int*				pnNum			= NULL;
	int					nLen;
	int*				pnFlag			= NULL;
	int					nCount			= 0;
	int					nAns			= 0;
	
	scanf("%d", &nInputN);
	pnSeq = (int*)malloc((nInputN + 1) * sizeof(int));
	pnNum = (int*)malloc((nInputN + 1) * sizeof(int));
	pnFlag = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnFlag, 0, (nInputN + 1) * sizeof(int));
	for (int i = 1; i <= nInputN; i++)
		scanf("%d", pnSeq + i);
	memcpy(pnNum, pnSeq, (nInputN + 1) * sizeof(int));
	sort(pnNum + 1, pnNum + 1 + nInputN);
	nLen = unique(pnNum + 1, pnNum + 1 + nInputN) - pnNum;

	for (int i = 1; i <= nInputN; i++)
		pnSeq[i] = lower_bound(pnNum + 1, pnNum + 1 + nLen, pnSeq[i]) - pnNum;

	for (int i = 1; i <= nInputN; i++)
	{
		pnFlag[pnSeq[i]]++;
		if(pnFlag[pnSeq[i]] == 2)
		{
			nCount++;
			pnFlag[pnSeq[i]] = 0;
		}
		if (nCount < 2)
			continue;
		nCount = 0;
		nAns++;
		memset(pnFlag, 0, (nInputN + 1) * sizeof(int));
	}

	printf("%d\n", nAns);

		


	

Exit0:

	return 0;
}