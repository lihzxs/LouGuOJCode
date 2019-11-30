/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-5 23:43
//	Comment		:	OJ(P1658)
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
#define	MAXNUM		100000000
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int				nInputX;
	int				nInputN;
	int				nCount				= -1;
	int*			pnSeq				= NULL;
	int*			pnFlag				= NULL;
	//int*			pnCount				= NULL;
	int				nAns				= 0;
	int				nSum				= 0;
	
	scanf("%d%d", &nInputX, &nInputN);

	pnSeq = (int*)malloc(nInputN * sizeof(int));


	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeq + i);

	sort(pnSeq, pnSeq + nInputN);

	if (pnSeq[0] != 1)
		printf("-1");
	else
	{
		nSum = 0;
		while (nSum < nInputX)
		{
			int i;
			for (i = nInputN - 1; i >= 0; i--)
				if (pnSeq[i] <= nSum + 1)
					break;
			nAns++;
			nSum += pnSeq[i];
		}
		printf("%d", nAns);
	}



Exit0:
	return 0;
}