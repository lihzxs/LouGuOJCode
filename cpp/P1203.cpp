/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-11 19:36
//	Comment		:	OJ(P1203)
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
	int					nInputN;
	string				szInput;
	char				cLeft;
	char				cRight;
	int					nAns			= -1;
	int					nCount			= 0;
	cin >> nInputN >> szInput;

	szInput = szInput + szInput + szInput;

	for (int i = nInputN; i < nInputN * 2; i++)
	{
		if (szInput[i] == szInput[i + 1])
			continue;
		nCount = 0;
		cLeft = szInput[i];
		cRight = szInput[i + 1];
		for (int j = i; j > 0; j--)
		{
			if ((szInput[j] == cLeft || szInput[j] == 'w') && cLeft != 'w')
				nCount++;
			else if (cLeft == 'w')
			{
				cLeft = szInput[j];
				nCount++;
			}
			else
				break;
			
		}
		for (int j = i + 1; j < 3 * nInputN; j++)
		{
			if ((szInput[j] == cRight || szInput[j] == 'w') && cRight != 'w')
				nCount++;
			else if (cRight == 'w')
			{
				cRight = szInput[j];
				nCount++;
			}
			else
				break;
		}
		nAns = max(nAns, nCount);
		nCount = 0;
	}


	nAns = min(nAns, nInputN);
	if (nAns == -1)
		nAns = nInputN;
	printf("%d", nAns);

Exit0:

	return 0;
}