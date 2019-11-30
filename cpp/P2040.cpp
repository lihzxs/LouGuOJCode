/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-31 22:30
//	Comment		:	OJ(P2040)
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

int ppnMat[4][4];
int	ppnFlag[4][4];

bool Check()
{
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			if (!ppnMat[i][j])
				return false;
	return true;
}


void DFS(int nSum, int nCount, int& nMin)
{
	if (nCount > nMin)
		return;

	if(Check())
		nMin = min(nCount, nMin);

	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
		{
			if (!ppnFlag[i][j])
			{
				ppnFlag[i][j] = 1;
				ppnMat[i][j] = !ppnMat[i][j];

				if (i + 1 <= 3)
					ppnMat[i + 1][j] = !ppnMat[i + 1][j];
				if (i - 1 >= 1)
					ppnMat[i - 1][j] = !ppnMat[i - 1][j];
				if (j + 1 <= 3)
					ppnMat[i][j + 1] = !ppnMat[i][j + 1];
				if (j - 1 >= 1)
					ppnMat[i][j - 1] = !ppnMat[i][j - 1];

				DFS(nSum, nCount + 1, nMin);


				ppnMat[i][j] = !ppnMat[i][j];

				if (i + 1 <= 3)
					ppnMat[i + 1][j] = !ppnMat[i + 1][j];
				if (i - 1 >= 1)
					ppnMat[i - 1][j] = !ppnMat[i - 1][j];
				if (j + 1 <= 3)
					ppnMat[i][j + 1] = !ppnMat[i][j + 1];
				if (j - 1 >= 1)
					ppnMat[i][j - 1] = !ppnMat[i][j - 1];
				ppnFlag[i][j] = 0;
			}
		}
}



int main(int argc, char* argv[])
{
	int				nSum = 0;
	int				nMin		= 1000;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
		{
			scanf("%d", &ppnMat[i][j]);
			nSum += ppnMat[i][j];
		}


	DFS(nSum, 0, nMin);

	printf("%d", nMin);



Exit0:
	return 0;
}