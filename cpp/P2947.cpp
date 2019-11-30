/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-11 00:38
//	Comment		:	OJ(P2947)
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



int main(int argc, char* argv[])
{
	int				nInputN;
	int				nPre;
	int				nPIndex;
	int				nP;
	int*			pnSeq				= NULL;
	int*			pnAns				= NULL;
	scanf("%d", &nInputN);

	pnSeq = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnSeq, 0, (nInputN + 1) * sizeof(int));
	pnAns = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnAns, 0, (nInputN + 1) * sizeof(int));

	for (int i = 1; i <= nInputN; i++)
		scanf("%d", pnSeq + i);


	for (int i = nInputN - 1; i >= 1; i--)
	{
		nP = i + 1;
		while (pnSeq[i] >= pnSeq[nP] && pnSeq[nP] > 0)
			nP = pnAns[nP];
		pnAns[i] = nP;
	}

	for (int i = 1; i <= nInputN; i++)
		printf("%d\n", pnAns[i]);


Exit0:

	return 0;
}