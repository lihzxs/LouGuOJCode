/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-30 21:33
//	Comment		:	OJ(P4924)
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
#include <sstream>

using namespace std;
#define	MAXNUM		100000000
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
	int**			ppnTemp			= NULL;
	int				nCount			= 1;
	int				nStartX;
	int				nStartY;
	int				nEndX;
	int				nEndY;
	int				nInputX;
	int				nInputY;
	int				nInputR;
	int				nInputZ;
	scanf("%d%d", &nInputN, &nInputM);

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	ppnTemp = (int**)malloc((nInputN + 1) * sizeof(int*));
	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		ppnTemp[i] = (int*)malloc((nInputN + 1) * sizeof(int));
	}
		

	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputN; j++)
			ppnMat[i][j] = nCount++;

	while (nInputM--)
	{

		scanf("%d%d%d%d", &nInputX, &nInputY, &nInputR, &nInputZ);
		nStartX = nInputX - nInputR;
		nStartY = nInputY - nInputR;
		nEndX = nInputX + nInputR;
		nEndY = nInputY + nInputR;
		if (nInputZ == 0)
		{
			for (int i = nStartX; i <= nEndX; i++)
				for (int j = nStartY; j <= nEndY; j++)
					ppnTemp[nInputX - nInputY + j][nInputX + nInputY - i] = ppnMat[i][j];
		}
		else
		{
			for (int i = nStartX; i <= nEndX; i++)
				for (int j = nStartY; j <= nEndY; j++)
					ppnTemp[nInputX + nInputY - j][nInputY - nInputX + i] = ppnMat[i][j];
		}

		for (int i = nStartX; i <= nEndX; i++)
			for (int j = nStartY; j <= nEndY; j++)
				ppnMat[i][j] = ppnTemp[i][j];

		
	}

	for (int i = 1; i <= nInputN; i++)
	{
		for (int j = 1; j <= nInputN; j++)
			printf("%d ", ppnMat[i][j]);
		printf("\n");
	}
		



Exit0:
	return 0;
}