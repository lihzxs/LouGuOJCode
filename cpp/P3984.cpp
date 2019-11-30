/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-18 20:01
//	Comment		:	OJ(P3984)
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
	int					nInputT;
	int					nPreInput;
	int					nInputTemp;

	scanf("%d%d", &nInputN, &nInputT);
	scanf("%d", &nPreInput);
	for (int i = 1; i < nInputN; i++)
	{
		scanf("%d", &nInputTemp);

		if (nInputTemp > nPreInput + nInputT - 1)
			nAns += nInputT;
		else
			nAns += nInputTemp - nPreInput;


		nPreInput = nInputTemp;
	}
	nAns += nInputT;

	printf("%d", nAns);



Exit0:

	return 0;
}