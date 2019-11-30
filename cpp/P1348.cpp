/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-19 15:41
//	Comment		:	OJ(P1348)
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
	int				nInputA;
	int				nInputB;
	int				nAns				= 0;
	scanf("%d%d", &nInputA, &nInputB);

	for (int i = nInputA; i <= nInputB; i++)
		if (i % 2 || !(i % 4))
			nAns++;

	printf("%d", nAns);


Exit0:

	return 0;
}