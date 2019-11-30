/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-31 20:58
//	Comment		:	OJ(P3353)
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
	int				nInputN;
	int				nInputW;
	int				nAns				= 0;
	int				nMaxIndex			= 0;
	int				nX;
	int				nB;
	int*			pnAdd				= NULL;

	scanf("%d%d", &nInputN, &nInputW);
	pnAdd = (int*)malloc(100005 * sizeof(int));
	memset(pnAdd, 0, 100005 * sizeof(int));

	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d", &nX, &nB);
		pnAdd[nX] += nB;
		nMaxIndex = max(nMaxIndex, nX);
	}
	for (int i = 1; i <= nMaxIndex; i++)
		pnAdd[i] += pnAdd[i - 1];

	for (int i = nInputW; i <= nMaxIndex; i++)
		nAns = max(nAns, pnAdd[i] - pnAdd[i - nInputW]);


	printf("%d", nAns);


Exit0:
	return 0;
}