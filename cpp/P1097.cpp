/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-25 21:45
//	Comment		:	OJ(P1097)
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
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;




int main(int argc, char* argv[])
{
	int					nInputN;
	int*				pnSeq				= NULL;
	int					nPreIndex			= 0;
	int					nPreNum				= 0;


	scanf("%d", &nInputN);

	pnSeq = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeq + i);

	sort(pnSeq, pnSeq + nInputN);
	nPreNum = pnSeq[0];
	for (int i = 0; i < nInputN; i++)
	{
		if (pnSeq[i] != nPreNum)
		{
			printf("%d %d\n", nPreNum,i - nPreIndex);
			nPreNum = pnSeq[i];
			nPreIndex = i;
		}
	}
	printf("%d %d\n", pnSeq[nInputN - 1], nInputN - nPreIndex);



		


Exit0:

	return 0;
}