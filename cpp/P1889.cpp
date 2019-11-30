/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-16 21:50
//	Comment		:	OJ(P1889)
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


int main(int argc, char* argv[])
{
	int				nInputN;
	int*			pnX;
	int*			pnY;
	int*			pnSortX;
	int*			pnSortY;
	int				nTargetX;
	int				nTargetY;
	int				nSum				= 0;
	scanf("%d", &nInputN);
	pnX = (int*)malloc(nInputN * sizeof(int));
	pnY = (int*)malloc(nInputN * sizeof(int));
	pnSortX = (int*)malloc(nInputN * sizeof(int));
	pnSortY = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", pnX + i);
		scanf("%d", pnY + i);
	}

	memcpy(pnSortX, pnY, nInputN * sizeof(int));
	memcpy(pnSortY, pnX, nInputN * sizeof(int));

	sort(pnSortX, pnSortX + nInputN);
	sort(pnSortY, pnSortY + nInputN);


	for (int i = 0; i < nInputN; i++)
		pnSortY[i] -= i + 1;

	sort(pnSortY, pnSortY + nInputN);

	if (nInputN % 2 == 0)
	{
		nTargetX = (pnSortX[nInputN / 2] + pnSortX[nInputN / 2 - 1]) / 2;
		nTargetY = (pnSortY[nInputN / 2] + pnSortY[nInputN / 2 - 1]) / 2;
	}
	else
	{
		nTargetX = pnSortX[nInputN / 2];
		nTargetY = pnSortY[nInputN / 2];
	}

	for (int i = 0; i < nInputN; i++)
	{
		nSum += abs(pnSortX[i] - nTargetX);
		nSum += abs(pnSortY[i] - nTargetY);
	}

	printf("%d", nSum);



Exit0:

	return 0;
}