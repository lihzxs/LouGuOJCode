/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-6 21:31
//	Comment		:	OJ(P1086)
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

typedef struct SPeanut
{
	int		nX;
	int		nY;
	int		nNum;
}SPeanut;

bool cmp(const SPeanut& sFirst, const SPeanut& sSecond)
{
	return sFirst.nNum > sSecond.nNum;
}



int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int				nInputK;
	int				nInputTemp;
	int				nCount				= 0;
	SPeanut*		psPeanut			= NULL;
	int				nUseTime			= 0;
	int				nAns				= 0;
	int				nPreX;
	int				nPreY;
	int				nBackTime;
	int				nMinX;
	int				nMinY;
	int				nMinDis;
	int				nMinIndex;
	scanf("%d%d%d", &nInputN, &nInputM, &nInputK);

	psPeanut = (SPeanut*)malloc(nInputN * nInputM * sizeof(SPeanut));

	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j <= nInputM; j++)
		{
			scanf("%d", &nInputTemp);
			if (nInputTemp != 0)
			{
				psPeanut[nCount].nX = j;
				psPeanut[nCount].nY = i;
				psPeanut[nCount].nNum = nInputTemp;
				nCount++;
			}
		}


	sort(psPeanut, psPeanut + nCount, cmp);
	if (2 * psPeanut[0].nY + 1 >= nInputK)
	{
		if (2 * psPeanut[0].nY + 1 > nInputK)
			printf("0\n");
		else
			printf("%d\n", psPeanut[0].nNum);
	}
	else
	{
		nUseTime = psPeanut[0].nY + 1;
		nBackTime = psPeanut[0].nY;
		nPreX = psPeanut[0].nX;
		nPreY = psPeanut[0].nY;
		nAns += psPeanut[0].nNum;
		for (int i = 1; i < nCount; i++)
		{
			if (nUseTime + nBackTime >= nInputK)
				break;
			
			if (nUseTime + abs(psPeanut[i].nX - nPreX) +
				abs(psPeanut[i].nY - nPreY) + psPeanut[i].nY + 1 > nInputK)
				break;
			else
			{
				nUseTime += abs(psPeanut[i].nX - nPreX) +
					abs(psPeanut[i].nY - nPreY) + 1;
				nBackTime = psPeanut[i].nY;
				nAns += psPeanut[i].nNum;
				nPreX = psPeanut[i].nX;
				nPreY = psPeanut[i].nY;
			}

		}
		printf("%d\n", nAns);
	}







Exit0:
	return 0;
}