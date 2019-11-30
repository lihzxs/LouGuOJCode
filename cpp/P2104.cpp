/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-31 23:42
//	Comment		:	OJ(P2104)
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

char			scTemp[5000005];

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false);
	int				nInputN;
	int				nInputM;
	int				nTemp;
	vector<int>		lsNum;
	int				nFlag = 0;
	string			szTemp;

	scanf("%d%d", &nInputN, &nInputM);
	getchar();
	scanf("%s", scTemp);
	for (int i = 0; i < nInputN; i++)
		lsNum.push_back(scTemp[i] - '0');

	scanf("%s", scTemp);

	for (int i = 0; i < nInputM; i++)
	{
		if (scTemp[i] == '+')
		{
			nTemp = lsNum.size() - 1;
			while (lsNum[nTemp] == 1)
				nTemp--;

			lsNum[nTemp] = 1;
			for (int j = nTemp + 1; j < lsNum.size(); j++)
				lsNum[j] = 0;

		}
		else if (scTemp[i] == '-')
		{
			nTemp = lsNum.size() - 1;
			while (lsNum[nTemp] == 0)
				nTemp--;
			lsNum[nTemp] = 0;
			for (int j = nTemp + 1; j < lsNum.size(); j++)
				lsNum[j] = 1;
		}
		else if (scTemp[i] == '*')
			lsNum.push_back(0);
		else if (scTemp[i] == '/')
			lsNum.pop_back();
	}

	for (int i = 0; i < lsNum.size(); i++)
		printf("%d", lsNum[i]);


Exit0:
	return 0;
}