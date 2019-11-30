/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-30 15:04
//	Comment		:	OJ(P1898)
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

int main(int argc, char* argv[])
{
	string			szInput;
	int				nInputST;
	string			szTemp			= "";
	string			szNow			= "";


	cin >> szInput >> nInputST;

	for (int i = 0; i < szInput.length(); i++)
	{
		szTemp += to_string(szInput[i] - 'A' + nInputST);
	}




	while(szTemp.length() > 3)
	{
		for (int i = 0; i < szTemp.length(); i++)
			szTemp[i] -= '0';
		for (int j = 1; j < szTemp.length(); j++)
			szNow += to_string((szTemp[j - 1] + szTemp[j]) % 10);


		szTemp = szNow;
		szNow = "";
	}

	for (int i = 0; i < szTemp.length(); i++)
		szTemp[i] -= '0';

	if (szTemp[0] == 1 &&
		szTemp[1] == 0 &&
		szTemp[2] == 0)
		printf("100\n");
	else
	{
		for (int j = 1; j < szTemp.length(); j++)
			szNow += to_string((szTemp[j - 1] + szTemp[j]) % 10);
		if (szNow[0] == '0')
			printf("%d", szNow[1] - '0');
		else
			cout << szNow;
	}

	



Exit0:

	return 0;
}