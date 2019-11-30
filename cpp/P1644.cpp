/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-26 22:52
//	Comment		:	OJ(P1644)
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


void DFS(int& nCount, int nX, int nY, int nInputN, int nInputM)
{

	if (nX > nInputM)
		return;
	if (nY > nInputN || nY < 0)
		return;

	if (nX == nInputM && nY == nInputN)
		nCount++;



	DFS(nCount, nX + 2, nY + 1, nInputN, nInputM);
	DFS(nCount, nX + 1, nY + 2, nInputN, nInputM);
	DFS(nCount, nX + 2, nY - 1, nInputN, nInputM);
	DFS(nCount, nX + 1, nY - 2, nInputN, nInputM);

}




int main(int argc, char* argv[])
{

	int					nInputN;
	int					nInputM;
	int					nCount			 = 0;

	int**				ppnMat;

	scanf("%d%d", &nInputN, &nInputM);

	//ppnMat = (int**)malloc((nInputN + 1) * sizeof(int*));

	//for (int i = 1; i <= nInputN; i++)
	//{
	//	ppnMat[i] = (int*)malloc((nInputM + 1) * sizeof(int));
	//	memset(ppnMat[i], 0, (nInputM + 1) * sizeof(int));
	//}

	DFS(nCount, 0, 0, nInputN, nInputM);

	printf("%d", nCount);





Exit0:

	return 0;
}