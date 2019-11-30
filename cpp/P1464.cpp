/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-3 19:48
//	Comment		:	OJ(P1464)
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
#define	MAXNUM		100000000
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

long long			nMat[21][21][21];

long long fun(int a, int b, int c)
{
	
	if (a <= 0 || b <= 0 || c <= 0)
	{
	    a = 0; b = 0; c = 0;
		return nMat[a][b][c] = 1;
	}
	else if (a > 20 || b > 20 || c > 20)
	{
	    a = 20; b = 20; c = 20;
		return nMat[a][b][c] = fun(20, 20, 20);
	}
	else if (nMat[a][b][c] != -1)
		return nMat[a][b][c];
	else if (a < b && b < c)
	{
		nMat[a][b][c - 1] = fun(a, b, c - 1);
		nMat[a][b - 1][c - 1] = fun(a, b - 1, c - 1);
		nMat[a][b - 1][c] = fun(a, b - 1, c);


		return nMat[a][b][c] = nMat[a][b][c - 1] + 
			nMat[a][b - 1][c - 1] - nMat[a][b - 1][c];
	}
	else
	{
		nMat[a - 1][b][c] = fun(a - 1, b, c);
		nMat[a - 1][b - 1][c] = fun(a - 1, b - 1, c);
		nMat[a - 1][b][c - 1] = fun(a - 1, b, c - 1);
		nMat[a - 1][b - 1][c - 1] = fun(a - 1, b - 1, c - 1);

		return nMat[a][b][c] = nMat[a - 1][b][c] + nMat[a - 1][b - 1][c] + 
			nMat[a - 1][b][c - 1] - nMat[a - 1][b - 1][c - 1];
	}
}



int main(int argc, char* argv[])
{
	for (int i = 0; i < 21; i++)
		for (int j = 0; j < 21; j++)
			for (int k = 0; k < 21; k++)
				nMat[i][j][k] = -1;
	

	int				nInputA  = 15;
	int				nInputB  = 15;
	int				nInputC  = 15;
	fun(nInputA, nInputB, nInputC);
	while (true)
	{
		scanf("%d%d%d", &nInputA, &nInputB, &nInputC);
		if (nInputA == -1 && nInputB == -1 && nInputC == -1)
			break;
		printf("w(%d, %d, %d) = %lld\n", 
			nInputA, nInputB, nInputC,fun(nInputA, nInputB, nInputC));
	}



Exit0:
	return 0;
}