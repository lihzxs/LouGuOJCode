/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-20 16:55
//	Comment		:	OJ(P1037)
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


void DFS(char cTemp, int* pnFlag, map<int, vector<int> >& mpChange)
{
	pnFlag[cTemp - '0'] = 1;
	for (int i = 0; i < mpChange[cTemp - '0'].size(); i++)
	{
		if (!pnFlag[mpChange[cTemp - '0'][i]])
			DFS(mpChange[cTemp - '0'][i] + '0', pnFlag, mpChange);
	}

}




int main(int argc, char* argv[])
{

	string				szTemp;
	int					nInputK;
	map<string, bool>	mpFlag;
	map<int, vector<int> >		mpChange;
	int					nCount = 0;
	int					nA;
	int					nB;
	int					nSum;
	int					nTemp;
	int*				pnAns = NULL;
	int*				pnFlag = NULL;

	pnAns = (int*)malloc(100 * sizeof(int));
	memset(pnAns, 0, 100 * sizeof(int));
	pnFlag = (int*)malloc(10 * sizeof(int));
	cin >> szTemp >> nInputK;

	for (int i = 0; i < nInputK; i++)
	{
		scanf("%d%d", &nA, &nB);
		mpChange[nA].push_back(nB);
	}

	pnAns[0] = 1;

	for (int i = 0; i < szTemp.length(); i++)
	{
		memset(pnFlag, 0, 10 * sizeof(int));
		DFS(szTemp[i], pnFlag, mpChange);
		nSum = 0;
		for (int j = 0; j < 10; j++)
			nSum += pnFlag[j];
		nTemp = 0;
		for (int j = 0; j < 100; j++)
		{
			pnAns[j] = pnAns[j] * nSum + nTemp;
			nTemp = pnAns[j] / 10;
			pnAns[j] %= 10;
		}
	}
	int nFlag = 0;
	for (int i = 99; i >= 0; i--)
	{
		if (pnAns[i] != 0)
			nFlag = 1;
		if (nFlag == 0 && pnAns[i] == 0)
			continue;
		printf("%d", pnAns[i]);
	}

	



Exit0:

	return 0;
}