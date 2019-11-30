/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-23 22:12
//	Comment		:	OJ(P5079)
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


int	Check(int** ppnMat, int nN, int nM, int nNowX, int nNowY)
{
	ppnMat[nNowX][nNowY] = '.';
	if (((nNowY + 1) <= nM && ppnMat[nNowX][nNowY + 1] != '#') || nNowY == nM)
	{
		if (ppnMat[nNowX + 1][nNowY] == '#' &&
			ppnMat[nNowX + 2][nNowY] == '#' && ppnMat[nNowX + 3][nNowY] == '#' &&
			ppnMat[nNowX + 4][nNowY] == '#')
		{

			for (int i = nNowX; i <= nNowX + 4; i++)
				ppnMat[i][nNowY] = '.';
			return 1;
		}
	}


	if (ppnMat[nNowX + 1][nNowY] == '#' && ppnMat[nNowX + 2][nNowY] == '#' &&
		ppnMat[nNowX + 4][nNowY] == '#' && ppnMat[nNowX][nNowY + 1] == '#' &&
		ppnMat[nNowX + 2][nNowY + 1] == '#' && ppnMat[nNowX + 4][nNowY + 1] == '#' &&
		ppnMat[nNowX][nNowY + 2] == '#' && ppnMat[nNowX + 2][nNowY + 2] == '#' &&
		ppnMat[nNowX + 3][nNowY + 2] == '#' && ppnMat[nNowX + 4][nNowY + 2] == '#' &&
		ppnMat[nNowX + 3][nNowY] == '#' && ppnMat[nNowX + 1][nNowY + 2] == '#')
	{
		ppnMat[nNowX + 1][nNowY] = '.'; ppnMat[nNowX + 2][nNowY] = '.';
		ppnMat[nNowX + 4][nNowY] = '.'; ppnMat[nNowX][nNowY + 1] = '.';
		ppnMat[nNowX + 2][nNowY + 1] = '.'; ppnMat[nNowX + 4][nNowY + 1] = '.';
		ppnMat[nNowX][nNowY + 2] = '.'; ppnMat[nNowX + 2][nNowY + 2] = '.';
		ppnMat[nNowX + 3][nNowY + 2] = '.'; ppnMat[nNowX + 4][nNowY + 2] = '.';
		ppnMat[nNowX + 3][nNowY] = '.'; ppnMat[nNowX + 1][nNowY + 2] = '.';
		return 8;
	}

	if (ppnMat[nNowX + 1][nNowY] == '#' && ppnMat[nNowX + 2][nNowY] == '#' &&
		ppnMat[nNowX + 4][nNowY] == '#' && ppnMat[nNowX][nNowY + 1] == '#' &&
		ppnMat[nNowX + 2][nNowY + 1] == '#' && ppnMat[nNowX + 4][nNowY + 1] == '#' &&
		ppnMat[nNowX][nNowY + 2] == '#' && ppnMat[nNowX + 2][nNowY + 2] == '#' &&
		ppnMat[nNowX + 3][nNowY + 2] == '#' && ppnMat[nNowX + 4][nNowY + 2] == '#' &&
		ppnMat[nNowX + 1][nNowY + 2] == '#')
	{
		ppnMat[nNowX + 1][nNowY] = '.'; ppnMat[nNowX + 2][nNowY] = '.';
		ppnMat[nNowX + 4][nNowY] = '.'; ppnMat[nNowX][nNowY + 1] = '.';
		ppnMat[nNowX + 2][nNowY + 1] = '.'; ppnMat[nNowX + 4][nNowY + 1] = '.';
		ppnMat[nNowX][nNowY + 2] = '.'; ppnMat[nNowX + 2][nNowY + 2] = '.';
		ppnMat[nNowX + 3][nNowY + 2] = '.'; ppnMat[nNowX + 4][nNowY + 2] = '.';
		ppnMat[nNowX + 1][nNowY + 2] = '.';
		return 9;
	}


	if (ppnMat[nNowX + 1][nNowY] == '#' && ppnMat[nNowX + 2][nNowY] == '#' &&
		ppnMat[nNowX + 4][nNowY] == '#' && ppnMat[nNowX][nNowY + 1] == '#' &&
		ppnMat[nNowX + 2][nNowY + 1] == '#' && ppnMat[nNowX + 4][nNowY + 1] == '#' &&
		ppnMat[nNowX][nNowY + 2] == '#' && ppnMat[nNowX + 2][nNowY + 2] == '#' &&
		ppnMat[nNowX + 3][nNowY + 2] == '#' && ppnMat[nNowX + 4][nNowY + 2] == '#' &&
		ppnMat[nNowX + 3][nNowY] == '#')
	{
		ppnMat[nNowX + 1][nNowY] = '.'; ppnMat[nNowX + 2][nNowY] = '.';
		ppnMat[nNowX + 4][nNowY] = '.'; ppnMat[nNowX][nNowY + 1] = '.';
		ppnMat[nNowX + 2][nNowY + 1] = '.'; ppnMat[nNowX + 4][nNowY + 1] = '.';
		ppnMat[nNowX][nNowY + 2] = '.'; ppnMat[nNowX + 2][nNowY + 2] = '.';
		ppnMat[nNowX + 3][nNowY + 2] = '.'; ppnMat[nNowX + 4][nNowY + 2] = '.';
		ppnMat[nNowX + 3][nNowY] = '.';
		return 6;
	}

	if (ppnMat[nNowX + 1][nNowY] == '#' && ppnMat[nNowX + 2][nNowY] == '#' &&
		ppnMat[nNowX + 4][nNowY] == '#' && ppnMat[nNowX][nNowY + 1] == '#' &&
		ppnMat[nNowX + 4][nNowY + 1] == '#' &&
		ppnMat[nNowX][nNowY + 2] == '#' && ppnMat[nNowX + 2][nNowY + 2] == '#' &&
		ppnMat[nNowX + 3][nNowY + 2] == '#' && ppnMat[nNowX + 4][nNowY + 2] == '#' &&
		ppnMat[nNowX + 3][nNowY] == '#' && ppnMat[nNowX + 1][nNowY + 2] == '#')
	{
		ppnMat[nNowX + 1][nNowY] = '.'; ppnMat[nNowX + 2][nNowY] = '.';
		ppnMat[nNowX + 4][nNowY] = '.'; ppnMat[nNowX][nNowY + 1] = '.';
		ppnMat[nNowX + 4][nNowY + 1] = '.';
		ppnMat[nNowX][nNowY + 2] = '.'; ppnMat[nNowX + 2][nNowY + 2] = '.';
		ppnMat[nNowX + 3][nNowY + 2] = '.'; ppnMat[nNowX + 4][nNowY + 2] = '.';
		ppnMat[nNowX + 3][nNowY] = '.'; ppnMat[nNowX + 1][nNowY + 2] = '.';
		return 0;
	}

	if (ppnMat[nNowX + 2][nNowY] == '#' && ppnMat[nNowX + 3][nNowY + 2] == '#' &&
		ppnMat[nNowX + 4][nNowY] == '#' && ppnMat[nNowX + 2][nNowY + 1] == '#' &&
		ppnMat[nNowX + 4][nNowY + 1] == '#' && ppnMat[nNowX][nNowY + 1] == '#' &&
		ppnMat[nNowX][nNowY + 2] == '#' && ppnMat[nNowX + 1][nNowY + 2] == '#' &&
		ppnMat[nNowX + 2][nNowY + 2] == '#' && ppnMat[nNowX + 4][nNowY + 2] == '#')
	{
		ppnMat[nNowX + 2][nNowY] = '.'; ppnMat[nNowX + 3][nNowY + 2] = '.';
		ppnMat[nNowX + 4][nNowY] = '.'; ppnMat[nNowX + 2][nNowY + 1] = '.';
		ppnMat[nNowX + 4][nNowY + 1] = '.'; ppnMat[nNowX][nNowY + 1] = '.';
		ppnMat[nNowX][nNowY + 2] = '.'; ppnMat[nNowX + 1][nNowY + 2] = '.';
		ppnMat[nNowX + 2][nNowY + 2] = '.'; ppnMat[nNowX + 4][nNowY + 2] = '.';
		return 3;
	}


	if (ppnMat[nNowX + 2][nNowY] == '#' && ppnMat[nNowX + 3][nNowY] == '#' &&
		ppnMat[nNowX + 4][nNowY] == '#' && ppnMat[nNowX + 2][nNowY + 1] == '#' &&
		ppnMat[nNowX + 4][nNowY + 1] == '#' && ppnMat[nNowX][nNowY + 1] == '#' &&
		ppnMat[nNowX][nNowY + 2] == '#' && ppnMat[nNowX + 1][nNowY + 2] == '#' &&
		ppnMat[nNowX + 2][nNowY + 2] == '#' && ppnMat[nNowX + 4][nNowY + 2] == '#')
	{
		ppnMat[nNowX + 2][nNowY] = '.'; ppnMat[nNowX + 3][nNowY] = '.';
		ppnMat[nNowX + 4][nNowY] = '.'; ppnMat[nNowX + 2][nNowY + 1] = '.';
		ppnMat[nNowX + 4][nNowY + 1] = '.'; ppnMat[nNowX][nNowY + 1] = '.';
		ppnMat[nNowX][nNowY + 2] = '.'; ppnMat[nNowX + 1][nNowY + 2] = '.';
		ppnMat[nNowX + 2][nNowY + 2] = '.'; ppnMat[nNowX + 4][nNowY + 2] = '.';
		return 2;
	}

	if (ppnMat[nNowX + 1][nNowY] == '#' && ppnMat[nNowX + 2][nNowY] == '#' &&
		ppnMat[nNowX + 4][nNowY] == '#' && ppnMat[nNowX][nNowY + 1] == '#' &&
		ppnMat[nNowX + 2][nNowY + 1] == '#' && ppnMat[nNowX + 4][nNowY + 1] == '#' &&
		ppnMat[nNowX][nNowY + 2] == '#' && ppnMat[nNowX + 2][nNowY + 2] == '#' &&
		ppnMat[nNowX + 3][nNowY + 2] == '#' && ppnMat[nNowX + 4][nNowY + 2] == '#')
	{
		ppnMat[nNowX + 1][nNowY] = '.'; ppnMat[nNowX + 2][nNowY] = '.';
		ppnMat[nNowX + 4][nNowY] = '.'; ppnMat[nNowX][nNowY + 1] = '.';
		ppnMat[nNowX + 2][nNowY + 1] = '.'; ppnMat[nNowX + 4][nNowY + 1] = '.';
		ppnMat[nNowX][nNowY + 2] = '.'; ppnMat[nNowX + 2][nNowY + 2] = '.';
		ppnMat[nNowX + 3][nNowY + 2] = '.'; ppnMat[nNowX + 4][nNowY + 2] = '.';
		return 5;
	}

	if (ppnMat[nNowX + 1][nNowY] == '#' && ppnMat[nNowX + 2][nNowY] == '#' &&
		ppnMat[nNowX + 2][nNowY + 1] == '#' && ppnMat[nNowX][nNowY + 2] == '#' &&
		ppnMat[nNowX + 3][nNowY + 2] == '#' && ppnMat[nNowX + 1][nNowY + 2] == '#' &&
		ppnMat[nNowX + 2][nNowY + 2] == '#' && ppnMat[nNowX + 4][nNowY + 2] == '#')
	{
		ppnMat[nNowX + 1][nNowY] = '.'; ppnMat[nNowX + 2][nNowY] = '.';
		ppnMat[nNowX + 2][nNowY + 1] = '.'; ppnMat[nNowX][nNowY + 2] = '.';
		ppnMat[nNowX + 3][nNowY + 2] = '.'; ppnMat[nNowX + 1][nNowY + 2] = '.';
		ppnMat[nNowX + 2][nNowY + 2] = '.'; ppnMat[nNowX + 4][nNowY + 2] = '.';
		return 4;
	}




	if (ppnMat[nNowX][nNowY + 1] == '#' && ppnMat[nNowX][nNowY + 2] == '#' &&
		ppnMat[nNowX + 3][nNowY + 2] == '#' && ppnMat[nNowX + 1][nNowY + 2] == '#' &&
		ppnMat[nNowX + 2][nNowY + 2] == '#' && ppnMat[nNowX + 4][nNowY + 2] == '#')
	{
		ppnMat[nNowX][nNowY + 1] = '.'; ppnMat[nNowX][nNowY + 2] = '.';
		ppnMat[nNowX + 3][nNowY + 2] = '.'; ppnMat[nNowX + 1][nNowY + 2] = '.';
		ppnMat[nNowX + 2][nNowY + 2] = '.'; ppnMat[nNowX + 4][nNowY + 2] = '.';
		return 7;
	}





}



int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false);

	int			nInputN;
	int			nInputM;
	int**		ppnMat					= NULL;
	char		cTemp;
	string		szTemp;
	scanf("%d%d", &nInputN, &nInputM);

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));

	for (int i = 1; i <= nInputN; i++)
		ppnMat[i] = (int*)malloc((nInputM + 1) * sizeof(int));


	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputM; j++)
		{
			scanf(" %c", &cTemp);
			ppnMat[i][j] = cTemp;
		}
	for (int i = 1; i <= nInputM; i++)
		for (int j = 1; j <= nInputN; j++)
		{
			if (ppnMat[j][i] == '#')
				cout << Check(ppnMat, nInputN, nInputM, j, i);
		}


Exit0:

	return 0;
}