/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-24 21:33
//	Comment		:	OJ(P2813)
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
#define	MAXNUM		1000000001
#define	EPS         0.0001
#define MODNUM		2e31


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;



int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputM;
	int				nPreAttack			= 0;
	int*			pnDefence			= NULL;
	int*			pnAttack			= NULL;
	int				nAns				= 0;
	BOOL			bFlag				= false;

	scanf("%d%d", &nInputM, &nInputN);
	pnDefence = (int*)malloc(nInputM * sizeof(int));
	pnAttack = (int*)malloc(nInputN * sizeof(int));
	for (int i = 0; i < nInputM; i++)
		scanf("%d", pnDefence + i);

	for (int i = 0; i < nInputN; i++)
		scanf("%d", pnAttack + i);

	sort(pnDefence, pnDefence + nInputM);
	sort(pnAttack, pnAttack + nInputN);

	for (int i = 0; i < nInputM; i++)
	{
		bFlag = false;
		for (int j = nPreAttack; j < nInputN; j++)
		{
			if (pnAttack[j] > pnDefence[i])
			{
				pnAttack[j] = 0;
				nPreAttack = j + 1;
				bFlag = true;
				break;
			}
		}
		if (!bFlag)
		{
			printf("0");
			return 0;
		}
	}

	for (int i = 0; i < nInputN; i++)
		nAns += pnAttack[i];

	printf("%d", nAns);








			

Exit0:

	return 0;
}