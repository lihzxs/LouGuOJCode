/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-16 21:22
//	Comment		:	OJ(P2074)
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

typedef struct SCOW_FARM
{
	int			nPrice;
	int			nNum;
}SCOW_FARM;


bool cmp(const SCOW_FARM sFirst, const SCOW_FARM sSecond)
{
	return sFirst.nPrice < sSecond.nPrice;
}


int main(int argc, char* argv[])
{
	int			nInputN;
	int			nInputM;
	int			nInputT;
	int			nInputK;
	int			nInputX;
	int			nInputY;
	int			nCount				= 0;
	int			nAns				= 0;
	int**		ppnMat				= NULL;


	scanf("%d%d%d%d", &nInputN, &nInputM, &nInputK, &nInputT);




	for (int i = 0; i < nInputK; i++)
	{
		scanf("%d%d", &nInputX, &nInputY);
		swap(nInputX, nInputY);
		for (int j = nInputX - nInputT; j <= nInputX + nInputT; j++)
		{
			if (j < 1 || j > nInputM)
				continue;
			for (int k = nInputY - nInputT; k <= nInputY + nInputT; k++)
			{
				if (k < 1 || k > nInputN)
					continue;
				if ((j - nInputX) * (j - nInputX) +
					(k - nInputY) * (k - nInputY) <= nInputT * nInputT)
					nCount++;
				
					
			}
		}
		if (nCount > nAns)
			nAns = nCount;
		nCount = 0;
	}


	printf("%d", nAns);

	




Exit0:

	return 0;
}


