/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-24 19:34
//	Comment		:	OJ(P5542)
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
#define MODNUM		1000000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputK;
	int				nStartX;
	int				nStartY;
	int				nEndX;
	int				nEndY;
	int**			ppnMat			= NULL;
	int				nAns			= 0;

	scanf("%d%d", &nInputN, &nInputK);


	ppnMat = (int**)malloc(1001 * sizeof(int*));
	for (int i = 0; i <= 1000; i++)
	{
		ppnMat[i] = (int*)malloc(1001 * sizeof(int));
		memset(ppnMat[i], 0, 1001 * sizeof(int));
	}

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d%d%d", &nStartX, &nStartY, &nEndX, &nEndY);
		ppnMat[nStartX + 1][nStartY + 1]++;
		ppnMat[nEndX + 1][nEndY + 1]++;
		ppnMat[nStartX + 1][nEndY + 1]--;
		ppnMat[nEndX + 1][nStartY + 1]--;
	}

	for (int i = 1; i <= 1000; i++)
		for (int j = 1; j <= 1000; j++)
		{
			ppnMat[i][j] += ppnMat[i - 1][j] + 
				ppnMat[i][j - 1] - ppnMat[i - 1][j - 1];
			if (ppnMat[i][j] == nInputK)
				nAns++;
		}



	printf("%d", nAns);
Exit0:

	return 0;
}