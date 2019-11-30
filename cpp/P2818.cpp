/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-18 20:56
//	Comment		:	OJ(P2818)
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
#include <float.h>

using namespace std;
#define	MAXNUM		1000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;



int main(int argc, char* argv[])
{
	int					nInputN;
	string				szInput;
	int					nAns				= 0;
	cin >> nInputN;
	cin >> szInput;

	for (int i = 0; i < szInput.length() - 1; i++)
		nAns = (nAns * 10 + szInput[i] - '0') % nInputN;

	nAns = (nAns * 10 + szInput[szInput.length() - 1] - '0') % nInputN;

		if (nAns == 0)
		printf("%d", nInputN);
	else
		printf("%d", nAns);

Exit0:

	return 0;
}