
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
#define	MAXNUM		1000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	string				szInput;

	cin >> szInput;

	for (int i = 0; i < szInput.size(); i++)
	{
		if ((szInput[i] == 'c' && szInput[i + 1] == 'h') ||
			(szInput[i] == 'h' && szInput[i - 1] == 'c') ||
			szInput[i] == 'o' || szInput[i] == 'k' || szInput[i] == 'u')
			continue;
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;

Exit0:

	return 0;
}