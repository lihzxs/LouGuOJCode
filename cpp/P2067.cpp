/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-3 21:41
//	Comment		:	OJ(P2067)
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




int main(int argc, char* argv[])
{
	int				nInputN;
	int				nOneIndex;
	int				nZeroX;
	int				nZeroY;
	int*			pnX				= NULL;
	int*			pnY				= NULL;
	int				nCount			= 0;
	double			nK;
	double			nB;
	int*			pnXCount		= 0;
	int*			pnYCount		= 0;
	string*			pszInput;
	int				nTemp			= 0;
	int				nMax			= 0;
	scanf("%d", &nInputN);
	pnX = (int*)malloc(2 * sizeof(int));
	pnY = (int*)malloc(2 * sizeof(int));
	
	pnYCount = (int*)malloc((nInputN + 1) * sizeof(int));
	pnXCount = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnYCount, 0, (nInputN + 1) * sizeof(int));
	memset(pnXCount, 0, (nInputN + 1) * sizeof(int));
	pszInput = new string[nInputN + 1];
	for (int i = 1; i <= nInputN; i++)
	{
		cin >> pszInput[i];

		for (int j = 0; j < pszInput[i].length(); j++)
		{
			if (pszInput[i][j] == 'x')
			{
				pnX[nCount] = j + 1;
				pnY[nCount] = i;
				nCount++;
			}
			if (pszInput[i][j] == 'x' || pszInput[i][j] == '1')
			{
				pnYCount[i]++;
				pnXCount[j]++;
			}
		}
	}

	for (int i = 0; i <= nInputN; i++)
	{
		if (nMax < pnXCount[i])
		{
			nMax = pnXCount[i];
			nZeroX = i + 1;
		}
	}
	nMax = 0;

	for (int i = 0; i <= nInputN; i++)
	{
		if (nMax < pnYCount[i])
		{
			nMax = pnYCount[i];
			nZeroY = i;
		}
	}
		




	for (int i = 0; i < 2; i++)
	{
		pnX[i] = pnX[i] - nZeroX;
		pnY[i] = nZeroY - pnY[i];
	}

	if (pnX[0] == pnX[1])
		printf("x=%.4f\n", double(pnX[0]));
	else if(pnY[0] == pnY[1])
		printf("y=%.4f\n", double(pnY[0]));
	else
	{
		nK = (pnY[0] - pnY[1]) * 1.0 / (pnX[0] - pnX[1]);
		nB = pnY[0] - 
			(pnY[0] - pnY[1]) * 1.0 / (pnX[0] - pnX[1]) * pnX[0];
				if (nB < 0)
			printf("y=%.4fx%.4f\n", nK, nB);
		else if (nB == 0)
			printf("y=%.4fx\n", nK);
		else
			printf("y=%.4fx+%.4f\n", nK, nB);
	}
Exit0:
	return 0;
}