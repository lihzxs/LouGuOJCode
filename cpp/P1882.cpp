/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-22 09:59
//	Comment		:	OJ(P1882)
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
#define MODNUM		2e64


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int			nInputN;
	int			nM;
	int			nTemp;
	priority_queue<pair<int, int>,
		vector<pair<int, int> >,
		greater<pair<int, int> > > q;
	vector<int>* pvecSeq;
	int*		pnL;
	int*		pnFlag;
	pair<int, int> prTemp;
	scanf("%d", &nInputN);
	pvecSeq = new vector<int>[nInputN + 1];
	pnL = (int*)malloc((nInputN + 1) * sizeof(int));
	pnFlag = (int*)malloc((nInputN + 1) * sizeof(int));
	memset(pnFlag, 0, (nInputN + 1) * sizeof(int));

	for (int i = 1; i <= nInputN; i++)
	{
		scanf("%d", pnL + i);
		scanf("%d", &nM);
		while (nM--)
		{
			scanf("%d", &nTemp);
			pvecSeq[i].push_back(nTemp);
		}
	}

	pnFlag[1] = 1;
	q.push({ pnL[1], 1 });

	nTemp = nInputN - 1;
	while (nTemp--)
	{
		prTemp = q.top();
		q.pop();
		for (int i = 0; i < pvecSeq[prTemp.second].size(); i++)
			if (!pnFlag[pvecSeq[prTemp.second][i]])
			{
				pnFlag[pvecSeq[prTemp.second][i]] = 1;
				q.push({ prTemp.first + pnL[pvecSeq[prTemp.second][i]],
					pvecSeq[prTemp.second][i] });
			}
	}

	printf("%d", q.top().first);
Exit0:

	return 0;
}