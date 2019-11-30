/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-24 15:48
//	Comment		:	OJ(P1012)
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


bool Cmp(const string& szFirst, const string& szSecond)
{
	return (szFirst + szSecond) > (szSecond + szFirst);
}




int main(int argc, char* argv[])
{
	int				nInputN;
	string*			pszInput;


	scanf("%d", &nInputN);
	pszInput = new string[nInputN];

	for (int i = 0; i < nInputN; i++)
		cin >> pszInput[i];


	sort(pszInput, pszInput + nInputN, Cmp);

	for (int i = 0; i < nInputN; i++)
		cout << pszInput[i];

	cout << endl;





			

Exit0:

	return 0;
}