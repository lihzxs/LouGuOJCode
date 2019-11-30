/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-21 15:31
//	Comment		:	OJ(P1328)
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
#define	MAXNUM		150
#define	EPS         0.0001
#define MODNUM		1000000007ll


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int PrimeInit(unsigned int* punSeq, BYTE* pbyIsPrime)
{
	int		nIndex = 0;
	memset(pbyIsPrime, true, MAXNUM * sizeof(BYTE));
	for (int i = 2; i < MAXNUM; i++)
	{
		if (pbyIsPrime[i])
		{
			punSeq[nIndex++] = i;
			for (int j = i * 2; j < MAXNUM; j += i)
				pbyIsPrime[j] = 0;
		}
	}
	pbyIsPrime[0] = false;
	pbyIsPrime[1] = true;
	return nIndex;
}


int main(int argc, char* argv[])
{
	int**			ppnJudgeMat				= NULL;
	int				nInputN;
	int				nALeap;
	int				nBLeap;
	int*			pnA						= NULL;
	int*			pnB						= NULL;
	int				nAIndex					= 0;
	int				nBIndex					= 0;
	int				nSumA					= 0;
	int				nSumB					= 0;
	scanf("%d%d%d", &nInputN, &nALeap, &nBLeap);

	pnA = (int*)malloc(nALeap * sizeof(int));
	pnB = (int*)malloc(nBLeap * sizeof(int));
	ppnJudgeMat = (int**)malloc(5 * sizeof(int*));
	for (int i = 0; i < 5; i++)
		ppnJudgeMat[i] = (int*)malloc(5 * sizeof(int));

	ppnJudgeMat[0][0] = 0;
	ppnJudgeMat[0][1] = -1;
	ppnJudgeMat[0][2] = 1;
	ppnJudgeMat[0][3] = 1;
	ppnJudgeMat[0][4] = -1;
	ppnJudgeMat[1][0] = 1;
	ppnJudgeMat[1][1] = 0;
	ppnJudgeMat[1][2] = -1;
	ppnJudgeMat[1][3] = 1;
	ppnJudgeMat[1][4] = -1;
	ppnJudgeMat[2][0] = -1;
	ppnJudgeMat[2][1] = 1;
	ppnJudgeMat[2][2] = 0;
	ppnJudgeMat[2][3] = -1;
	ppnJudgeMat[2][4] = 1;
	ppnJudgeMat[3][0] = -1;
	ppnJudgeMat[3][1] = -1;
	ppnJudgeMat[3][2] = 1;
	ppnJudgeMat[3][3] = 0;
	ppnJudgeMat[3][4] = 1;
	ppnJudgeMat[4][0] = 1;
	ppnJudgeMat[4][1] = 1;
	ppnJudgeMat[4][2] = -1;
	ppnJudgeMat[4][3] = -1;
	ppnJudgeMat[4][4] = 0;


	for (int i = 0; i < nALeap; i++)
		scanf("%d", pnA + i);
	for (int i = 0; i < nBLeap; i++)
		scanf("%d", pnB + i);


	while (nInputN != 0)
	{
		if (nAIndex == nALeap)
			nAIndex = 0;

		if (nBIndex == nBLeap)
			nBIndex = 0;


		if (ppnJudgeMat[pnA[nAIndex]][pnB[nBIndex]] > 0)
			nSumA++;
		else if (ppnJudgeMat[pnA[nAIndex]][pnB[nBIndex]] < 0)
			nSumB++;

		nAIndex++;
		nBIndex++;

		nInputN--;
	}
	printf("%d %d", nSumA, nSumB);

Exit0:

	return 0;
}