/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-10 01:04
//	Comment		:	OJ(P2090)
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


void DFS(int nLeft, int nRight, int nCount, int& nMin)
{
    
	if (nLeft == 1 && nRight == 1)
	{
		nMin = min(nMin, nCount);
		return;
	}
	if (nLeft == nRight)
		return;
	if (nCount > nMin)
		return;
	if (nLeft > nRight)
		DFS(nLeft - nRight, nRight, nCount + 1, nMin);
	else
		DFS(nLeft, nRight - nLeft, nCount + 1, nMin);
}



int main(int argc, char* argv[])
{
	int				nInputN;
	int				nMin				= 1000000000;
	scanf("%d", &nInputN);
	for (int i = 2; i < nInputN; i++)
		DFS(i, nInputN, 0, nMin);

	printf("%d", nMin);

Exit0:
	return 0;
}