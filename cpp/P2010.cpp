/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-3 14:17
//	Comment		:	OJ(P2010)
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
#define	MAXNUM		100000000
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

bool IsPalindrome(string& szTemp)
{
	int i = 0;
	int j = szTemp.length() - 1;
	while (i < j)
	{
		if (szTemp[i] != szTemp[j])
			return false;
		i++;
		j--;
	}
	return true;
}


int main(int argc, char* argv[])
{
	int				nDate1;
	int				nDate2;
	int				nYear;
	string			szYear;
	int				nMonth;
	string			szMonth;
	int				nDay;
	string			szDay;
	string			szInput;
	int				nAns				= 0;
	int*			pnDay				= NULL;

	scanf("%d%d", &nDate1, &nDate2);

	if (nDate1 == nDate2)
	{
		szInput = to_string(nDate1);
		if (IsPalindrome(szInput))
			printf("1\n");
		else
			printf("0\n");
	}
	else
	{
		pnDay = (int*)malloc(13 * sizeof(int));
		pnDay[1] = 31;
		pnDay[2] = 28;
		pnDay[3] = 31;
		pnDay[4] = 30;
		pnDay[5] = 31;
		pnDay[6] = 30;
		pnDay[7] = 31;
		pnDay[8] = 31;
		pnDay[9] = 30;
		pnDay[10] = 31;
		pnDay[11] = 30;
		pnDay[12] = 31;
		nYear = nDate1 / 10000;
		nMonth = nDate1 % 10000 / 100;
		nDay = nDate1 % 100;
		while (nYear != nDate2 / 10000 ||
			nMonth != nDate2 % 10000 / 100 || nDay != nDate2 % 100)
		{
			szYear = to_string(nYear);
			if (szYear.length() < 4)
				for (int i = 0; i < 4 - szYear.length(); i++)
					szYear = '0' + szYear;
			szMonth = to_string(nMonth);
			if (szMonth.length() < 2)
				for (int i = 0; i < 2 - szMonth.length(); i++)
					szMonth = '0' + szMonth;
			szDay = to_string(nDay);
			if (szDay.length() < 2)
				for (int i = 0; i < 2 - szDay.length(); i++)
					szDay = '0' + szDay;
			szInput = szYear + szMonth + szDay;


			if (IsPalindrome(szInput))
				nAns++;
			nDay++;
			if (nDay > pnDay[nMonth] +
				(nMonth == 2 && ((nYear % 4 == 0 && nYear % 100 != 0) ||
					nYear % 400 == 0)))
			{
				nDay = 1;
				nMonth++;
			}
			if (nMonth > 12)
			{
				nYear++;
				nMonth = 1;
			}

		}

		printf("%d", nAns);


	}












Exit0:
	return 0;
}