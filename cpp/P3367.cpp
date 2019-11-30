/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-4 14:40
//	Comment		:	OJ(P3367)
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
	int*			pnSet			= NULL;
	int				nInputA;
	int				nInputB;
	int				nInputC;
	scanf("%d%d", &nInputN, &nInputM);

	pnSet = (int*)malloc((nInputN + 1) * sizeof(int));

	for (int i = 1; i <= nInputN; i++)
		pnSet[i] = i;

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d%d", &nInputA, &nInputB, &nInputC);
		if (nInputA == 1)
			pnSet[Fin(pnSet, nInputB)] = Fin(pnSet, nInputC);
		else
		{
			if (Fin(pnSet, nInputB) == Fin(pnSet, nInputC))
				printf("Y\n");
			else
				printf("N\n");
		}
	}
	






Exit0:
	return 0;
}