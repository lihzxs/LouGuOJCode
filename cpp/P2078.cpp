/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-2 22:42
//	Comment		:	OJ(P2078)
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
	int				nInputM;
	int				nA;
	int				nB;
	int				nCountA = 0;
	int				nCountB = 0;
	int*			pnSetA = NULL;
	int*			pnSetB = NULL;
	int				nInputP;
	int				nInputQ;
	scanf("%d%d", &nInputN, &nInputM);
	scanf("%d%d", &nInputP, &nInputQ);
	pnSetA = (int*)malloc((nInputN + 1) * sizeof(int));
	pnSetB = (int*)malloc((nInputM + 1) * sizeof(int));

	for (int i = 1; i <= nInputN; i++)
		pnSetA[i] = i;
	for (int i = 1; i <= nInputM; i++)
		pnSetB[i] = i;

	for (int i = 0; i < nInputP; i++)
	{
		scanf("%d%d", &nA, &nB);
		pnSetA[Fin(pnSetA, nA)] = Fin(pnSetA, nB);
	}
	for (int i = 2; i <= nInputN; i++)
		if (Fin(pnSetA, i) == Fin(pnSetA, 1))
			nCountA++;
	for (int i = 0; i < nInputQ; i++)
	{
		scanf("%d%d", &nA, &nB);
		nA = -nA;
		nB = -nB;
		pnSetB[Fin(pnSetB, nA)] = Fin(pnSetB, nB);
	}

	for (int i = 2; i <= nInputM; i++)
		if (Fin(pnSetB, i) == Fin(pnSetB, 1))
			nCountB++;


	printf("%d", min(nCountA, nCountB) + 1);






Exit0:
	return 0;
}