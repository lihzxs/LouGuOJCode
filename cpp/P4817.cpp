/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-14 00:47
//	Comment		:	OJ(P4817)
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
#define MODNUM		2e31


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

void DFS(int nV, bool pB, int nT, int nA, int nB ,int& nMax)
{
	if (nV > nT)
		return;
	if (nV == nT)
	{
		printf("%d", nT);
		exit(0);
	}
	nMax = max(nMax, nV);
	if (pB)	
		DFS(nV / 2, 0, nT,nA, nB,nMax);
	DFS(nV + nA, pB, nT, nA, nB, nMax);
	DFS(nV + nB, pB, nT, nA, nB, nMax);
	return;
}


int main(int argc, char* argv[])
{
	int					nT;
	int					nA;
	int					nB;
	int					nMax				= 0;
	scanf("%d%d%d", &nT, &nA, &nB);
	DFS(0, 1, nT, nA, nB, nMax);
	printf("%d", nMax);
Exit0:

	return 0;
}