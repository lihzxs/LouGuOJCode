/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-28 16:53
//	Comment		:	OJ(P1230)
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

typedef struct SDate
{
	int nTime;
	int	nMoney;
}SDate;


bool Cmp(const SDate& sFirst, const SDate& sSecond)
{
	return sFirst.nTime < sSecond.nTime;
}


int main(int argc, char* argv[])
{
	int				nInputM;
	int				nInputN;
	int				nSum			= 0;
	int				nGet			= 0;
	int				nMax			= 0;
	int*			pnTime			= NULL;
	int*			pnMoney			= NULL;
	int*			pnAns			= NULL;
	int				nMin			= 0;
	int				nMinIndex;
	SDate*			psDate			= NULL;
	scanf("%d%d", &nInputM, &nInputN);

	pnTime = (int*)malloc(nInputN * sizeof(int));
	pnMoney = (int*)malloc(nInputN * sizeof(int));
	psDate = (SDate*)malloc(nInputN * sizeof(SDate));

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", pnTime + i);
		nMax = max(nMax, pnTime[i]);
	}
		

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", pnMoney + i);
		psDate[i].nTime = pnTime[i];
		psDate[i].nMoney = pnMoney[i];
		nSum += pnMoney[i];
		
	}

	
	sort(psDate, psDate + nInputN, Cmp);

	pnAns = (int*)malloc((nMax + 1) * sizeof(int));
	memset(pnAns, 0, (nMax + 1) * sizeof(int));

	for (int i = 0; i < nInputN; i++)
	{
		if (pnAns[psDate[i].nTime] == 0)
			pnAns[psDate[i].nTime] = psDate[i].nMoney;
		else
		{
			nMin = nInputM;
			for (int j = 1; j <= psDate[i].nTime; j++)
			{
				if (nMin > pnAns[j])
				{
					nMin = pnAns[j];
					nMinIndex = j;
				}
			}
			if (nMin < psDate[i].nMoney)
				pnAns[nMinIndex] = psDate[i].nMoney;
		}
	}

	for (int i = 1; i <= nMax; i++)
		nGet += pnAns[i];
		



		


	if (nInputM - nSum + nGet < 0)
		printf("0");
	else
		printf("%d", nInputM - nSum + nGet);

Exit0:

	return 0;
}