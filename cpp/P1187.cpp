/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-11 21:07
//	Comment		:	OJ(P1187)
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
#include <list>

using namespace std;
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		2000001


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int**			ppnMat			= NULL;
	int				nSum			= 0;
	int				nAns			= 0;
	string			szInput;
	scanf("%d%d", &nInputN, &nInputM);
	ppnMat = (int**)malloc((nInputN + 2) * sizeof(int*));

	for (int i = 0; i <= nInputN + 1; i++)
	{
		ppnMat[i] = (int*)malloc((nInputM + 2) * sizeof(int));
		memset(ppnMat[i], 0, (nInputM + 2) * sizeof(int));
	}

	for (int i = 1; i <= nInputN; i++)
	{
		cin >> szInput;
		for (int j = 0; j < szInput.length(); j++)
			ppnMat[i][j + 1] = szInput[j] - '0';
	}
		


	for (int i = 1; i <= nInputN; i++)
	{
		for (int j = 1; j <= nInputM; j++)
		{
			nSum += (ppnMat[i][j] - ppnMat[i - 1][j]) < 0 ?
				0 : (ppnMat[i][j] - ppnMat[i - 1][j]);
			nSum += (ppnMat[i][j] - ppnMat[i + 1][j]) < 0 ?
				0 : (ppnMat[i][j] - ppnMat[i + 1][j]);
			nSum += (ppnMat[i][j] - ppnMat[i][j - 1]) < 0 ?
				0 : (ppnMat[i][j] - ppnMat[i][j - 1]);
			nSum += (ppnMat[i][j] - ppnMat[i][j + 1]) < 0 ?
				0 : (ppnMat[i][j] - ppnMat[i][j + 1]);
			if (ppnMat[i][j] != 0)
				nSum += 2;
			//ppnMat[i][j] = nSum;
			//cout << nSum << " ";
			nAns += nSum;
			nSum = 0;
		}
		//cout << endl;
	}





	printf("%d", nAns);




Exit0:

	return 0;
}