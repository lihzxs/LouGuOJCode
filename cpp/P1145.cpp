/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-11 14:26
//	Comment		:	OJ(P1145)
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

using namespace std;
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		2000001


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;



int main(int argc, char* argv[])
{
	int				nInputK;
	int				nInputM;
	int				nTemp;
	int				nBegin			= 0;
	scanf("%d", &nInputK);

	nInputM = nInputK;

	while (true)
	{
		nInputM++;
		nBegin = 0;
		for (int i = 0; i < nInputK; i++)
		{
			nBegin = (nBegin + nInputM - 1) % (2 * nInputK - i);
			if (nBegin < nInputK)
				break;
		}
		if (nBegin >= nInputK)
			break;
	}

	printf("%d", nInputM);


Exit0:

	return 0;
}