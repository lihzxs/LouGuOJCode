/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-15 14:43
//	Comment		:	OJ(P1581)
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


int main(int argc, char* argv[])
{
	char			cInput;
	int*			pnMod				= NULL;
	string			szInput;
	int				nFlag				= 0;
	int				nCount				= 0;
	int				nTemp;
	int				nPre;
	stack<int>		sNum[3];
	//while (cin >> cInput)
	//{
	//	if (cInput >= '0' && cInput <= '9')
	//		sNum[nFlag].push(cInput - '0');
	//	if (cInput == '+')
	//		nFlag = !nFlag;
	//}

	cin >> szInput;

	for (int i = 0; i < szInput.length(); i++)
	{
		if (szInput[i] >= '0' && szInput[i] <= '9')
		{
			if (szInput[i] == '1' &&
				i + 1 < szInput.length() && szInput[i + 1] == '0')
			{
				sNum[nFlag].push(10);
				i++;
			}
			else
				sNum[nFlag].push(szInput[i] - '0');
		}
		if (szInput[i] == '+')
			nFlag = !nFlag;
	}


	pnMod = (int*)malloc(7 * sizeof(int));

	pnMod[0] = 2;
	pnMod[1] = 3;
	pnMod[2] = 5;
	pnMod[3] = 7;
	pnMod[4] = 11;
	pnMod[5] = 13;
	nPre = 0;
	while (!sNum[0].empty() && !sNum[1].empty())
	{
		nTemp = (sNum[0].top() + sNum[1].top() + nPre);
		sNum[0].pop();
		sNum[1].pop();
		nPre = nTemp / pnMod[nCount];
		sNum[2].push(nTemp % pnMod[nCount]);
		nCount++;
	}
	while (!sNum[0].empty())
	{
		nTemp = (sNum[0].top() + nPre);
		sNum[0].pop();
		nPre = nTemp / pnMod[nCount];
		sNum[2].push(nTemp % pnMod[nCount]);
		nCount++;
	}
	while (!sNum[1].empty())
	{
		nTemp = (sNum[1].top() + nPre);
		sNum[1].pop();
		nPre = nTemp / pnMod[nCount];
		sNum[2].push(nTemp % pnMod[nCount]);
		nCount++;
	}
	while (nPre != 0)
	{
		nTemp = nPre;
		nPre = nTemp / pnMod[nCount];
		sNum[2].push(nTemp % pnMod[nCount]);
		nCount++;
	}

	printf("%d", sNum[2].top());
	sNum[2].pop();
	while (!sNum[2].empty())
	{
		printf(",%d", sNum[2].top());
		sNum[2].pop();
	}


Exit0:

	return 0;
}