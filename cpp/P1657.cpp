/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-3 21:04
//	Comment		:	OJ(P1657)
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


void DFS(int** ppnLikeBook, BOOL* pbIsChoose, 
	int nNum, int& nCount, int nNowX)
{
	if (nNum == nNowX)
	{
		nCount++;
		return;
	}
	if (!pbIsChoose[ppnLikeBook[nNowX][0]])
	{
		pbIsChoose[ppnLikeBook[nNowX][0]] = 1;
		DFS(ppnLikeBook, pbIsChoose, nNum, nCount, nNowX + 1);
		pbIsChoose[ppnLikeBook[nNowX][0]] = 0;
	}
	if (!pbIsChoose[ppnLikeBook[nNowX][1]])
	{
		pbIsChoose[ppnLikeBook[nNowX][1]] = 1;
		DFS(ppnLikeBook, pbIsChoose, nNum, nCount, nNowX + 1);
		pbIsChoose[ppnLikeBook[nNowX][1]] = 0;
	}
}




int main(int argc, char* argv[])
{
	int**			ppnLikeBook				= NULL;
	int				nInputN;
	BOOL*			pbIsChoose				= NULL;
	int				nAns					= 0;

	scanf("%d", &nInputN);

	ppnLikeBook = (int**)malloc(nInputN * sizeof(int*));
	for (int i = 0; i < nInputN; i++)
		ppnLikeBook[i] = (int*)malloc(2 * sizeof(int));

	pbIsChoose = (BOOL*)malloc((nInputN + 1) * sizeof(BOOL));
	memset(pbIsChoose, 0, (nInputN + 1) * sizeof(BOOL));

	for (int i = 0; i < nInputN; i++)
		scanf("%d%d", &ppnLikeBook[i][0], &ppnLikeBook[i][1]);


	DFS(ppnLikeBook, pbIsChoose, nInputN, nAns, 0);
	if (nInputN == 0)
		nAns = 0;
	printf("%d", nAns);

Exit0:
	return 0;
}