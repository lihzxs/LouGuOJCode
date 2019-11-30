/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-30 19:45
//	Comment		:	OJ(P1143)
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

int CalcGCD(int a, int b)
{
	if (a%b == 0)
		return b;
	return CalcGCD(b, a%b);
}

int main(int argc, char* argv[])
{

	int				nInputN;
	string			szInput;
	int				nInputM;
	int				nPow = 1;
	int				nNum				= 0;
	stack<int>		sOutput;

	cin >> nInputN;
	cin >> szInput;
	cin >> nInputM;

	for (int i = szInput.length() - 1; i >= 0; i--)
	{
		if (szInput[i] == '1')
			nNum += 1 * nPow;
		if (szInput[i] == '2')
			nNum += 2 * nPow;
		if (szInput[i] == '3')
			nNum += 3 * nPow;
		if (szInput[i] == '4')
			nNum += 4 * nPow;
		if (szInput[i] == '5')
			nNum += 5 * nPow;
		if (szInput[i] == '6')
			nNum += 6 * nPow;
		if (szInput[i] == '7')
			nNum += 7 * nPow;
		if (szInput[i] == '8')
			nNum += 8 * nPow;
		if (szInput[i] == '9')
			nNum += 9 * nPow;
		if (szInput[i] == 'A')
			nNum += 10 * nPow;
		if (szInput[i] == 'B')
			nNum += 11 * nPow;
		if (szInput[i] == 'C')
			nNum += 12 * nPow;
		if (szInput[i] == 'D')
			nNum += 13 * nPow;
		if (szInput[i] == 'E')
			nNum += 14 * nPow;
		if (szInput[i] == 'F')
			nNum += 15 * nPow;
		nPow *= nInputN;
	}


	while (nNum != 0)
	{
		sOutput.push(nNum % nInputM);
		nNum /= nInputM;
	}

	while (!sOutput.empty())
	{
		nInputM = sOutput.top();
		sOutput.pop();
		if (nInputM > 9)
		{
			if (nInputM == 10)
				printf("A");
			if (nInputM == 11)
				printf("B");
			if (nInputM == 12)
				printf("C");
			if (nInputM == 13)
				printf("D");
			if (nInputM == 14)
				printf("E");
			if (nInputM == 15)
				printf("F");
		}
		else
		{
			printf("%d", nInputM);
		}
	}





Exit0:

	return 0;
}