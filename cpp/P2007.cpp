/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-13 16:27
//	Comment		:	OJ(P2007)
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

using namespace std;
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		2e31


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int			nMat[7][4][4];
void Op1()
{
	int			nTempA;
	int			nTempB;
	int			nTempC;

	nTempA = nMat[1][1][3];
	nTempB = nMat[1][2][3];
	nTempC = nMat[1][3][3];

	nMat[1][1][3] = nMat[6][1][3];
	nMat[1][2][3] = nMat[6][2][3];
	nMat[1][3][3] = nMat[6][3][3];

	nMat[6][1][3] = nMat[2][1][3];
	nMat[6][2][3] = nMat[2][2][3];
	nMat[6][3][3] = nMat[2][3][3];

	nMat[2][1][3] = nMat[5][1][3];
	nMat[2][2][3] = nMat[5][2][3];
	nMat[2][3][3] = nMat[5][3][3];

	nMat[5][1][3] = nTempA;
	nMat[5][2][3] = nTempB;
	nMat[5][3][3] = nTempC;

	nTempA = nMat[4][1][1];
	nMat[4][1][1] = nMat[4][3][1];
	nMat[4][3][1] = nMat[4][3][3];
    nMat[4][3][3] = nMat[4][1][3];
	nMat[4][1][3] = nTempA;

	nTempA = nMat[4][1][2];
	nMat[4][1][2] = nMat[4][2][1];
	nMat[4][2][1] = nMat[4][3][2];
	nMat[4][3][2] = nMat[4][2][3];
	nMat[4][2][3] = nTempA;
}
void Op2()
{
	int			nTempA;
	int			nTempB;
	int			nTempC;

	nTempA = nMat[1][1][3];
	nTempB = nMat[1][2][3];
	nTempC = nMat[1][3][3];

	nMat[1][1][3] = nMat[5][1][3];
	nMat[1][2][3] = nMat[5][2][3];
	nMat[1][3][3] = nMat[5][3][3];

	nMat[5][1][3] = nMat[2][1][3];
	nMat[5][2][3] = nMat[2][2][3];
	nMat[5][3][3] = nMat[2][3][3];

	nMat[2][1][3] = nMat[6][1][3];
	nMat[2][2][3] = nMat[6][2][3];
	nMat[2][3][3] = nMat[6][3][3];

	nMat[6][1][3] = nTempA;
	nMat[6][2][3] = nTempB;
	nMat[6][3][3] = nTempC;

	nTempA = nMat[4][1][1];
	nMat[4][1][1] = nMat[4][1][3];
	nMat[4][1][3] = nMat[4][3][3];
	nMat[4][3][3] = nMat[4][3][1];
	nMat[4][3][1] = nTempA;

	nTempA = nMat[4][1][2];
	nMat[4][1][2] = nMat[4][2][3];
	nMat[4][2][3] = nMat[4][3][2];
	nMat[4][3][2] = nMat[4][2][1];
	nMat[4][2][1] = nTempA;
}
void Op3()
{
	int			nTempA;
	int			nTempB;
	int			nTempC;

	nTempA = nMat[1][1][1];
	nTempB = nMat[1][1][2];
	nTempC = nMat[1][1][3];

	nMat[1][1][1] = nMat[3][1][1];
	nMat[1][1][2] = nMat[3][1][2];
	nMat[1][1][3] = nMat[3][1][3];

	nMat[3][1][1] = nMat[2][1][1];
	nMat[3][1][2] = nMat[2][1][2];
	nMat[3][1][3] = nMat[2][1][3];

	nMat[2][1][1] = nMat[4][1][1];
	nMat[2][1][2] = nMat[4][1][2];
	nMat[2][1][3] = nMat[4][1][3];

	nMat[4][1][1] = nTempA;
	nMat[4][1][2] = nTempB;
	nMat[4][1][3] = nTempC;

	nTempA = nMat[5][1][1];
	nMat[5][1][1] = nMat[5][3][1];
	nMat[5][3][1] = nMat[5][3][3];
	nMat[5][3][3] = nMat[5][1][3];
	nMat[5][1][3] = nTempA;

	nTempA = nMat[5][1][2];
	nMat[5][1][2] = nMat[5][2][1];
	nMat[5][2][1] = nMat[5][3][2];
	nMat[5][3][2] = nMat[5][2][3];
	nMat[5][2][3] = nTempA;
}

void Op4()
{
	int			nTempA;
	int			nTempB;
	int			nTempC;

	nTempA = nMat[1][1][1];
	nTempB = nMat[1][1][2];
	nTempC = nMat[1][1][3];

	nMat[1][1][1] = nMat[4][1][1];
	nMat[1][1][2] = nMat[4][1][2];
	nMat[1][1][3] = nMat[4][1][3];

	nMat[4][1][1] = nMat[2][1][1];
	nMat[4][1][2] = nMat[2][1][2];
	nMat[4][1][3] = nMat[2][1][3];

	nMat[2][1][1] = nMat[3][1][1];
	nMat[2][1][2] = nMat[3][1][2];
	nMat[2][1][3] = nMat[3][1][3];

	nMat[3][1][1] = nTempA;
	nMat[3][1][2] = nTempB;
	nMat[3][1][3] = nTempC;

	nTempA = nMat[5][1][1];
	nMat[5][1][1] = nMat[5][1][3];
	nMat[5][1][3] = nMat[5][3][3];
	nMat[5][3][3] = nMat[5][3][1];
	nMat[5][3][1] = nTempA;

	nTempA = nMat[5][1][2];
	nMat[5][1][2] = nMat[5][2][3];
	nMat[5][2][3] = nMat[5][3][2];
	nMat[5][3][2] = nMat[5][2][1];
	nMat[5][2][1] = nTempA;
}


int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false);

	string		szOp;
	string		szTemp;
	cin >> szOp;
	for (int i = 1; i <= 6; i++)
		for (int j = 1; j <= 3; j++)
		{
			cin >> szTemp;
			for (int k = 0; k < 3; k++)
				nMat[i][j][k + 1] = szTemp[k] - '0';
		}
	

	for (int i = 0; i < szOp.length(); i++)
	{
		if (szOp[i] == '1')
			Op1();
		if (szOp[i] == '2')
			Op2();
		if (szOp[i] == '3')
			Op3();
		if (szOp[i] == '4')
			Op4();
	}
	for (int i = 1; i <= 6; i++)
		for (int j = 1; j <= 3; j++)
		{
			for (int k = 1; k <= 3; k++)
				printf("%d", nMat[i][j][k]);
			printf("\n");
		}


Exit0:

	return 0;
}