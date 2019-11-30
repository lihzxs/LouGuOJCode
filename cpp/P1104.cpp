/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-16 11:24
//	Comment		:	OJ(P1304)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <stack>
#include <string>
#include <string.h>
using namespace std;
#define	MAXNUM		20000
#define	EPS         0.0001
#define ERROR_ID    0

typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

typedef struct SBIRTHDAY
{
	string		szName = "";
	int			nYear;
	int			nMonth;
	int			nDay;
	int			nCount;
}SBIRTHDAY;


bool cmp(const SBIRTHDAY sFirst, const SBIRTHDAY sSecond)
{
	if (sFirst.nYear == sSecond.nYear)
	{
		if (sFirst.nMonth == sSecond.nMonth)
		{
			if (sFirst.nDay == sSecond.nDay)
				return sFirst.nCount > sSecond.nCount;
			return sFirst.nDay < sSecond.nDay;
		}
		return sFirst.nMonth < sSecond.nMonth;
	}
	return sFirst.nYear < sSecond.nYear;
}


int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false);

	int				nInputN;
	SBIRTHDAY*		psBirthdaySeq			= NULL;

	cin >> nInputN;

	psBirthdaySeq = new SBIRTHDAY[nInputN];

	for (int i = 0; i < nInputN; i++)
	{
		cin >> psBirthdaySeq[i].szName
		>> psBirthdaySeq[i].nYear
		>> psBirthdaySeq[i].nMonth
		>> psBirthdaySeq[i].nDay;
		psBirthdaySeq[i].nCount = i;
	}



	sort(psBirthdaySeq, psBirthdaySeq + nInputN, cmp);
	for (int i = 0; i < nInputN; i++)
		cout << psBirthdaySeq[i].szName << endl;

	




Exit0:

	return 0;
}