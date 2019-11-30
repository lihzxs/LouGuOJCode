/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-19 14:19

//	Comment		:	OJ(P3926)
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
#define	MAXNUM		100
#define	EPS         0.0001



typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;




int main(int argc, char* argv[])
{
	int			nInputA;
	int			nInputC;
	int			nInputP;
	int			nInputQ;
	int			nInputR;
	int			nInputX;
	int			nAns			= 0;

	scanf("%d%d%d%d%d%d", &nInputA, &nInputC, &nInputP,
		&nInputQ, &nInputR, &nInputX);

	while (nInputA < nInputC)
	{
		nInputX -= nInputP;
		if (nInputX < 0)
		{
			printf("%d", nInputA);
			return 0;
		}
		nInputA++;
	}
	if (nInputA == nInputC)
	{
		nInputX -= nInputQ;
		if (nInputX < 0)
		{
			printf("%d", nInputA);
			return 0;
		}
	}
	while (true)
	{
		nInputX -= nInputR;
		if (nInputX < 0)
			break;
		nInputA++;
	}
	printf("%d", nInputA);



Exit0:

	return 0;
}