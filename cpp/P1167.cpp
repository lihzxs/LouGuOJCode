/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-10 14:58
//	Comment		:	OJ(P1167)
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





int main(int argc, char* argv[])
{
	int				nInputN;
	int				nAns				= 0;
	int*			pnTime				= NULL;
	int				pnStrat[6];
	int				pnEnd[6];
	int				pnDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,31,30 };
	long long		llM					= 0;
	scanf("%d", &nInputN);
	pnTime = (int*)malloc(nInputN * sizeof(int));

	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnTime + i);
	sort(pnTime, pnTime + nInputN);

	scanf("%d-%d-%d-%d:%d", &pnStrat[1], &pnStrat[2], &pnStrat[3], &pnStrat[4], &pnStrat[5]);
	scanf("%d-%d-%d-%d:%d", &pnEnd[1], &pnEnd[2], &pnEnd[3], &pnEnd[4], &pnEnd[5]);

	for (int i = pnStrat[1]; i < pnEnd[1]; i++)
	{
		if (i % 4 == 0 || (i % 100 == 0 && i % 400 == 0))
			llM -= 366;
		else
			llM -= 365;
	}

	for (int i = 1; i < pnStrat[2]; i++)
		llM += pnDay[i];
	for (int i = 1; i < pnEnd[2]; i++)
		llM -= pnDay[i];

	if (pnStrat[1] % 4 == 0 || (pnStrat[1] % 100 == 0 && pnStrat[1] % 400 == 0))
		if (pnStrat[2] > 2)
			llM++;
	if (pnEnd[1] % 4 == 0 || (pnEnd[1] % 100 == 0 && pnEnd[1] % 400 == 0))
		if (pnEnd[2] > 2)
			llM--;
	llM += pnStrat[3];
	llM -= pnEnd[3];
	llM *= 1440;

	llM += 60 * pnStrat[4] + pnStrat[5];
	llM -= 60 * pnEnd[4] + pnEnd[5];
	llM *= -1;

	for (int i = 0; i < nInputN; i++)
		if (llM >= pnTime[i])
		{
			llM -= pnTime[i];
			nAns++;
		}
		else
			break;

	printf("%d", nAns);
			


Exit0:
	return 0;
}