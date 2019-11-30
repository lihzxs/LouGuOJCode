/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-14 21:16
//	Comment		:	OJ(P1793)
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
	int				nInputE;
	int*			pnSet = NULL;
	int				nInputA;
	int				nInputB;
	int				nInputC;
	int*			pnS = NULL;
	int*			pnE = NULL;
	vector<int>		vecAns;
	scanf("%d%d", &nInputN, &nInputE);

	pnSet = (int*)malloc((nInputN + 1) * sizeof(int));
	pnS = (int*)malloc((nInputE + 1) * sizeof(int));
	pnE = (int*)malloc((nInputE + 1) * sizeof(int));

	for (int i = 1; i <= nInputE; i++)
		scanf("%d%d", &pnS[i], &pnE[i]);

	for (int j = 2; j < nInputN; j++)
	{
		for (int i = 1; i <= nInputN; i++)
			pnSet[i] = i;
		for (int i = 1; i <= nInputE; i++)
		{
			if (pnS[i] != j && pnE[i] != j)
				pnSet[Fin(pnSet, pnS[i])] = Fin(pnSet, pnE[i]);
		}
		if (Fin(pnSet, 1) != Fin(pnSet, nInputN))
			vecAns.push_back(j);
	}

	printf("%d\n", vecAns.size());
	for (int i = 0; i < vecAns.size(); i++)
		printf("%d ", vecAns[i]);
Exit0:
	return 0;
}