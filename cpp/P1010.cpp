/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-11 20:31
//	Comment		:	OJ(P1010)
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

using namespace std;
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		2000001


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

void Calu(int nNum)
{
	int			nCount = 0;
	stack<int>	sNum;
	while (nNum)
	{
		if (nNum % 2 == 1)
			sNum.push(nCount);
		nNum /= 2;
		nCount++;
	}
	while (!sNum.empty())
	{
		if (sNum.top() == 0)
			printf("2(0)");
		else if (sNum.top() == 1)
			printf("2");
		else if (sNum.top() == 2)
			printf("2(2)");
		else
		{
			printf("2(");
			Calu(sNum.top());
			printf(")");
			
		}
		if (sNum.size() != 1)
			printf("+");
		sNum.pop();
	}



}



int main(int argc, char* argv[])
{
	int						nInputN;
	vector<int>				vecFirst;
	int						nCount			= 0;
	map<int, vector<int>>	nAns;
	scanf("%d", &nInputN);


	Calu(nInputN);







Exit0:

	return 0;
}