/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-2 23:45
//	Comment		:	OJ(P1364)
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
	int				nInputN;
	int**			ppnMat				= NULL;
	int*			pnSeq				= NULL;
	int*			pnSeqPreL				= NULL;
	int*			pnSeqPreR				= NULL;
	int*			pnSeqNextL				= NULL;
	int*			pnSeqNextR				= NULL;
	int*			pnFlag					= NULL;
	int				nSum;
	int				nMin				= 1000000000;
	int				nQSize;
	int				nCount;
	int				nTemp;
	queue<int>		qBFS;
	scanf("%d", &nInputN);

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	pnSeq = (int*)malloc((nInputN + 1) * sizeof(int));
	pnSeqPreL = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnSeqPreL, 0, (nInputN + 1) * sizeof(int));
	pnSeqPreR = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnSeqPreR, 0, (nInputN + 1) * sizeof(int));
	pnSeqNextL = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnSeqNextL, 0, (nInputN + 1) * sizeof(int));
	pnSeqNextR = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnSeqNextR, 0, (nInputN + 1) * sizeof(int));
	pnFlag = (int*)malloc((nInputN + 1) * sizeof(int));
	for (int i = 1; i <= nInputN; i++)
	{
		scanf("%d", pnSeq + i);
		scanf("%d", pnSeqNextL + i);
		scanf("%d", pnSeqNextR + i);
		pnSeqPreL[pnSeqNextL[i]] = i;
		pnSeqPreR[pnSeqNextR[i]] = i;
	}


	for (int i = 1; i <= nInputN; i++)
	{
		memset(pnFlag, 0, (nInputN + 1) * sizeof(int));
		qBFS.push(i);
		pnFlag[i] = 1;
		nCount = 0;
		nSum = 0;
		while (!qBFS.empty())
		{
			nCount++;
			nQSize = qBFS.size();
			while (nQSize--)
			{
				nTemp = qBFS.front();
				qBFS.pop();
				if (nTemp == 0)
					continue;
				if (pnSeqNextL[nTemp] && !pnFlag[pnSeqNextL[nTemp]])
				{
					pnFlag[pnSeqNextL[nTemp]] = 1;
					nSum += nCount * pnSeq[pnSeqNextL[nTemp]];
					qBFS.push(pnSeqNextL[nTemp]);
				}
				if (pnSeqNextR[nTemp] && !pnFlag[pnSeqNextR[nTemp]])
				{
					pnFlag[pnSeqNextR[nTemp]] = 1;
					nSum += nCount * pnSeq[pnSeqNextR[nTemp]];
					qBFS.push(pnSeqNextR[nTemp]);
				}
				if (pnSeqPreL[nTemp] && !pnFlag[pnSeqPreL[nTemp]])
				{
					pnFlag[pnSeqPreL[nTemp]] = 1;
					nSum += nCount * pnSeq[pnSeqPreL[nTemp]];
					qBFS.push(pnSeqPreL[nTemp]);
				}
				if (pnSeqPreR[nTemp] && !pnFlag[pnSeqPreR[nTemp]])
				{
					pnFlag[pnSeqPreR[nTemp]] = 1;
					nSum += nCount * pnSeq[pnSeqPreR[nTemp]];
					qBFS.push(pnSeqPreR[nTemp]);
				}

			}///while (nQSize--)

		}///while (!qBFS.empty())
		nMin = min(nMin, nSum);
	}

	printf("%d", nMin);

Exit0:
	return 0;
}