
////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-23 20:31
//	Comment		:	OJ(P5146)
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
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;




int main(int argc, char* argv[])
{
	int				nInputN;
	int*			pnSeq			= NULL;
	int*			pnDis			= NULL;
	int				nLeft			= 0;
	int				nRight			= 0;
	int				nFinL;
	int				nFinR;
	int				nFlag;
	long long		nMin			= 100000000000000ll;
	long long		nAnsMax			= -100000000000000ll;
	int				nSum;
	scanf("%d", &nInputN);

	pnSeq = (int*)malloc(nInputN * sizeof(int));
	pnDis = (int*)malloc(nInputN * sizeof(int));
	pnDis[0] = 0;

	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeq + i);

	for (int i = 0; i < nInputN; i++)
	{
		nMin = min(nMin, (long long)pnSeq[i]);
		nAnsMax = max(nAnsMax, pnSeq[i] - nMin);
	}

	printf("%lld", nAnsMax);


	


Exit0:

	return 0;
}