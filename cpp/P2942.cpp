/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-22 22:35
//	Comment		:	OJ(P2942)
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
#define MODNUM		2e64


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int					nC;
	int					nN;
	int					nA1;
	int					nA2;
	int					nB1;
	int					nB2;
	int					nC1;
	int					nC2;
	long long*			pnFlag			= NULL;
	int					nIndex1			= 1;
	int					nIndex2			= 1;
	long long			llTemp1;
	long long			llTemp2;
	scanf("%d%d", &nC, &nN);

	scanf("%d%d%d", &nA1, &nB1, &nC1);
	scanf("%d%d%d", &nA2, &nB2, &nC2);

	pnFlag = (long long*)malloc((nN + 1) * sizeof(long long));
	memset(pnFlag, 0, (nN + 1) * sizeof(long long));

	pnFlag[1] = nC;

	for (int i = 2; i <= nN; i++)
	{
		llTemp1 = nA1 * pnFlag[nIndex1] / nC1 + nB1;
		llTemp2 = nA2 * pnFlag[nIndex2] / nC2 + nB2;
		if (llTemp1 < llTemp2)
		{
			pnFlag[i] = llTemp1;
			nIndex1++;
 		}
		else if (llTemp1 > llTemp2)
		{
			pnFlag[i] = llTemp2;
			nIndex2++;
		}
		else
		{
			pnFlag[i] = llTemp1;
			nIndex1++;
			nIndex2++;
		}
	}

	printf("%lld", pnFlag[nN]);


Exit0:

	return 0;
}