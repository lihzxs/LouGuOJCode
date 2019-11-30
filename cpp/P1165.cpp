/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-2 13:42
//	Comment		:	OJ(P1165)
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
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;



int main(int argc, char* argv[])
{
	int				nInputTemp;
	int				nW;
	int				nInputN;
	stack<int>		sContainer;
	stack<int>		sMax;

	scanf("%d", &nInputN);
	while (nInputN--)
	{
		scanf("%d", &nInputTemp);
		if (nInputTemp == 0)
		{
			scanf("%d", &nW);
			sContainer.push(nW);
			if (sMax.empty() || sMax.top() <= nW)
				sMax.push(nW);
		}
		else if (nInputTemp == 1)
		{
			if (sContainer.top() == sMax.top())
				sMax.pop();
			sContainer.pop();
		}
		else
		{
			if (sMax.empty())
				printf("0\n");
			else
				printf("%d\n", sMax.top());
		}
	}





Exit0:

	return 0;
}