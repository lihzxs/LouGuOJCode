/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-16 23:38
//	Comment		:	OJ(P1154)
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
	int				nInputN;
	bool*			pnFlag			= NULL;
	int*			pnSeq			= NULL;
	scanf("%d", &nInputN);

	pnSeq = (int*)malloc(nInputN * sizeof(int));
	pnFlag = (bool*)malloc((1000000 + 1) * sizeof(bool));
	memset(pnFlag, 0, (1000000 + 1) * sizeof(bool));
	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeq + i);

	for (int i = 0; i < nInputN; i++)
		for (int j = i + 1; j < nInputN; j++)
			pnFlag[abs(pnSeq[i] - pnSeq[j])] = 1;

	while (pnFlag[nInputN])
		nInputN++;

	printf("%d", nInputN);

Exit0:

	return 0;
}