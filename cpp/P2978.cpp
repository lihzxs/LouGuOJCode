/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-22 21:03
//	Comment		:	OJ(P2978)
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
#define	MAXNUM		150
#define	EPS         0.0001
#define MODNUM		1000000007ll


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int	Fin(map<int, int>& Rel, int nNum)
{
	if (Rel[nNum] == nNum)
		return nNum;
	else
		return Fin(Rel, Rel[nNum]);
}



int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int				nInputQ;
	int				nFirst;
	int				nRecord;
	BOOL			bIsPrint			= false;
	int				nSecond;
	map<int, int>	mapRel;

	scanf("%d%d%d", &nInputN, &nInputM, &nInputQ);

	for (int i = 1; i <= nInputN; i++)
		mapRel[i] = i;

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d", &nFirst, &nSecond);
		mapRel[Fin(mapRel, nFirst)] = Fin(mapRel, nSecond);
	}

	for (int i = 0; i < nInputQ; i++)
	{
		scanf("%d%d", &nFirst, &nSecond);
		if (Fin(mapRel, nFirst) == Fin(mapRel, nSecond))
			printf("Y\n");
		else
			printf("N\n");
	}




Exit0:

	return 0;
}