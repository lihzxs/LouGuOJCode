/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-11 16:33
//	Comment		:	OJ(P1199)
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
	int**			ppnMat				= NULL;
	int				nAns				= 0;
	scanf("%d", &nInputN);

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	
	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		ppnMat[i][i] = 0;
	}
		

	for (int i = 1; i < nInputN; i++)
		for (int j = i + 1; j <= nInputN; j++)
		{
			scanf("%d", &ppnMat[i][j]);
			ppnMat[j][i] = ppnMat[i][j];
		}
	for (int i = 1; i <= nInputN; i++)
	{
		sort(ppnMat[i] + 1, ppnMat[i] + 1 + nInputN);
		nAns = max(nAns, ppnMat[i][nInputN - 1]);
	}
	printf("1\n%d\n", nAns);

Exit0:

	return 0;
}