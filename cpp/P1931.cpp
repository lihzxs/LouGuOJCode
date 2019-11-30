/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-22 23:13
//	Comment		:	OJ(P1931)
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
#define MODNUM		2e64


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;



int main(int argc, char* argv[])
{
	int					nInputN;
	int					nInputM;
	int					nInputT	= 0;
	int*				pnFlag;
	double				fTemp;
	double*				pfDis				= NULL;
	string				szName;
	string				szStart;
	string				szEnd;
	map<string, int>	mpNum;
	double**			ppnMat;



	ppnMat = (double**)malloc(31 * sizeof(double*));

	for (int i = 1; i < 31; i++)
		ppnMat[i] = (double*)malloc(31 * sizeof(double));

	while (scanf("%d", &nInputN))
	{
		if (nInputN == 0)
			break;
		for (int i = 1; i <= nInputN; i++)
			for (int j = 1; j <= nInputN; j++)
				if (i == j)
					ppnMat[i][j] = 1;
				else
					ppnMat[i][j] = 0;
		mpNum.clear();
		for (int i = 1; i <= nInputN; i++)
		{
			cin >> szName;
			mpNum[szName] = i;
		}
		scanf("%d", &nInputM);

		for (int i = 0; i < nInputM; i++)
		{
			cin >> szStart >> fTemp >> szEnd;
			ppnMat[mpNum[szStart]][mpNum[szEnd]] = fTemp;
		}
		for (int k = 1; k <= nInputN; k++)
			for (int i = 1; i <= nInputN; i++)
				for (int j = 1; j <= nInputN; j++)
					ppnMat[i][j] = max(ppnMat[i][j], ppnMat[i][k] * ppnMat[k][j]);
		int nFlag = 0;
		for (int j = 1; j <= nInputN; j++)
			if (ppnMat[j][j] > 1)
			{
				nFlag = 1;
				break;
			}

		if (nFlag)
			printf("Case %d: Yes\n", ++nInputT);
		else
			printf("Case %d: No\n", ++nInputT);

	}

Exit0:

	return 0;
}