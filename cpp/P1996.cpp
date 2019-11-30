/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-20 15:52
//	Comment		:	OJ(P1996)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <stack>
#include <set>
#include <list>
#include <string>
#include <string.h>
using namespace std;
#define	MAXNUM		20000
#define	EPS         0.0001
#define DIRNUM		4
#define ERROR_ID    0

typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;




int main(int argc, char* argv[])
{
	int							nInputN;
	int							nInputM;
	int							nCount			= 0;
	list<int>					lsNum;
	list<int>::iterator			iter;


	scanf("%d%d", &nInputN, &nInputM);

	for (int i = 0; i < nInputN; i++)
		lsNum.push_back(i + 1);


	iter = lsNum.begin();
	while (!lsNum.empty())
	{
		nCount++;
		if (nCount == nInputM)
		{
			nCount = 0;
			printf("%d ", *iter);
			iter = lsNum.erase(iter);
		}
		else
			++iter;
		if (iter == lsNum.end())
			iter = lsNum.begin();
	}

	



	

Exit0:

	return 0;
}

