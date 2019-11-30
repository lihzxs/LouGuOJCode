/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-20 22:37
//	Comment		:	OJ(P1024)
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
#define	MAXNUM		10010
#define	EPS         0.001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	double							nInputA;
	double							nInputB;
	double							nInputC;
	double							nInputD;
	double						fX1;
	double						fX2;
	pair<int, int>				prTemp;
	vector<pair<int, int> >		vIndex;

	double			fLeft;
	double			fRight;
	double			fMid;
	scanf("%lf%lf%lf%lf", &nInputA, &nInputB, &nInputC, &nInputD);

	for (int i = -100; i < 100; i++)
	{
		fX1 = i;
		fX2 = i + 1;
		fX1 = nInputA * fX1 * fX1 * fX1 +
			nInputB * fX1 * fX1 + nInputC * fX1 + nInputD;
		fX2 = nInputA * fX2 * fX2 * fX2 +
			nInputB * fX2 * fX2 + nInputC * fX2 + nInputD;
		if ((fX1 <= 0 && fX2 > 0) || (fX1 > 0 && fX2 <= 0))
		{
			prTemp.first = i;
			prTemp.second = i + 1;
			vIndex.push_back(prTemp);
		}
	}

	for (int i = 0; i < vIndex.size(); i++)
	{
		fLeft = vIndex[i].first;
		fRight = vIndex[i].second;

		while (fRight - fLeft > EPS)
		{
			fMid = (fRight + fLeft) / 2.0;
			fX1 = nInputA * fLeft * fLeft * fLeft +
				nInputB * fLeft * fLeft + nInputC * fLeft + nInputD;
			fX2 = nInputA * fMid * fMid * fMid +
				nInputB * fMid * fMid + nInputC * fMid + nInputD;

			if ((fX1 <= 0 && fX2 > 0) || (fX1 > 0 && fX2 <= 0))
				fRight = fMid;
			else
				fLeft = fMid;
		}

		printf("%.2f ", fLeft);


	}



Exit0:
	return 0;
}