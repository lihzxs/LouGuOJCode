/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-24 16:52
//	Comment		:	OJ(P5461)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <list>
#include <string>
#include <string.h>
#include <set>
#include <queue>
#include <map>

using namespace std;
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		1000000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int main(int argc, char* argv[])
{
	int				nInputN;
	int				nLenght;
	
	scanf("%d", &nInputN);
	nLenght = pow(2, nInputN);

	for (int i = 1; i <= nLenght; i++)
	{
		for (int j = 1; j <= nLenght; j++)
		{
			printf("%d ", (i - 1 | j - 1) != (nLenght - 1) ? 0 : 1);
		}
		printf("\n");
	}
		

Exit0:

	return 0;
}