/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-24 15:40
//	Comment		:	OJ(P2693)
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
	int				nAns			= 1;
	int				nDis;
	int*			pnSeqFirst		= NULL;
	int*			pnSeqSecond		= NULL;


	pnSeqFirst = (int*)malloc(3 * sizeof(int));
	pnSeqSecond = (int*)malloc(3 * sizeof(int));


	scanf("%d", &nInputN);
	if (nInputN < 5)
	{
		printf("%d", nInputN * nInputN * nInputN);
		return 0;
	}
	for (int i = 0; i < 3; i++)
		scanf("%d", pnSeqFirst + i);

	for (int i = 0; i < 3; i++)
		scanf("%d", pnSeqSecond + i);

	for (int i = 0; i < 3; i++)
	{
		nDis = min(abs(pnSeqFirst[i] - pnSeqSecond[i]),
			nInputN - abs(pnSeqFirst[i] - pnSeqSecond[i]));
		if (nDis < 5)
			nAns *= (5 - nDis);
		else
			nAns = 0;
	}

	printf("%d", 250 - nAns);






			

Exit0:

	return 0;
}