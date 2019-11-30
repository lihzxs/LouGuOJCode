
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
	int			nN;
	string		szA;
	string		szB;
	string		szC;
	string		szD;
	cin >> nN;

	while (nN--)
	{
		cin >> szA >> szB >> szC;
		if (szA == "BEGINNING")
			szD.push_back(szC[0]);
		if (szA == "MIDDLE")
			szD.push_back(szC[(szC.size() - 1) / 2]);
		if (szA == "END")
			szD.push_back(szC[(szC.size() - 1)]);

	}

	cout << szD << endl;

Exit0:
	return 0;
}