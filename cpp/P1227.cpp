/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-15 01:18
//	Comment		:	OJ(P1227)
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
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		2e31


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int main(int argc, char* argv[])
{
	int				nN;
	pair<double, double>	prTemp[20005];
	pair<double, double>	prT1;
	pair<double, double>	prT2;

	scanf("%d", &nN);

	for (int i = 1; i <= nN; i++)
		scanf("%lf%lf", &prTemp[i].first, &prTemp[i].second);

	sort(prTemp + 1, prTemp + 1 + nN);

	prT1 = { (prTemp[1].first + prTemp[nN].first) / 2, 
		(prTemp[1].second + prTemp[nN].second) / 2 };

	for (int i = 1; i <= (nN + 1) / 2; i++)
	{
		prT2 = { (prTemp[i].first + prTemp[nN - i + 1].first) / 2,
		(prTemp[i].second + prTemp[nN - i + 1].second) / 2 };
		if (prT1 != prT2)
		{
			printf("This is a dangerous situation!");
			return 0;
		}
	}
	printf("V.I.P. should stay at (%.1f,%.1f).", prT1.first, prT1.second);

Exit0:

	return 0;
}