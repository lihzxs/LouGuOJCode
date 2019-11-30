/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-29 23:14
//	Comment		:	OJ(P1216)
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
	int**			ppnMat				= NULL;
	int				nInputTemp;

	scanf("%d", &nInputN);
	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));

	for (int i = 1; i <= nInputN; i++)
		ppnMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));

	for(int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= i; j++)
		{
			scanf("%d", &nInputTemp);
			ppnMat[i][j] = nInputTemp;
		}


	for (int i = nInputN - 1; i >= 1; i--)
	{
		for (int j = 1; j <= i; j++)
			ppnMat[i][j] += max(ppnMat[i + 1][j], ppnMat[i + 1][j + 1]);
	}

	printf("%d", ppnMat[1][1]);








Exit0:

	return 0;
}