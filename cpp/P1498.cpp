/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-30 23:06
//	Comment		:	OJ(P1498)
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
#include <sstream>

using namespace std;
#define	MAXNUM		100000000
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	string		szOut[10][1050];
	szOut[1][1] = " /\\ ";
	szOut[1][2] = "/__\\";

	for (int i = 2; i <= 10; i++)
	{
		for (int j = 1; j <= pow(2, i) / 2; j++)
		{
			for (int k = 0; k < pow(2, i - 1); k++)
				szOut[i][j] += " ";
			szOut[i][j] += szOut[i - 1][j];

			if (i != 10)
			for (int k = 0; k < pow(2, i - 1); k++)
				szOut[i][j] += " ";
		}
		for (int j = pow(2, i) / 2 + 1; j <= pow(2, i); j++)
		{
			szOut[i][j] = szOut[i - 1][j - (int)pow(2, i) / 2] + szOut[i - 1][j - (int)pow(2, i) / 2];
		}
		//for (int j = 1; j <= pow(2, i); j++)
		//	cout << szOut[i][j] << endl;

		//cout << endl;
		//cout << i << endl;
	}
	

	int nInputN;
	scanf("%d", &nInputN);

	for (int j = 1; j <= pow(2, nInputN); j++)
		cout << szOut[nInputN][j] << endl;



Exit0:
	return 0;
}