/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-23 23:45
//	Comment		:	OJ(P2665)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <list>
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

	int				nInputN;
	int				pnX[205];
	int				pnY[205];
	int				nAns			= 0;
	double			fTemp;
	vector<double>	lsK;
	scanf("%d", &nInputN);

	for (int i = 0; i < nInputN; i++)
		scanf("%d%d", pnX + i, pnY + i);

	for (int i = 0; i < nInputN; i++)
		for (int j = i + 1; j < nInputN; j++)
		{
			if (pnX[i] == pnX[j])
				lsK.push_back(0.0);
			else if (pnY[i] == pnY[j])
				lsK.push_back(1000000.0);
			else
				lsK.push_back((pnX[i] - pnX[j]) * 1.0 / (pnY[i] - pnY[j]));
		}

	sort(lsK.begin(), lsK.end());

	for (int i = 1; i < lsK.size(); i++)
		if (lsK[i] - lsK[i - 1] > 1e-12)
			nAns++;

	printf("%d", nAns + 1);

Exit0:

	return 0;
}