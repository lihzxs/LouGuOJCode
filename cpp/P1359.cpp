/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-2 20:20
//	Comment		:	OJ(P1359)
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
	int**			ppnMat					= NULL;
	int				nInputTemp;
	scanf("%d", &nInputN);
	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));

	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		ppnMat[i][i] = 1000001;
	}

	for (int i = 1; i <= nInputN; i++)
		for (int j = i + 1; j <= nInputN; j++)
		{
			scanf("%d", &nInputTemp);
			ppnMat[i][j] = nInputTemp;
			ppnMat[j][i] = nInputTemp;
		}

	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputN; j++)
			for (int k = 1; k <= nInputN; k++)
			{
				if (k <= i || k >= j)
					continue;
				if (ppnMat[i][j] > ppnMat[i][k] + ppnMat[k][j])
					ppnMat[i][j] = ppnMat[i][j] =
					ppnMat[i][k] + ppnMat[k][j];
			}

	printf("%d", ppnMat[1][nInputN]);




Exit0:

	return 0;
}