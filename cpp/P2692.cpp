/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-19 18:43
//	Comment		:	OJ(P2692)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <stack>
#include <string>
#include <string.h>
using namespace std;
#define	MAXNUM		20000
#define	EPS         0.0001
#define ERROR_ID    0

typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;



int main(int argc, char* argv[])
{

	int					nInputN;
	int					nInputM;
	int					nInputB;
	int					nInputG;
	int					nInputX;
	int					nInputY;
	int					nCountX			= 0;
	int					nCountY			= 0;
	long long			llAns;
	BOOL*				bFlagX			= NULL;
	BOOL*				bFlagY			= NULL;


	scanf("%d%d%d%d", &nInputN, &nInputM, 
		&nInputB, &nInputG);

	bFlagX = (BOOL*)malloc(nInputM * sizeof(BOOL));
	memset(bFlagX, false, nInputM * sizeof(BOOL));
	bFlagY = (BOOL*)malloc(nInputN * sizeof(BOOL));
	memset(bFlagY, false, nInputN * sizeof(BOOL));
	for (int i = 0; i < nInputB; i++)
	{
		scanf("%d%d", &nInputX, &nInputY);
		for (int j = nInputX; j <= nInputY; j++)
			bFlagY[j] = true;
	}

	for (int i = 0; i < nInputG; i++)
	{
		scanf("%d%d", &nInputX, &nInputY);
		for (int j = nInputX; j <= nInputY; j++)
			bFlagX[j] = true;
	}

	for (int i = 0; i < nInputN; i++)
		if (!bFlagY[i])
			nCountY++;
	for (int i = 0; i < nInputM; i++)
		if (!bFlagX[i])
			nCountX++;
	llAns = nInputM * nInputN - nCountX * nCountY;
	printf("%lld", llAns);






Exit0:





	return 0;
}


