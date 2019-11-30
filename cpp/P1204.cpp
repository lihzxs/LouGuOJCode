/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-1 21:37
//	Comment		:	OJ(P1204)
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
	int				nInputN;
	bool*			pbFlag				= NULL;
	int				nLeft;
	int				nRight;
	int				nStart				= 10000000;
	int				nEnd				= 0;
	int				nTrueMax			= 0;
	int				nCountTrue			= 0;
	int				nFalseMax			= 0;
	int				nCountFalse			= 0;
	scanf("%d", &nInputN);

	pbFlag = (bool*)malloc(1000001 * sizeof(bool));
	memset(pbFlag, 0, 1000001 * sizeof(bool));

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d", &nLeft, &nRight);
		if (nLeft < nStart)
			nStart = nLeft;
		if (nEnd < nRight)
			nEnd = nRight;
		for (int j = nLeft; j < nRight; j++)
			pbFlag[j] = 1;
	}


	for (int i = nStart; i < nEnd; i++)
	{
		if (pbFlag[i])
		{
			nCountTrue++;
			nCountFalse = 0;
		}
		else
		{
			nCountFalse++;
			nCountTrue = 0;
		}
		if (nTrueMax < nCountTrue)
			nTrueMax = nCountTrue;
		if (nFalseMax < nCountFalse)
			nFalseMax = nCountFalse;

	}


	printf("%d %d", nTrueMax, nFalseMax);


Exit0:

	return 0;
}