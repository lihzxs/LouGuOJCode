/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-11-4 15:31
//	Comment		:	OJ(P5412)
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
	int				nInputT;
	int				nInputN;
	int*			pnIsBoy				= NULL;
	double*			pnHeiht				= NULL;
	double*			pnBoy				= NULL;
	double*			pnGirl				= NULL;
	double			fTemp;
	int				nCountBoy;
	int				nCountGirl;
	pnIsBoy = (int*)malloc(10005 * sizeof(int));
	pnHeiht = (double*)malloc(10005 * sizeof(double));
	pnBoy = (double*)malloc(10005 * sizeof(double));
	pnGirl = (double*)malloc(10005 * sizeof(double));


	scanf("%d", &nInputT);

	while (nInputT--)
	{
		nCountBoy = 0;
		nCountGirl = 0;
		scanf("%d", &nInputN);
		for (int i = 0; i < nInputN; i++)
			cin >> pnIsBoy[i];
		for (int i = 0; i < nInputN; i++)
			cin >> pnHeiht[i];

		for (int i = 0; i < nInputN; i++)
		{
			if (pnIsBoy[i] == 1)
				pnBoy[nCountBoy++] = pnHeiht[i];
			else
				pnGirl[nCountGirl++] = pnHeiht[i];
		}
		sort(pnBoy, pnBoy + nCountBoy);
		sort(pnGirl, pnGirl + nCountGirl);

		for (int i = 0; i < nCountGirl; i++)
			cout << pnGirl[i] << " ";
		cout << endl;
		for (int i = 0; i < nCountBoy; i++)
			cout << pnBoy[i] << " ";
		cout << endl;
	}



Exit0:
	return 0;
}