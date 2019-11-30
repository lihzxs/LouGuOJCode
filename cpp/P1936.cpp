/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-7 16:14
//	Comment		:	OJ(P1936)
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
#define	MAXNUM		150
#define	EPS         0.0001
#define MODNUM		1000000007ll


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;



int main(int argc, char* argv[])
{
	int					nInputN;
	int		 			nTemp;
	int					nN;
	int					nM;
	scanf("%d", &nInputN);

	nN = 1;
	nM = 2;
	while (nN + nM <= nInputN)
	{
		nTemp = nN + nM;
		nN = nM;
		nM = nTemp;
	}

	printf("m=%d\nn=%d\n", nN, nM);
Exit0:

	return 0;
}