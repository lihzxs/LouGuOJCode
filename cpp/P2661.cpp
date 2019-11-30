/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-15 22:52
//	Comment		:	OJ(P2661)
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

void DFS(int* pnSeq, int* pnCount, int* pnFirstVis, int* pnSecondVis,
	int nN, int nX, int nCount, int& nMin)
{
	if (pnSecondVis[nX])
		return;
	if (pnFirstVis[nX])
		nMin = min(nMin, nCount - pnCount[nX]);
	else
	{
		pnFirstVis[nX] = 1;
		pnCount[nX] = nCount;
		DFS(pnSeq, pnCount, pnFirstVis, pnSecondVis,
			nN, pnSeq[nX], nCount + 1, nMin);
		pnSecondVis[nX] = 1;
	}
}




int main(int argc, char* argv[])
{
	int				nInputN;
	int*			pnSeq				= NULL;
	int*			pnCount				= NULL;
	int*			pnFirstVis			= NULL;
	int*			pnSecondVis			= NULL;
	int				nMin				= 1000000000;
	scanf("%d", &nInputN);

	pnSeq = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnSeq, 0, (nInputN + 1) * sizeof(int));
	pnCount = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnCount, 0, (nInputN + 1) * sizeof(int));
	pnFirstVis = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnFirstVis, 0, (nInputN + 1) * sizeof(int));
	pnSecondVis = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnSecondVis, 0, (nInputN + 1) * sizeof(int));

	for (int i = 1; i <= nInputN; i++)
		scanf("%d", &pnSeq[i]);

	for (int i = 1; i <= nInputN; i++)
		DFS(pnSeq, pnCount, pnFirstVis, pnSecondVis,
			nInputN, i, 0, nMin);
	printf("%d", nMin);
Exit0:
	return 0;
}