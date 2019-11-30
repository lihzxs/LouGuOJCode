/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-14 20:01
//	Comment		:	OJ(P5016)
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


int main(int argc, char* argv[])
{
	long long					nInputN;
	long long					nInputM;
	long long					nP1;
	long long				nS1;
	long long					nS2;
	long long*				pnSeq			= NULL;
	long long					nCountA			= 0;
	long long					nCountB			= 0;
	long long		    		nTemp;
	long long					nMin;
	long long					nAns;
	scanf("%lld", &nInputN);

	pnSeq = (long long*)malloc((nInputN + 1) * sizeof(long long));

	for (int i = 1; i <= nInputN; i++)
		scanf("%lld", pnSeq + i);

	scanf("%lld%lld%lld%lld", &nInputM, &nP1, &nS1, &nS2);


	pnSeq[nP1] += nS1;

	for (long long i = 1; i < nInputM; i++)
		nCountA += (nInputM - i) * pnSeq[i];
	for (long long i = nInputM + 1; i <= nInputN; i++)
		nCountB += (i - nInputM) * pnSeq[i];

	nTemp = abs(nCountA - nCountB);
	nMin = nTemp;
	if (nS2 == 0)
		printf("1");
	else if (nTemp == 0)
		printf("%lld", nInputM);
	else if (min(abs(nCountA + nS2 - nCountB), 
		abs(nCountB + nS2 - nCountA)) > nTemp)
		printf("%lld", nInputM);
	else
	{

		if (nCountA < nCountB)
		{
			for (int i = 1; i <= nInputM - 1; i++)
			{
				if (abs(nCountA + (nInputM - i) * nS2 - nCountB) < nMin)
				{
					nMin = abs(nCountA + (nInputM - i) * nS2 - nCountB);
					nAns = i;
				}
			}
		}
		else if (nCountA > nCountB)
		{
			for (int i = nInputM + 1; i <= nInputN; i++)
			{
				if (abs(nCountB + (i - nInputM) * nS2 - nCountA) < nMin)
				{
					nMin = abs(nCountB + (i - nInputM) * nS2 - nCountA);
					nAns = i;
				}
			}
		}

		printf("%lld", nAns);
			
		
	}

Exit0:

	return 0;
}