/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-2 15:47
//	Comment		:	OJ(P1803)
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

typedef struct STime
{
	int			nStart;
	int			nEnd;
}STime;

bool Cmp(const STime& sFirst, const STime& sSecond)
{
	if (sFirst.nEnd == sSecond.nEnd)
		return sFirst.nStart < sSecond.nStart;
	return sFirst.nEnd < sSecond.nEnd;
}


void DFS(STime* psTime, BOOL* pbFlag, int nNum,
	int nPreEnd, int nPreCount,int& nCount)
{
	if (nPreCount > nCount)
		nCount = nPreCount;
	for (int i = 0; i < nNum; i++)
	{
		if (!pbFlag[i] && nPreEnd <= psTime[i].nStart)
		{
			pbFlag[i] = 1;
			DFS(psTime, pbFlag, nNum, psTime[i].nEnd, nPreCount + 1, nCount);
			pbFlag[i] = 0;
		}
	}
}




int main(int argc, char* argv[])
{
	int				nInputN;
	STime*			psTime;
	int				nCount				= 0;
	int				nPreEnd;
	BOOL*			pbFlag				= NULL;

	scanf("%d", &nInputN);
	psTime = (STime*)malloc(nInputN * sizeof(STime));
	pbFlag = (BOOL*)malloc(nInputN * sizeof(BOOL));
	memset(pbFlag, 0, nInputN * sizeof(BOOL));
	for (int i = 0; i < nInputN; i++)
		scanf("%d%d", &psTime[i].nStart, &psTime[i].nEnd);

	sort(psTime, psTime + nInputN, Cmp);
	nPreEnd = psTime[0].nEnd;
	for (int i = 1; i < nInputN; i++)
	{
		if (psTime[i].nStart >= nPreEnd)
		{
			nPreEnd = psTime[i].nEnd;
			nCount++;
		}
	}
	printf("%d\n", nCount + 1);


Exit0:

	return 0;
}