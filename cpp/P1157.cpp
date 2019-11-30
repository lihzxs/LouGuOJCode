/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-28 22:57
//	Comment		:	OJ(P1157)
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

using namespace std;
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

void DFS(int* pnNumFlag, int nCount, int nR,int nNum, int*	pnOutput)
{
	if (nCount >= nR)
	{
		for (int i = 0; i < nCount; i++)
			printf("%3d", pnOutput[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= nNum; i++)
	{
		if (pnNumFlag[i])
		{
			if (nCount != 0 && i <= pnOutput[nCount - 1])
				continue;
			pnNumFlag[i] = false;
			pnOutput[nCount] = i;
			DFS(pnNumFlag, nCount + 1, nR, nNum, pnOutput);
			pnNumFlag[i] = true;
		}
	}
}


int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputR;
	int*			pnNumFlag				= NULL;
	string			szInput;
	int*			pnOutput				= NULL;
	int				nAns					= 0;

	scanf("%d%d", &nInputN, &nInputR);
	pnOutput = (int*)malloc(nInputR * sizeof(int));
	pnNumFlag = (int*)malloc((nInputN + 1) * sizeof(int));

	memset(pnNumFlag, false, (nInputN + 1) * sizeof(int));

	for (int i = 1; i <= nInputN; i++)
		pnNumFlag[i] = true;


	DFS(pnNumFlag, 0, nInputR, nInputN, pnOutput);

Exit0:

	return 0;
}