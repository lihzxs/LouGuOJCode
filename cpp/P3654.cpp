/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-27 11:25
//	Comment		:	OJ(P3654)
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






int main(int argc, char* argv[])
{

	int					nInputN;
	int					nInputM;
	int					nInputK;
	int					nCount				= 0;
	int					nAns				= 0;
	int					nFlag				= 0;
	string*				pszMat				= NULL;

	scanf("%d%d%d", &nInputN, &nInputM, &nInputK);

	pszMat = new string[nInputN];

	for (int i = 0; i < nInputN; i++)
		cin >> pszMat[i];

	for (int i = 0; i < nInputN; i++)
	{
		for (int j = 0; j < nInputM; j++)
		{
			nCount = 0;
			for (int k = j; k < nInputM; k++)
				if (pszMat[i][k] == '.') nCount++;
				else 
					break;
			if (nCount >= nInputK)
				nAns++;

			nCount = 0;
			for (int k = i; k < nInputN; k++)
				if (pszMat[k][j] == '.') nCount++;
				else
					break;
			if (nCount >= nInputK)
				nAns++;
		}
	}
	if (nInputK == 1)
		nAns /= 2;
	printf("%d", nAns);



Exit0:

	return 0;
}