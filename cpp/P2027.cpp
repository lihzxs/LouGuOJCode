/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-11 15:42
//	Comment		:	OJ(P2027)
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

string		szRun[2];
int			nIndex;
int			nDeep;
int			pF;
int			mem[40000];
void Print(int nL, int nR)
{
	for (int i = nL; i <= nR; i++)
	{
		if (szRun[0][i] == '<')
			nIndex--;
		else if (szRun[0][i] == '>')
			nIndex++;
		else if (szRun[0][i] == '+')
			mem[nIndex]++;
		else if (szRun[0][i] == '-')
			mem[nIndex]--;
		else if (szRun[0][i] == '.')
			printf("%c", mem[nIndex]);
		else if (szRun[0][i] == ',')
			mem[nIndex] = (pF == szRun[1].size() ? -1 : szRun[1][pF++]);
		else if (szRun[0][i] == '[')
		{
			nDeep = 0;
			int j;
			for (j = i;; j++)
			{
				if (szRun[0][j] == '[')
					nDeep++;
				if (szRun[0][j] == ']')
				{
					nDeep--;
					if (nDeep == 0)
						break;
				}
			}
			for (; mem[nIndex]; Print(i + 1, j - 1));
			i = j;
		}
	}
}



int main(int argc, char* argv[])
{
	char		cTemp;

	int			nFlag			= 0;
	

	memset(mem, 0, 40000 * sizeof(int));
	while (scanf("%c", &cTemp) != EOF)
	{
		if (cTemp == '$' && nFlag)
			break;
		if (cTemp == '$' && !nFlag)
		{
			nFlag = 1;
			continue;
		}
			
		if (nFlag == 0)
		{
			if (cTemp == '<' || cTemp == '>' || cTemp == '[' || cTemp == ']' ||
				cTemp == '+' || cTemp == '-' || cTemp == '.' || cTemp == ',')
				szRun[nFlag].push_back(cTemp);
		}
		else
			szRun[nFlag].push_back(cTemp);
	}

	szRun[1] = szRun[1].substr(1, szRun[1].size() - 1);

	Print(0, szRun[0].size() - 1);


Exit0:

	return 0;
}