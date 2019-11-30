/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-2 21:59
//	Comment		:	OJ(P1596)
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

void DFS(int** ppnMat, int nN, int nM, int nX, int nY)
{
	ppnMat[nY][nX] = 0;

	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
		{
			if (nX + i < 1 || nX + i > nM)
				continue;
			if (nY + j < 1 || nY + j > nN)
				continue;
			if (ppnMat[nY + j][nX + i])
				DFS(ppnMat, nN, nM, nX + i, nY + j);
		}
}






int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	BOOL**			ppnMat			= NULL;
	int				nAns			= 0;
	string			szInput;

	scanf("%d%d", &nInputN, &nInputM);
	ppnMat = (BOOL**)malloc((nInputN + 1) * sizeof(BOOL*));
	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (BOOL*)malloc((nInputM + 1) * sizeof(BOOL));
	}

	for (int i = 1; i <= nInputN; i++)
	{
		cin >> szInput;
		for (int j = 0; j < szInput.length(); j++)
		{
			if (szInput[j] == '.')
				ppnMat[i][j + 1] = 0;
			else
				ppnMat[i][j + 1] = 1;
		}
	}

	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputM; j++)
		{
			if (ppnMat[i][j])
			{
				DFS(ppnMat, nInputN, nInputM, j, i);
				nAns++;
			}
		}


	printf("%d", nAns);





Exit0:

	return 0;
}