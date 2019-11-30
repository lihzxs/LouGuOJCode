/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-29 10:58
//	Comment		:	OJ(P1458)
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

int CalcGCD(int a, int b)
{
	if (a%b == 0)
		return b;
	return CalcGCD(b, a%b);
}

typedef struct SNum
{
	int			nUp;
	int			nDown;
	double		fNum;
}SNum;


bool Cmp(const SNum& sFirst, const SNum& sSecond)
{
	return sFirst.fNum < sSecond.fNum;
}


int main(int argc, char* argv[])
{
	int				nInputN;
	SNum*			psNum			= NULL;
	int				nCount			= NULL;
	int				nGCD;
	scanf("%d", &nInputN);

	psNum = (SNum*)malloc(nInputN * nInputN * sizeof(SNum));

	for (int i = 1; i <= nInputN; i++)
		for (int j = 1; j < nInputN && j < i; j++)
		{

			nGCD = CalcGCD(i, j);
			if (nGCD > 1)
				continue;
			psNum[nCount].nUp = j / nGCD;
			psNum[nCount].nDown = i / nGCD;

			psNum[nCount].fNum = psNum[nCount].nUp * 1.0 / psNum[nCount].nDown;
			nCount++;
		}


	sort(psNum, psNum + nCount, Cmp);


	printf("0/1\n");
	for (int i = 0; i < nCount; i++)
		printf("%d/%d\n", psNum[i].nUp, psNum[i].nDown);
	printf("1/1\n");



	



Exit0:

	return 0;
}