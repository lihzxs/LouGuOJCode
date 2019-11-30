/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-10 15:14
//	Comment		:	OJ(P1913)
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

using namespace std;
#define	MAXNUM		150
#define	EPS         0.0001
#define MODNUM		1006


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


void DFS(int** ppnMat, int nX, int nY, 
	int nN, int nM, int nCount, int** ppnFlag)
{
	ppnFlag[nX][nY] = true;
	if (nX - 1 >= 1 && nX - 1 <= nN && !ppnFlag[nX - 1][nY] && ppnMat[nX - 1][nY] == 2)
		DFS(ppnMat, nX - 1, nY, nN, nM, nCount + 1, ppnFlag);
	if (nX + 1 >= 1 && nX + 1 <= nN && !ppnFlag[nX + 1][nY] && ppnMat[nX + 1][nY] == 1)
		DFS(ppnMat, nX + 1, nY, nN, nM, nCount + 1, ppnFlag);
	if (nY - 1 >= 1 && nY - 1 <= nM && !ppnFlag[nX][nY - 1] && ppnMat[nX][nY - 1] == 4)
		DFS(ppnMat, nX, nY - 1, nN, nM, nCount + 1, ppnFlag);
	if (nY + 1 >= 1 && nY + 1 <= nM && !ppnFlag[nX][nY + 1] && ppnMat[nX][nY + 1] == 3)
		DFS(ppnMat, nX, nY + 1, nN, nM, nCount + 1, ppnFlag);

}



int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int**			ppnMat;
	string			szInput;
	int				nAns			= 0;
	pair<int,int>*	ppair			= 0;
	int**			ppnFlag;
	scanf("%d%d", &nInputN, &nInputM);

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	ppnFlag = (int**)malloc((nInputN + 1) * sizeof(int*));
	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputM + 1) * sizeof(int));
		ppnFlag[i] = (int*)malloc((nInputM + 1) * sizeof(int));
		memset(ppnFlag[i], 0, (nInputM + 1) * sizeof(int));
	}
		

	for (int i = 1; i <= nInputN; i++)
	{
		cin >> szInput;
		for (int j = 0; j < szInput.length(); j++)
		{
			if (szInput[j] == 'u')
				ppnMat[i][j + 1] = 1;
			else if (szInput[j] == 'd')
				ppnMat[i][j + 1] = 2;
			else if (szInput[j] == 'l')
				ppnMat[i][j + 1] = 3;
			else if (szInput[j] == 'r')
				ppnMat[i][j + 1] = 4;
			else
				ppnMat[i][j + 1] = 0;
		}
	}

	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputM; j++)
		{
			if (ppnMat[i][j] == 0)
				DFS(ppnMat, i, j, nInputN, nInputM, 0, ppnFlag);
		}
	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputM; j++)
		{
			if (ppnFlag[i][j])
				nAns++;
		}
		
	printf("%d", nAns);




Exit0:

	return 0;
}