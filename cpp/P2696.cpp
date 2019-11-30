/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-15 17:59
//	Comment		:	OJ(P2696)
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
#include <list>
#include <queue>
#include <map>

using namespace std;
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		2e31


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int Cal(int nN, int nK)
{
	int nT = 0;
	for (int i = 2; i <= nN; i++)
		nT = (nT + nK) % i;
	return nT + 1;
}


int main(int argc, char* argv[])
{
	int					nInputN;
	int					nTemp;
	int					nAns			= 0;
	scanf("%d", &nInputN);

	while (true)
	{
		nTemp = Cal(nInputN, 2);
		if (nTemp == nInputN)
		{
			nAns += nTemp * 2;
			break;
		}
		nAns += (nInputN - nTemp);
		nInputN -= (nInputN - nTemp);
	}

	printf("%d", nAns);


Exit0:

	return 0;
}