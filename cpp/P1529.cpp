/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-11 1:04
//	Comment		:	OJ(P1529)
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



int main(int argc, char* argv[])
{
	int				nInputM;
	map<int, int>	mpNum;
	map<int, int>	mpAlp;
	int**			ppnMat				= NULL;
	string			szA;
	string			szB;
	int				nNum;

	ppnMat = (int**)malloc(60 * sizeof(int*));
	for (int i = 0; i < 60; i++)
	{
		ppnMat[i] = (int*)malloc(60 * sizeof(int));
		memset(ppnMat[i], 0, 60 * sizeof(int));
	}
		

	for (int i = 1; i <= 26; i++)
	{
		mpNum['a' + i - 1] = i;
		mpAlp[i] = 'a' + i - 1;
	}
		

	for (int i = 1; i <= 26; i++)
	{
		mpNum['A' + i - 1] = i + 26;
		mpAlp[i + 26] = 'A' + i - 1;
	}
		
	scanf("%d", &nInputM);

	for (int i = 0; i < nInputM; i++)
	{
		cin >> szA >> szB >> nNum;
		if (szA[0] == szB[0])
			continue;
		if (ppnMat[mpNum[szA[0]]][mpNum[szB[0]]] == 0)
			ppnMat[mpNum[szA[0]]][mpNum[szB[0]]] =
			ppnMat[mpNum[szB[0]]][mpNum[szA[0]]] = nNum;
		else
			ppnMat[mpNum[szA[0]]][mpNum[szB[0]]] =
			ppnMat[mpNum[szB[0]]][mpNum[szA[0]]] =
			min(nNum, ppnMat[mpNum[szB[0]]][mpNum[szA[0]]]);
	}

	unsigned int*	pnDis = NULL;
	int*		pnFlag = NULL;
	pnDis = (unsigned int*)malloc((60 + 1) * sizeof(unsigned int));
	memset(pnDis, 127, (60 + 1) * sizeof(unsigned int));
	pnFlag = (int*)malloc((60 + 1) * sizeof(int));
	memset(pnFlag, 0, (60 + 1) * sizeof(int));
	pnDis[mpNum['Z']] = 0;
	int nMin;
	int	nPoint;
	for (int i = 1; i <= 52; i++)
	{

		nMin = pnDis[0];
		for (int j = 1; j <= 52; j++)
		{
			if (pnDis[j] < nMin && pnFlag[j] == false)
			{
				nMin = pnDis[j];
				nPoint = j;
			}
		}

		pnFlag[nPoint] = true;

		for (int j = 1; j <= 52; j++)
		{
			if (ppnMat[nPoint][j] != 0)
			{
				if (pnDis[j] > pnDis[nPoint] + ppnMat[nPoint][j] &&
					pnFlag[j] == false)
					pnDis[j] = pnDis[nPoint] + ppnMat[nPoint][j];
			}
		}
	}
	nMin = pnDis[0];
	int		nIndex;
	for (int i = 27; i < 52; i++)
	{
		if (i == mpNum['Z'])
			continue;
		if (nMin > pnDis[i])
		{
			nMin = pnDis[i];
			nIndex = i;
		}
	}

	printf("%c %d\n", mpAlp[nIndex], nMin);


Exit0:

	return 0;
}