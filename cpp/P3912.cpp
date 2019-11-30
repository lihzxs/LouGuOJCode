/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-15 00:50
//	Comment		:	OJ(P3912)
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

	bool*	pbIsPrime = NULL;
	int		nInputN;
	int		nAns;

	scanf("%d", &nInputN);
	pbIsPrime = (bool*)malloc((nInputN + 1) * sizeof(bool));
	memset(pbIsPrime, 0, (nInputN + 1) * sizeof(bool));

	nAns = nInputN - 1;

	for (int i = 2; i * i <= nInputN; i++)
	{
		if (!pbIsPrime[i])
		{
			for (int j = i * 2; j <= nInputN; j += i)
			{
				if (!pbIsPrime[j])
				{
					pbIsPrime[j] = 1;
					nAns--;
				}
			}
		}
	}
	printf("%d", nAns);
Exit0:
	return 0;
}