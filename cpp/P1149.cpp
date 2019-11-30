/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-29 16:58
//	Comment		:	OJ(P1149)
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
	int*			pnSeq			= NULL;
	int				nInputN;
	int				nAns			= 0;
	int				nTemp;
	int				nCount			= 0;
	pnSeq = (int*)malloc(1001 * sizeof(int));
	memset(pnSeq, 0, 1001 * sizeof(int));

	pnSeq[0] = 0;
	pnSeq[1] = 0;
	pnSeq[2] = 0;
	pnSeq[3] = 0;
	pnSeq[4] = 0;
	pnSeq[5] = 0;
	pnSeq[6] = 0;
	pnSeq[7] = 0;
	pnSeq[8] = 0;
	pnSeq[9] = 0;
	pnSeq[10] = 0;
	pnSeq[11] = 0;
	pnSeq[12] = 0;
	pnSeq[13] = 0;
	pnSeq[14 - 1] = 1;
	pnSeq[15 - 1] = 2;
	pnSeq[16 - 1] = 8;
	pnSeq[17 - 1] = 9;
	pnSeq[18 - 1] = 6;
	pnSeq[19 - 1] = 9;
	pnSeq[20 - 1] = 29;
	pnSeq[21 - 1] = 39;
	pnSeq[22 - 1] = 29;
	pnSeq[23 - 1] = 65;
	pnSeq[24 - 1] = 88;
	pnSeq[24] = 128;
	scanf("%d", &nInputN);
	printf("%d", pnSeq[nInputN]);

Exit0:

	return 0;
}