/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-17 22:35
//	Comment		:	OJ(P4888)
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


int Ans(string* pszMat, int nN, int nX, int nY)
{
	int		nCountV = 0;
	int		nCountH = 0;
	int	i = nX;
	int j = nX;

	while (pszMat[i][nY] == pszMat[j][nY])
	{
		nCountV += 2;
		i--;
		j++;
		if (i < 1 || j > nN)
			break;
	}

	i = nY;
	j = nY;
	while (pszMat[nX][i] == pszMat[nX][j])
	{
		nCountH += 2;
		i--;
		j++;
		if (i < 1 || j > nN)
			break;
	}
	return max(nCountH, nCountV) - 1;
}


int main(int argc, char* argv[])
{
	int					nInputN;
	int					nInputM;
	int					nX;
	int					nY;
	string*				pszMat				= NULL;
	string				szTemp;

	scanf("%d%d", &nInputN, &nInputM);

	pszMat = new string[nInputN + 1];


	for (int i = 1; i <= nInputN; i++)
	{
		cin >> pszMat[i];
		pszMat[i] = " " + pszMat[i];
	}

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d", &nX, &nY);
		printf("%d\n", Ans(pszMat, nInputN, nX, nY));
	}




Exit0:

	return 0;
}