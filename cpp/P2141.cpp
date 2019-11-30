/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-18 21:50
//	Comment		:	OJ(P2141)
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
#include <map>

using namespace std;
#define	MAXNUM		3
#define	EPS         0.0001
#define MODNUM		1000000007ll


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	set<int>		setSeq;
	map<int, bool>	mapFlag;
	int				nInputN;
	int				nInputTemp;
	int				nAns			= 0;
	scanf("%d", &nInputN);
	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", &nInputTemp);
		setSeq.insert(nInputTemp);
		mapFlag[nInputTemp] = false;
	}

	for (set<int>::iterator iter = setSeq.begin();
		iter != setSeq.end(); iter++)
		for (set<int>::iterator iter2 = setSeq.begin();
			iter2 != setSeq.end(); iter2++)
	{
		if (iter == iter2)
			continue;
		set<int>::iterator iter3 = setSeq.find(*iter + *iter2);
		if (iter3 != setSeq.end() && !mapFlag[*iter3])
		{
			mapFlag[*iter3] = true;
			nAns++;
		}
			
	}

	printf("%d", nAns);

Exit0:

	return 0;
}