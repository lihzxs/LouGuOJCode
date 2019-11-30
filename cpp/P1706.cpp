/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-7 16:02
//	Comment		:	OJ(P1706)
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
#define	MAXNUM		150
#define	EPS         0.0001
#define MODNUM		1000000007ll


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;



void DFS(BOOL* pbFlag, int nNum, int nCount, int* Output)
{
	if (nCount == nNum)
	{
		for (int i = 0; i < nCount; i++)
			printf("%5d", Output[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= nNum; i++)
	{
		if (!pbFlag[i])
		{
			pbFlag[i] = 1;
			Output[nCount] = i;
			DFS(pbFlag, nNum, nCount + 1, Output);
			pbFlag[i] = 0;
		}
	}
}



int main(int argc, char* argv[])
{
	int					nInputN;
	BOOL*				pbFlag				= NULL;
	int*				pnOutput			= NULL;
	scanf("%d", &nInputN);

	pbFlag = (BOOL*)malloc((nInputN + 1) * sizeof(BOOL));
	pnOutput = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pbFlag, 0, (nInputN + 1) * sizeof(BOOL));

	DFS(pbFlag, nInputN, 0, pnOutput);




Exit0:

	return 0;
}