/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-2 23:04
//	Comment		:	OJ(P1218)
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

int main(int argc, char* argv[])
{
	int					nInputN;
	int**				szOutpt			= NULL;

	scanf("%d", &nInputN);

	szOutpt = (int**)malloc((8 + 1) * sizeof(int*));

	for (int i = 0; i <= 8; i++)
		szOutpt[i] = (int*)malloc(20 * sizeof(int));

	szOutpt[1][0] = 2;
	szOutpt[1][1] = 3;
	szOutpt[1][2] = 5;
	szOutpt[1][3] = 7;
	szOutpt[1][4] = 0;

	szOutpt[2][0] = 23;
	szOutpt[2][1] = 29;
	szOutpt[2][2] = 31;
	szOutpt[2][3] = 37;
	szOutpt[2][4] = 53;
	szOutpt[2][5] = 59;
	szOutpt[2][6] = 71;
	szOutpt[2][7] = 73;
	szOutpt[2][8] = 79;
	szOutpt[2][9] = 0;

	szOutpt[3][0] = 233;
	szOutpt[3][1] = 239;
	szOutpt[3][2] = 293;
	szOutpt[3][3] = 311;
	szOutpt[3][4] = 313;
	szOutpt[3][5] = 317;
	szOutpt[3][6] = 373;
	szOutpt[3][7] = 379;
	szOutpt[3][8] = 593;
	szOutpt[3][9] = 599;
	szOutpt[3][10] = 719;
	szOutpt[3][11] = 733;
	szOutpt[3][12] = 739;
	szOutpt[3][13] = 797;
	szOutpt[3][14] = 0;

	szOutpt[4][0] = 2333;
	szOutpt[4][1] = 2339;
	szOutpt[4][2] = 2393;
	szOutpt[4][3] = 2399;
	szOutpt[4][4] = 2939;
	szOutpt[4][5] = 3119;
	szOutpt[4][6] = 3137;
	szOutpt[4][7] = 3733;
	szOutpt[4][8] = 3739;
	szOutpt[4][9] = 3793;
	szOutpt[4][10] = 3797;
	szOutpt[4][11] = 5939;
	szOutpt[4][12] = 7193;
	szOutpt[4][13] = 7331;
	szOutpt[4][14] = 7333;
	szOutpt[4][15] = 7393;
	szOutpt[4][16] = 0;

	szOutpt[5][0] = 23333;
	szOutpt[5][1] = 23339;
	szOutpt[5][2] = 23399;
	szOutpt[5][3] = 23993;
	szOutpt[5][4] = 29399;
	szOutpt[5][5] = 31193;
	szOutpt[5][6] = 31379;
	szOutpt[5][7] = 37337;
	szOutpt[5][8] = 37339;
	szOutpt[5][9] = 37397;
	szOutpt[5][10] = 59393;
	szOutpt[5][11] = 59399;
	szOutpt[5][12] = 71933;
	szOutpt[5][13] = 73331;
	szOutpt[5][14] = 73939;
	szOutpt[5][15] = 0;

	szOutpt[6][0] = 233993;
	szOutpt[6][1] = 239933;
	szOutpt[6][2] = 293999;
	szOutpt[6][3] = 373379;
	szOutpt[6][4] = 373393;
	szOutpt[6][5] = 593933;
	szOutpt[6][6] = 593993;
	szOutpt[6][7] = 719333;
	szOutpt[6][8] = 739391;
	szOutpt[6][9] = 739393;
	szOutpt[6][10] = 739397;
	szOutpt[6][11] = 739399;
	szOutpt[6][12] = 0;

	szOutpt[7][0] = 2339933;
	szOutpt[7][1] = 2399333;
	szOutpt[7][2] = 2939999;
	szOutpt[7][3] = 3733799;
	szOutpt[7][4] = 5939333;
	szOutpt[7][5] = 7393913;
	szOutpt[7][6] = 7393931;
	szOutpt[7][7] = 7393933;
	szOutpt[7][8] = 0;

	szOutpt[8][0] = 23399339;
	szOutpt[8][1] = 29399999;
	szOutpt[8][2] = 37337999;
	szOutpt[8][3] = 59393339;
	szOutpt[8][4] = 73939133;
	szOutpt[8][5] = 0;


	for (int i = 0; i < 20; i++)
	{
		if (szOutpt[nInputN][i] == 0)
			break;
		printf("%d\n", szOutpt[nInputN][i]);
	}



Exit0:
	return 0;
}