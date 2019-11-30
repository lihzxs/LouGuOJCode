/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-6 20:33
//	Comment		:	OJ(P1506)
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
#define	MAXNUM		100000000
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

void DFS(int** ppnMat, int nX, int nY, int** ppnGuide, int nN, int nM)
{
	if (ppnMat[nY][nX] == 1)
		return;
	ppnMat[nY][nX] = 1;
	for (int i = 1; i <= 4; i++)
	{
		if (nY + ppnGuide[i][0] < 1 || nY + ppnGuide[i][0] > nN)
			continue;
		if (nX + ppnGuide[i][1] < 1 || nX + ppnGuide[i][1] > nM)
			continue;
		DFS(ppnMat, nX + ppnGuide[i][1], nY + ppnGuide[i][0],
			ppnGuide, nN, nM);
	}

}




int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int**			ppnMat				 = NULL;
	int**			ppnGuide			 = NULL;
	string			szInput;
	int				nAns				 = 0;
	scanf("%d%d", &nInputN, &nInputM);


	ppnGuide = (int**)malloc(5 * sizeof(int*));

	for (int i = 1; i < 5; i++)
		ppnGuide[i] = (int*)malloc(2 * sizeof(int));

	ppnGuide[1][0] = 1; ppnGuide[1][1] = 0;
	ppnGuide[2][0] = -1; ppnGuide[2][1] = 0;
	ppnGuide[3][0] = 0; ppnGuide[3][1] = 1;
	ppnGuide[4][0] = 0; ppnGuide[4][1] = -1;


	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));

	for (int i = 1; i <= nInputN; i++)
		ppnMat[i] = (int*)malloc((nInputM + 1) * sizeof(int));

	for (int i = 1; i <= nInputN; i++)
	{
		cin >> szInput;
		for (int j = 0; j < szInput.length(); j++)
		{
			if (szInput[j] == '0')
				ppnMat[i][j + 1] = 0;
			else
				ppnMat[i][j + 1] = 1;
		}
	}

	for (int i = 1; i <= nInputN; i++)
	{
		if (ppnMat[i][1] == 0)
			DFS(ppnMat, 1, i,
				ppnGuide, nInputN, nInputM);
		if (ppnMat[i][nInputM] == 0)
			DFS(ppnMat, nInputM, i,
				ppnGuide, nInputN, nInputM);
	}

	for (int i = 1; i <= nInputM; i++)
	{
		if (ppnMat[1][i] == 0)
			DFS(ppnMat, i, 1,
				ppnGuide, nInputN, nInputM);
		if (ppnMat[nInputN][i] == 0)
			DFS(ppnMat, i, nInputN,
				ppnGuide, nInputN, nInputM);
	}

	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputM; j++)
			if (ppnMat[i][j] == 0)
				nAns++;


	printf("%d", nAns);




Exit0:
	return 0;
}