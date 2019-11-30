/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-20 16:06
//	Comment		:	OJ(P1724)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <stack>
#include <set>
#include <list>
#include <string>
#include <string.h>
using namespace std;
#define	MAXNUM		20000
#define	EPS         0.0001
#define DIRNUM		4
#define ERROR_ID    0

typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;





int main(int argc, char* argv[])
{
	int							nInputN;
	int							nInputM;
	int							nAnsX			= 0;
	int							nAnsY			= 0;
	int							nIndex			= 0;
	string						szInput;

	cin >> szInput;
	scanf("%d", &nInputN);

	for (int i = 0; i < szInput.length(); i++)
	{
		if (szInput[i] == 'E')
			nAnsX++;
		if (szInput[i] == 'S')
			nAnsY--;
		if (szInput[i] == 'W')
			nAnsX--;
		if (szInput[i] == 'N')
			nAnsY++;
	}

	nAnsX *= nInputN / szInput.length();
	nAnsY *= nInputN / szInput.length();
	nInputN = nInputN % szInput.length();

	while (nInputN)
	{
		if (szInput[nIndex] == 'E')
			nAnsX++;
		if (szInput[nIndex] == 'S')
			nAnsY--;
		if (szInput[nIndex] == 'W')
			nAnsX--;
		if (szInput[nIndex] == 'N')
			nAnsY++;
		nIndex++;
		nInputN--;

	}

	printf("%d %d", nAnsX, nAnsY);


	

Exit0:

	return 0;
}

