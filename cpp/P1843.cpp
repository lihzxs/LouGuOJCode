/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-29 23:37
//	Comment		:	OJ(P1843)
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
	int						nInputN;
	int						nInputA;
	int						nInputB;
	int						nTemp;
	int						nT;
	priority_queue<int>		qNum;

	scanf("%d%d%d", &nInputN, &nInputA, &nInputB);

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", &nTemp);
		qNum.push(nTemp);
	}
	nT = 0;

	while (qNum.top() - nT * nInputA > 0)
	{
		nT++;
		nTemp = qNum.top();
		qNum.pop();
		qNum.push(nTemp - nInputB);
	}
	printf("%d", nT);

		




Exit0:

	return 0;
}