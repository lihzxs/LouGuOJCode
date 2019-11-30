/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-19 22:52
//	Comment		:	OJ(P12958)
//
///////////////////////////////////////////

//#include "pch.h"
/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-16 11:24
//	Comment		:	OJ(P1304)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <stack>
#include <string>
#include <string.h>
using namespace std;
#define	MAXNUM		20000
#define	EPS         0.0001
#define DIRNUM		4
#define ERROR_ID    0

typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;




int main(int argc, char* argv[])
{
	//ios::sync_with_stdio(false);

	int				nInputR;
	int				nInputC;
	int				nNowX			= 1;
	int				nNowY			= 1;
	int				nMax			= 0;
	int				nTempX			= 1;
	int				nTempY			= 1;
	int				nAns			= 0;
	int**			ppnDir			= NULL;
	int**			ppnMat			= NULL;
	BYTE**			ppbyMat			= NULL;

	ppnDir = (int**)malloc(DIRNUM * sizeof(int));
	for (int i = 0; i < DIRNUM; i++)
		ppnDir[i] = (int*)malloc(2 * sizeof(int));

	ppnDir[0][0] = 1; ppnDir[0][1] = 0;
	ppnDir[1][0] = 0; ppnDir[1][1] = 1;
	ppnDir[2][0] = -1; ppnDir[2][1] = 0;
	ppnDir[3][0] = 0; ppnDir[3][1] = -1;



	//cin >> nInputR >> nInputC;
	scanf("%d%d", &nInputR, &nInputC);

	ppnMat = (int**)malloc(100 * sizeof(int));
	ppbyMat = (BYTE**)malloc(100 * sizeof(BYTE));

	for (int i = 1; i < nInputR + 1; i++)
	{
		ppnMat[i] = (int*)malloc(100 * sizeof(int));
		ppbyMat[i] = (BYTE*)malloc(100 * sizeof(BYTE));
		memset(ppbyMat[i], false, 100 * sizeof(BYTE));
	}


	for (int i = 1; i < nInputR + 1; i++)
		for (int j = 1; j < nInputC + 1; j++)
			scanf("%d", &ppnMat[i][j]);//cin >> ppnMat[i][j];

	while (nNowX < nInputC || nNowY < nInputR)
	{
		//ppbyMat[nNowY][nNowX] = true;
		nAns += ppnMat[nNowY][nNowX];
		ppnMat[nNowY][nNowX] = 0;
		for (int i = 0; i < DIRNUM; i++)
		{
			if (nNowY + ppnDir[i][1] < 1 || nNowY + ppnDir[i][1] > nInputR)
				continue;
			if (nNowX + ppnDir[i][0] < 1 || nNowX + ppnDir[i][0] > nInputC)
				continue;
			if (ppnMat[nNowY + ppnDir[i][1]][nNowX + ppnDir[i][0]] >
				nMax)
			{
				nMax = ppnMat[nNowY + ppnDir[i][1]][nNowX + ppnDir[i][0]];
				nTempX = nNowX + ppnDir[i][0];
				nTempY = nNowY + ppnDir[i][1];
			}
		}
		nNowX = nTempX;
		nNowY = nTempY;
		nMax = 0;
	}

	nAns += ppnMat[nInputR][nInputC];
	printf("%d", nAns);






	




Exit0:

	return 0;
}





