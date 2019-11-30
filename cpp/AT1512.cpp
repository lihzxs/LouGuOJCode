
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

int pnCount[100005];

int main(int argc, char* argv[])
{
	int			nInputN;
	int			nInputM;
	int			nTemp;

	scanf("%d%d", &nInputN, &nInputM);
	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d", &nTemp);
		pnCount[nTemp]++;
		if (pnCount[nTemp] > nInputN / 2)
		{
			printf("%d\n", nTemp);
			return 0;
		}
	}
	printf("?\n");
Exit0:

	return 0;
}