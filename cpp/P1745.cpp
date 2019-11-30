/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-3 23:44
//	Comment		:	OJ(P1745)
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
int			nInputN;
void Print(int* pnSeq, int& nStep)
{
	printf("Step %d:", nStep);
	for (int i = 1; i <= 2 * nInputN + 2; i++)
	{
		if (pnSeq[i] == 1)
			printf("1");
		else if (pnSeq[i] == 2)
			printf("2");
		else
			printf("0");
	}
	printf("\n");
	nStep++;
}

void Move(int* pnSeq, int nN, int& nStep,int& nSp, int nTemp)
{
	pnSeq[nSp] = pnSeq[nTemp];
	pnSeq[nTemp] = 3;
	pnSeq[nSp + 1] = pnSeq[nTemp + 1];
	pnSeq[nTemp + 1] = 3;
	nSp = nTemp;
	Print(pnSeq, nStep);
}

void Presson(int* pnSeq, int nN, int& nStep, int& nSp)
{
	if (nN == 4)
	{
		Move(pnSeq, nN, nStep, nSp, 4);
		Move(pnSeq, nN, nStep, nSp, 8);
		Move(pnSeq, nN, nStep, nSp, 2);
		Move(pnSeq, nN, nStep, nSp, 7);
		Move(pnSeq, nN, nStep, nSp, 1);
	}
	else
	{
		Move(pnSeq, nN, nStep, nSp, nN);
		Move(pnSeq, nN, nStep, nSp, 2 * nN - 1);
		Presson(pnSeq, nN - 1, nStep, nSp);
	}
}



int main(int argc, char* argv[])
{

	int*		pnSeq				= NULL;
	int			nStep				= 0;
	int			nSp;

	scanf("%d", &nInputN);
	nSp = 2 * nInputN + 1;
	pnSeq = (int*)malloc((2 * nInputN + 3) * sizeof(int));

	for (int i = 1; i <= nInputN; i++)
		pnSeq[i] = 1;
	for (int i = nInputN + 1; i <= 2 * nInputN; i++)
		pnSeq[i] = 2;
	pnSeq[2 * nInputN + 1] = 3;
	pnSeq[2 * nInputN + 2] = 3;

	Print(pnSeq, nStep);
	Presson(pnSeq, nInputN, nStep, nSp);
	printf("%d", nStep - 1);
Exit0:
	return 0;
}