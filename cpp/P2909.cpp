/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-29 22:41
//	Comment		:	OJ(P2909)
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



int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int				nInputD;
	int				nInputL;
	int*			pnSeq				= NULL;
	int				nCount				= 0;
	int				nRecord				= 0;
	int*			pnCount				= NULL;
	int				nSum				= 0;

	scanf("%d%d%d%d", &nInputN, &nInputM, &nInputD, &nInputL);

	pnSeq = (int*)malloc(nInputN * sizeof(int));
	pnCount = (int*)malloc(nInputM * sizeof(int));
	memset(pnCount, 0, nInputM * sizeof(int));

	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeq + i);

	sort(pnSeq, pnSeq + nInputN);

	for (int nRecord = nInputN - 1; nRecord >= 0 && pnSeq[nRecord] >= nInputL; nRecord--);
	
	for (int i = nRecord + 1; i < nInputN; i++)
	{
		if (pnSeq[i] - pnCount[nCount % nInputM] * nInputD >= nInputL)
		{
			
			pnCount[nCount % nInputM]++;
			nCount++;
		}
	}

	for (int i = 0; i < nInputM; i++)
		nSum += pnCount[i];


	printf("%d", nSum);






Exit0:

	return 0;
}