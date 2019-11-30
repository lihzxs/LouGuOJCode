
////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-21 23:31
//	Comment		:	OJ(P1233)
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
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

typedef struct SDate
{
	int	nL;
	int	nW;
}SDate;

bool Cmp(const SDate& sFirst, const SDate& sSecond)
{
	if (sFirst.nL == sSecond.nL)
		return sFirst.nW > sSecond.nW;
	return sFirst.nL > sSecond.nL;
}


int main(int argc, char* argv[])
{
	int			nInputN;
	int*		pnCount = NULL;
	int*		pnFlag = NULL;
	int			nMax = 0;
	int			nPre;
	SDate*		psDate = NULL;

	cin >> nInputN;

	psDate = (SDate*)malloc(nInputN * sizeof(SDate));
	pnCount = (int*)malloc(nInputN * sizeof(int));
	pnFlag = (int*)malloc(nInputN * sizeof(int));
	memset(pnCount, 0, nInputN * sizeof(int));
	memset(pnFlag, 0, nInputN * sizeof(int));
	for (int i = 0; i < nInputN; i++)
		cin >> psDate[i].nL >> psDate[i].nW;

	sort(psDate, psDate + nInputN, Cmp);

	for (int i = 0; i < nInputN; i++)
	{
		if (pnFlag[i])
			continue;
		nPre = psDate[i].nW;
		for (int j = i + 1; j < nInputN; j++)
		{
			if (psDate[j].nW <= nPre && pnFlag[j] == 0)
			{
				pnFlag[j] = 1;
				nPre = psDate[j].nW;
			}
		}
	}

	for (int i = 0; i < nInputN; i++)
		if (!pnFlag[i])
			nMax++;


	printf("%d", nMax);


Exit0:

	return 0;
}