/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-22 21:51
//	Comment		:	OJ(P1628)
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
#define	MAXNUM		150
#define	EPS         0.0001
#define MODNUM		1000000007ll


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;





int main(int argc, char* argv[])
{
	int				nInputN;
	string			szT;
	string*			pszInput;
	string*			pszOutput;
	int				nCount			= 0;
	scanf("%d", &nInputN);

	pszInput = new string[nInputN];
	pszOutput = new string[nInputN];

	for (int i = 0; i < nInputN; i++)
		cin >> pszInput[i];
	cin >> szT;

	for (int i = 0; i < nInputN; i++)
	{
		if (pszInput[i].find(szT) == 0)
			pszOutput[nCount++] = pszInput[i];
	}

	sort(pszOutput, pszOutput + nCount);

	for (int i = 0; i < nCount; i++)
		cout << pszOutput[i] << endl;







Exit0:

	return 0;
}