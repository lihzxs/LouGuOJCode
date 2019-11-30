/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-17 17:03
//	Comment		:	OJ(P2207)
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


typedef struct SNode
{
	int		nLeft;
	int		nRight;
}SNode;

bool Cmp(const SNode& sFirst, const SNode& sSecond)
{
	if (sFirst.nRight == sSecond.nRight)
		return sFirst.nLeft < sSecond.nLeft;
	return sFirst.nRight < sSecond.nRight;
}


int main(int argc, char* argv[])
{
	int				nInputK;
	SNode*			psNode				= NULL;
	int				nInputN;
	int				nAns				= 0;
	int				nLast				= -1;

	scanf("%d%d", &nInputN, &nInputK);

	psNode = (SNode*)malloc(nInputK * sizeof(SNode));

	for (int i = 0; i < nInputK; i++)
	{
		scanf("%d%d", &psNode[i].nLeft, &psNode[i].nRight);
		if (psNode[i].nLeft > psNode[i].nRight)
			swap(psNode[i].nLeft, psNode[i].nRight);
	}

	sort(psNode, psNode + nInputK, Cmp);


	for (int i = 0; i < nInputK; i++)
	{
		if (psNode[i].nLeft >= nLast)
		{
			nAns++;
			nLast = psNode[i].nRight;
		}
		else if (psNode[i].nRight < nLast)
			nLast = psNode[i].nRight;
	}
	printf("%d", nAns + 1);
Exit0:

	return 0;
}