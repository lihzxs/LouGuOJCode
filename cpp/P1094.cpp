/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-23 22:36
//	Comment		:	OJ(P1094)
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
	int				nInputW;
	int				nInputG;
	int*			pnSeq				= NULL;
	int				nAns				= 0;

	scanf("%d", &nInputW);
	scanf("%d", &nInputG);

	pnSeq = (int*)malloc(nInputG * sizeof(int));

	for (int i = 0; i < nInputG; i++)
		scanf("%d", pnSeq + i);

	sort(pnSeq, pnSeq + nInputG);


	int i = 0;
	int j = nInputG - 1;


	while (i <= j)
	{
		if (pnSeq[i] + pnSeq[j] <= nInputW)
		{
			i++;
			j--;
		}
		else
		{
			j--;
		}
		nAns++;
	}

	printf("%d", nAns);






Exit0:

	return 0;
}