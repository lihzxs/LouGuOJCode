/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-15 23:48
//	Comment		:	OJ(P4519)
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
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;
queue<int>		qX;
queue<int>		qY;
queue<int>		qZ;


int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int				nInputK;
	int				nAns				= 0;
	int				nPre				= 0;
	int				nTemp;
	scanf("%d", &nInputN);
	scanf("%d", &nInputM);
	scanf("%d", &nInputK);
	nPre = 0;
	for (int i = 0; i < nInputM; i++)
	{
		scanf("%d", &nTemp);
		if (nTemp - nInputK > nPre)
		{
			nAns += (nTemp - nInputK - nPre - 1) / (2 * nInputK + 1) + 
				((nTemp - nInputK - nPre - 1) % (2 * nInputK + 1) != 0);
			nPre = nTemp + nInputK;
		}
		else
			nPre = max(nTemp + nInputK, nPre);
	}
	if (nPre < nInputN)
		nAns += (nInputN - nPre) / (2 * nInputK + 1) +
		((nInputN - nPre) % (2 * nInputK + 1) != 0);
	printf("%d", nAns);



Exit0:

	return 0;
}