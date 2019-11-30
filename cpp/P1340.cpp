/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-22 23:43
//	Comment		:	OJ(P1340)
//
///////////////////////////////////////////

#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
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
#include <list>
#include <float.h>

using namespace std;
#define	MAXNUM		1000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int**			ppnMat = NULL;
	unsigned int*	pnDis = 0;
	int*			pnFlag = NULL;
	int				nX;
	int				nY;
	int				nW;
	int				nMin;
	int				nPoint = 1;
	int				nSum = 0;
	scanf("%d%d", &nInputN, &nInputM);

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	pnFlag = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnFlag, 0, (nInputN + 1) * sizeof(int));
	pnDis = (unsigned int*)malloc((nInputN + 1) * sizeof(unsigned int));
	memset(pnDis, 127, (nInputN + 1) * sizeof(int));
	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		memset(ppnMat[i], 0, (nInputN + 1) * sizeof(int));
	}

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d%d", &nX, &nY, &nW);
		if (ppnMat[nX][nY] != 0)
			ppnMat[nX][nY] = min(nW, ppnMat[nX][nY]);
		else
			ppnMat[nX][nY] = nW;
		ppnMat[nY][nX] = ppnMat[nX][nY];

		memset(pnDis, 127, (nInputN + 1) * sizeof(int));
		memset(pnFlag, 0, (nInputN + 1) * sizeof(int));
		pnDis[1] = 0;

		for (int i = 1; i <= nInputN; i++)
		{
			nMin = pnDis[0];
			for (int j = 1; j <= nInputN; j++)
			{
				if (pnDis[j] < nMin && pnFlag[j] == false)
				{
					nMin = pnDis[j];
					nPoint = j;
				}
			}

			pnFlag[nPoint] = true;

			for (int j = 1; j <= nInputN; j++)
			{
				if (ppnMat[nPoint][j] != 0)
				{
					if (pnDis[j] > ppnMat[nPoint][j] && pnFlag[j] == false)
						pnDis[j] = ppnMat[nPoint][j];
				}
			}
		}
		int nFlag = 1;
		nSum = 0;
		for (int i = 1; i <= nInputN; i++)
		{
			if (pnDis[i] == pnDis[0])
			{
				nFlag = 0;
				printf("-1");
				break;
			}
			nSum += pnDis[i];
		}
		if (nFlag)
			printf("%d", nSum);
		printf("\n");
	}




Exit0:

	return 0;
}