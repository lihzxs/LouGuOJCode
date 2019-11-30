/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-12 19:35
//	Comment		:	OJ(P3913)
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

using namespace std;
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		2000001


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;



int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputK;
	int				nInputX;
	int				nInputY;
	int*			pnHor;
	int*			pnVer;
	long long		llCountH			= 0;
	long long		llCountV			= 0;
	long long		llAns				= 0;

	scanf("%d%d", &nInputN, &nInputK);

	pnHor = (int*)malloc(nInputK * sizeof(int));
	pnVer = (int*)malloc(nInputK * sizeof(int));

	for (int i = 0; i < nInputK; i++)
	{
		scanf("%d%d", &nInputX, &nInputY);
		pnHor[i] = nInputX;
		pnVer[i] = nInputY;
	}
	sort(pnHor, pnHor + nInputK);
	sort(pnVer, pnVer + nInputK);

	llCountH = unique(pnHor, pnHor + nInputK) - pnHor;
	llCountV = unique(pnVer, pnVer + nInputK) - pnVer;

	printf("%lld", 
		llCountH * nInputN + llCountV * nInputN - llCountH * llCountV);


Exit0:

	return 0;
}