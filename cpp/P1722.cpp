/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-28 11:37
//	Comment		:	OJ(P1722)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
#include <set>
#include <queue>
#include <list>
#include <map>

using namespace std;
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


bool Cmp(pair <long long, int>& a, pair <long long, int>& b)
{
	if (a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}



int main(int argc, char* argv[])
{
	int						nInputN;
	int*					pnSeq				 = 0;
	int						nRecord;
	
	scanf("%d", &nInputN);


	pnSeq = (int*)malloc((nInputN + 1) * sizeof(int));

	pnSeq[0] = 1;
	pnSeq[1] = 1;
	pnSeq[2] = 2;

	for (int i = 3; i <= nInputN; i++)
	{
		nRecord = 0;
		while (nRecord < i)
		{
			pnSeq[i] += pnSeq[nRecord] * pnSeq[i - 1 - nRecord] % 100;
			pnSeq[i] %= 100;
			nRecord++;
		}
	}

	printf("%d", pnSeq[nInputN]);



Exit0:

	return 0;
}