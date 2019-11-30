/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-25 22:40
//	Comment		:	OJ(P5551)
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


inline int read() {//快读
	int X = 0; bool d = 0; char ch = 0;
	while (!isdigit(ch)) d |= ch == '-', ch = getchar();
	while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
	return d ? -X : X;
}

int				nInputN;
long long ScanfTree(int nDeep)
{
	long long llTemp;
	llTemp = read();
	if (nDeep == nInputN)
		return llTemp;
	else
		return llTemp +
		max(ScanfTree(nDeep + 1), ScanfTree(nDeep + 1));
}



int main(int argc, char* argv[])
{

	int				nPow = 1;
	long long**		ppllSeq;
	long long		llTemp;

	scanf("%d", &nInputN);
	printf("%lld", ScanfTree(1));
	

Exit0:

	return 0;
}