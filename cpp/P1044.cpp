/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-2 21:01
//	Comment		:	OJ(P1044)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
#include <set>
#include <queue>
#include <list>
#include <map>

using namespace std;
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;



int main(int argc, char* argv[])
{
	int				nInputN;
	int*			pnAns			= NULL;
	scanf("%d", &nInputN);

	pnAns = (int*)malloc((nInputN + 1) * sizeof(int));
	pnAns[0] = 1;
	pnAns[1] = 1;
	for (int i = 2; i <= nInputN; i++)
		for (int j = 0; j < i; j++)
			pnAns[i] += pnAns[j] * pnAns[i - j - 1];

	printf("%d", pnAns[nInputN]);
Exit0:

	return 0;
}