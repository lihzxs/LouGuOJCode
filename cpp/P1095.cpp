/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-5 15:48
//	Comment		:	OJ(P1095)
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


int main(int argc, char* argv[])
{
	int				nInputM;
	int				nInputS;
	int				nInputT;
	int				nM;
	int				nSRun;
	int				nSFla;
	int				nT;
	int				nTime;
	int				nDis;

	scanf("%d%d%d", &nInputM, &nInputS, &nInputT);
	nSFla = 0;
	nSRun = 0;

	for (int i = 1; i <= nInputT; i++)
	{
		nSRun += 17;
		if (nInputM >= 10)
		{
			nSFla += 60;
			nInputM -= 10;
		}
		else
			nInputM += 4;
		if (nSFla > nSRun)
			nSRun = nSFla;
		if (nSRun > nInputS)
		{
			printf("Yes\n");
			printf("%d", i);
			return 0;
		}
	}

	printf("No\n");
	printf("%d", nSRun);


Exit0:
	return 0;
}