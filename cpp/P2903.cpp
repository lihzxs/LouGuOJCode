/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-17 20:39
//	Comment		:	OJ(P1903)
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
	int					nInputN;
	int					nEX;
	int					nEY;
	int					nStart;
	int					nEnd;
	int					nTemp;
	double				fTemp;
	double				fSum			= 0;
	int*				pnX				= NULL;
	int*				pnY				= NULL;
	int*				pnR				= NULL;
	int*				pnFlag			= NULL;
	int*				pnIndex			= NULL;
	double*				pfS				= NULL;
	queue<int>			qBFS;

	scanf("%d%d%d", &nInputN, &nEX, &nEY);

	pnX = (int*)malloc(nInputN * sizeof(int));
	pnY = (int*)malloc(nInputN * sizeof(int));
	pnR = (int*)malloc(nInputN * sizeof(int));
	pnFlag = (int*)malloc(nInputN * sizeof(int));
	pnIndex = (int*)malloc(nInputN * sizeof(int));
	memset(pnIndex, 0, nInputN * sizeof(int));
	pfS = (double*)malloc(nInputN * sizeof(double));
	memset(pnFlag, 0, nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d%d", pnX + i, pnY + i, pnR + i);
		if (pnX[i] == 0 && pnY[i] == 0)
			nStart = i;
		else if (pnX[i] == nEX && pnY[i] == nEY)
			nEnd = i;
	}

	pnFlag[nStart] = 1;
	qBFS.push(nStart);
	pfS[nStart] = 10000;
	pnIndex[nStart] = -1;
	while (!qBFS.empty())
	{
		nTemp = qBFS.front();
		qBFS.pop();

		for (int i = 0; i < nInputN; i++)
		{
			if (pnFlag[i])
				continue;
			if ((pnX[nTemp] - pnX[i]) * (pnX[nTemp] - pnX[i]) +
				(pnY[nTemp] - pnY[i]) * (pnY[nTemp] - pnY[i]) ==
				(pnR[i] + pnR[nTemp]) * (pnR[i] + pnR[nTemp]))
			{
				pnFlag[i] = 1;
				fTemp = pnR[nTemp] * 1.0 / pnR[i];
				pfS[i] = pfS[nTemp] * fTemp;
				pnIndex[i] = nTemp;
				if (i == nEnd)
				{
					for (int i = nEnd; i != -1; i = pnIndex[i])
						fSum += pfS[i];
					printf("%d", (int)fSum);
					return 0;
				}
				qBFS.push(i);
			}
		}
	}





Exit0:

	return 0;
}