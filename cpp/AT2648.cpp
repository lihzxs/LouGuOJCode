
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
#include <list>
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
	int				nN;
	int				nA;
	deque<int>		q;
	scanf("%d", &nN);

	for (int i = 1; i <= nN; i++)
	{
		scanf("%d", &nA);
		if (i & 1)
			q.push_back(nA);
		else
			q.push_front(nA);
	}
	if (nN & 1)
		reverse(q.begin(), q.end());
	for (auto iter = q.begin(); iter != q.end(); iter++)
		cout << *iter << " ";
	printf("\n");
Exit0:

	return 0;
}