/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-4 21:16
//	Comment		:	OJ(P2038)
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

BOOL IsPrime(int nNum)
{
	for (int i = 2; i <= int(sqrt(nNum)); i++)
	{
		if (nNum % i == 0)
			return false;
	}
	return true;
}







int main(int argc, char* argv[])
{

	int							nInputN;
	int							nInputD;
	int							nX;
	int							nY;
	int							nK;
	int							nSum		= 0;
	int							nMax		= 0;
	int							nCount		= 0;
	int**						ppnMat		= NULL;
	int**						ppnMatCount	= NULL;

	scanf("%d%d", &nInputD, &nInputN);

	ppnMat = (int**)malloc(129 * sizeof(int*));
	ppnMatCount = (int**)malloc(129 * sizeof(int*));
	for (int i = 0; i < 129; i++)
	{
		ppnMat[i] = (int*)malloc(129 * sizeof(int));
		ppnMatCount[i] = (int*)malloc(129 * sizeof(int));
		memset(ppnMat[i], 0, 129 * sizeof(int));
		memset(ppnMatCount[i], 0, 129 * sizeof(int));
	}

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d%d", &nX, &nY, &nK);
		ppnMat[nY][nX] = nK;
	}

	for (int i = 0; i <= 128; i++)
		for (int j = 0; j <= 128; j++)
		{
			for (int k = i - nInputD; k <= i + nInputD; k++)
			{
				if (k < 0 || k > 128)
					continue;
				for (int l = j - nInputD; l <= j + nInputD; l++)
				{
					if (l < 0 || l > 128)
						continue;
					nSum += ppnMat[l][k];
				}
					
			}
				
			ppnMatCount[j][i] = nSum;
			if (nSum > nMax)
				nMax = nSum;
			nSum = 0;
		}

	for (int i = 0; i <= 128; i++)
		for (int j = 0; j <= 128; j++)
			if (nMax == ppnMatCount[j][i])
				nCount++;

	printf("%d %d\n", nCount, nMax);





Exit0:
	return 0;
}