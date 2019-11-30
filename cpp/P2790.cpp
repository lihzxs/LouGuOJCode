/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-7 21:38
//	Comment		:	OJ(P2790)
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

void Find(vector<int>* pvecNum, int nN, int nNum, int& nP, int& nH)
{
	for (nP = 0; nP < nN; nP++)
		for (nH = 0; nH < pvecNum[nP].size(); nH++)
			if (pvecNum[nP][nH] == nNum)
				return;
}

void Clear(vector<int>* pvecNum,int nP, int nH)
{
	int nTemp;
	for (int i = nH + 1; i < pvecNum[nP].size(); i++)
	{
		nTemp = pvecNum[nP][i];
		pvecNum[nTemp].push_back(nTemp);
	}
	pvecNum[nP].resize(nH + 1);
}

void Pile(vector<int>* pvecNum,int nP, int nH, int nP2)
{
	int n = pvecNum[nP].size();
	for (int i = nH; i < pvecNum[nP].size(); i++)
		pvecNum[nP2].push_back(pvecNum[nP][i]);
	pvecNum[nP].resize(nH);
}



int main(int argc, char* argv[])
{
	int					nN;
	vector<int>*		pvecNum;
	string				szInput;
	string				sz2;
	int					nA;
	int					nB;
	scanf("%d", &nN);
	pvecNum = new vector<int>[nN];

	for (int i = 0; i < nN; i++)
		pvecNum[i].push_back(i);


	while (true)
	{
		cin >> szInput;
		if (szInput == "quit")
			break;
		cin >> nA >> sz2 >> nB;
		int nPa = 0;
		int nPb = 0;
		int nHa = 0;
		int nHb = 0;

		if (nA == nB)
			continue;

		Find(pvecNum, nN, nA, nPa, nHa);
		Find(pvecNum, nN, nB, nPb, nHb);
		if (nPa == nPb)
			continue;
		if (sz2 == "onto")
			Clear(pvecNum, nPb, nHb);
		if (szInput == "move")
			Clear(pvecNum, nPa, nHa);

		Pile(pvecNum, nPa, nHa, nPb);

	}

	for (int i = 0; i < nN; i++)
	{
		printf("%d:", i);

		for (int j = 0; j < pvecNum[i].size(); j++)
			printf(" %d", pvecNum[i][j]);
		printf("\n");
	}


Exit0:

	return 0;
}