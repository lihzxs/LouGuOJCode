/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-18 23:01
//	Comment		:	OJ(P1057)
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
#include <float.h>

using namespace std;
#define	MAXNUM		1000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int					nInputN;
	int					nInputM;
	int**				ppnMat				= NULL;
	scanf("%d%d", &nInputN, &nInputM);

	ppnMat = (int**)malloc((nInputM + 1) * sizeof(int*));

	for (int i = 0; i <= nInputM; i++)
	{
		ppnMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		memset(ppnMat[i], 0, (nInputN + 1) * sizeof(int));
	}
		

	ppnMat[0][1] = 1;
	for (int i = 1; i <= nInputM; i++)
		for (int j = 1; j <= nInputN; j++)
		{
			if (j == 1)
				ppnMat[i][j] = ppnMat[i - 1][nInputN] + 
				ppnMat[i - 1][2];
			else if (j == nInputN)
				ppnMat[i][j] = ppnMat[i - 1][1] +
				ppnMat[i - 1][nInputN - 1];
			else
				ppnMat[i][j] = ppnMat[i - 1][j - 1] +
				ppnMat[i - 1][j + 1];
		}


	printf("%d", ppnMat[nInputM][1]);

Exit0:

	return 0;
}