/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-13 22:19
//	Comment		:	OJ(P1101)
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
#include <float.h>

using namespace std;
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

int**			ppnFlag			= NULL;

void JudgeH(string* pszMat, int nX, int nY, int nNum, char cNorm)
{
	string				szCmp;
	int					nCount			= 0;
	if (cNorm == 'y')
		szCmp = "yizhong";
	else
		szCmp = "gnohziy";

	for (int i = nY; i < nY + szCmp.length(); i++)
	{
		if (i > nNum)
			break;
		if (szCmp[nCount] == pszMat[nX][i])
			nCount++;
		else
			break;
	}

	if (nCount == szCmp.length())
	{
		for (int i = nY; i < nY + szCmp.length(); i++)
		{
			if (i > nNum)
				break;
			ppnFlag[nX][i] = 1;
		}	
	}
}


void JudgeV(string* pszMat, int nX, int nY, int nNum, char cNorm)
{
	string				szCmp;
	int					nCount = 0;
	if (cNorm == 'y')
		szCmp = "yizhong";
	else
		szCmp = "gnohziy";

	for (int i = nX; i < nX + szCmp.length(); i++)
	{
		if (i > nNum)
			break;
		if (szCmp[nCount] == pszMat[i][nY])
			nCount++;
		else
			break;
	}

	if (nCount == szCmp.length())
	{
		for (int i = nX; i < nX + szCmp.length(); i++)
		{
			if (i > nNum)
				break;
			ppnFlag[i][nY] = 1;
		}
	}
}


void Judge45(string* pszMat, int nX, int nY, int nNum, char cNorm)
{
	string				szCmp;
	int					nCount = 0;
	if (cNorm == 'y')
		szCmp = "yizhong";
	else
		szCmp = "gnohziy";

	for (int i = 0; i < szCmp.length(); i++)
	{
		if (nX + i > nNum)
			break;
		if (nY + i > nNum)
			break;

		if (szCmp[nCount] == pszMat[nX + i][nY + i])
			nCount++;
		else
			break;
	}

	if (nCount == szCmp.length())
	{
		for (int i = 0; i < szCmp.length(); i++)
		{
			if (nX + i > nNum)
				break;
			if (nY + i > nNum)
				break;
			ppnFlag[nX + i][nY + i] = 1;
		}
	}
}

void Judge_45(string* pszMat, int nX, int nY, int nNum, char cNorm)
{
	string				szCmp;
	int					nCount = 0;
	if (cNorm == 'y')
		szCmp = "yizhong";
	else
		szCmp = "gnohziy";

	for (int i = 0; i < szCmp.length(); i++)
	{
		if (nX - i < 1)
			break;
		if (nY - i < 1)
			break;
		if (szCmp[nCount] == pszMat[nX - i][nY - i])
			nCount++;
		else
			break;
	}

	if (nCount == szCmp.length())
	{
		for (int i = 0; i < szCmp.length(); i++)
		{
			if (nX - i < 1)
				break;
			if (nY - i < 1)
				break;
			ppnFlag[nX - i][nY - i] = 1;
		}
			
	}
}


void Judge(string* pszMat, int nX, int nY, int nNum, char cNorm)
{
	JudgeH(pszMat, nX, nY, nNum, cNorm);
	JudgeV(pszMat, nX, nY, nNum, cNorm);
	Judge45(pszMat, nX, nY, nNum, cNorm);
	Judge_45(pszMat, nX, nY, nNum, cNorm);
}






int main(int argc, char* argv[])
{
	int				nInputN;
	string*			pszMat					= NULL;
	scanf("%d", &nInputN);

	pszMat = new string[nInputN + 1];
	ppnFlag = (int**)malloc((nInputN + 1) * sizeof(int*));


	for (int i = 1; i <= nInputN; i++)
	{
		cin >> pszMat[i];
		pszMat[i] = " " + pszMat[i];
		ppnFlag[i] = (int*)malloc((nInputN + 1) * sizeof(int));
		memset(ppnFlag[i], 0, (nInputN + 1) * sizeof(int));
	}
		

	for (int i = 1; i <= nInputN; i++)
	{
		for (int j = 1; j <= nInputN; j++)
		{
			if (ppnFlag[i][j])
				continue;
			if (pszMat[i][j] == 'y')
				Judge(pszMat, i, j, nInputN, 'y');
			else if (pszMat[i][j] == 'g')
				Judge(pszMat, i, j, nInputN, 'g');

		}
	}


	for (int i = 1; i <= nInputN; i++)
	{
		for (int j = 1; j <= nInputN; j++)
		{
			if (ppnFlag[i][j])
				printf("%c", pszMat[i][j]);
			else
				printf("*");
		}
		printf("\n");
	}




Exit0:

	return 0;
}