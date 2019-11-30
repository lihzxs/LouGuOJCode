/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-26 23:13
//	Comment		:	OJ(P2681)
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

	int					nInputN;
	int					nInputM;
	map<int, int>		mapCount;
	int*				pnSeq			= NULL;
	int					nInputFlag;
	int					nInputX;
	int					nInputY;
	int					nMax			= 0;
	int					nAns			= 0;

	scanf("%d%d", &nInputN, &nInputM);

	pnSeq = (int*)malloc((nInputN + 1) * sizeof(int));

	for (int i = 1; i < nInputN + 1; i++)
		scanf("%d", pnSeq + i);

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d%d", &nInputFlag, &nInputX, &nInputY);
		if (nInputFlag)
			pnSeq[nInputX] = nInputY;
		else
		{
			mapCount.clear();
			nMax = 0;
			for (int j = nInputY; j >= nInputX; j--)
			{
				mapCount[pnSeq[j]]++;
				if (mapCount[pnSeq[j]] > nMax)
				{
					nMax = mapCount[pnSeq[j]];
					nAns = pnSeq[j];
				}
				else if (mapCount[pnSeq[j]] == nMax)
					nAns = min(nAns, pnSeq[j]);
			}
			printf("%d\n", nAns);
		}
	}





Exit0:

	return 0;
}