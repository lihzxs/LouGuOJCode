/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-17 00:23
//	Comment		:	OJ(P1504)
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
#include <bitset>

using namespace std;
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		2e31


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int main(int argc, char* argv[])
{
	int					nInputN;
	int					nTemp;
	bitset<10005>		bstA;
	bitset<10005>		bstAns;
	bstAns.set();
	scanf("%d", &nInputN);

	for (int i = 1; i <= nInputN; i++)
	{
		bstA.reset();
		bstA[0] = 1;
		scanf("%d", &nTemp);
		while (nTemp != -1)
		{
			bstA |= bstA << nTemp;
			scanf("%d", &nTemp);
		}
		bstAns &= bstA;
	}


	for (int i = 10000; i >= 0; i--)
	{
		if (bstAns[i])
		{
			printf("%d", i);
			return 0;
		}
	}
	
Exit0:

	return 0;
}