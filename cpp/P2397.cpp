/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-16 15:58
//	Comment		:	OJ(P2397)
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


int main(int argc, char* argv[])
{
	int				nInputN;
	int				nStore = 0;
	int				nCount = 0;
	int				nTemp;
	scanf("%d", &nInputN);

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", &nTemp);
		if (nStore == nTemp)
			nCount++;
		if (nCount == 0)
		{
			nStore = nTemp;
			nCount++;
		}
		if (nStore != nTemp)
			nCount--;
	}
	printf("%d", nStore);

Exit0:

	return 0;
}