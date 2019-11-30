/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-3 15:46
//	Comment		:	OJ(P2142)
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


int main(int argc, char* argv[])
{
	string			szNum1;
	string			szNum2;
	int				nPre			 = 0;
	stack<int>		sNum1;
	stack<int>		sNum2;
	stack<int>		sOutput;
	int				nZeroFlag;
	int				nTemp;
	cin >> szNum1 >> szNum2;
	
	nZeroFlag = true;
	for (int i = 0; i < szNum1.length(); i++)
	{
		if (nZeroFlag && szNum1[i] - '0' == 0)
			continue;
		if (szNum1[i] - '0' >= 0)
		{
			sNum1.push(szNum1[i] - '0');
			nZeroFlag = false;
		}
	}
		
	nZeroFlag = true;
	for (int i = 0; i < szNum2.length(); i++)
	{
		if (nZeroFlag && szNum2[i] - '0' == 0)
			continue;
		if (szNum2[i] - '0' >= 0)
		{
			sNum2.push(szNum2[i] - '0');
			nZeroFlag = false;
		}
	}
	if (sNum1.size() == 0)
		sNum1.push(0);
	if (sNum2.size() == 0)
		sNum2.push(0);


	if (sNum1.size() < sNum2.size())
	{
		printf("-");
		swap(sNum1, sNum2);
	}
		



	while (!sNum1.empty() && !sNum2.empty())
	{
		if (sNum1.top() + nPre < sNum2.top())
		{
			nPre = 10 + sNum1.top() + nPre - sNum2.top();
			nTemp = -1;
		}
		else
		{
			nPre = sNum1.top() + nPre - sNum2.top();
			nTemp = 0;
		}
		sOutput.push(abs(nPre));
		sNum1.pop();
		sNum2.pop();
		nPre = nTemp;
	}

	while (!sNum1.empty())
	{
		if (sNum1.top() + nPre < 0)
		{
			nPre = 10 + sNum1.top() + nPre;
			nTemp = -1;
		}
		else
		{
			nPre = sNum1.top() + nPre;
			nTemp = 0;
		}
		sOutput.push(abs(nPre));
		sNum1.pop();
		nPre = nTemp;
	}
	if (nPre < 0)
		printf("-");

	while (sOutput.top() == 0 && sOutput.size() > 1)
		sOutput.pop();
	if (sOutput.empty())
		printf("0");
	while (!sOutput.empty())
	{
		printf("%d", sOutput.top());
		sOutput.pop();
	}

Exit0:
	return 0;
}