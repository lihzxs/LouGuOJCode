/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-9 22:31
//	Comment		:	OJ(P1588)
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
	int					nInputT;
	int					nF;
	int					nC;
	int*				mpFlag;
	queue<int>			qBFS;
	int					nCount;
	int					nTemp;
	int					nQsize;
	scanf("%d", &nInputT);
	mpFlag = (int*)malloc(100005 * sizeof(int));
Start:
	while (nInputT--)
	{

		while (!qBFS.empty())
			qBFS.pop();
		memset(mpFlag, 0, 100005 * sizeof(int));
		nCount = 0;
		scanf("%d%d", &nF, &nC);

		mpFlag[nF] = 1;
		qBFS.push(nF);
		while (!qBFS.empty())
		{
			nQsize = qBFS.size();
			nCount++;
			while (nQsize--)
			{
				nTemp = qBFS.front();
				if (nTemp == nC)
				{
					printf("%d\n", nCount - 1);
					goto Start;
				}
				qBFS.pop();
				if (nTemp < 0 || nTemp > 100005)
					continue;
				if (nTemp - 1 >= 0 && !mpFlag[nTemp - 1])
				{
					qBFS.push(nTemp - 1);
					mpFlag[nTemp - 1] = 1;
				}
				if (nTemp + 1 <= 100000 && !mpFlag[nTemp + 1])
				{
					qBFS.push(nTemp + 1);
					mpFlag[nTemp + 1] = 1;
				}
				if (2 * nTemp <= 100000 && !mpFlag[2 * nTemp])
				{
					qBFS.push(2 * nTemp);
					mpFlag[2 * nTemp] = 1;
				}
			}
		}


	}




Exit0:

	return 0;
}