/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-17 15:14
//	Comment		:	OJ(P1234)
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

	string				szInput;
	int					nInputN;
	int					nInputM;
	int**				ppnMat			= NULL;
	int**				ppnGuide		= NULL;
	int					nCount			= 0;
	int					nNewX;
	int					nNewY;
	ppnGuide = (int**)malloc(4 * sizeof(int*));
	for (int i = 0; i < 4; i++)
		ppnGuide[i] = (int*)malloc(2 * sizeof(int));

	ppnGuide[0][0] = 1; ppnGuide[0][1] = 0;
	ppnGuide[1][0] = 0; ppnGuide[1][1] = 1;
	ppnGuide[2][0] = -1; ppnGuide[2][1] = 0;
	ppnGuide[3][0] = 0; ppnGuide[3][1] = -1;

	scanf("%d%d", &nInputN, &nInputM);

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));

	for (int i = 0; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputM + 1) * sizeof(int));
		memset(ppnMat[i], 127, (nInputM + 1) * sizeof(int));
	}
	for (int i = 1; i <= nInputN; i++)
	{
		cin >> szInput;
		for (int j = 0; j < szInput.length(); j++)
		{
			if (szInput[j] == 'h')
				ppnMat[i][j + 1] = 1;
			if (szInput[j] == 'e')
				ppnMat[i][j + 1] = 0;
		}
	}

	for (int i = 1; i <= nInputN; i++)
	{
		for (int j = 1; j <= nInputM; j++)
		{
			if (ppnMat[i][j] == 1)
			for (int k = 0; k < 4; k++)
			{
				nNewX = i + 3 * ppnGuide[k][0];
				nNewY = j + 3 * ppnGuide[k][1];
				if (i + 3 * ppnGuide[k][0] < 1 || 
					i + 3 * ppnGuide[k][0] > nInputN)
					continue;
				if (j + 3 * ppnGuide[k][1] < 1 || 
					j + 3 * ppnGuide[k][1] > nInputM)
					continue;
				if (ppnMat[i + ppnGuide[k][0]][j + ppnGuide[k][1]] == 0 && 
					ppnMat[i + 2 * ppnGuide[k][0]][j + 2 * ppnGuide[k][1]] == 1 && 
					ppnMat[i + 3 * ppnGuide[k][0]][j + 3 * ppnGuide[k][1]] == 0)
					nCount++;
			}
			
		}
	}


	printf("%d", nCount);



Exit0:

	return 0;
}