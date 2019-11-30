
////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-22 21:08
//	Comment		:	OJ(P5098)
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

int main(int argc, char* argv[])
{
	int					nInputN;
	int					nMax				= 0;
	int					nX;
	int					nY;
	int					nMaxXAddY			= 0;
	int					nMinXAddY			= 10000000;
	int					nMaxXReDY			= 0;
	int					nMinXReDY			= 10000000;


	scanf("%d", &nInputN);

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d", &nX, &nY);
		nMaxXAddY = max(nMaxXAddY, nX + nY);
		nMinXAddY = min(nMinXAddY, nX + nY);
		nMaxXReDY = max(nMaxXReDY, nX - nY);
		nMinXReDY = min(nMinXReDY, nX - nY);
	}


	printf("%d", max(nMaxXAddY - nMinXAddY, nMaxXReDY - nMinXReDY));


Exit0:

	return 0;
}