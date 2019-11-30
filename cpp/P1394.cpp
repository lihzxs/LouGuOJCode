/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-26 15:49
//	Comment		:	OJ(P1394)
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
	int			nInputN;
	int			nInputM;
	int			nA;
	int			nB;
	int			nMaxIndex;
	int			nMax				= 0;
	int*		pnHeigh				= NULL;
	int*		pnSet				= NULL;
	int			nCount				= 0;
	int			nAns;
	scanf("%d%d", &nInputN, &nInputM);

	pnHeigh = (int*)malloc((nInputN + 1) * sizeof(int));
	pnSet = (int*)malloc((nInputN + 1) * sizeof(int));
	for (int i = 1; i <= nInputN; i++)
	{
		scanf("%d", pnHeigh + i);
		//if (pnHeigh[i] > nMax)
		//{
		//	nMax = pnHeigh[i];
		//	nMaxIndex = i;
		//}
	}

	//for (int i = 1; i <= nInputN; i++)
	//{
	//	if (pnHeigh[i] == nMax && i != nMaxIndex)
	//	{
	//		printf("Non");
	//		return 0;
	//	}
	//}
	for (int i = 1; i <= nInputN; i++)
		pnSet[i] = i;
	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d", &nA, &nB);
		if (pnHeigh[Fin(pnSet, nA)] > pnHeigh[Fin(pnSet, nB)])
			pnSet[Fin(pnSet, nB)] = Fin(pnSet, nA);
		else if (pnHeigh[Fin(pnSet, nA)] < pnHeigh[Fin(pnSet, nB)])
			pnSet[Fin(pnSet, nA)] = Fin(pnSet, nB);
	}

	for (int i = 1; i <= nInputN; i++)
	{
		if (pnSet[i] == i)
		{
			nCount++;
			nAns = i;
			if (nCount > 1)
			{
				printf("Non");
				return 0;
			}
		}
	}

	printf("Oui, j'ai trouve la solution.\n");
	printf("%d\n", nAns);

		




Exit0:

	return 0;
}