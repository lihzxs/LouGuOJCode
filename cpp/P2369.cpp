/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-18 20:22
//	Comment		:	OJ(P2369)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <stack>
#include <string>
#include <string.h>
#include <set>
#include <queue>

using namespace std;
#define	MAXNUM		3
#define	EPS         0.0001


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	priority_queue<int, vector<int>, less<int> >		pqSeq;
	priority_queue<int, vector<int>, greater<int> >		pqSeqOutput;
	int													nInputN;
	int													nInputM;
	int													nInputTemp;


	scanf("%d%d", &nInputN, &nInputM);
	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", &nInputTemp);
		if (pqSeq.size() < nInputM)
			pqSeq.push(nInputTemp);
		else if (nInputTemp < pqSeq.top())
		{
			pqSeq.pop();
			pqSeq.push(nInputTemp);
		}

	}

	for (int i = 0; i < nInputM && !pqSeq.empty(); i++)
	{
		pqSeqOutput.push(pqSeq.top());
		pqSeq.pop();
	}

	for (int i = 0; i < nInputM; i++)
	{
		cout << pqSeqOutput.top() << endl;
		pqSeqOutput.pop();
	}



Exit0:

	return 0;
}