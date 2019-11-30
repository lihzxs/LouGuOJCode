
////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-23 00:31
//	Comment		:	OJ(P1744)
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
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;




int main(int argc, char* argv[])
{
	int					nInputN;
	int					nInputM;
	double**				ppnMat			= NULL;
	map<int, pair<int, int> >	mpMarket;
	int					nStart;
	int					nEnd;
	double				fTemp;
	scanf("%d", &nInputN);

	ppnMat = (double**)malloc((nInputN + 1) * sizeof(double*));

	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (double*)malloc((nInputN + 1) * sizeof(double));
		for (int j = 1; j <= nInputN; j++)
			ppnMat[i][j] = 3000000;
	}

	for (int i = 1; i <= nInputN; i++)
	{
		scanf("%d%d", &nStart, &nEnd);
		mpMarket[i].first = nStart;
		mpMarket[i].second = nEnd;
	}

	scanf("%d", &nInputM);

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d", &nStart, &nEnd);
		fTemp = sqrt((mpMarket[nStart].first - mpMarket[nEnd].first) *
			(mpMarket[nStart].first - mpMarket[nEnd].first) + 
			(mpMarket[nStart].second - mpMarket[nEnd].second) *
			(mpMarket[nStart].second - mpMarket[nEnd].second));

		ppnMat[nStart][nEnd] = fTemp;
		ppnMat[nEnd][nStart] = fTemp;
	}


	for (int k = 1; k <= nInputN; k++)
		for (int i = 1; i <= nInputN; i++)
			for (int j = 1; j <= nInputN; j++)
			{
				if (i == j || i == k || j == k)
					continue;

				if (ppnMat[i][j] > ppnMat[i][k] + ppnMat[k][j])
					ppnMat[i][j] = ppnMat[i][k] + ppnMat[k][j];
			}

	scanf("%d%d", &nStart, &nEnd);

	printf("%.2f", ppnMat[nStart][nEnd]);






Exit0:

	return 0;
}