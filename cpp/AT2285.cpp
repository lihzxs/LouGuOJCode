
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
	int				nInputN;
	int				nMax = 0;
	string			szInput;

	cin >> nInputN >> szInput;
	nInputN = 0;
	for (int i = 0; i < szInput.length(); i++)
	{
		if (szInput[i] == 'I')
			nInputN++;
		else
			nInputN--;
		nMax = max(nMax, nInputN);
	}


	cout << nMax;

Exit0:
	return 0;
}