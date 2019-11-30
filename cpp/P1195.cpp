/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-16 00:11
//	Comment		:	OJ(P1195)
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

typedef struct SEdge
{
	int nX;
	int nY;
	int nL;
}SEdge;

bool Cmp(SEdge& sFirst, SEdge& sSecond)
{
	return sFirst.nL < sSecond.nL;
}
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
	SEdge			sEdge[10005];
	int				nInputN;
	int				nInputM;
	int				nInputK;
	int				nFX;
	int				nFY;
	int				nAns				= 0;
	int				nCount				= 0;
	int*			pnSet				= NULL;

	scanf("%d%d%d", &nInputN, &nInputM, &nInputK);

	pnSet = (int*)malloc((nInputN + 1) * sizeof(int));
	for (int i = 1; i <= nInputN; i++)
		pnSet[i] = i;
	for (int i = 0; i < nInputM; i++)
		scanf("%d%d%d", &sEdge[i].nX, &sEdge[i].nY, &sEdge[i].nL);

	sort(sEdge, sEdge + nInputM, Cmp);

	for (int i = 0; i < nInputM; i++)
	{
		nFX = Fin(pnSet, sEdge[i].nX);
		nFY = Fin(pnSet, sEdge[i].nY);
		if (nFX != nFY)
		{
			pnSet[nFX] = nFY;
			nCount++;
			nAns += sEdge[i].nL;
		}
		if (nCount == nInputN - nInputK)
		{
			printf("%d", nAns);
			return 0;
		}
	}
	printf("No Answer");
	

Exit0:
	return 0;
}