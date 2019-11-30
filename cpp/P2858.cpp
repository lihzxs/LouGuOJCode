/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-6 16:29
//	Comment		:	OJ(P2858)
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
	deque<int>		dqFood;
	int				nCount				= 0;
	int				nTemp;
	int				nRight;
	int*			pnSeq				= NULL;
	int**			ppnDp				= NULL;
	long long				nAns				= 0;
	scanf("%d", &nInputN);

	pnSeq = (int*)malloc((nInputN + 1) * sizeof(int));
	
	ppnDp = (int**)malloc((nInputN + 1) * sizeof(int*));


	for (int i = 1; i <= nInputN; i++)
	{
		scanf("%d", pnSeq + i);
		ppnDp[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		memset(ppnDp[i], 0, (nInputN + 1) * sizeof(int));
	}

	for (int i = 1; i <= nInputN; i++)
		ppnDp[i][i] = pnSeq[i] * nInputN;

	for (int i = 2; i <= nInputN; i++)
	{
		for (int nLeft = 1; nLeft <= nInputN; nLeft++)
		{
			nRight = nLeft + i - 1;
			if (nRight > nInputN)
				break;
			ppnDp[nLeft][nRight] = max(ppnDp[nLeft][nRight - 1] + pnSeq[nRight] * (nInputN - i + 1),
				ppnDp[nLeft + 1][nRight] + pnSeq[nLeft] * (nInputN - i + 1));
		}
	}

	printf("%d", ppnDp[1][nInputN]);
Exit0:

	return 0;
}