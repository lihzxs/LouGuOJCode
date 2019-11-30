/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-14 19:38
//	Comment		:	OJ(P2729)
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
	int					pnF[4];
	int					pn1[4];
	int					pn2[4];
	int					pn3[4];
	int					nAnsF;
	int					nAns1;
	int					nAns2;
	int					nAns3;

	for (int i = 1; i <= 3; i++)
		scanf("%d", pnF + i);
	for (int i = 1; i <= 3; i++)
		scanf("%d%d%d", pn1 + i, pn2 + i, pn3 + i);

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			for (int k = 0; k < 100; k++)
			{
				if (!i && !j && !k)
					continue;
				nAns1 = pn1[1] * i + pn1[2] * j + pn1[3] * k;
				nAns2 = pn2[1] * i + pn2[2] * j + pn2[3] * k;
				nAns3 = pn3[1] * i + pn3[2] * j + pn3[3] * k;
				nAnsF = 0;
				if (nAns1 != 0 && pnF[1] != 0)
					nAnsF = nAns1 / pnF[1];
				else if (nAns2 != 0 && pnF[2] != 0)
					nAnsF = nAns2 / pnF[2];
				else if (nAns3 != 0 && pnF[3] != 0)
					nAnsF = nAns3 / pnF[3];
				if (pnF[1] * nAnsF == nAns1 && pnF[2] * nAnsF == nAns2 && pnF[3] * nAnsF == nAns3)
				{
					printf("%d %d %d %d", i, j, k, nAnsF);
					return 0;
				}

			}


	printf("NONE");

Exit0:

	return 0;
}