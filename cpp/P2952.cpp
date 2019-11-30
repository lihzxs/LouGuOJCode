/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-25 22:35
//	Comment		:	OJ(P2952)
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
#include <list>
#include <map>

using namespace std;
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;




int main(int argc, char* argv[])
{
	int					nInputN;
	int					nInputK;
	list<int>			qCow;
	string				szInput;
	int					nCount			= 1;
	szInput.resize(20);
	scanf("%d", &nInputN);
	for (int i = 1; i <= nInputN; i++)
	{
		scanf("%s", &szInput[0]);
		if (szInput[0] == 'A')
		{
			scanf("%s", &szInput[0]);
			if (szInput[0] == 'L')
				qCow.push_front(nCount);
			else
				qCow.push_back(nCount);

			nCount++;
		}
		else
		{
			scanf("%s", &szInput[0]);
			if (szInput[0] == 'L')
			{
				scanf("%d", &nInputK);
				for (int j = 0; j < nInputK; j++)
					qCow.pop_front();
			}
			else
			{
				scanf("%d", &nInputK);
				for (int j = 0; j < nInputK; j++)
					qCow.pop_back();
			}
		}
	}

	for (list<int>::iterator iter = qCow.begin();
		iter != qCow.end(); iter++)
	{
		printf("%d\n", *iter);
	}
		





		


Exit0:

	return 0;
}