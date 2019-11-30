/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-19 23:04
//	Comment		:	OJ(P2080)
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

void DFS(pair<int, int>* pprDate, int nN, int nPre,
	int* pnFlag, int nSumF, int nSumS, int nV, int& nMin)
{
	
	if (nSumF + nSumS >= nV)
		nMin = min(nMin, abs(nSumF - nSumS));

	if (nMin == 0)
		return;

	for (int i = nPre + 1; i < nN; i++)
	{
		if (!pnFlag[i])
		{
			pnFlag[i] = 1;
			DFS(pprDate, nN, i,
				pnFlag, nSumF + pprDate[i].first, 
				nSumS + pprDate[i].second, nV, nMin);
			pnFlag[i] = 0;
		}
	}

}




int main(int argc, char* argv[])
{
	int					nInputV;
	int					nInputN;
	int					nTemp				= 0;
	int*				pnFlag				= NULL;	
	int					nMin				= 1000000;
	pair<int, int>*		pprDate;
	scanf("%d%d", &nInputN, &nInputV);

	pprDate = new pair<int, int>[nInputN];
	pnFlag = (int*)malloc(nInputN * sizeof(int));
	memset(pnFlag, 0, nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", &nTemp);
		pprDate[i].first = nTemp;
		scanf("%d", &nTemp);
		pprDate[i].second = nTemp;
	}


	DFS(pprDate, nInputN, -1,
		pnFlag, 0, 0, nInputV, nMin);

	if (nMin == 1000000)
		printf("-1");
	else
		printf("%d", nMin);

Exit0:
	return 0;
}