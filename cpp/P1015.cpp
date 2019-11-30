/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-13 23:09
//	Comment		:	OJ(P1015)
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
#include <list>
#include <float.h>

using namespace std;
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int Add(int* pnAns, int nM, stack<int>& sA, stack<int>& sB)
{
	stack<int>		sTemp;
	int				nPre		= 0;
	int				nTemp;
	while (!sA.empty() && !sB.empty())
	{
		nTemp = sA.top() + sB.top() + nPre;
		nPre = nTemp / nM;
		sTemp.push(nTemp % nM);
		sA.pop();
		sB.pop();
	}
	if (nPre > 0)
		sTemp.push(nPre);

	nTemp = sTemp.size();
	for (int i = 0; i < nTemp; i++)
	{
		pnAns[i] = sTemp.top();
		sTemp.pop();
	}
	return nTemp;

}

bool IsPalindrome(int* pnAns, int nCount)
{
	int i = 0;
	int j = nCount - 1;
	while (i < j)
	{
		if (pnAns[i] != pnAns[j])
			return false;
		i++;
		j--;
	}
	return true;
}

int main(int argc, char* argv[])
{
	int				nInputN;
	string			szInputM;
	stack<int>		sA;
	stack<int>		sB;
	int*			pnAns;
	int				nCount;
	int				nStep					= 0;
	pnAns = (int*)malloc(10000 * sizeof(int));

	cin >> nInputN >> szInputM;
	nCount = szInputM.length();
	for (int i = 0; i < szInputM.length(); i++)
	{
		if (szInputM[i] == 'A')
			pnAns[i] = 10;
		else if (szInputM[i] == 'B')
			pnAns[i] = 11;
		else if (szInputM[i] == 'C')
			pnAns[i] = 12;
		else if (szInputM[i] == 'D')
			pnAns[i] = 13;
		else if (szInputM[i] == 'E')
			pnAns[i] = 14;
		else if (szInputM[i] == 'F')
			pnAns[i] = 15;
		else
			pnAns[i] = szInputM[i] - '0';
	}

	while (!IsPalindrome(pnAns, nCount))
	{
		nStep++;
		if (nStep > 30)
			break;
		for (int i = nCount - 1; i >= 0; i--)
			sA.push(pnAns[i]);
		for (int i = 0; i < nCount; i++)
			sB.push(pnAns[i]);

		nCount = Add(pnAns, nInputN, sA, sB);
	}


	if (nStep > 30)
		printf("Impossible!");
	else
		printf("STEP=%d", nStep);
	




Exit0:

	return 0;
}