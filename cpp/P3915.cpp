/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-11 22:41
//	Comment		:	OJ(P3915)
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

int DFS(vector<int>* pvecNode, int nNowP, int nLastP, int nK)
{
	int nSum = 1;
	for (int i = 0; i < pvecNode[nNowP].size(); i++)
	{
		if (pvecNode[nNowP][i] == nLastP)
			continue;
		int nTemp = DFS(pvecNode, pvecNode[nNowP][i], nNowP, nK);
		if (nTemp == -1 || nTemp > nK)
			return -1;
		else if (nTemp == nK)
			continue;
		nSum += nTemp;
	}
	return nSum;
}



int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputT;
	int				nInputK;
	int				nPA;
	int				nPB;
	int				nAns;
	vector<int>*	pvecNode;

	pvecNode = new vector<int>[100005];
	scanf("%d", &nInputT);
	while (nInputT--)
	{
		scanf("%d%d", &nInputN, &nInputK);
		for (int i = 1; i <= nInputN; i++)
			pvecNode[i].clear();
		for (int i = 1; i < nInputN; i++)
		{
			scanf("%d%d", &nPA, &nPB);
			pvecNode[nPA].push_back(nPB);
			pvecNode[nPB].push_back(nPA);
		}
		nAns = DFS(pvecNode, 1, 1, nInputK);
		if (nAns == nInputK)
			printf("YES\n");
		else
			printf("NO\n");
	}


Exit0:

	return 0;
}