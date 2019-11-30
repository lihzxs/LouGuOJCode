/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-27 16:34
//	Comment		:	OJ(P2242)
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
	int					nInputN;
	int					nInputM;
	int					nInputTemp;
	int*				pnDis				= NULL;
	int					nPreInput;
	int					nAns				= 0;
	scanf("%d%d", &nInputN, &nInputM);
	pnDis = (int*)malloc((nInputN - 1) * sizeof(int));

	scanf("%d", &nPreInput);
	for (int i = 0; i < nInputN - 1; i++)
	{
		scanf("%d", &nInputTemp);
		pnDis[i] = nInputTemp - nPreInput;
		nPreInput = nInputTemp;
	}

	sort(pnDis, pnDis + nInputN - 1);

	for (int i = 0; i < nInputN - nInputM; i++)
		nAns += pnDis[i];

	printf("%d", nAns + nInputM);



Exit0:

	return 0;
}