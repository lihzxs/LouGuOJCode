/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-1 19:31
//	Comment		:	OJ(P1595)
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
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;



int main(int argc, char* argv[])
{
	int				nInputN;
	long long*		pllSeq			 = 0;
	scanf("%d", &nInputN);
	pllSeq = (long long*)malloc((nInputN + 1) * sizeof(long long));
	
	if (nInputN == 1)
		printf("0\n");
	else if (nInputN == 2)
		printf("1\n");
	else
	{
		pllSeq[1] = 0;
		pllSeq[2] = 1;
		for (int i = 3; i <= nInputN; i++)
			pllSeq[i] = (i - 1) * (pllSeq[i - 2] + pllSeq[i - 1]);

		printf("%lld", pllSeq[nInputN]);

	}



Exit0:

	return 0;
}