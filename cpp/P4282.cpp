/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-4 15:36
//	Comment		:	OJ(P4282)
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
#define	MAXNUM		100000000
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

long long MyPow(long long n, long long m)
{
	long long nAns		= 1;
	for (int i = 0; i < m; i++)
		nAns *= n;
	return nAns;
}




int main(int argc, char* argv[])
{
	int				nInputN;
	int*			pnAdd				= NULL;
	int*			pnItemA				= NULL;
	long long		nA					= 0;
	int*			pnItemB				= NULL;
	long long		nB					= 0;
	long long		nM					= 1;
	long long		nAns				= 0;
	int				nPre				= 0;
	string			szOp;
	int				nPow;

	scanf("%d", &nInputN);
	pnAdd = (int*)malloc(nInputN * sizeof(int));
	pnItemA = (int*)malloc(nInputN * sizeof(int));
	pnItemB = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnAdd + i);

	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnItemA + i);

	cin >> szOp;

	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnItemB + i);


	for (int i = 0; i < nInputN; i++)
		nM *= pnAdd[i];

	if (szOp[0] == '+')
		for (int i = nInputN - 1; i >= 0; i--)
		{
			pnItemA[i] += pnItemB[i] + nPre;
			nPre = pnItemA[i] / pnAdd[i];
			pnItemA[i] = pnItemA[i] % pnAdd[i];
		}
	else
		for (int i = nInputN - 1; i >= 0; i--)
		{
			pnItemA[i] -= pnItemB[i];
			while (pnItemA[i] < 0)
			{
				pnItemA[i - 1]--;
				pnItemA[i] += pnAdd[i];
			}
		}

	for (int i = 0; i < nInputN - 1; i++)
		printf("%d ", pnItemA[i]);
	printf("%d", pnItemA[nInputN - 1]);
	printf("\n");

		




Exit0:
	return 0;
}