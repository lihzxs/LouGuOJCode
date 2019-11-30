/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-25 23:26
//	Comment		:	OJ(P1608)
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
#define	MAXNUM		1000000000
#define	EPS         0.0001
#define MODNUM		2e31


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;




void SPFA(int nStart, int nEnd, int nN, int* pnCount, int* pnDis,
	int** ppnMat)
{
	queue<int>	qSPFA;
	int			nTemp;
	int*		pnFlag;


	pnFlag = (int*)malloc((nN + 1) * sizeof(int));

	for (int i = 0; i <= nN; i++)
		pnDis[i] = MAXNUM;
	memset(pnFlag, 0, (nN + 1) * sizeof(int));
	memset(pnCount, 0, (nN + 1) * sizeof(int));

	pnCount[nStart] = 1;
	pnDis[nStart] = 0;
	qSPFA.push(nStart);
	pnFlag[nStart] = 1;

	while (!qSPFA.empty())
	{
		nTemp = qSPFA.front();
		qSPFA.pop();
		pnFlag[nTemp] = 0;
		if (nTemp == nEnd)
			continue;
		for (int i = 1; i <= nN; i++)
		{
			if (pnDis[nTemp] + ppnMat[nTemp][i] == pnDis[i])
			{
				pnCount[i] += pnCount[nTemp];
			}

			if (pnDis[nTemp] + ppnMat[nTemp][i] < pnDis[i])
			{
				pnDis[i] = pnDis[nTemp] + ppnMat[nTemp][i];
				pnCount[i] = pnCount[nTemp];
			}
			if (!pnFlag[i] && pnCount[i])
			{
				qSPFA.push(i);
				pnFlag[i] = 1;
			}
		}
		pnCount[nTemp] = 0;
	}

}


int main(int argc, char* argv[])
{
	int					nN;
	int					nM;
	int					nK;
	int					nStart;
	int					nEnd;
	int					nLong;
	int					nTemp;
	long long			llAns = 0;
	int					nNum;
	int*				pnCount;
	int*				pnDis;
	int**				ppnMat;

	scanf("%d%d", &nN, &nM);

	ppnMat = (int**)malloc((nN + 1) * sizeof(int*));
	for (int i = 1; i <= nN; i++)
	{
		ppnMat[i] = (int*)malloc((nN + 1) * sizeof(int));
		for (int j = 1; j <= nN; j++)
			ppnMat[i][j] = MAXNUM;
	}

	pnCount = (int*)malloc((nN + 1) * sizeof(int));
	pnDis = (int*)malloc((nN + 1) * sizeof(int));




	for (int i = 0; i < nM; i++)
	{
		scanf("%d%d%d", &nStart, &nEnd, &nLong);
		ppnMat[nStart][nEnd] = min(ppnMat[nStart][nEnd], nLong);
	}

	SPFA(1, nN, nN, pnCount, pnDis, ppnMat);



	if (pnDis[nN] == MAXNUM)
		printf("No answer");
	else
		printf("%d %d", pnDis[nN], pnCount[nN]);



Exit0:

	return 0;
}