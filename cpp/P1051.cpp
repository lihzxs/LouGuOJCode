/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-21 16:48
//	Comment		:	OJ(P1051)
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

typedef struct SStuInfo
{
	string		szName;
	int			nStuScore;
	int			nClaScore;
	BOOL		IsLeader;
	BOOL		IsWest;
	int			nPaperNum;
	int			nSum;
}SStuInfo;



int main(int argc, char* argv[])
{
	string				szInputTemp;
	int					nInputN;
	int					nSum				= 0;
	int					nMax				= 0;
	int					nIndex				= 0;
	SStuInfo*			psStuInfo			= NULL;

	scanf("%d", &nInputN);

	psStuInfo = new SStuInfo[nInputN];

	for (int i = 0; i < nInputN; i++)
	{
		psStuInfo[i].nSum = 0;
		cin >> psStuInfo[i].szName;
		scanf("%d%d", &psStuInfo[i].nStuScore, &psStuInfo[i].nClaScore);
		cin >> szInputTemp;
		if (szInputTemp[0] == 'Y')
			psStuInfo[i].IsLeader = true;
		else
			psStuInfo[i].IsLeader = false;
		cin >> szInputTemp;
		if (szInputTemp[0] == 'Y')
			psStuInfo[i].IsWest = true;
		else
			psStuInfo[i].IsWest = false;
		scanf("%d", &psStuInfo[i].nPaperNum);

		if (psStuInfo[i].nStuScore > 80 && psStuInfo[i].nPaperNum >= 1)
			psStuInfo[i].nSum += 8000;
		if (psStuInfo[i].nStuScore > 85 && psStuInfo[i].nClaScore > 80)
			psStuInfo[i].nSum += 4000;
		if (psStuInfo[i].nStuScore > 90)
			psStuInfo[i].nSum += 2000;
		if (psStuInfo[i].nStuScore > 85 && psStuInfo[i].IsWest)
			psStuInfo[i].nSum += 1000;
		if (psStuInfo[i].nClaScore > 80 && psStuInfo[i].IsLeader)
			psStuInfo[i].nSum += 850;

		nSum += psStuInfo[i].nSum;
	}

	for (int i = 0; i < nInputN; i++)
	{
		if (psStuInfo[i].nSum > nMax)
		{
			nMax = psStuInfo[i].nSum;
			nIndex = i;
		}
	}

	cout << psStuInfo[nIndex].szName << endl;
	cout << psStuInfo[nIndex].nSum << endl;
	cout << nSum << endl;







Exit0:

	return 0;
}