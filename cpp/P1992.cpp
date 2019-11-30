/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-10 00:38
//	Comment		:	OJ(P1992)
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


int Mode(int a, int b, int mode)
{
	int sum = 1;
	a = a % mode;

	while (b > 0) {
		if (b % 2 == 1)		//判断是否是奇数，是奇数的话将多出来的数事先乘如sum
			sum = (sum * a) % mode;

		b /= 2;
		a = (a * a) % mode;// 不断的两两合并再取模，减小a和b的规模
	}
	return sum;
}

bool Check(int* pnEnter, int nN)
{
	for (int i = 1; i <= nN; i++)
		if (pnEnter[i])
			return false;
	return true;
}

int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	long long		nInputK;
	int				nCount = 0;
	int				nInputA;
	int				nInputB;
	int				nInputC;
	int*			pnEnter				= NULL;
	int*			pnFlag				= NULL;
	int**			ppnMat				= NULL;

	
	scanf("%d%d%lld", &nInputN, &nInputM, &nInputK);

	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	pnEnter = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnEnter, 0, (nInputN + 1) * sizeof(int));
	pnFlag = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnFlag, 0, (nInputN + 1) * sizeof(int));
	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		memset(ppnMat[i], 0, (nInputN + 1) * sizeof(int));
	}

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d", &nInputA, &nInputB);
		ppnMat[nInputA][nInputB] = 1;
	}

	for (int i = 1; i <= nInputN; i++)
	{
		for (int j = 1; j <= nInputN; j++)
			pnEnter[i] += ppnMat[j][i];
	}

	for (int i = 1; i <= nInputN; i++)
	{
		if (pnEnter[i] == 0 && !pnFlag[i])
		{
			pnFlag[i] = 1;
			for (int j = 1; j <= nInputN; j++)
				pnEnter[j] -= ppnMat[i][j];
			i = 0;
		}
	}



	if (!Check(pnEnter, nInputN))
	{
		printf("No\n");
		printf("%lld\n", nInputK * nInputK);
	}
	else
	{
		printf("Yes\n");
		printf("%d\n", Mode(2, nInputK, 9997));
	}





Exit0:
	return 0;
}