/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-25 23:50
//	Comment		:	OJ(P1017)
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

void Ans(int nN, int nK)
{
	if (nN == 0)
		return;
	int nTemp = nN % nK;

	if (nTemp < 0)
	{
		nTemp -= nK;
		nN += nK;
	}

	if (nTemp < 10)
		nTemp += '0';
	else
		nTemp = 'A' + nTemp - 10;
	Ans(nN / nK, nK);

	printf("%c", nTemp);
}

int main(int argc, char* argv[])
{
	int			nInputN;
	int			nInputK;

	cin >> nInputN >> nInputK;

	cout << nInputN << "=";
	Ans(nInputN, nInputK);
	cout << "(base" << nInputK << ")";

Exit0:

	return 0;
}