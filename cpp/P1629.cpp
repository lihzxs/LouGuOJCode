/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-14 01:09
//	Comment		:	OJ(P1629)
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

int			nDis[1005][1005];
int main(int argc, char* argv[])
{

	int			nN;
	int			nM;
	int			nX;
	int			nY;
	int			nZ;
	int			nSum;




	scanf("%d%d", &nN, &nM);


	for (int i = 1; i <= nN; i++)
		for (int j = 1; j <= nN; j++)
			nDis[i][j] = 200000000;


	for (int i = 0; i < nM; i++)
	{
		scanf("%d%d%d", &nX, &nY, &nZ);
		nDis[nX][nY] = min(nDis[nX][nY], nZ);
	}

	for (int k = 1; k <= nN; k++)
		for (int i = 1; i <= nN; i++)
			for (int j = 1; j <= nN; j++)
				nDis[i][j] = min(nDis[i][j], nDis[i][k] + nDis[k][j]);


	nSum = 0;

	for (int i = 2; i <= nN; i++)
		nSum += (nDis[i][1] + nDis[1][i]);

	printf("%d\n", nSum);

Exit0:

	return 0;
}