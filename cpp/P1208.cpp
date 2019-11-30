/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-19 20:07
//	Comment		:	OJ(P1208)
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
	int			nAns			= 0;
	SCOW_FARM*	sCowFarm		= NULL;

	scanf("%d%d", &nInputN, &nInputM);

	sCowFarm = (SCOW_FARM*)malloc(nInputM * sizeof(SCOW_FARM));

	for (int i = 0; i < nInputM; i++)
		scanf("%d%d", &(sCowFarm + i)->nPrice, &(sCowFarm + i)->nNum);

	sort(sCowFarm, sCowFarm + nInputM, cmp);

	for (int i = 0; i < nInputM; i++)
	{
		if (nInputN >= sCowFarm[i].nNum)
		{
			nAns += sCowFarm[i].nNum * sCowFarm[i].nPrice;
			nInputN -= sCowFarm[i].nNum;
		}
		else
		{
			nAns += nInputN * sCowFarm[i].nPrice;
			nInputN = 0;
		}
	}

	printf("%d", nAns);


Exit0:

	return 0;
}


