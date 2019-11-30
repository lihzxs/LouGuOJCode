/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-17 20:17
//	Comment		:	OJ(P2655)
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


int main(int argc, char* argv[])
{
	int					nInputT;
	int					nInputN;
	int					nYear;
	int					nMonth;
	int					nDay;
	int					nHour;
	int					nMinute;
	int					nSecond;

	long long					nAnsYear;
	long long					nAnsMonth;
	long long					nAnsDay;
	long long					nAnsHour;
	long long					nAnsMinute;
	long long					nAnsSecond;

	int*				pnCountDay;
	int					nIndex;
	long long			nAll;

	pnCountDay = (int*)malloc(13 * sizeof(int));
	
	pnCountDay[1] = 31;
	pnCountDay[2] = 28;
	pnCountDay[3] = 31;
	pnCountDay[4] = 30;
	pnCountDay[5] = 31;
	pnCountDay[6] = 30;
	pnCountDay[7] = 31;
	pnCountDay[8] = 31;
	pnCountDay[9] = 30;
	pnCountDay[10] = 31;
	pnCountDay[11] = 30;
	pnCountDay[12] = 31;
	scanf("%d", &nInputT);
	
	while (nInputT--)
	{
		nAll = 1;
		nIndex = 0;
		scanf("%d", &nInputN);
		scanf("%d", &nYear);
		scanf("%d", &nMonth);
		scanf("%d", &nDay);
		scanf("%d", &nHour);
		scanf("%d", &nMinute);
		scanf("%d", &nSecond);
		for (int i = 1; i < nInputN; i++)
			nAll <<= 1;
		nAll--;

		nAnsSecond = nSecond;
		nAnsSecond += nAll;
		nAnsMinute = nAnsSecond / 60;
		nAnsSecond %= 60;
		nAnsMinute += nMinute;

		nAnsHour = nAnsMinute / 60;
		nAnsMinute %= 60;
		nAnsHour += nHour;

		nAnsDay = nAnsHour / 24;
		nAnsHour %= 24;
		nAnsDay += nDay;

		nAnsMonth = nMonth;
		nAnsYear = nYear;

		if (nAnsYear % 400 == 0 || (nAnsYear % 4 == 0 && nAnsYear % 100 != 0))
			pnCountDay[2] = 29;
		else
			pnCountDay[2] = 28;

		while (nAnsDay > pnCountDay[nAnsMonth])
		{
			nAnsDay -= pnCountDay[nAnsMonth];
			nAnsMonth++;
			if (nAnsMonth > 12)
			{
				nAnsMonth = 1;
				nAnsYear++;
				if (nAnsYear % 400 == 0 || (nAnsYear % 4 == 0 && nAnsYear % 100 != 0))
					pnCountDay[2] = 29;
				else
					pnCountDay[2] = 28;
			}
		}

		printf("%lld %lld %lld %lld %lld %lld\n", nAnsYear, nAnsMonth, nAnsDay, 
			nAnsHour, nAnsMinute, nAnsSecond);


	}


Exit0:

	return 0;
}