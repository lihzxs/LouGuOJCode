/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-28 23:20
//	Comment		:	OJ(P2299)
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
	int			nInputN;
	int			nInputM;
	int**		ppnMat			= NULL;
	unsigned int*		pnDis			= NULL;
	int*		pnFlag			= NULL;
	int			nStart;
	int			nEnd;
	int			nLong;
	int			nMin;
	int			nPoint;
	scanf("%d%d", &nInputN, &nInputM);
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

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d%d", &nStart, &nEnd, &nLong);
		if (ppnMat[nStart][nEnd] != 0)
			ppnMat[nStart][nEnd] = min(ppnMat[nStart][nEnd], nLong);
		else
			ppnMat[nStart][nEnd] = nLong;
		ppnMat[nEnd][nStart] = ppnMat[nStart][nEnd];
	}

	for (int i = 2; i <= nInputN; i++)
		if (ppnMat[1][i] != 0)
			pnDis[i] = ppnMat[1][i];

	pnFlag[1] = true;

	for (int i = 2; i <= nInputN; i++)
	{

		nMin = pnDis[0];
		for (int j = 2; j <= nInputN; j++)
		{
			if (pnDis[j] < nMin && pnFlag[j] == false)
			{
				nMin = pnDis[j];
				nPoint = j;
			}
		}

		pnFlag[nPoint] = true;

		for (int j = 2; j <= nInputN; j++)
		{
			if (ppnMat[nPoint][j] != 0)
			{
				if (pnDis[j] > pnDis[nPoint] + ppnMat[nPoint][j] &&
					pnFlag[j] == false)
					pnDis[j] = pnDis[nPoint] + ppnMat[nPoint][j];
			}
		}
	}


	printf("%d", pnDis[nInputN]);

Exit0:

	return 0;
}