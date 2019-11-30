/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-30 21:58
//	Comment		:	OJ(P3093)
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

typedef struct SDate
{
	int		nMilk;
	int		nTime;
}SDate;

bool Cmp(const SDate& sFirst, const SDate& sSecond)
{
	if (sFirst.nMilk == sSecond.nMilk)
		return sFirst.nTime < sSecond.nTime;
	else
		return sFirst.nMilk > sSecond.nMilk;
}


int main(int argc, char* argv[])
{
	int				nInputN;
	SDate*			psDate				= NULL;
	int*			pnFlag				= NULL;
	int				nIndex;
	int				nAns				= 0;
	
	scanf("%d", &nInputN);

	pnFlag = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnFlag, 0, (nInputN + 1) * sizeof(int));
	psDate = (SDate*)malloc((nInputN + 1) * sizeof(SDate));

	for (int i = 1; i <= nInputN; i++)
		scanf("%d%d", &psDate[i].nMilk, &psDate[i].nTime);

	sort(psDate + 1, psDate + nInputN + 1, Cmp);

	for (int i = 1; i <= nInputN; i++)
	{
		nIndex = 0;
		for (int j = psDate[i].nTime; j >= 1; j--)
			if (!pnFlag[j])
			{
				nIndex = j;
				break;
			}

		if (nIndex)
		{
			pnFlag[nIndex] = 1;
			nAns += psDate[i].nMilk;
		}
	}

	printf("%d", nAns);




Exit0:
	return 0;
}