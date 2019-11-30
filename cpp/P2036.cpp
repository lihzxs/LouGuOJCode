/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-17 16:39
//	Comment		:	OJ(P2036)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <stack>
#include <string>
#include <string.h>
#include <set>
using namespace std;
#define	MAXNUM		1000000000
#define	EPS         0.0001


#define ERROR_ID    0

#define PROCESS_ERROR(Condition)    \
{                                   \
        if (!(Condition))           \
        {                           \
            goto Exit0;             \
        }                           \
}


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int PrimeInit(unsigned int* punSeq, BYTE* pbyIsPrime)
{
	int		nIndex = 0;
	memset(pbyIsPrime, 1, MAXNUM * sizeof(BYTE));
	for (int i = 2; i < MAXNUM; i++)
	{
		if (pbyIsPrime[i])
		{
			punSeq[nIndex++] = i;
			for (int j = i * 2; j < MAXNUM; j += i)
				pbyIsPrime[j] = 0;
		}
	}
	return nIndex;
}

int		g_nMin			= MAXNUM;

void DFS(int* pnInputS, int* pnInputB, BOOL* pbIsVis, int nCount,int nNum,int nMul, int nSum)
{
	if (abs(nMul - nSum) < g_nMin && nCount != 0)
	{
		g_nMin = abs(nMul - nSum);
		return;
	}
	if (nCount >= nNum)
		return;


	for (int i = 0; i < nNum; i++)
	{
		if (!pbIsVis[i])
		{
			nCount++;
			pbIsVis[i] = true;
			DFS(pnInputS, pnInputB, pbIsVis,
				nCount, nNum, nMul * pnInputS[i],
				nSum + pnInputB[i]);
			pbIsVis[i] = false;
			nCount--;
		}
	}
}




int main(int argc, char* argv[])
{

	int					nInputN;

	int*				pnInputS			= NULL;
	int*				pnInputB			= NULL;
	BOOL*				pbIsVis				= NULL;

	scanf("%d", &nInputN);


	pbIsVis = (BOOL*)malloc(nInputN * sizeof(BOOL));
	memset(pbIsVis, 0, nInputN * sizeof(BOOL));
	pnInputS = (int*)malloc(nInputN * sizeof(int));
	pnInputB = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
		scanf("%d%d", pnInputS + i, pnInputB + i);

	DFS(pnInputS, pnInputB, pbIsVis, 0, nInputN, 1, 0);
	printf("%d", g_nMin);







	



Exit0:

	return 0;
}



