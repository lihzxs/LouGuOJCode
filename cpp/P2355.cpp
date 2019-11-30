/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-28 22:35
//	Comment		:	OJ(P2355)
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

int main(int argc, char* argv[])
{
	int			nInputK;
	scanf("%d", &nInputK);
	int			nInputN;
	int			nInputX;
	int			nInputY;
	int			nInputR;
	int			nInputM;
	int			nNowX;
	int			nNowY;
	int			nR;
	int			nC;
	while (nInputK--)
	{
		scanf("%d%d%d%d%d", &nInputN, &nInputX, 
			&nInputY, &nInputR, &nInputM);
		if (nInputX == 1)
		{
			nR = 1;
			while (nInputM > nInputR)
			{
				nR++;
				nInputM -= nInputR;
			}
			if (nInputY == 2)
				swap(nInputM, nR);
			printf("%d %d ", nR, nInputM);
		}
		else
		{
			nNowX = 1;
			nNowY = 1;
			for (int i = 2; i <= nInputM; i++)
			{
				nNowY += 2;
				if (nNowY > nInputR)
				{
					nNowX++;
					nNowY = (nNowX % 2 == 0 ? 2 : 1);
				}
			}
			if (nInputY == 2)
				swap(nNowX, nNowY);
			printf("%d %d ", nNowX, nNowY);
		}
	}


Exit0:

	return 0;
}