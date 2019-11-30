/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-29 23:57
//	Comment		:	OJ(P1403)
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


void DFS(int* pnSeq, BOOL* pbFlag, int nNum, int nM, int nPre, int& nCount, int nStart)
{
	if (nPre >= nM)
	{
		if(nPre == nM)
			nCount++;
		return;
	}
	for (int i = nStart; i < nNum; i++)
	{
		if (!pbFlag[i])
		{
			pbFlag[i] = true;
			DFS(pnSeq, pbFlag, nNum, nM, nPre + pnSeq[i], nCount, i + 1);
			pbFlag[i] = false;
		}
	}
}





int main(int argc, char* argv[])
{
	int				nInputN;
	int				nAns			= 0;
	scanf("%d", &nInputN);

	for (int i = 1; i <= nInputN; i++)
		nAns += nInputN / i;


	printf("%d", nAns);













Exit0:

	return 0;
}