/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-27 23:12
//	Comment		:	OJ(P1583)
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

typedef struct SQNum
{
	int		nQ;
	int		nIndex;
}SQNum;

bool Cmp(const SQNum& sFirst, const SQNum& sSecond)
{
	if (sFirst.nQ == sSecond.nQ)
		return sFirst.nIndex < sSecond.nIndex;
	return sFirst.nQ > sSecond.nQ;
}




int main(int argc, char* argv[])
{
	int								nInputL;
	int								nInputN;
	int*							pnSeqE;
	SQNum*							psQNum				= 0;

	scanf("%d%d", &nInputL, &nInputN);

	psQNum = (SQNum*)malloc(nInputL * sizeof(SQNum));

	pnSeqE = (int*)malloc(11 * sizeof(int));

	for (int i = 1; i < 11; i++)
		scanf("%d", pnSeqE + i);

	for (int i = 0; i < nInputL; i++)
	{
		scanf("%d", &psQNum[i].nQ);
		psQNum[i].nIndex = i + 1;
	}

	sort(psQNum, psQNum + nInputL, Cmp);





	for (int i = 0; i < nInputL; i++)
	{
		psQNum[i].nQ += pnSeqE[i % 10 + 1];
	}



    sort(psQNum, psQNum + nInputL, Cmp);

	printf("%d", psQNum[0].nIndex);
	for (int i = 1; i < nInputN; i++)
		printf(" %d", psQNum[i].nIndex);

		








Exit0:

	return 0;
}