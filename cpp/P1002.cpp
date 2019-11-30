/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-12 15:52
//	Comment		:	OJ(P1002)
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
	int			nInputM;
	int			nInputX;
	int			nInputY;
	long long**		ppnMat					= NULL;
	scanf("%d%d%d%d", &nInputN, &nInputM, &nInputX, &nInputY);

	ppnMat = (long long**)malloc((nInputN + 1) * sizeof(long long*));

	for (int i = 0; i <= nInputN; i++)
	{
		ppnMat[i] = (long long*)malloc((nInputM + 1) * sizeof(long long));
		memset(ppnMat[i], 0, (nInputM + 1) * sizeof(long long));
	}

	for(int i = 0; i <= nInputN; i++)
		for (int j = 0; j <= nInputM; j++)
		{
			if (j - 1 < 0 && i - 1 < 0)
				ppnMat[0][0] = 1;
			else if (j - 1 < 0)
				ppnMat[i][j] += ppnMat[i - 1][j];
			else if (i - 1 < 0)
				ppnMat[i][j] += ppnMat[i][j - 1];
			else
				ppnMat[i][j] += ppnMat[i - 1][j] + ppnMat[i][j - 1];


			if (i == nInputX && j == nInputY)
				ppnMat[i][j] = 0;
			if (i == nInputX + 2 && j == nInputY + 1)
				ppnMat[i][j] = 0;
			if (i == nInputX - 2 && j == nInputY - 1)
				ppnMat[i][j] = 0;
			if (i == nInputX + 2 && j == nInputY - 1)
				ppnMat[i][j] = 0;
			if (i == nInputX - 2 && j == nInputY + 1)
				ppnMat[i][j] = 0;

			if (i == nInputX + 1 && j == nInputY + 2)
				ppnMat[i][j] = 0;
			if (i == nInputX - 1 && j == nInputY - 2)
				ppnMat[i][j] = 0;
			if (i == nInputX + 1 && j == nInputY - 2)
				ppnMat[i][j] = 0;
			if (i == nInputX - 1 && j == nInputY + 2)
				ppnMat[i][j] = 0;
		}

	printf("%lld", ppnMat[nInputN][nInputM]);
Exit0:

	return 0;
}