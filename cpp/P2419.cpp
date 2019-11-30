/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-15 23:47
//	Comment		:	OJ(P1960)
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

int Mat[105][105];
int main(int argc, char* argv[])
{
	int				nN;
	int				nM;
	int				nStart;
	int				nEnd;
	int				nTemp;
	int				nAns = 0;

	scanf("%d%d", &nN, &nM);

	for (int i = 1; i <= nM; i++)
	{
		scanf("%d%d", &nStart, &nEnd);
		Mat[nStart][nEnd] = 1;
	}

	for (int k = 1; k <= nN; k++)
		for (int i = 1; i <= nN; i++)
			for (int j = 1; j <= nN; j++)
			{
				if (i == j || i == k || j == k)
					continue;
				if (Mat[i][k] && Mat[k][j])
					Mat[i][j] = 1;
			}


	for (int i = 1; i <= nN; i++)
	{
		nTemp = 1;
		for (int j = 1; j <= nN; j++)
		{
			if (i == j)
				continue;
			else
				nTemp = (Mat[i][j] || Mat[j][i]);
			if (nTemp == 0)
				break;
		}
		nAns += nTemp;
			
	}

	printf("%d", nAns);



Exit0:
	return 0;
}