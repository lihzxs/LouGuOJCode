/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-17 15:31
//	Comment		:	OJ(P2427)
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

bool Check(int** ppnMat, int nX, int nY, int nTar, int nLong)
{
	for (int i = 1; i <= nLong; i++)
	{
		if (ppnMat[nX + nLong][nY - i] != nTar)
			return false;
		if (ppnMat[nX + nLong][nY + i] != nTar)
			return false;
		if (ppnMat[nX - nLong][nY - i] != nTar)
			return false;
		if (ppnMat[nX - nLong][nY + i] != nTar)
			return false;
		if (ppnMat[nX + i][nY + nLong] != nTar)
			return false;
		if (ppnMat[nX - i][nY + nLong] != nTar)
			return false;
		if (ppnMat[nX + i][nY - nLong] != nTar)
			return false;
		if (ppnMat[nX - i][nY - nLong] != nTar)
			return false;
	}
	return true;
}




int main(int argc, char* argv[])
{

	int					nInputN;
	int					nInputM;
	int					nInputQ;
	int**				ppnMat				= NULL;
	int					nX;
	int					nY;
	int					nLong;
	string				szTemp;

	scanf("%d%d%d", &nInputN, &nInputM, &nInputQ);

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputM + 1) * sizeof(int));
		memset(ppnMat[i], 0, (nInputM + 1) * sizeof(int));
	}

	for (int i = 1; i <= nInputN; i++)
	{
		cin >> szTemp;
		for (int j = 0; j < szTemp.length(); j++)
			ppnMat[i][j + 1] = szTemp[j];

	}


	for (int i = 0; i < nInputQ; i++)
	{
		scanf("%d%d", &nX, &nY);
		nLong = min(nX, nY);
		nX++;
		nY++;

		nLong = min(nInputN - nX, nLong);
		nLong = min(nLong, nInputM - nY);

		for (int i = 0; i <= nLong + 1; i++)
		{
			if (i == nLong + 1)
			{
				printf("%d\n", 2 * nLong + 1);
				break;
			}
			if (!Check(ppnMat, nX, nY, ppnMat[nX][nY],i))
			{
				printf("%d\n", 2 * (i - 1) + 1);
				break;
			}
		}
	}




Exit0:

	return 0;
}