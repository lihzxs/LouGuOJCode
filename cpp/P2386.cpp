/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-18 20:37
//	Comment		:	OJ(P2386)
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
#define	MAXNUM		1000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

void DFS(int nM, int nN, int nPre, int nSum, int nCount, int& nAns)
{
	
	if (nSum == nN)
	{
		nAns++;
		return;
	}

	if (nCount >= nM)
		return;

	if (nSum >= nN)
		return;

	for (int i = nPre; i <= nN - nSum; i++)
		DFS(nM, nN, i, nSum + i, nCount + 1, nAns);
}



int main(int argc, char* argv[])
{
	int					nInputT;
	int					nInputM;
	int					nInputN;
	int					nAns;
	scanf("%d", &nInputT);
	while (nInputT--)
	{
		scanf("%d%d", &nInputM, &nInputN);
		nAns = 0;
		DFS(nInputN, nInputM, 1, 0, 0, nAns);
		printf("%d\n", nAns);
	}


Exit0:

	return 0;
}