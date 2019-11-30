/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-20 17:17
//	Comment		:	OJ(P1538)
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
	int				nInputN;
	string			szInput;
	string*			pszOutput			= NULL;
	
	pszOutput = new string[10];

	pszOutput[0] = "-|| ||-";
	pszOutput[1] = "  |  | ";
	pszOutput[2] = "- |-| -";
	pszOutput[3] = "- |- |-";
	pszOutput[4] = " ||- | ";
	pszOutput[5] = "-| - |-";
	pszOutput[6] = "-| -||-";
	pszOutput[7] = "- |  | ";
	pszOutput[8] = "-||-||-";
	pszOutput[9] = "-||- |-";

	cin >> nInputN;
	cin >> szInput;

	for (int i = 0; i < 7; i++)
	{
		if (i == 2 || i == 5)
			continue;
		if (i % 3 == 0)
		{
			for (int j = 0; j < szInput.size(); j++)
			{
				cout << " ";
				for (int k = 0; k < nInputN; k++)
					cout << pszOutput[szInput[j] - 48][i];
				cout << "  ";
			}
			cout << endl;
		}///if (i % 3 == 0)
		else
		{
			for (int j = 0; j < nInputN; j++)
			{
				for (int k = 0; k < szInput.length(); k++)
				{
					cout << pszOutput[szInput[k] - 48][i];
					for (int l = 0; l < nInputN; l++)
						cout << " ";
					cout << pszOutput[szInput[k] - 48][i + 1] << " ";
				}
				cout << endl;
			}///for (int j = 0; j < nInputN; j++)
			
		}
	}



Exit0:
	return 0;
}