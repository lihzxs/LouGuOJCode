/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-22 11:23
//	Comment		:	OJ(P1068)
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

typedef struct SScore
{
	int			nId;
	int			nScore;
}SScore;

bool Cmp(const SScore sFirst, const SScore sSecond)
{
	if (sFirst.nScore == sSecond.nScore)
		return sFirst.nId < sSecond.nId;
	return sFirst.nScore > sSecond.nScore;

}






int main(int argc, char* argv[])
{

	int				nInputM;
	int				nInputN;
	int				nAnsN;
	SScore*			sScore			= NULL;

	scanf("%d%d", &nInputN, &nInputM);

	sScore = new SScore[nInputN];

	for (int i = 0; i < nInputN; i++)
		scanf("%d%d", &sScore[i].nId, &sScore[i].nScore);

	sort(sScore, sScore + nInputN, Cmp);

	for (int i = 0; i < nInputN; i++)
		if (sScore[i].nScore == sScore[int(nInputM * 1.5) - 1].nScore)
			nAnsN = i;


	printf("%d %d\n", sScore[nAnsN].nScore, nAnsN + 1);

	for (int i = 0; i < nAnsN + 1; i++)
		printf("%d %d\n", sScore[i].nId, sScore[i].nScore);
















Exit0:

	return 0;
}