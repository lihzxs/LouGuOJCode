/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-25 21:33
//	Comment		:	OJ(P3392)
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
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;




int main(int argc, char* argv[])
{
	int					nInputN;
	int					nInputM;
	int					nAns				= 0;
	int					nCountW				= 0;
	int					nCountB				= 0;
	int					nCountR				= 0;
	string*				pszInput			= NULL;

	scanf("%d%d", &nInputN, &nInputM);
	nAns = nInputM * nInputN;
	pszInput = new string[nInputN + 1];

	for (int i = 1; i <= nInputN; i++)
		cin >> pszInput[i];


	for (int i = 1; i < nInputN; i++)
	{
		for (int j = i + 1; j < nInputN; j++)
		{

			for (int k = 1; k <= i; k++)
				for (int l = 0; l < nInputM; l++)
					if (pszInput[k][l] != 'W')
						nCountW++;
			for (int k = i + 1; k <= j; k++)
				for (int l = 0; l < nInputM; l++)
					if (pszInput[k][l] != 'B')
						nCountB++;
			for (int k = j + 1; k <= nInputN; k++)
				for (int l = 0; l < nInputM; l++)
					if (pszInput[k][l] != 'R')
						nCountR++;

			nAns = min(nAns, nCountB + nCountR + nCountW);
			nCountB = 0;
			nCountR = 0;
			nCountW = 0;
		}
	}

	printf("%d", nAns);





		


Exit0:

	return 0;
}