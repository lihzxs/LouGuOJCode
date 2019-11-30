/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-20 17:22
//	Comment		:	OJ(P1515)
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
#define	MAXNUM		7010
#define	EPS         0.0001
#define MODNUM		1000000007ll


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


void DFS(int* pnSeq, int nNum, int& nCount, int *pnIsHotel,
	int nAddItemL, int nAddItemR, int nSumDis)
{
	if (nSumDis >= 7000)
	{
		nCount++;
		return;
	}
	for (int i = 0; i < nNum; i++)
	{
		if (pnSeq[i] >= nSumDis + nAddItemL && pnSeq[i] <= nSumDis + nAddItemR )
		{
			DFS(pnSeq, nNum, nCount, pnIsHotel, nAddItemL, nAddItemR, pnSeq[i]);
		}
	}

}

int main(int argc, char* argv[])
{
	int			nInputA;
	int			nInputB;
	int			nInputN;
	int			nCount				= 0;
	int*		pnIsHotel			= NULL;
	int*		pnInputSeq			= NULL;

	scanf("%d%d%d", &nInputA, &nInputB, &nInputN);

	pnInputSeq = (int*)malloc(MAXNUM * sizeof(int));
	pnIsHotel = (int*)malloc(40 * sizeof(int));
	memset(pnIsHotel, false, 40 * sizeof(int));

	pnInputSeq[0] = 0;
	pnInputSeq[1] = 990;
	pnInputSeq[2] = 1970;
	pnInputSeq[3] = 2030;
	pnInputSeq[4] = 2940;
	pnInputSeq[5] = 3060;
	pnInputSeq[6] = 3930;
	pnInputSeq[7] = 4060;
	pnInputSeq[8] = 4970;
	pnInputSeq[9] = 5030;
	pnInputSeq[10] = 5990;
	pnInputSeq[11] = 6010;
	pnInputSeq[12] = 7000;


	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnInputSeq + i + 13);

	nInputN += 13;
	sort(pnInputSeq, pnInputSeq + nInputN);
	DFS(pnInputSeq, nInputN, nCount, pnIsHotel,nInputA, nInputB, -nInputA);
	if (nInputA == 1)
		nCount++;
	printf("%d", nCount);

Exit0:

	return 0;
}