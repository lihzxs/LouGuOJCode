
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
	int			nN;
	char		cTemp;
	int			nAns = 0;
	cin >> nN;
	for (int i = 1; i <= nN; i++)
	{
		cin >> cTemp;
		if (cTemp == 'A')
			nAns += 4;
		if (cTemp == 'B')
			nAns += 3;
		if (cTemp == 'C')
			nAns += 2;
		if (cTemp == 'D')
			nAns += 1;

	}

	if (nAns)
		printf("%.14f", nAns * 1.0 / nN);
	else
		printf("0");
		
	printf("\n");


Exit0:
	return 0;
}