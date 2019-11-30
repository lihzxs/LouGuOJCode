
////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-22 21:00
//	Comment		:	OJ(P5097)
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
	int			nNum;
	int			nIndex;
}SDate;

bool Cmp(const SDate& sFirst, const SDate& sSecond)
{
	if (sFirst.nNum == sSecond.nNum)
		return sFirst.nIndex < sSecond.nIndex;
	return sFirst.nNum < sSecond.nNum;
}


int main(int argc, char* argv[])
{
	int					nInputN;
	int					nInputQ;
	SDate*				psDate			= NULL;
	int					nStart;
	int					nEnd;
	scanf("%d%d", &nInputN, &nInputQ);

	psDate = (SDate*)malloc((nInputN) * sizeof(SDate));

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", &psDate[i].nNum);
		psDate[i].nIndex = i + 1;
	}

	sort(psDate, psDate + nInputN, Cmp);


	for (int i = 0; i < nInputQ; i++)
	{
		scanf("%d%d", &nStart, &nEnd);
		for (int j = 0; j < nInputN; j++)
		{
			if (psDate[j].nIndex >= nStart &&
				psDate[j].nIndex <= nEnd)
			{
				printf("%d\n", psDate[j].nNum);
				break;
			}
		}
	}







Exit0:

	return 0;
}