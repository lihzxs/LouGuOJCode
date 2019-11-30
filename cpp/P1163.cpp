/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-9 19:47
//	Comment		:	OJ(P1163)
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

using namespace std;
#define	MAXNUM		150
#define	EPS         0.0001
#define MODNUM		1006


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int				nInputMonth;
	double			fEPS;
	double			fHigh;
	double			fLow;
	double			fMid;
	double			fTemp;
	scanf("%d%d%d", &nInputN, &nInputM, &nInputMonth);

	fHigh = 5.0;
	fLow = 0.0;
	fEPS = fHigh - fLow;
	fMid = (fHigh + fLow) / 2.0;
	while (fEPS > 0.0001)
	{
		fTemp = nInputN;
		for (int i = 0; i < nInputMonth; i++)
			fTemp = fTemp * (1 + fMid) - nInputM;
		if (fTemp > 0)
			fHigh = fMid;
		else
			fLow = fMid;
		fEPS = fHigh - fLow;
		fMid = (fHigh + fLow) / 2.0;
	}

	printf("%.1f", fMid * 100);


Exit0:

	return 0;
}