/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-5 21:56
//	Comment		:	OJ(P1105)
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
	int			nHight;
	int			nLeft;
	int			nRight;
	int			nId;
}SDate;

bool Cmp(const SDate& sFirst, const SDate& sSecond)
{
	if (sFirst.nHight == sSecond.nHight)
		return sFirst.nId < sSecond.nId;
	return sFirst.nHight < sSecond.nHight;
}

int main(int argc, char* argv[])
{
	SDate*		psDate				= NULL;
	SDate*		psSort				= NULL;
	int			nInputH;
	int			nInputL;
	int			nInputR;
	int			nInputN;
	int			nMaxHL;
	int			nIndexL;
	int			nMaxHR;
	int			nIndexR;
	scanf("%d", &nInputN);
	psDate = (SDate*)malloc(nInputN * sizeof(SDate));
	psSort = (SDate*)malloc(nInputN * sizeof(SDate));
	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d%d", &nInputH, &nInputL, &nInputR);
		psDate[i].nHight = nInputH;
		psDate[i].nLeft = nInputL;
		psDate[i].nRight = nInputR;
		psDate[i].nId = i;
	}
	memcpy(psSort, psDate, nInputN * sizeof(SDate));
	sort(psSort, psSort + nInputN, Cmp);


	for (int i = 0; i < nInputN; i++)
	{
		nMaxHL = 0;
		nMaxHR = 0;
		nIndexL = -1;
		nIndexR = -1;
		for (int j = 0; j < nInputN; j++)
		{
			if (psSort[j].nHight == psDate[i].nHight)
				break;
			if (nMaxHL < psSort[j].nHight && 
				psSort[j].nLeft < psDate[i].nLeft && 
				psSort[j].nRight > psDate[i].nLeft)
			{
				nMaxHL = psSort[j].nHight;
				nIndexL = psSort[j].nId;
			}
			if (nMaxHR < psSort[j].nHight && 
				psSort[j].nRight > psDate[i].nRight && 
				psSort[j].nLeft < psDate[i].nRight)
			{
				nMaxHR = psSort[j].nHight;
				nIndexR = psSort[j].nId;
			}
		}
		printf("%d %d\n", nIndexL + 1, nIndexR + 1);
	}




	



Exit0:
	return 0;
}