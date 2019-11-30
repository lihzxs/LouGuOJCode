/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-23 20:57
//	Comment		:	OJ(P4759)
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
	int			nInputN;
	int			nStart;
	int			nEnd;
	int			nInputT;
	scanf("%d", &nInputT);
	while (nInputT--)
	{
		bool		bIsPrint = false;
		scanf("%d", &nInputN);


		for (int i = 2; i <= int(sqrt(2 * nInputN)); i++)
		{
			if (2 * nInputN % i == 0)
			{
				if ((2 * nInputN / i - i + 1) % 2 == 0 &&
					(2 * nInputN / i + i - 1) % 2 == 0 && (2 * nInputN / i - i + 1) !=
					(2 * nInputN / i + i - 1))
				{
					nStart = (2 * nInputN / i - i + 1) / 2;
					nEnd = (2 * nInputN / i + i - 1) / 2;
					printf("%d = %d", nInputN, nStart);
					bIsPrint = true;
					for (int j = nStart + 1; j <= nEnd; j++)
						printf(" + %d", j);
					break;
				}
			}
		}

		if (!bIsPrint)
			printf("IMPOSSIBLE");

		printf("\n");
	}








Exit0:

	return 0;
}