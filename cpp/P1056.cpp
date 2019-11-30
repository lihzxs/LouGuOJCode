/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-17 22:01
//	Comment		:	OJ(P1056)
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
#define	MAXNUM		1000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

typedef struct SLineCount
{
	int			nIndex;
	int			nCount;
}SLineCount;

bool Cmp(const SLineCount& sFirst, const SLineCount& sSecond)
{
	return sFirst.nCount > sSecond.nCount;
}
bool Cmp2(const SLineCount& sFirst, const SLineCount& sSecond)
{
	return sFirst.nIndex < sSecond.nIndex;
}

int main(int argc, char* argv[])
{
	int					nInputN;
	int					nInputM;
	int					nInputK;
	int					nInputL;
	int					nInputD;
	int*				pnRecordX			= NULL;
	int*				pnRecordY			= NULL;
	SLineCount*			psCX				= NULL;
	SLineCount*			psCY				= NULL;
	int					nInputX1;
	int					nInputY1;
	int					nInputX2;
	int					nInputY2;
	int					nCountX				= 0;
	int					nCountY				= 0;


	scanf("%d%d%d%d%d", &nInputN, &nInputM, 
		&nInputK, &nInputL, &nInputD);

	pnRecordX = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnRecordX, 0, (nInputN + 1) * sizeof(int));
	pnRecordY = (int*)malloc((nInputM + 1) * sizeof(int));
	memset(pnRecordY, 0, (nInputM + 1) * sizeof(int));

	psCX = (SLineCount*)malloc(nInputD * sizeof(SLineCount));
	psCY = (SLineCount*)malloc(nInputD * sizeof(SLineCount));

	for (int i = 0; i < nInputD; i++)
	{
		scanf("%d%d%d%d", &nInputX1, &nInputY1, &nInputX2, &nInputY2);

		if (nInputX1 == nInputX2)
			pnRecordY[min(nInputY1, nInputY2)]++;
		if (nInputY1 == nInputY2)
			pnRecordX[min(nInputX1, nInputX2)]++;
	}


	for (int i = 1; i <= nInputN; i++)
	{
		if (pnRecordX[i] != 0)
		{
			psCX[nCountX].nCount = pnRecordX[i];
			psCX[nCountX].nIndex = i;
			nCountX++;
		}
	}

	for (int i = 1; i <= nInputM; i++)
	{
		if (pnRecordY[i] != 0)
		{
			psCY[nCountY].nCount = pnRecordY[i];
			psCY[nCountY].nIndex = i;
			nCountY++;
		}
	}

	sort(psCX, psCX + nCountX, Cmp);
	sort(psCY, psCY + nCountY, Cmp);


	sort(psCX, psCX + nInputK, Cmp2);
	for (int i = 0; i < nInputK; i++)
		printf("%d ", psCX[i].nIndex);

	printf("\n");

	sort(psCY, psCY + nInputL, Cmp2);
	for (int i = 0; i < nInputL; i++)
		printf("%d ", psCY[i].nIndex);









Exit0:

	return 0;
}