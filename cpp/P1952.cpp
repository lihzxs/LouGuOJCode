/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-26 14:27
//	Comment		:	OJ(P1952)
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

int main(int argc, char* argv[])
{
	int			nInputN;
	int			nTemp;
	int			nPre;
	string		szNumA;
	string		szNumB;
	stack<int>	sA;
	stack<int>	sB;
	stack<int>	sAns;
	cin >> nInputN >> szNumA >> szNumB;


	for (int i = 0; i < szNumA.length(); i++)
	{
		if (szNumA[i] > '9')
			sA.push(szNumA[i] - 'a' + 10);
		else
			sA.push(szNumA[i] - '0');
	}

	for (int i = 0; i < szNumB.length(); i++)
	{
		if (szNumB[i] > '9')
			sB.push(szNumB[i] - 'a' + 10);
		else
			sB.push(szNumB[i] - '0');
	}
	nPre = 0;
	while (!sA.empty() && !sB.empty())
	{
		nTemp = sA.top() + sB.top() + nPre;
		sA.pop();
		sB.pop();
		sAns.push(nTemp % nInputN);
		nPre = nTemp / nInputN;
	}

	while (!sA.empty())
	{
		nTemp = sA.top() + nPre;
		sA.pop();
		sAns.push(nTemp % nInputN);
		nPre = nTemp / nInputN;
	}
	while (!sB.empty())
	{
		nTemp = sB.top() + nPre;
		sB.pop();
		sAns.push(nTemp % nInputN);
		nPre = nTemp / nInputN;
	}

	if (nPre)
		sAns.push(nPre);

	while (!sAns.empty())
	{
		nTemp = sAns.top();
		sAns.pop();
		if (nTemp >= 10)
			nTemp = nTemp - 10 + 'a';
		else
			nTemp = nTemp + '0';

		printf("%c", nTemp);
	}


Exit0:

	return 0;
}