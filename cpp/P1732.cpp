/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-14 21:03
//	Comment		:	OJ(P1732)
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
	int				nInputT;
	int				nInputN;
	bool*			pbFlag				= NULL;
	long long		llSum;
	int				nPre;
	int				nTemp;
	scanf("%d", &nInputT);

	pbFlag = (bool*)malloc(66000 * sizeof(bool));
	while (nInputT--)
	{
		llSum = 0;
		memset(pbFlag, 0, 66000 * sizeof(bool));
		scanf("%d", &nInputN);
		scanf("%d", &nTemp);
		nPre = nTemp;
		pbFlag[nPre] = true;
		llSum += nPre;
		for (int i = 1; i < nInputN; i++)
		{
			scanf("%d", &nTemp);
			int j = nTemp;
			int k = nTemp;
			while (j >= 0 || k <= 65536)
			{
				if (pbFlag[j] && j >= 0)
				{
					llSum += nTemp - j;
					break;
				}
				else if (pbFlag[k] && k <= 65536)
				{
					llSum += k - nTemp;
					break;
				}
				j--;
				k++;
			}
			pbFlag[nTemp] = true;
		}
		printf("%lld\n", llSum);
	}


Exit0:

	return 0;
}