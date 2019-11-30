/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-25 22:14
//	Comment		:	OJ(P4346)
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



int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false);
	string			szLine[12];
	string			szInput[9];
	string			szTemp;
	int*			pnNum;
	int				nCount				= 0;
	pnNum = (int*)malloc(20 * sizeof(int));
	szLine[0] = "xxxxx.x...x.x...x.x...x.x...x.x...x.xxxxx.";
	szLine[1] = "....x.....x.....x.....x.....x.....x.....x.";
	szLine[2] = "xxxxx.....x.....x.xxxxx.x.....x.....xxxxx.";
	szLine[3] = "xxxxx.....x.....x.xxxxx.....x.....x.xxxxx.";
	szLine[4] = "x...x.x...x.x...x.xxxxx.....x.....x.....x.";
	szLine[5] = "xxxxx.x.....x.....xxxxx.....x.....x.xxxxx.";
	szLine[6] = "xxxxx.x.....x.....xxxxx.x...x.x...x.xxxxx.";
	szLine[7] = "xxxxx.....x.....x.....x.....x.....x.....x.";
	szLine[8] = "xxxxx.x...x.x...x.xxxxx.x...x.x...x.xxxxx.";
	szLine[9] = "xxxxx.x...x.x...x.xxxxx.....x.....x.xxxxx.";
	szLine[10] = "........x.....x...xxxxx...x.....x.........";

	for (int i = 0; i < 7; i++)
	{
		cin >> szInput[i];
		szInput[i] += ".";
	}
		



	for (int i = 0; i < szInput[0].length(); i += 6)
	{
		szTemp = "";
		
		for (int j = 0; j < 7; j++)
			szTemp += szInput[j].substr(i, 6);
		for (int j = 0; j <= 10; j++)
			if (szTemp == szLine[j])
			{
				pnNum[nCount++] = j;
				break;
			}

	}
	stack<int> sNum[2];
	int			nFlag	= 0;			
	for (int i = 0; i < nCount; i++)
	{
		if (pnNum[i] == 10)
			nFlag = !nFlag;
		else
			sNum[nFlag].push(pnNum[i]);
	}

	stack<int>			sAns;
	int					nPre			= 0;
	int					nTemp;
	while (!sNum[0].empty() && !sNum[1].empty())
	{
		nTemp = sNum[0].top() + sNum[1].top() + nPre;
		sNum[0].pop();
		sNum[1].pop();
		sAns.push(nTemp % 10);
		nPre = nTemp / 10;
	}

	while (!sNum[0].empty())
	{
		nTemp = sNum[0].top() + nPre;
		sNum[0].pop();
		sAns.push(nTemp % 10);
		nPre = nTemp / 10;
	}
	while (!sNum[1].empty())
	{
		nTemp = sNum[1].top() + nPre;
		sNum[1].pop();
		sAns.push(nTemp % 10);
		nPre = nTemp / 10;
	}

	if (nPre)
		sAns.push(nPre);

	nCount = 0;
	while (!sAns.empty())
	{
		pnNum[nCount++] = sAns.top();
		sAns.pop();
	}

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < nCount; j++)
		{
			cout << szLine[pnNum[j]].substr(i * 6, 5);
			if (j != nCount - 1)
				cout << ".";
		}	
		cout << endl;
	}
		

Exit0:

	return 0;
}