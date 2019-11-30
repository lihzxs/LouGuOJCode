/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-11 21:23
//	Comment		:	OJ(P1334)
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

using namespace std;
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		2000001


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int						nInputN;
	priority_queue<int, vector<int>, greater<int> >		qLenght;
	int						nSum			= 0;
	int						nTemp;
	long long					nAns			= 0;
	scanf("%d", &nInputN);

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", &nTemp);
		qLenght.push(nTemp);
	}

	for (int i = 0; i < nInputN - 1; i++)
	{
		nTemp = qLenght.top();
		qLenght.pop();
		nTemp += qLenght.top();
		qLenght.pop();
		nAns += nTemp;
		qLenght.push(nTemp);
	}

	printf("%lld", nAns);














Exit0:

	return 0;
}