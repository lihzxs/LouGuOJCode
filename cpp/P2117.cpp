/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-19 16:50
//	Comment		:	OJ(P2117)
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

int	Ans(int** ppnMat, int nN)
{
	int nSum = 0;
	for (int i = 1; i <= nN; i++)
		for (int j = 1; j <= nN; j++)
			nSum += ppnMat[i][j] * ppnMat[j][i];
	return nSum % 2;
}

void ReverseH(int** ppnMat, int nX, int nN)
{
	for (int i = 1; i <= nN; i++)
		ppnMat[nX][i] = !ppnMat[nX][i];
}
void ReverseV(int** ppnMat, int nX, int nN)
{
	for (int i = 1; i <= nN; i++)
		ppnMat[i][nX] = !ppnMat[i][nX];
}


int main(int argc, char* argv[])
{
	int					nInputN;
	int					nInputQ;
	int					nTemp;
	int**				ppnMat				= NULL;
	int					nAns;



	scanf("%d%d", &nInputN, &nInputQ);

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	for (int i = 1; i <= nInputN; i++)
		ppnMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));

	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputN; j++)
		{
			scanf("%d", &nTemp);
			ppnMat[i][j] = nTemp;
		}
	nAns = Ans(ppnMat, nInputN);
	for (int i = 0; i < nInputQ; i++)
	{
		scanf("%d", &nTemp);
		if (nTemp == 3)
			printf("%d",nAns);
		else
		{
			scanf("%d", &nTemp);
			nAns = !nAns;
		}
			
	}



Exit0:

	return 0;
}