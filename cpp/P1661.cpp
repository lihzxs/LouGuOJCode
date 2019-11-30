/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-23 15:57
//	Comment		:	OJ(P1661)
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
#include <list>
#include <float.h>

using namespace std;
#define	MAXNUM		10000017
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int Fin(int* pnSet, int nNum)
{
	if (pnSet[nNum] == nNum)
		return pnSet[nNum];
	else
		return pnSet[nNum] =
		Fin(pnSet, pnSet[nNum]);
}

int main(int argc, char* argv[])
{
	int				nInputN;
	int*			pnX;
	int*			pnY;
	int*			pnSet;
	int				nLeft;
	int				nRight;
	int				nMid;
	int				nDis;
	int				nCount;
	scanf("%d", &nInputN);
	pnX = (int*)malloc((nInputN + 1) * sizeof(int));
	pnY = (int*)malloc((nInputN + 1) * sizeof(int));
	pnSet = (int*)malloc((nInputN + 1) * sizeof(int));
	for (int i = 1; i <= nInputN; i++)
		pnSet[i] = i;

	for (int i = 1; i <= nInputN; i++)
		scanf("%d%d", pnX + i, pnY + i);

	nLeft = 0;
	nRight = 1000000000;
	while (nLeft <= nRight)
	{
		nMid = (nLeft + nRight) / 2;
		for (int i = 1; i <= nInputN; i++)
			pnSet[i] = i;
		for (int i = 1; i <= nInputN; i++)
			for (int j = i + 1; j <= nInputN; j++)
			{
				nDis = abs(pnX[i] - pnX[j]) + abs(pnY[i] - pnY[j]);
				if (nDis <= nMid * 2)
				{
					if (Fin(pnSet, i) != Fin(pnSet, j))
						pnSet[Fin(pnSet, i)] = Fin(pnSet, j);
				}
			}
		nCount = 0;
		for (int i = 1; i <= nInputN; i++)
		{
			if (pnSet[i] == i)
				nCount++;
		}

		if (nCount == 1)
			nRight = nMid - 1;
		else
			nLeft = nMid + 1;
	}

	printf("%d", nRight + 1);

Exit0:

	return 0;
}