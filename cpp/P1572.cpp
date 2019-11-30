/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-21 18:42
//	Comment		:	OJ(P1572)
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

long CalcGCD(long a, long b)
{
	if (a%b == 0)
		return b;
	return CalcGCD(b, a%b);
}

int main(int argc, char* argv[])
{
	string			szInput;
	string			szTemp;
	long				nAnsUp;
	long				nAnsDown;
	int				nTemp;
	int				nCount				= 0;
	int*			pnSeq				= NULL;

	cin >> szInput;
	szInput += '.';
	pnSeq = (int*)malloc(szInput.length() * sizeof(int));

	for (int i = 0; i < szInput.length(); i++)
	{
		if (szInput[i] >= '0' && szInput[i] <= '9')
		{
			for (int j = i + 1; j < szInput.length(); j++)
			{
				if (szInput[j] < '0' || szInput[j] > '9')
				{
					szTemp = szInput.substr(i, j - i);
					pnSeq[nCount] = atoi(szTemp.c_str());
					if (i > 0 && szInput[i - 1] == '-')
						pnSeq[nCount] = -pnSeq[nCount];
					nCount++;
					i = j;
					break;
				}
			}///for (int j = i + 1; j < szInput.length(); j++)

		}///if (szInput[i] >= '0' && szInput[i] <= '9')
	}///for (int i = 0; i < szInput.length(); i++)
	nAnsUp = pnSeq[0];
	nAnsDown = pnSeq[1];

	for (int i = 2; i < nCount; i += 2)
	{
		nAnsUp = (nAnsUp * pnSeq[i + 1] + pnSeq[i] * nAnsDown) / 
			CalcGCD(nAnsDown, pnSeq[i + 1]);
		nAnsDown = nAnsDown * pnSeq[i + 1] /
			CalcGCD(nAnsDown, pnSeq[i + 1]);
	}

		if (nAnsUp % nAnsDown == 0)
		printf("%ld", nAnsUp / nAnsDown);
	else if (nAnsDown < 0 || nAnsUp < 0)
		printf("-%ld/%ld", abs(nAnsUp / CalcGCD(nAnsDown, nAnsUp)), 
			abs(nAnsDown / CalcGCD(nAnsDown, nAnsUp)));
	else
		printf("%ld/%ld", abs(nAnsUp / CalcGCD(nAnsDown, nAnsUp)),
			abs(nAnsDown / CalcGCD(nAnsDown, nAnsUp)));
Exit0:
	return 0;
}