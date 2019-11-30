/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-14 21:50
//	Comment		:	OJ(P1591)
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
#include <list>
#include <float.h>

using namespace std;
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

stack<int> sA;
void Mult(int* pnA, int nB, int* pnB)
{

	int nCount = 0;
	int	nPre = 0;
	int nTemp;
	for (int i = 0; pnA[i] != -1; i++)
		sA.push(pnA[i]);
	while (!sA.empty())
	{
		pnB[nCount++] = sA.top() * nB;
		sA.pop();
	}

	for (int i = 0; i < nCount; i++)
	{
		nTemp = pnB[i] + nPre;
		nPre = nTemp / 10;
		pnB[i] = nTemp % 10;
	}

	while (nPre != 0)
	{
		pnB[nCount++] = nPre % 10;
		nPre /= 10;
	}

	pnB[nCount] = -1;

	int i = 0;
	int j = nCount - 1;

	while (i < j)
	{
		swap(pnB[i], pnB[j]);
		i++;
		j--;
	}
}


void Init(int** ppnNum)
{
	ppnNum[1][0] = 1;
	ppnNum[1][1] = -1;
	for (int i = 2; i <= 1000; i++)
		Mult(ppnNum[i - 1], i, ppnNum[i]);
}


int main(int argc, char* argv[])
{
	int**			ppnNum;
	int				nInputT;
	int				nN;
	int				nNum;
	int				nCount		= 0;
	ppnNum = (int**)malloc(1001 * sizeof(int*));
	
	for (int i = 1; i <= 1000; i++)
		ppnNum[i] = (int*)malloc(10000 * sizeof(int));

	Init(ppnNum);

	scanf("%d", &nInputT);
	
	while (nInputT--)
	{
		nCount = 0;
		scanf("%d%d", &nN, &nNum);
		for (int i = 0; ppnNum[nN][i] != -1; i++)
			if (ppnNum[nN][i] == nNum)
				nCount++;
		printf("%d\n", nCount);
	}


Exit0:

	return 0;
}