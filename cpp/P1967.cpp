/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-25 22:20
//	Comment		:	OJ(P1967)
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

struct SEdge
{
	int nU;
	int nV;
	int nCost;
};

bool Cmp(SEdge& sFirst, SEdge& sSecond)
{
	return sFirst.nCost > sSecond.nCost;
}


int Fin(int* pnSet, int nNum)
{
	if (pnSet[nNum] == nNum)
		return pnSet[nNum];
	else
		return pnSet[nNum] =
		Fin(pnSet, pnSet[nNum]);
}

int main(int argc, char* argv[])
{
	int					nN;
	int					nM;
	int					nQ;
	int					nX;
	int					nY;
	int					nFu;
	int					nFv;
	int					nTemp;
	vector<int>			vecTemp;
	SEdge				sTemp;
	int*				pnSet;
	int*				pnAns;
	SEdge*				psEdge;
	set<int>*			pstNum;
	scanf("%d%d", &nN, &nM);
	pstNum = new set<int>[nN + 1];
	pnSet = (int*)malloc((nN + 1) * sizeof(int));
	
	psEdge = (SEdge*)malloc((nM + 1) * sizeof(SEdge));
	for (int i = 1; i <= nN; i++)
		pnSet[i] = i;
	
	for (int i = 0; i < nM; i++)
		scanf("%d%d%d", &psEdge[i].nU, &psEdge[i].nV, &psEdge[i].nCost);

	sort(psEdge, psEdge + nM, Cmp);

	scanf("%d", &nQ);

	for (int i = 0; i < nQ; i++)
	{
		scanf("%d%d", &nX, &nY);
		pstNum[nX].insert(i);
		pstNum[nY].insert(i);
	}
	
	pnAns = (int*)malloc((nQ + 1) * sizeof(int));
	for (int i = 0; i <= nQ; i++)
		pnAns[i] = -1;

	for (int i = 0; i < nM; i++)
	{
		sTemp = psEdge[i];
		nFu = Fin(pnSet, sTemp.nU);
		nFv = Fin(pnSet, sTemp.nV);
		if (nFu == nFv)
			continue;

		if (pstNum[nFu].size() > pstNum[nFv].size())
			swap(nFu, nFv);

		vecTemp.clear();
		for (auto iter = pstNum[nFu].begin();
			iter != pstNum[nFu].end(); iter++)
		{
			nTemp = *iter;
			if (pstNum[nFv].count(nTemp))
			{
				pnAns[nTemp] = sTemp.nCost;
				vecTemp.push_back(nTemp);
			}
			pstNum[nFv].insert(nTemp);
		}

		for (int i = 0; i < vecTemp.size(); i++)
			pstNum[nFv].erase(vecTemp[i]);
		pnSet[nFu] = nFv;
	}

	for (int i = 0; i < nQ; i++)
		printf("%d\n", pnAns[i]);




Exit0:

	return 0;
}