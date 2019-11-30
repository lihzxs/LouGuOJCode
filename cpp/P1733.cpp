/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-22 09:35
//	Comment		:	OJ(P1733)
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
#define MODNUM		2e64


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int Zhuan(int nIndex, int nDVDNum, int nOrder, int* pnSeq, int* pnInD)
{
	int nTemp[11];
	int nLast = 1;
	memset(nTemp, 1, sizeof(nTemp));
	for (int i = 1; i <= nDVDNum; i++)
		for (int j = nIndex + 1; j <= nOrder; j++)
			if (pnSeq[j] == pnInD[i])
			{
				nTemp[i] = j;
				break;
			}

	for (int i = 1; i <= nDVDNum; i++)
		if (nTemp[i] > nTemp[nLast])
			nLast = i;
	return nLast;
}


int main(int argc, char* argv[])
{
	int			nDVDNum;
	int			nOrder;
	int*		pnSeq			= NULL;
	int*		pnInD			= NULL;
	int*		pnNext;
	int			nAns			= 0;
	int			nMax			= 0;
	int			nIndex			= 0;
	int			nPre;
	int			nFlag;
	scanf("%d%d", &nDVDNum, &nOrder);

	pnSeq = (int*)malloc((nOrder + 1) * sizeof(int));
	pnInD = (int*)malloc((nDVDNum + 1) * sizeof(int));
	pnNext = (int*)malloc((nDVDNum + 1) * sizeof(int));
	memset(pnNext, 0, (nDVDNum + 1) * sizeof(int));
	for (int i = 1; i <= nOrder; i++)
		scanf("%d", pnSeq + i);
	for (int i = 1; i <= nDVDNum; i++)
		pnInD[i] = pnSeq[i];

	if (nOrder <= nDVDNum)
		printf("%d", nOrder);
	else
	{
		nAns = nDVDNum;
		for (int i = nDVDNum + 1; i <= nOrder; i++)
		{
			nFlag = 1;
			for (int j = 1; j <= nDVDNum; j++)
			{
				if (pnSeq[i] == pnInD[j]) 
				{
					nFlag = 0;
					break;
				}
			}
			if (nFlag)
			{
				nAns++;
				nPre = Zhuan(i, nDVDNum, nOrder, pnSeq, pnInD);
				pnInD[nPre] = pnSeq[i];
			}
		}
		printf("%d", nAns);
	}







Exit0:

	return 0;
}