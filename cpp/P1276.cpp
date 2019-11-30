/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-27 22:36
//	Comment		:	OJ(P1276)
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






int main(int argc, char* argv[])
{
	int								nInputL;
	int								nInputN;
	int								nFlag;
	int								nRight;
	int								nLeft;
	int								nCount				= 0;
	int								nAns				= 0;
	int*							pnFlag				= NULL;

	scanf("%d%d", &nInputL, &nInputN);
	pnFlag = (int*)malloc((nInputL + 1) * sizeof(int));

	memset(pnFlag, 1, (nInputL + 1) * sizeof(int));

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d%d", &nFlag, &nLeft, &nRight);
		for (int i = nLeft; i <= nRight; i++)
		{
			if (!nFlag)
			{
				if (pnFlag[i] == 2)
					nCount++;
				pnFlag[i] = 0;
			}
			else
				if (pnFlag[i] == 0)
					pnFlag[i] = 2;
		}
	}

	for (int i = 0; i <= nInputL; i++)
		if (pnFlag[i] == 2)
			nAns++;


	printf("%d\n%d\n", nAns, nCount);




Exit0:

	return 0;
}