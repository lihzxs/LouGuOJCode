/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-26 17:11
//	Comment		:	OJ(P1465)
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

string		g_szAns[4][10] = {
	{"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
	{"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX","XC"},
	{"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
	{"M", "MM", "MMM"}
};

typedef struct SOut
{
	char	cTemp;
	int		nNum;
}SOut;


int main(int argc, char* argv[])
{
	int					nInputN;
	int					nTemp;
	map<char, int>		mpCount;
	SOut*				psOut			= NULL;
	string				szTemp;
	int					nCount			= 0;
	psOut = (SOut*)malloc(10 * sizeof(SOut));

	scanf("%d", &nInputN);

	for (int i = 1; i <= nInputN; i++)
	{
		nTemp = i;
		nCount = 0;
		while (nTemp)
		{
			if (nTemp % 10 != 0)
			{
				szTemp = g_szAns[nCount][nTemp % 10 - 1];
				for (int j = 0; j < szTemp.length(); j++)
					mpCount[szTemp[j]]++;
			}
			nCount++;
			nTemp /= 10;
		}
	}

	if (mpCount['I'] > 0)
		printf("I %d\n", mpCount['I']);
	if (mpCount['V'] > 0)
		printf("V %d\n", mpCount['V']);
	if (mpCount['X'] > 0)
		printf("X %d\n", mpCount['X']);
	if (mpCount['L'] > 0)
		printf("L %d\n", mpCount['L']);
	if (mpCount['C'] > 0)
		printf("C %d\n", mpCount['C']);
	if (mpCount['D'] > 0)
		printf("D %d\n", mpCount['D']);
	if (mpCount['M'] > 0)
		printf("M %d\n", mpCount['M']);







Exit0:

	return 0;
}