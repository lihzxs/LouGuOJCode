/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-29 23:36
//	Comment		:	OJ(P1164)
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


void DFS(int* pnSeq, BOOL* pbFlag, int nNum, int nM, int nPre, int& nCount, int nStart)
{
	if (nPre >= nM)
	{
		if(nPre == nM)
			nCount++;
		return;
	}
	for (int i = nStart; i < nNum; i++)
	{
		if (!pbFlag[i])
		{
			pbFlag[i] = true;
			DFS(pnSeq, pbFlag, nNum, nM, nPre + pnSeq[i], nCount, i + 1);
			pbFlag[i] = false;
		}
	}
}





int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int*			pnSeq				= NULL;
	BOOL*			pbFlag				= NULL;
	int				nCount				= 0;

	scanf("%d%d", &nInputN, &nInputM);

	pnSeq = (int*)malloc(nInputN * sizeof(int));
	pbFlag = (BOOL*)malloc(nInputN * sizeof(BOOL));
	memset(pbFlag, 0, nInputN * sizeof(BOOL));
	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnSeq + i);


	DFS(pnSeq, pbFlag, nInputN, nInputM, 0, nCount, 0);

	printf("%d", nCount);












Exit0:

	return 0;
}