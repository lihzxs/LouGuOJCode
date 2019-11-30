/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-21 11:33
//	Comment		:	OJ(P1014)
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
	int				nRow;
	int				nDis;
	int				nRecord;
	int				nSum		= 0;
	scanf("%d", &nInputN);

	for (nRecord = 1; nRecord < nInputN; nRecord++)
	{
		if (nSum + nRecord <= nInputN)
			nSum += nRecord;
		else
			break;
	}

	

	nDis = nInputN - nSum;

	if (nDis == 0)
	{
		nRecord--;
		if (nRecord % 2)
			printf("1/%d", nRecord);
		else
			printf("%d/1", nRecord);
	}
	else
	{
		if (nRecord % 2)
			printf("%d/%d", nRecord - nDis + 1, nDis);
		else
			printf("%d/%d", nDis, nRecord - nDis + 1);

	}
















	


Exit0:

	return 0;
}