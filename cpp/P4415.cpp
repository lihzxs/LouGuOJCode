/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-17 20:56
//	Comment		:	OJ(P4415)
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
#define	MAXNUM		1000001
#define	EPS         0.0001
#define MODNUM		100000007


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	int					nInputN1;
	int					nInputN2;
	int					nTime;
	int*				pnFlag = NULL;
	string				szN1;
	string				szN2;

	scanf("%d%d", &nInputN1, &nInputN2);
	cin >> szN1;
	cin >> szN2;
	scanf("%d", &nTime);

	pnFlag = (int*)malloc((nInputN1 + nInputN2) * sizeof(int));
	memset(pnFlag, 0, (nInputN1 + nInputN2) * sizeof(int));

	for (int i = nInputN1; i < nInputN2 + nInputN1; i++)
		pnFlag[i] = 1;

	int i = 0;
	int j = szN1.length() - 1;

	while (i < j)
	{
		swap(szN1[i], szN1[j]);
		i++;
		j--;
	}

	szN1 = szN1 + szN2;

	while (nTime--)
	{
		for (int i = 1; i < nInputN1 + nInputN2; i++)
		{
			if (pnFlag[i - 1]== 0 && pnFlag[i] == 1)
			{
				swap(szN1[i - 1], szN1[i]);
				swap(pnFlag[i - 1], pnFlag[i]);
				i++;
			}
		}///for (int i = 0; i < nInputN1 + nInputN2; i++)
	}///while (nTime--)


	cout << szN1 << endl;

Exit0:

	return 0;
}