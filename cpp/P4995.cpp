/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-22 10:18
//	Comment		:	OJ(P4995)
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
#define MODNUM		2e64


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int			nInputN;
	long long	llAns			= 0;
	long long*	pllSeq			= NULL;

	scanf("%d", &nInputN);
	pllSeq = (long long*)malloc((nInputN + 1) * sizeof(long long));
	pllSeq[0] = 0;
	for (int i = 1; i <= nInputN; i++)
		scanf("%lld", pllSeq + i);

	sort(pllSeq + 1, pllSeq + 1 + nInputN);

	int i = 0;
	int j = nInputN;

	while (i < j)
	{
		llAns += pow((pllSeq[j] - pllSeq[i]), 2);
		i++;
		llAns += pow((pllSeq[i] - pllSeq[j]), 2);
		j--;
	}

	printf("%lld", llAns);

Exit0:

	return 0;
}