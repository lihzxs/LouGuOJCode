/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-3 11:28
//	Comment		:	OJ(P2837)
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
	int					nInputN;
	int*				pnSeq				= NULL;
	int*				pnOne				= NULL;
	int*				pnTwo				= NULL;
	int					nCount				= 0;
	int					nAns				= 0;

	scanf("%d", &nInputN);
	pnSeq = (int*)malloc((nInputN + 1) * sizeof(int));
	pnOne = (int*)malloc((nInputN + 1) * sizeof(int));
	pnTwo = (int*)malloc((nInputN + 1)* sizeof(int));

	nAns = nInputN;
	pnTwo[0] = 0;
	pnOne[0] = 0;
	for (int i = 1; i <= nInputN; i++)
	{
		scanf("%d", pnSeq + i);
		if (pnSeq[i] == 1)
		{
			pnOne[i] = pnOne[i - 1] + 1;
			pnTwo[i] = pnTwo[i - 1];
		}
		else
		{
			pnOne[i] = pnOne[i - 1];
			pnTwo[i] = pnTwo[i - 1] + 1;
		}
	}
	for (int i = 0; i <= nInputN; i++)
		nAns = min(nAns, pnTwo[i] + pnOne[nInputN] - pnOne[i]);


	printf("%d", nAns);

Exit0:
	return 0;
}