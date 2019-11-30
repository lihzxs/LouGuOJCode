
////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-22 18:41
//	Comment		:	OJ(P2902)
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

	int					nInputN;
	int					nInputC;
	int					nTemp;
	int*				pnSeq				= NULL;
	int					nMax;
	int					nCount				= 0;
	scanf("%d%d", &nInputN, &nInputC);

	pnSeq = (int*)malloc(nInputN * sizeof(int));

	for (int i = 1; i <= nInputC; i++)
	{
		scanf("%d", &nTemp);
		while (nTemp--)
			pnSeq[nCount++] = i;
	}

	sort(pnSeq, pnSeq + nInputN);


	for (int i = 0; i < nInputN / 2; i++)
		printf("%d %d\n", pnSeq[i], pnSeq[i + nInputN / 2]);






Exit0:

	return 0;
}