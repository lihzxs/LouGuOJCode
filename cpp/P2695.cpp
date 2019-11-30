/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-12 19:05
//	Comment		:	OJ(P2695)
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

using namespace std;
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		2000001


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;



int main(int argc, char* argv[])
{
	int						nInputN;
	int						nInputM;
	int*					pnSeqMonster			= NULL;
	int*					pnSeqFighter			= NULL;
	int						nRecord;
	int						nAns					= 0;
	scanf("%d%d", &nInputN, &nInputM);

	pnSeqMonster = (int*)malloc(nInputN * sizeof(int));
	pnSeqFighter = (int*)malloc(nInputM * sizeof(int));

	for (int i = 0; i < nInputN; i++)
		scanf("%d", &pnSeqMonster[i]);

	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d", &pnSeqFighter[i]);
		nAns += pnSeqFighter[i];
	}
		

	if (nInputM == nInputN)
	{
		printf("%d", nAns);
		return 0;
	}
	else if (nInputN > nInputM)
	{
		printf("you died!");
		return 0;
	}


	sort(pnSeqMonster, pnSeqMonster + nInputN);
	sort(pnSeqFighter, pnSeqFighter + nInputM);
	nRecord = 0;
	nAns = 0;
	for (int i = 0; i < nInputN; i++)
	{
		for (; nRecord < nInputM; nRecord++)
		{
			if (pnSeqFighter[nRecord] >= pnSeqMonster[i])
			{
				nAns += pnSeqFighter[nRecord];
				nRecord++;
				break;
			}
		}
		if (nRecord == nInputM)
		{
			printf("you died!");
			return 0;
		}
	}

	printf("%d", nAns);


Exit0:

	return 0;
}