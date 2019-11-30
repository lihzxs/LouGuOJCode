/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-24 15:08
//	Comment		:	OJ(P2026)
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


int CalcGCD(int a, int b)
{
	if (a%b == 0)
		return b;
	return CalcGCD(b, a%b);
}



int main(int argc, char* argv[])
{
	int				nInputX1;
	int				nInputY1;
	int				nInputX2;
	int				nInputY2;
	int				nKUp;
	int				nKDown;
	int				nCUp;
	int				nCDown;
	int				nTemp;
	double			nAnsK;
	double			nAnsC;
	string			szOutput			= "y=";

	scanf("%d%d%d%d", &nInputX1, &nInputY1, &nInputX2, &nInputY2);
	if (nInputX1 == nInputX2)
	{
		printf("x=%d\n", nInputX1);
		return 0;
	}
	else if (nInputY1 == nInputY2)
	{
		printf("y=%d\n", nInputY1);
		return 0;
	}
		

	nKUp = nInputY1 - nInputY2;
	nKDown = nInputX1 - nInputX2;

	nTemp = nKUp;
	nKUp /= CalcGCD(nKDown, nKUp);
	nKDown /= CalcGCD(nKDown, nTemp);

	nCUp = nInputX1 * nInputY2 - nInputY1 * nInputX2;
	nCDown = nInputX1 - nInputX2;

	nCDown /= CalcGCD(nCUp, nCDown);
	nCUp /= CalcGCD(nCUp, nCDown);

	if (nKDown < 0 && nKUp < 0)
	{
		nKDown = -nKDown;
		nKUp = -nKUp;
	}
		

	if (nKDown < 0 || nKUp < 0)
	{
		if (abs(nKDown) == 1)
			szOutput += "-" + to_string(abs(nKUp));
		else
			szOutput += "-" + to_string(abs(nKUp)) + "/" + to_string(abs(nKDown)) + "*";
	}
	else
	{
		if (abs(nKDown) == 1)
			szOutput += to_string(abs(nKUp));
		else
			szOutput += to_string(nKUp) + "/" + to_string(nKDown) + "*";
	}
	szOutput += "x";
	if (nCUp < 0 && nCDown < 0)
	{
		nCUp = -nCUp;
		nCDown = -nCDown;
	}

	if (nCUp == 0)
	{
		cout << szOutput << endl;
		return 0;
	}
		
	if (nCUp < 0 || nCDown < 0)
	{
		if (abs(nCDown) == 1)
			szOutput += "-" + to_string(abs(nCUp));
		else
			szOutput += "-" + to_string(abs(nCUp)) + "/" + to_string(abs(nCDown));
	}
	else
	{
		if (abs(nCDown) == 1)
			szOutput += "+" + to_string(abs(nCUp));
		else
			szOutput += "+" + to_string(nCUp) + "/" + to_string(nCDown);
	}

	cout << szOutput << endl;

	









			

Exit0:

	return 0;
}