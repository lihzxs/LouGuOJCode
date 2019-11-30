/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-18 16:42
//	Comment		:	OJ(P2089)
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
using namespace std;
#define	MAXNUM		3
#define	EPS         0.0001

typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int				nInputN;
	int				nCount			= 0;
	
	scanf("%d", &nInputN);

	if (nInputN < 10)
	{
		printf("0\n");
		return 0;
	}

	for (int i = 1; i <= MAXNUM; i++)
		for (int j = 1; j <= MAXNUM; j++)
			for (int k = 1; k <= MAXNUM; k++)
				for (int l = 1; l <= MAXNUM; l++)
					for (int n = 1; n <= MAXNUM; n++)
						for (int m = 1; m <= MAXNUM; m++)
							for (int o = 1; o <= MAXNUM; o++)
								for (int q = 1; q <= MAXNUM; q++)
									for (int r = 1; r <= MAXNUM; r++)
										for (int s = 1; s <= MAXNUM; s++)
											if (i + j + k + l + n + m + o + q + r + s == nInputN)
												nCount++;
	printf("%d\n", nCount);

	for (int i = 1; i <= MAXNUM; i++)
		for (int j = 1; j <= MAXNUM; j++)
			for (int k = 1; k <= MAXNUM; k++)
				for (int l = 1; l <= MAXNUM; l++)
					for (int n = 1; n <= MAXNUM; n++)
						for (int m = 1; m <= MAXNUM; m++)
							for (int o = 1; o <= MAXNUM; o++)
								for (int q = 1; q <= MAXNUM; q++)
									for (int r = 1; r <= MAXNUM; r++)
										for (int s = 1; s <= MAXNUM; s++)
											if (i + j + k + l + n + m + o + q + r + s == nInputN)
												if (i + j + k + l + n + m + o + q + r + s == nInputN)
													printf("%d %d %d %d %d %d %d %d %d %d\n",
														i, j, k, l, n, m, o, q, r, s);


Exit0:

	return 0;
}