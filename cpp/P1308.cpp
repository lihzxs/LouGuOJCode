/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-4 13:20
//	Comment		:	OJ(P1308)
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
#define	MAXNUM		100000000
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;






int main(int argc, char* argv[])
{
	string			szWord;
	string			szInput;
	int				nFirst			= 1000001;
	int				nCount			= 0;
	int				nAdd			= 0;
	string			szTemp;
	
	getline(cin, szWord);
	transform(szWord.begin(), szWord.end(),
		szWord.begin(), ::tolower);
	getline(cin, szInput);

	transform(szInput.begin(), szInput.end(),
		szInput.begin(), ::tolower);
	szInput = szInput + " ";
	for (int i = 0; i < szInput.length(); i++)
	{
	    if (szInput[i] == ' ')
			continue;
		for (int j = i + 1; j < szInput.length(); j++)
		{
			if (szInput[j] == ' ')
			{
				szTemp = szInput.substr(i, j - i);
				if (szTemp == szWord)
				{
					if (i < nFirst)
						nFirst = i;
					nCount++;
				}
				i = j;
				break;
			}
		}
	}
	if (nCount == 0)
		printf("-1");
	else
		printf("%d %d", nCount, nFirst);

	printf("\n");

Exit0:
	return 0;
}