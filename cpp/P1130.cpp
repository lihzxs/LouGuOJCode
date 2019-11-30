/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-2 21:29
//	Comment		:	OJ(P1130)
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
	int				nInputM;
	int**			ppnMat			= NULL;
	int				nTempY;
	int				nMin			= 10000000; 

	scanf("%d%d", &nInputN, &nInputM);

	ppnMat = (int**)malloc((nInputM + 1) * sizeof(int*));

	for (int i = 1; i <= nInputM; i++)
		ppnMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));

	for (int i = 1; i <= nInputM; i++)
		for (int j = 1; j <= nInputN; j++)
			scanf("%d", &ppnMat[i][j]);

	
	for (int j = 2; j <= nInputN; j++)
	{
		for (int i = 1; i <= nInputM; i++)
		{
			if (i == 1)
				nTempY = nInputM;
			else
				nTempY = i - 1;
			ppnMat[i][j] = min(ppnMat[nTempY][j - 1], ppnMat[i][j - 1]) +
				ppnMat[i][j];
		}
	}


	for (int i = 1; i <= nInputM; i++)
		if (ppnMat[i][nInputN] < nMin)
			nMin = ppnMat[i][nInputN];


	printf("%d", nMin);






Exit0:

	return 0;
}