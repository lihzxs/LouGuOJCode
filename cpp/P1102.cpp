/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-13 17:16
//	Comment		:	OJ(P1102)
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
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int				nInputN;
	long			nInputC;
	map<long, long>	mpNumCount;
	long*			plSeq					= NULL;
	long			lPre;
	long				nAns					= 0;
	scanf("%d%ld", &nInputN, &nInputC);

	plSeq = (long*)malloc(nInputN * sizeof(long));


	for (int i = 0; i < nInputN; i++)
		scanf("%ld", plSeq + i);

	for (int i = 0; i < nInputN; i++)
	{
		mpNumCount[plSeq[i]]++;
		plSeq[i] -= nInputC;
	}
	for (int i = 0; i < nInputN; i++)
		nAns += mpNumCount[plSeq[i]];

	printf("%ld", nAns);
Exit0:

	return 0;
}