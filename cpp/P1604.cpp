/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-17 15:50
//	Comment		:	OJ(P1604)
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
	int					nTemp;
	int					nPre;
	string				szNumA;
	string				szNumB;
	stack<int>			sA;
	stack<int>			sB;
	stack<int>			sAns;
	map<int, int>		mpDir;
	map<int, int>		mpOut;

	cin >> nInputN;
	cin >> szNumA;
	cin >> szNumB;

	for (int i = '0'; i <= '9'; i++)
	{
		mpDir[i] = i - '0';
		mpOut[i - '0'] = i;
	}
		

	for (int i = 'A'; i <= 'Z'; i++)
	{
		mpDir[i] = i - 'A' + 10;
		mpOut[i - 'A' + 10] = i;
	}
		
	for (int i = 0; i < szNumA.length(); i++)
		sA.push(mpDir[szNumA[i]]);

	for (int i = 0; i < szNumB.length(); i++)
		sB.push(mpDir[szNumB[i]]);
	nPre = 0;
	while (!sA.empty() && !sB.empty())
	{
		nTemp = sA.top() + sB.top() + nPre;
		nPre = nTemp / nInputN;
		sAns.push(nTemp % nInputN);
		sA.pop();
		sB.pop();
	}

	while (!sA.empty())
	{
		nTemp = sA.top() + nPre;
		nPre = nTemp / nInputN;
		sAns.push(nTemp % nInputN);
		sA.pop();
	}

	while (!sB.empty())
	{
		nTemp = sB.top() + nPre;
		nPre = nTemp / nInputN;
		sAns.push(nTemp % nInputN);
		sB.pop();
	}

	while (nPre != 0)
	{
		nTemp = nPre;
		nPre = nTemp / nInputN;
		sAns.push(nTemp % nInputN);
	}


	while (!sAns.empty())
	{
		printf("%c", mpOut[sAns.top()]);
		sAns.pop();
	}
		



Exit0:

	return 0;
}