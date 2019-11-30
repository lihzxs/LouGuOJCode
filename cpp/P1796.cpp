/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-14 10:16
//	Comment		:	OJ(P1796)
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
	int									nInputN;
	int									nInputK;
	int**								ppnMat				= NULL;
	int									nSum				= 0;
	int									nCount				= 0;
	int									nMin				= 1000000;
	int									nC;
	int									nW;
	scanf("%d", &nInputN);
	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	for (int i = 0; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc(101 * sizeof(int));
		//memset(ppnMat[i], 0, 101 * sizeof(int));
		for (int j = 1; j <= 100; j++)
			ppnMat[i][j] = 1000000;
	}

	



	ppnMat[0][0] = 1;
	ppnMat[0][1] = 0;
	for (int i = 1; i <= nInputN; i++)
	{
		scanf("%d", &nInputK);
		ppnMat[i][0] = nInputK;
		for (int j = 1 ; j <= nInputK; j++)
		{
			while (scanf("%d", &nC))
			{
				if (nC == 0)
					break;
				scanf("%d", &nW);
				ppnMat[i][j] = min(ppnMat[i - 1][nC] + nW, ppnMat[i][j]);
			}
		}///for (int j = 1 ; j <= nInputK; j++)
	}///for (int i = 0; i < nInputN; i++)


	for (int i = 1; i <= ppnMat[nInputN][0]; i++)
		nMin = min(ppnMat[nInputN][i], nMin);


	printf("%d", nMin);



Exit0:

	return 0;
}