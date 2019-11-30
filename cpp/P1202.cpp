/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-21 10:51
//	Comment		:	OJ(P1202)
//
///////////////////////////////////////////

///#include "pch.h"
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
#define	MAXNUM		7010
#define	EPS         0.0001
#define MODNUM		1000000007ll


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


bool IsLeapYear(int nYear)
{
	return ((nYear % 400) == 0 || (nYear % 100 != 0 && nYear % 4 == 0));
}


int main(int argc, char* argv[])
{
	int				nInputN;
	int				nFirstYear			= 1900;
	int*			pnCountDayOfMonth	= NULL;
	int*			pnAnsSeq			= 0;
	int				nPreMonth			= 3;

	pnCountDayOfMonth = (int*)malloc(12 * sizeof(int));
	pnAnsSeq = (int*)malloc(7 * sizeof(int));
	memset(pnAnsSeq, 0, 7 * sizeof(int));

	pnCountDayOfMonth[0] = 31;
	pnCountDayOfMonth[1] = 31;
	pnCountDayOfMonth[2] = 28;
	pnCountDayOfMonth[3] = 31;
	pnCountDayOfMonth[4] = 30;
	pnCountDayOfMonth[5] = 31;
	pnCountDayOfMonth[6] = 30;
	pnCountDayOfMonth[7] = 31;
	pnCountDayOfMonth[8] = 31;
	pnCountDayOfMonth[9] = 30;
	pnCountDayOfMonth[10] = 31;
	pnCountDayOfMonth[11] = 30;

	scanf("%d", &nInputN);


	for (int i = nFirstYear; i < nFirstYear + nInputN; i++)
	{
		pnCountDayOfMonth[2] += IsLeapYear(i);
		for (int j = 0; j < 12; j++)
		{
			nPreMonth = (nPreMonth + pnCountDayOfMonth[j])  %  7;
			pnAnsSeq[nPreMonth]++;
		}
		pnCountDayOfMonth[2] = 28;
	}


	printf("%d", pnAnsSeq[6]);
	for (int i = 0; i < 6; i++)
		printf(" %d", pnAnsSeq[i]);












	


Exit0:

	return 0;
}