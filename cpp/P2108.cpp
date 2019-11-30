/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-13 21:14
//	Comment		:	OJ(P2108)
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
#include <float.h>

using namespace std;
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int IsNum(string& szTemp)
{
	if (szTemp == "zero")
		return 0;
	if (szTemp == "one")
		return 1;
	if (szTemp == "two")
		return 2;
	if (szTemp == "three")
		return 3;
	if (szTemp == "four")
		return 4;
	if (szTemp == "five")
		return 5;
	if (szTemp == "six")
		return 6;
	if (szTemp == "seven")
		return 7;
	if (szTemp == "eight")
		return 8;
	if (szTemp == "nine")
		return 9;
	if (szTemp == "ten")
		return 10;
	if (szTemp == "eleven")
		return 11;
	if (szTemp == "twelve")
		return 12;
	if (szTemp == "thirteen")
		return 13;
	if (szTemp == "fourteen")
		return 14;
	if (szTemp == "fifteen")
		return 15;
	if (szTemp == "sixteen")
		return 16;
	if (szTemp == "seventeen")
		return 17;
	if (szTemp == "eighteen")
		return 18;
	if (szTemp == "nineteen")
		return 19;
	if (szTemp == "twenty")
		return 20;
	if (szTemp == "thirty")
		return 30;
	if (szTemp == "forty")
		return 40;
	if (szTemp == "fifty")
		return 50;
	if (szTemp == "sixty")
		return 60;
	if (szTemp == "seventy")
		return 70;
	if (szTemp == "eighty")
		return 80;
	if (szTemp == "ninety")
		return 90;
	return -1;
}



int main(int argc, char* argv[])
{
	int				nInputN;
	string			pszInput[100];
	int				nCount				= 0;
	int				nIsNe				= 0;
	int				nPre				= 10000000;
	int				nTemp				= 0;
	int				nAns				= 0;
	int				nNum				= 0;

	while (cin >> pszInput[nCount])
		nCount++;
	if (pszInput[0] == "negative")
		nIsNe = 1;

	for (int i = 0 + nIsNe; i < nCount; i++)
	{
		nTemp = IsNum(pszInput[i]);
		if (nTemp == -1)
		{
			if (pszInput[i] == "thousand")
			{
				nAns += nNum * 1000;
				nNum = 0;
			}
			if (pszInput[i] == "million")
			{
				nAns += nNum * 1000000;
				nNum = 0;
			}
			if (pszInput[i] == "hundred")
				nNum = nNum * 100;
		}
		else
			nNum += nTemp;
	}
	if (nIsNe)
		printf("-");
	nAns += nNum;
	printf("%d", nAns);


Exit0:

	return 0;
}