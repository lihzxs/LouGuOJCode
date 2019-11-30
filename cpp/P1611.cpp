/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-10 16:25
//	Comment		:	OJ(P1611)
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
#include <list>

using namespace std;
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		2000001


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	BOOL*			pbFlag			= NULL;
	string			szTemp;
	int				nTemp;

	pbFlag = (BOOL*)malloc(MAXNUM * sizeof(BOOL));
	memset(pbFlag, 0, MAXNUM * sizeof(BOOL));
	map<int, bool>	Flag;
	int				nInputA;
	int				nInputB;
	int				nAns			= 0;
	scanf("%d%d", &nInputA, &nInputB);

	for (int i = nInputA; i <= nInputB; i++)
	{
		szTemp = to_string(i);
		for (int j = 1; j < szTemp.length(); j++)
		{
			nTemp = atoi((szTemp.substr(j) + szTemp.substr(0, j)).c_str());
			if (nTemp > i && nTemp <= nInputB && !Flag[nTemp])
			{
				nAns++;
				Flag[nTemp] = 1;
			}
		}
		Flag.clear();
	}

	printf("%d", nAns);

Exit0:

	return 0;
}