/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-5 22:30
//	Comment		:	OJ(P2404)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
#include <set>
#include <queue>
#include <list>
#include <map>
#include <sstream>

using namespace std;
#define	MAXNUM		100000000
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


void DFS(int nNum, int nNowSum, int nStep, int* pnOutput)
{
	if (nNum <= nNowSum)
	{
		if (nNowSum == nNum)
		{
			printf("%d", pnOutput[1]);
			for (int i = 2; i < nStep; i++)
				printf("+%d", pnOutput[i]);
			printf("\n");
		}
		return;
	}
	for (int i = 1; i <= nNum - nNowSum; i++)
	{
		if (i < pnOutput[nStep - 1] || i == nNum)
			continue;
		pnOutput[nStep] = i;
		DFS(nNum, nNowSum + i, nStep + 1, pnOutput);
	}
}



int main(int argc, char* argv[])
{
	int					nInputN;
	int*				pnSeq			= NULL;
	scanf("%d", &nInputN);
	pnSeq = (int*)malloc((nInputN + 1) * sizeof(int));
	pnSeq[0] = 0;
	DFS(nInputN, 0, 1, pnSeq);


Exit0:
	return 0;
}