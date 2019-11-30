/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-25 00:28
//	Comment		:	OJ(P2256)
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


int Fin(int* pnSet, int nNum)
{
	if (pnSet[nNum] == nNum)
		return pnSet[nNum];
	else
		return pnSet[nNum] =
		Fin(pnSet, pnSet[nNum]);
}




int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int*			pnSet = NULL;
	int				nInputA;
	int				nInputB;
	int				nInputC;
	string			szTemp;
	string			szTemp2;
	map<string, int> mpName;
	scanf("%d%d", &nInputN, &nInputM);

	pnSet = (int*)malloc((nInputN + 1) * sizeof(int));

	for (int i = 1; i <= nInputN; i++)
		pnSet[i] = i;

	for (int i = 1; i <= nInputN; i++)
	{
		cin >> szTemp;
		mpName[szTemp] = i;
	}


	for (int i = 0; i < nInputM; i++)
	{
		cin >> szTemp >> szTemp2;
		pnSet[Fin(pnSet, mpName[szTemp])] = Fin(pnSet, mpName[szTemp2]);
	}



	scanf("%d", &nInputM);
	for (int i = 0; i < nInputM; i++)
	{
		cin >> szTemp >> szTemp2;
		if (Fin(pnSet, mpName[szTemp]) == Fin(pnSet, mpName[szTemp2]))
			printf("Yes.\n");
		else
			printf("No.\n");
	}

Exit0:
	return 0;
}