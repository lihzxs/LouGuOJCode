/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-18 19:46
//	Comment		:	OJ(P4431)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <stack>
#include <string>
#include <string.h>
#include <set>
using namespace std;
#define	MAXNUM		3
#define	EPS         0.0001

typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{

	int					nAns				= 0;
	int					nInputN;
	int					nInputX;
	int					nInputY;
	int					nInputMin;
	int					nInputMax;


	scanf("%d", &nInputN);

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d", &nInputX, &nInputY);
		printf("%d\n", 2 * min(nInputX, nInputY) - 2);
	}



Exit0:

	return 0;
}