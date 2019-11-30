/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-23 22:56
//	Comment		:	OJ(P1028)
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
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		2e31


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;







int main(int argc, char* argv[])
{
	int				nInputN;
	int*			pnCount			= NULL;
	scanf("%d", &nInputN);

	pnCount = (int*)malloc((nInputN + 1) * sizeof(int));

	memset(pnCount, 0, (nInputN + 1) * sizeof(int));

	for (int i = 1; i <= nInputN; i++)
	{
		for (int j = 1; j <= i / 2; j++)
			pnCount[i] += pnCount[j];
		pnCount[i]++;
	}

	printf("%d", pnCount[nInputN]);
Exit0:

	return 0;
}