/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-14 22:14
//	Comment		:	OJ(P1718)
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
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

void DFS(map<int, map<int, bool>>& mpLine, int nCount,
	int* pnFlag, int* pnRecord, int nNow, int nN)
{
	pnRecord[nCount] = nNow;
	if (nCount >= nN - 1)
	{
		if (mpLine[nNow][1])
		{
			for (int i = 0; i <= nCount; i++)
				printf("%d ", pnRecord[i]);
			exit(0);
		}
		return;
	}

	for (int j = 1; j <= nN; j++)
	{
		if (mpLine[nNow][j] && !pnFlag[j])
		{
			pnFlag[nNow] = 1;
			DFS(mpLine, nCount + 1,
				pnFlag, pnRecord, j, nN);
			pnFlag[nNow] = 0;
		}
	}

}


int main(int argc, char* argv[])
{
	int								nInputN;
	int*							pnRecord;
	int*							pnFlag;
	map<int, map<int, bool>>		mpLine;
	int								nStart;
	int								nEnd;

	scanf("%d", &nInputN);

	pnRecord = (int*)malloc((nInputN + 1) * sizeof(int));
	pnFlag = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnFlag, 0, (nInputN + 1) * sizeof(int));
	while(scanf("%d%d", &nStart, &nEnd) != EOF)
	{
		mpLine[nStart][nEnd] = true;
		mpLine[nEnd][nStart] = true;
	}

	DFS(mpLine, 0,
		pnFlag, pnRecord, 1, nInputN);

Exit0:

	return 0;
}