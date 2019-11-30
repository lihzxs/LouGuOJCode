/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-10 23:47
//	Comment		:	OJ(P5117)
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
	int			nInputN;
	int*		pnCount				= NULL;
	int			nInputA;
	int			nInputB;
	int			nInputC;
	int			nAns				= 0;
	scanf("%d", &nInputN);
	pnCount = (int*)malloc(1001 * sizeof(int));
	memset(pnCount, 0, 1001 * sizeof(int));

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d%d", &nInputA, &nInputB, &nInputC);
		for (int j = nInputA; j <= nInputB; j++)
			pnCount[j] += nInputC;
	}


	for (int i = 0; i <= 1000; i++)
		nAns = max(nAns, pnCount[i]);

	printf("%d", nAns);


Exit0:

	return 0;
}