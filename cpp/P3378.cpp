/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-8 23:41
//	Comment		:	OJ(P3378)
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
#define	MAXNUM		150
#define	EPS         0.0001
#define MODNUM		1006


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;




int main(int argc, char* argv[])
{
	priority_queue< int, vector<int>, greater<int> >			qC;
	int										nInputN;
	int										nTemp;

	scanf("%d", &nInputN);
	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", &nTemp);
		if (nTemp == 1)
		{
			scanf("%d", &nTemp);
			qC.push(nTemp);
		}
		else if (nTemp == 2)
		{
			cout << qC.top() << endl;
		}
		else
		{
			qC.pop();
		}

	}


Exit0:

	return 0;
}