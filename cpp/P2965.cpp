/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-28 15:41
//	Comment		:	OJ(P2965)
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
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

typedef struct SCow
{
	long long llW;
	long long llU;
}SCow;


bool Cmp(const SCow& sFirst, const SCow& sSecond)
{
	if (sFirst.llU == sSecond.llU)
		return sFirst.llW < sSecond.llW;
	return sFirst.llU > sSecond.llU;
}

long long MyPow(long long nDown, long long nUp, long long nModNum)
{
	long long				nAns			= 1;
	nDown %= nModNum;
	for (int i = 0; i < nUp; i++)
	{
		nAns *= nDown;
		nAns %= nModNum;
	}
	return nAns;
}


int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputA;
	int				nInputB;
	int				nInputC;
	int				nInputD;
	int				nInputE;
	int				nInputF;
	int				nInputG;
	int				nInputH;
	int				nInputM;
	long long		nSum				= 0;

	SCow*			psCow				= NULL;


	scanf("%d", &nInputN);
	scanf("%d", &nInputA);
	scanf("%d", &nInputB);
	scanf("%d", &nInputC);
	scanf("%d", &nInputD);
	scanf("%d", &nInputE);
	scanf("%d", &nInputF);
	scanf("%d", &nInputG);
	scanf("%d", &nInputH);
	scanf("%d", &nInputM);


	psCow = (SCow*)malloc((3 * nInputN + 1) * sizeof(SCow));


	for (int i = 0; i < 3 * nInputN; i++)
	{
		psCow[i].llW = nInputA % nInputD * MyPow(i, 5, nInputD) % nInputD +
			nInputB % nInputD * MyPow(i, 2, nInputD) % nInputD + nInputC % nInputD;

		psCow[i].llW %= nInputD;

		psCow[i].llU = nInputE % nInputH * MyPow(i, 5, nInputH) % nInputH +
			nInputF % nInputH * MyPow(i, 3, nInputH) % nInputH + nInputG % nInputH;

		psCow[i].llU %= nInputH;

	}
	sort(psCow, psCow + 3 * nInputN, Cmp);




	for (int i = 0; i < nInputN; i++)
	{
		nSum += psCow[i].llW % nInputM;
		nSum %= nInputM;
	}

	printf("%lld", nSum);
		








Exit0:

	return 0;
}