/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-24 00:03
//	Comment		:	OJ(P5197)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <list>
#include <string>
#include <string.h>
#include <set>
#include <queue>
#include <map>

using namespace std;
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		2e31


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;



int main(int argc, char* argv[])
{

	int				nInputN;
	int*			pnCount				= NULL;
	int				nAns = 0;
	int				nA;
	int				nB;
	scanf("%d", &nInputN);

	pnCount = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnCount, 0, (nInputN + 1) * sizeof(int));

	for (int i = 0; i < nInputN - 1; i++)
	{
		scanf("%d%d", &nA, &nB);
		pnCount[nA]++;
		pnCount[nB]++;
		nAns = max(nAns, pnCount[nA]);
		nAns = max(nAns, pnCount[nB]);
	}

	printf("%d", nAns + 1);


Exit0:

	return 0;
}