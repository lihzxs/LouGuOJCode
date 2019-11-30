/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-2 14:17
//	Comment		:	OJ(P3184)
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





int main(int argc, char* argv[])
{
	int			nInputN;
	int			nInputQ;
	int			nStart;
	int			nEnd;
	int*		pnSeq			= NULL;
	int*		pnStart			= NULL;
	int*		pnEnd			= NULL;

	scanf("%d%d", &nInputN, &nInputQ);

	pnSeq = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeq + i);

	sort(pnSeq, pnSeq + nInputN);

	while (nInputQ--)
	{
		scanf("%d%d", &nStart, &nEnd);
		pnStart = lower_bound(pnSeq, pnSeq + nInputN, nStart);
		pnEnd = upper_bound(pnSeq, pnSeq + nInputN, nEnd);
		printf("%d\n", pnEnd - pnStart);
	}





Exit0:

	return 0;
}