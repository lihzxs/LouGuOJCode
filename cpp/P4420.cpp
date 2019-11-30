/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-14 19:10
//	Comment		:	OJ(P4420)
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

int Check(int nX, int nY, char cTemp, string* pszMat)
{
	pszMat[nX][nY] = '.';
	if (pszMat[nX + 1][nY + 1] == cTemp &&
		pszMat[nX][nY + 1] == cTemp && pszMat[nX + 1][nY] == cTemp)
	{
		for (int i = nX; i <= nX + 1; i++)
			for (int j = nY; j <= nY + 1; j++)
				pszMat[i][j] = '.';
		return 1;
	}
	else if (pszMat[nX][nY + 1] == cTemp &&  
		pszMat[nX][nY + 2] == cTemp && pszMat[nX][nY + 3] == cTemp)
	{
		for (int i = nY; i <= nY + 3; i++)
			pszMat[nX][i] = '.';
		return 2;
	}
	else if (pszMat[nX + 1][nY] == cTemp &&
		pszMat[nX + 2][nY] == cTemp && pszMat[nX + 3][nY] == cTemp)
	{
		for (int i = nX; i <= nX + 3; i++)
			pszMat[i][nY] = '.';
		return 2;
	}
	else if (pszMat[nX + 1][nY] == cTemp &&
		pszMat[nX + 1][nY + 1] == cTemp && pszMat[nX + 2][nY + 1] == cTemp)
	{
		pszMat[nX + 1][nY] = '.';
		pszMat[nX + 1][nY + 1] = '.';
		pszMat[nX + 2][nY + 1] = '.';
		return 3;
	}
	else if (pszMat[nX][nY + 1] == cTemp &&
		pszMat[nX + 1][nY] == cTemp && pszMat[nX + 1][nY - 1] == cTemp)
	{
		pszMat[nX][nY + 1] = '.';
		pszMat[nX + 1][nY] = '.';
		pszMat[nX + 1][nY - 1] = '.';
		return 3;
	}
	else if (pszMat[nX][nY + 1] == cTemp &&
		pszMat[nX + 1][nY + 1] == cTemp && pszMat[nX + 1][nY + 2] == cTemp)
	{
		pszMat[nX][nY + 1] = '.';
		pszMat[nX + 1][nY + 1] = '.';
		pszMat[nX + 1][nY + 2] = '.';
		return 4;
	}
	else if (pszMat[nX + 1][nY] == cTemp &&
		pszMat[nX + 1][nY - 1] == cTemp && pszMat[nX + 2][nY - 1] == cTemp)
	{
		pszMat[nX + 1][nY] = '.';
		pszMat[nX + 1][nY - 1] = '.';
		pszMat[nX + 2][nY - 1] = '.';
		return 4;
	}
	else
	{
		if (pszMat[nX + 1][nY] == cTemp)
			pszMat[nX + 1][nY] = '.';
		if (pszMat[nX + 2][nY] == cTemp)
			pszMat[nX + 2][nY] = '.';
		if (pszMat[nX + 1][nY - 1] == cTemp)
			pszMat[nX + 1][nY - 1] = '.';
		if (pszMat[nX + 1][nY + 1] == cTemp)
			pszMat[nX + 1][nY + 1] = '.';
		if (pszMat[nX][nY + 1] == cTemp)
			pszMat[nX][nY + 1] = '.';
		if (pszMat[nX][nY + 2] == cTemp)
			pszMat[nX][nY + 2] = '.';
		return 5;
	}
}




int main(int argc, char* argv[])
{
	int					nInputN;
	int					nInputM;
	int*				pnCount				= NULL;
	string*				pszMat				= NULL;
	
	scanf("%d%d", &nInputN, &nInputM);
	pnCount = (int*)malloc(6 * sizeof(int));
	memset(pnCount, 0, 6 * sizeof(int));
	pszMat = new string[nInputN + 5];

	for (int i = 1; i <= nInputN; i++)
	{
		cin >> pszMat[i];
		pszMat[i] = " " + pszMat[i] + "    ";
	}
	pszMat[nInputN + 1] = "                                  ";
	pszMat[nInputN + 2] = "                                  ";
	pszMat[			 0] = "                                  ";

	for (int i = 1; i <= nInputN; i++)
	{
		for (int j = 1; j <= nInputM; j++)
			if (pszMat[i][j] != '.')
				pnCount[Check(i, j, pszMat[i][j], pszMat)]++;
	}

	for (int i = 1; i < 6; i++)
		printf("%d\n", pnCount[i]);


Exit0:

	return 0;
}