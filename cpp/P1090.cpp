/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-18 20:44
//	Comment		:	OJ(P1090)
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
	int												nInputN;
	int												nSum			= 0;
	int												nTemp;
	priority_queue<int, vector<int>, greater<int> >	qNum;


	scanf("%d", &nInputN);
	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", &nTemp);
		qNum.push(nTemp);
	}

	while (qNum.size() > 1)
	{
		nTemp = qNum.top();
		qNum.pop();
		nTemp += qNum.top();
		qNum.pop();
		nSum += nTemp;
		qNum.push(nTemp);
	}

	printf("%d", nSum);






Exit0:

	return 0;
}