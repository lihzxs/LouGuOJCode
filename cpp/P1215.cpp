/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-24 23:39
//	Comment		:	OJ(P1215)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <list>
#include <string>
#include <string.h>
#include <set>
#include <queue>
#include <map>

using namespace std;
#define	MAXNUM		10010
#define	EPS         0.0001
#define MODNUM		1000000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;



void DFS(int nNowA, int nNowB, int nNowC,
	int nA, int nB, int nC, int** ppnFlag, int* pnAns, int& nCount)
{

	if (ppnFlag[nNowA][nNowB])
		return;


	ppnFlag[nNowA][nNowB] = 1;

	if (nNowA == 0)
		pnAns[nCount++] = nNowC;


	if (nNowC > 0)
	{
		if (nNowA < nA)
			DFS(min(nA, nNowA + nNowC), nNowB, nNowC - min(nA, nNowA + nNowC) + nNowA,
				nA, nB, nC, ppnFlag, pnAns, nCount);
		if (nNowB < nB)
			DFS(nNowA, min(nNowB + nNowC, nB), nNowC - min(nB, nNowB + nNowC) + nNowB,
				nA, nB, nC, ppnFlag, pnAns, nCount);
	}
	

	if (nNowB > 0)
	{
		if (nNowA < nA)
			DFS(min(nA, nNowA + nNowB), nNowB - min(nA, nNowA + nNowB) + nNowA, nNowC,
				nA, nB, nC, ppnFlag, pnAns, nCount);
		if (nNowC < nC)
			DFS(nNowA, nNowB - min(nC, nNowC + nNowB) + nNowC, min(nC, nNowC + nNowB),
				nA, nB, nC, ppnFlag, pnAns, nCount);
	}

	if (nNowA > 0)
	{


		if (nNowB < nB)
			DFS(nNowA - min(nB, nNowA + nNowB) + nNowB, min(nB, nNowA + nNowB), nNowC,
				nA, nB, nC, ppnFlag, pnAns, nCount);
		if (nNowC < nC)
			DFS(nNowA - min(nC, nNowA + nNowC) + nNowC, nNowB, min(nC, nNowA + nNowC),
				nA, nB, nC, ppnFlag, pnAns, nCount);

	}


}





int main(int argc, char* argv[])
{

	int				nInputA;
	int				nInputB;
	int				nInputC;
	int				nCount				 = 0;
	int*			pnAns				 = NULL;
	int**			ppnFlag				 = NULL;
	
	scanf("%d%d%d", &nInputA, &nInputB, &nInputC);

	ppnFlag = (int**)malloc((nInputC + 1) * sizeof(int*));
	pnAns = (int*)malloc((nInputC + 1) * sizeof(int));
	for (int i = 0; i <= nInputC; i++)
	{
		ppnFlag[i] = (int*)malloc((nInputC + 1) * sizeof(int));
		memset(ppnFlag[i], 0, (nInputC + 1) * sizeof(int));
	}



		
	DFS(0, 0, nInputC,
		nInputA, nInputB, nInputC, ppnFlag, pnAns, nCount);

	sort(pnAns, pnAns + nCount);
	for (int i = 0; i < nCount; i++)
		printf("%d ", pnAns[i]);



	





Exit0:

	return 0;
}