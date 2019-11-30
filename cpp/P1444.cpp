/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-15 22:26
//	Comment		:	OJ(P1444)
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

bool Check(int* pnTo, int* pnFlag, int* pnCon, int nX)
{
	while (pnTo[nX])
	{
		if (pnFlag[nX])
			return true;
		pnFlag[nX] = 1;
		nX = pnCon[pnTo[nX]];
	}
	return false;
}


void DFS(int* pnTo, int* pnFlag, int* pnCon, int nStart, int nN, int& nAns)
{
	if (nStart > nN)
	{
		int nAdditem = 0;
		for (int i = 1; i <= nN && nAdditem == 0; i++)
		{
			memset(pnFlag, 0, (nN + 1) * sizeof(int));
			nAdditem = Check(pnTo, pnFlag, pnCon, i);
		}
		nAns += nAdditem;
		return;
	}
	if (pnCon[nStart])
		DFS(pnTo, pnFlag, pnCon, nStart + 1, nN, nAns);
	else
	{
		for (int i = nStart + 1; i <= nN; i++)
		{
			if (!pnCon[i])
			{
				pnCon[i] = nStart;
				pnCon[nStart] = i;
				DFS(pnTo, pnFlag, pnCon, nStart + 1, nN, nAns);
				pnCon[i] = 0;
				pnCon[nStart] = 0;
			}
		}
	}
}

bool Cmp(pair<int, int>& pA, pair<int, int>& pB)
{
	if (pA.second == pB.second)
		return pA.first < pB.first;
	return pA.second < pB.second;
}




int main(int argc, char* argv[])
{
	int				nInputN;
	pair<int, int>*	prTemp			= NULL;
	int*			pnTo			= NULL;
	int*			pnFlag			= NULL;
	int*			pnCon			= NULL;
	int				nAns			= 0;
	scanf("%d", &nInputN);
	prTemp = new pair<int, int>[nInputN + 1];
	pnTo = (int*)malloc((nInputN + 1) * sizeof(int));
	pnFlag = (int*)malloc((nInputN + 1) * sizeof(int));
	pnCon = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnTo, 0, (nInputN + 1) * sizeof(int));
	memset(pnFlag, 0, (nInputN + 1) * sizeof(int));
	memset(pnCon, 0, (nInputN + 1) * sizeof(int));
	for (int i = 1; i <= nInputN; i++)
		scanf("%d%d", &prTemp[i].first, &prTemp[i].second);

	sort(prTemp + 1, prTemp + nInputN + 1, Cmp);

	for (int i = 1; i <= nInputN - 1; i++)
	{
		if (prTemp[i].second == prTemp[i + 1].second)
			pnTo[i] = i + 1;
	}
	DFS(pnTo, pnFlag, pnCon, 1, nInputN, nAns);

	printf("%d", nAns);

Exit0:
	return 0;
}