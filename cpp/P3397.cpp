/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-21 14:01
//	Comment		:	OJ(P3397)
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
#define	MAXNUM		7010
#define	EPS         0.0001
#define MODNUM		1000000007ll


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;





int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int				nInputX1;
	int				nInputY1;
	int				nInputX2;
	int				nInputY2;
	int**			ppnMat				= NULL;

	scanf("%d%d", &nInputN, &nInputM);

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	for (int i = 1; i < nInputN + 1; i++)
	{
		ppnMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		memset(ppnMat[i], 0, (nInputN + 1) * sizeof(int));
	}

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d%d%d", &nInputX1, &nInputY1, &nInputX2, &nInputY2);
		for (int j = nInputX1; j <= nInputX2; j++)
			for (int k = nInputY1; k <= nInputY2; k++)
				ppnMat[j][k]++;
	}

	for (int i = 1; i <= nInputN; i++)
	{
		printf("%d", ppnMat[i][1]);
		for (int j = 2; j <= nInputN; j++)
			printf(" %d", ppnMat[i][j]);
		printf("\n");
	}
		




















	


Exit0:

	return 0;
}