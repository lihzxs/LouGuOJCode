/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-19 16:57
//	Comment		:	OJ(P1478)
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
#define ERROR_ID    0

typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

typedef struct SHeight_Strenght
{
	int		nHeight;
	int		nStrenght;
}SHeight_Strenght;

BOOL cmp(const SHeight_Strenght sFirst,
	const SHeight_Strenght sSecond)
{
	return sFirst.nStrenght < sSecond.nStrenght;
}


int main(int argc, char* argv[])
{

	int					nInputN;
	int					nInputS;
	int					nInputA;
	int					nInputB;
	int					nAns					= 0;
	SHeight_Strenght*	psAppleSeq				= NULL;

	scanf("%d%d", &nInputN, &nInputS);
	scanf("%d%d", &nInputA, &nInputB);

	psAppleSeq = (SHeight_Strenght*)malloc(nInputN * 
		sizeof(SHeight_Strenght));



	for (int i = 0; i < nInputN; i++)
	{
		scanf("%d%d", &psAppleSeq[i].nHeight, 
			&psAppleSeq[i].nStrenght);
	}

	sort(psAppleSeq, psAppleSeq + nInputN, cmp);

	for (int i = 0; i < nInputN; i++)
	{
		if (psAppleSeq[i].nHeight <= nInputA + nInputB &&
			psAppleSeq[i].nStrenght <= nInputS)
		{
			nAns++;
			nInputS -= psAppleSeq[i].nStrenght;
		}
	}

	printf("%d", nAns);


Exit0:





	return 0;
}


