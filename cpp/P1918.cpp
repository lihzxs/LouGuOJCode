/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-7 15:14
//	Comment		:	OJ(P1918)
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
	map<int, int>		mapFlag;
	int					nInputQ;
	int					nInputTemp;

	scanf("%d", &nInputN);

	for (int i = 1; i <= nInputN; i++)
	{
		scanf("%d", &nInputTemp);
		mapFlag[nInputTemp] = i;
	}
	scanf("%d", &nInputQ);

	for (int i = 0; i < nInputQ; i++)
	{
		scanf("%d", &nInputTemp);
		if (!mapFlag.count(nInputTemp))
			printf("0\n");
		else
			printf("%d\n", mapFlag[nInputTemp]);
	}







Exit0:

	return 0;
}