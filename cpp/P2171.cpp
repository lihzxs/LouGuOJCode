/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-27 21:15
//	Comment		:	OJ(P2171)
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

typedef struct STree
{
	int			nNum;
	STree*		psLeft;
	STree*		psRight;
}STree;


void AddItem(STree*& psRoot,int nX, int nDeep, int& nMaxDeep)
{
	nMaxDeep = max(nMaxDeep, nDeep);
	if (psRoot == NULL)
	{
		STree*		psTemp			= NULL;
		psTemp = (STree*)malloc(sizeof(STree));
		psTemp->nNum = nX;
		psTemp->psLeft = NULL;
		psTemp->psRight = NULL;
		psRoot = psTemp;
		return;
	}
	if (psRoot->nNum < nX)
		AddItem(psRoot->psRight, nX, nDeep + 1, nMaxDeep);
	else
		AddItem(psRoot->psLeft, nX, nDeep + 1, nMaxDeep);
}


void Print(STree* psRoot)
{
	if (psRoot == NULL)
		return;
	Print(psRoot->psLeft);
	Print(psRoot->psRight);
	printf("%d\n", psRoot->nNum);
}


int main(int argc, char* argv[])
{
	int				nInputN;
	int				nTemp;
	int				nDeep			= 0;
	STree*			psRoot			= NULL;
	scanf("%d", &nInputN);
	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", &nTemp);
		AddItem(psRoot, nTemp, 0, nDeep);
	}
	printf("deep=%d\n", nDeep + 1);
	Print(psRoot);
Exit0:

	return 0;
}