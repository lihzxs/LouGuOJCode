/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-16 23:54
//	Comment		:	OJ(P4368)
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
	int						nT;
	long long				llN;
	long long				llM;
	long long				llX;
	long long				llY;
	long long				llA;
	long long				llB;
	long long				llAns;
	long long				pllCount[2][2];
	long long				llTemp;
	scanf("%d", &nT);
	while (nT--)
	{
		scanf("%lld%lld%lld%lld%lld%lld", 
			&llN, &llM, &llX, &llY, &llA, &llB);
		if ((llX - 1) % llA == 0)
			pllCount[0][0] = (llX - 1) / llA;
		else
			pllCount[0][0] = -1;

		if ((llN - llX) % llA == 0)
			pllCount[0][1] = (llN - llX) / llA;
		else
			pllCount[0][1] = -1;

		if ((llY - 1) % llB == 0)
			pllCount[1][0] = (llY - 1) / llB;
		else
			pllCount[1][0] = -1;

		if ((llM - llY) % llB == 0)
			pllCount[1][1] = (llM - llY) / llB;
		else
			pllCount[1][1] = -1;

		llAns = -1;

		for (int i = 0; i <= 1; i++)
			for (int j = 0; j <= 1; j++)
			{
				if (pllCount[0][i] != -1 &&
					pllCount[1][j] != -1 &&
					(pllCount[1][j] - pllCount[0][i]) % 2 == 0)
				{
					llTemp = max(pllCount[1][j], pllCount[0][i]);
					if (llAns == -1 || llAns > llTemp)
						llAns = llTemp;
				}
			}


		printf("%lld\n", llAns);
	}

Exit0:

	return 0;
}