/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-31 23:03
//	Comment		:	OJ(P1566)
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
int			nMax;
void DFS(int* pnFlag, int* pnSeq, int nN, int nSum,
	int nPre, int nCount, int& nAns)
{
	if (nSum > nMax)
		return;
	if (pnFlag[nSum])
		nAns++;
	for (int i = nPre; i < nN; i++)
	{
		DFS(pnFlag, pnSeq, nN, nSum + pnSeq[i],
			i + 1, nCount, nAns);
	}
}


int main(int argc, char* argv[])
{
	int			nInputN;
	int			nInputM;
	int			nTemp;
	int			nAns;

	int*		pnSeq = NULL;
	int*		pnFlag = NULL;
	pnFlag = (int*)malloc(1005 * sizeof(int));
	pnSeq = (int*)malloc(1005 * sizeof(int));
	scanf("%d", &nInputN);
	while (nInputN--)
	{
		nAns = 0;
		nMax = 0;
		scanf("%d", &nInputM);
		memset(pnFlag, 0, 1005 * sizeof(int));

		for (int i = 0; i < nInputM; i++)
		{
			scanf("%d", &nTemp);
			pnSeq[i] = nTemp;
			nMax = max(nMax, nTemp);
			pnFlag[nTemp] = 1;
		}
		DFS(pnFlag, pnSeq, nInputM, 0,
			0, 0, nAns);
		printf("%d\n", nAns - nInputM);

	}



Exit0:
	return 0;
}