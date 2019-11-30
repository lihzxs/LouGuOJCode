/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-21 18:14
//	Comment		:	OJ(P2121)
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
#define	MAXNUM		1000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int Fin(int* pnSet, int nNum)
{
	if (pnSet[nNum] == nNum)
		return pnSet[nNum];
	else
		return pnSet[nNum] =
		Fin(pnSet, pnSet[nNum]);
}


typedef struct SDate
{
	int		nStart;
	int		nEnd;
	int		nNum;
}SDate;

bool Cmp(const SDate& sFirst, const SDate& sSecond)
{
	return sFirst.nNum > sSecond.nNum;
}



int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int				nInputK;
	int				nCount				= 0;
	int				nSum				= 0;
	int*			pnSet				= NULL;
	int				nInputA;
	int				nInputB;
	int				nInputW;
	SDate*			psDate				= NULL;

	scanf("%d%d%d", &nInputN, &nInputM, &nInputK);

	pnSet = (int*)malloc((nInputN + 1) * sizeof(int));

	for (int i = 1; i <= nInputN; i++)
		pnSet[i] = i;

	psDate = (SDate*)malloc(nInputM * sizeof(SDate));

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d%d%d", &nInputA, &nInputB, &nInputW);
		psDate[i].nStart = nInputA;
		psDate[i].nEnd = nInputB;
		psDate[i].nNum = nInputW;
	}

	sort(psDate, psDate + nInputM, Cmp);


	for (int i = 0; i < nInputM; i++)
	{
		if (Fin(pnSet, psDate[i].nStart) != 
			Fin(pnSet, psDate[i].nEnd))
		{
			pnSet[Fin(pnSet, psDate[i].nStart)] = 
				pnSet[Fin(pnSet, psDate[i].nEnd)];
			nSum += psDate[i].nNum;
			nCount++;
		}
		if (nCount == nInputK)
			break;
	}


	printf("%d", nSum);
Exit0:
	return 0;
}