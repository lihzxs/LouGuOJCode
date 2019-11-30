/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-26 16:37
//	Comment		:	OJ(P4994)
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
	int				nInputM;
	int				nAns = 3;
	int				nPrePre = 1;
	int				nPre	= 1;
	int				nTemp;

	scanf("%d", &nInputM);

	while (true)
	{
		nTemp = (nPre + nPrePre) % nInputM;
		if (nPre == 0 && nTemp == 1)
		{
			printf("%d", nAns - 1);
			break;
		}
		nPrePre = nPre;
		nPre = nTemp;
		nAns++;
	}
	
	



Exit0:

	return 0;
}