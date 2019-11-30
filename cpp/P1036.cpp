/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-4 20:54
//	Comment		:	OJ(P1036)
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

void DFS(int* pnSeq, BOOL* pbFlag,int nNum, int& nCount,
	int nK, int nNow, int nSum, int nTempi)
{
	if (nNow == nK && IsPrime(nSum))
	{
		nCount++;
		return;
	}
	if (nNow >= nK)
		return;
	for (int i = nTempi; i < nNum; i++)
	{
		if (!pbFlag[i])
		{
			pbFlag[i] = true;
			DFS(pnSeq, pbFlag, nNum, nCount,
				nK, nNow + 1, nSum + pnSeq[i], i);
			pbFlag[i] = false;
		}
	}
}





int main(int argc, char* argv[])
{

	int				nInputN;
	int				nInputK;
	int*			pnSeq					= NULL;
	BOOL*			pbFlag					= NULL;
	int				nCount					= 0;

	scanf("%d%d", &nInputN, &nInputK);

	pnSeq = (int*)malloc(nInputN * sizeof(int));
	pbFlag = (BOOL*)malloc(nInputN * sizeof(BOOL));
	memset(pbFlag, 0, nInputN * sizeof(BOOL));
	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeq + i);


	DFS(pnSeq, pbFlag, nInputN, nCount,
		nInputK, 0, 0, 0);

	printf("%d", nCount);



Exit0:
	return 0;
}