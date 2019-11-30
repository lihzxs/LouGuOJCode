/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-13 23:02
//	Comment		:	OJ(P1959)
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
int							pnFlag[5005][5005];
int Check(int a, int b, int c, int d)
{
	int nCX = a - c;
	int nCY = b - d;
	int nNewA;
	int nNewB;
	int nNewC;
	int nNewD;


	nNewA = a + nCY;
	nNewB = b - nCX;
	nNewC = c + nCY;
	nNewD = d - nCX;
	if (nNewA >= 0 && nNewA <= 5000 && nNewB >= 0 && nNewB <= 5000)
		if (nNewC >= 0 && nNewC <= 5000 && nNewD >= 0 && nNewD <= 5000)
			if (pnFlag[nNewA][nNewB] && pnFlag[nNewC][nNewD])
			return nCX * nCX + nCY * nCY;
	nNewA = a - nCY;
	nNewB = b + nCX;
	nNewC = c - nCY;
	nNewD = d + nCX;
	if (nNewA >= 0 && nNewA <= 5000 && nNewB >= 0 && nNewB <= 5000)
		if (nNewC >= 0 && nNewC <= 5000 && nNewD >= 0 && nNewD <= 5000)
			if (pnFlag[nNewA][nNewB] && pnFlag[nNewC][nNewD])
			return nCX * nCX + nCY * nCY;
	return 0;
}

int main(int argc, char* argv[])
{
	int							nInputN;
	pair<int, int>				prTemp[3005];
	int				nMax		= 0;
	int				nCount		= 0;
	scanf("%d", &nInputN);
	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d", &prTemp[i].first, &prTemp[i].second);
		pnFlag[prTemp[i].first][prTemp[i].second] = 1;
	}

	for (int i = 0; i < nInputN; i++)
		for (int j = 0; j < nInputN; j++)
			nMax = max(nMax, Check(prTemp[i].first, prTemp[i].second, prTemp[j].first, prTemp[j].second));


	printf("%d", nMax);
		


Exit0:

	return 0;
}