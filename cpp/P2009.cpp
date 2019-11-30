/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-1 22:13
//	Comment		:	OJ(P2009)
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
	ios::sync_with_stdio(false);
	int			nInputN;
	int			nInputM;
	int			nInputK;
	int**		ppnMat = NULL;
	unsigned int*		pnDis = NULL;
	int*		pnFlag = NULL;
	int			nStart;
	int			nEnd;
	int			nLong;
	int			nMin;
	int			nPoint;
	string		szStart;
	string		szEnd;
	map<char, int>		mpNum;

	//scanf("%d%d", &nInputN, &nInputK);
	cin >> nInputN >> nInputK;
	ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));
	for (int i = 1; i <= nInputN; i++)
	{
		ppnMat[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		memset(ppnMat[i], 0, (nInputN + 1) * sizeof(int));
	}

	pnDis = (unsigned int*)malloc((nInputN + 1) * sizeof(unsigned int));
	memset(pnDis, 127, (nInputN + 1) * sizeof(unsigned int));
	pnFlag = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnFlag, 0, (nInputN + 1) * sizeof(int));


	for (int i = 0; i < nInputN; i++)
		mpNum['A' + i] = i + 1;

	for (int i = 0; i < nInputN; i++)
	{
		nStart = mpNum['A' + i];
		if (i == nInputN - 1)
			nEnd = mpNum['A'];
		else
			nEnd = mpNum['A' + i + 1];
		cin >> nLong;
		ppnMat[nEnd][nStart] = ppnMat[nStart][nEnd] = nLong;
	}



	for (int i = 0; i < nInputK; i++)
	{
		cin >> szStart;
		cin >> szEnd;
		cin >> nLong;
		nStart = mpNum[szStart[0]];
		nEnd = mpNum[szEnd[0]];

		ppnMat[nStart][nEnd] = max(ppnMat[nStart][nEnd], nLong);
		ppnMat[nEnd][nStart] = ppnMat[nStart][nEnd];
	}
	cin >> szStart;
	cin >> szEnd;
	nStart = mpNum[szStart[0]];
	nEnd = mpNum[szEnd[0]];

	if (nStart == nEnd)
	{
		printf("%d", ppnMat[nStart][nEnd]);
		return 0;
	}
		
	pnDis[nStart] = 0;
	for (int i = 1; i <= nInputN; i++)
	{

		nMin = pnDis[0];
		for (int j = 1; j <= nInputN; j++)
		{
			if (pnDis[j] < nMin && pnFlag[j] == false)
			{
				nMin = pnDis[j];
				nPoint = j;
			}
		}

		pnFlag[nPoint] = true;
		if (nPoint == nEnd)
			break;
		for (int j = 1; j <= nInputN; j++)
		{
			if (ppnMat[nPoint][j] != 0)
			{
				if (pnDis[j] > pnDis[nPoint] + ppnMat[nPoint][j] &&
					pnFlag[j] == false)
					pnDis[j] = pnDis[nPoint] + ppnMat[nPoint][j];
			}
		}
	}


	printf("%d", pnDis[nEnd]);

Exit0:

	return 0;
}