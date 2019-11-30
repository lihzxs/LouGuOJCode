/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-6 22:13
//	Comment		:	OJ(P1479)
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
#define	MAXNUM		100000000
#define	EPS         0.0001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;




int main(int argc, char* argv[])
{
	int				nInputN;
	int*			pnSeqAns			= NULL;
	pnSeqAns = (int*)malloc(26 * sizeof(int));

	pnSeqAns[5] = 1;
	pnSeqAns[6] = 1;
	pnSeqAns[7] = 1;
	pnSeqAns[8] = 1;
	pnSeqAns[9] = 3;
	pnSeqAns[10] = 3;
	pnSeqAns[11] = 3;
	pnSeqAns[12] = 6;
	pnSeqAns[13] = 6;
	pnSeqAns[14] = 10;
	pnSeqAns[15] = 10;
	pnSeqAns[16] = 15;
	pnSeqAns[17] = 21;
	pnSeqAns[18] = 21;
	pnSeqAns[19] = 28;
	pnSeqAns[20] = 28;
	pnSeqAns[21] = 35;
	pnSeqAns[22] = 30;
	pnSeqAns[23] = 30;
	pnSeqAns[24] = 27;
	pnSeqAns[25] = 12;

	scanf("%d", &nInputN);
	printf("%d", pnSeqAns[nInputN]);

Exit0:
	return 0;
}