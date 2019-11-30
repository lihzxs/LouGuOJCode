/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-17 17:52
//	Comment		:	OJ(P2670)
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
#include <set>
using namespace std;
#define	MAXNUM		1000000000
#define	EPS         0.0001


#define ERROR_ID    0

#define PROCESS_ERROR(Condition)    \
{                                   \
        if (!(Condition))           \
        {                           \
            goto Exit0;             \
        }                           \
}


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int PrimeInit(unsigned int* punSeq, BYTE* pbyIsPrime)
{
	int		nIndex = 0;
	memset(pbyIsPrime, 1, MAXNUM * sizeof(BYTE));
	for (int i = 2; i < MAXNUM; i++)
	{
		if (pbyIsPrime[i])
		{
			punSeq[nIndex++] = i;
			for (int j = i * 2; j < MAXNUM; j += i)
				pbyIsPrime[j] = 0;
		}
	}
	return nIndex;
}







int main(int argc, char* argv[])
{

	int					nInputN;
	int					nInputM;
	int					nX;
	int					nY;
	int					nStartX;
	int					nStartY;
	string				szInput;
	int					nSum				= 0;
	int**				ppnMat				= NULL;




	scanf("%d%d", &nInputN, &nInputM);


	ppnMat = (int**)malloc(nInputN * sizeof(int*));
	for (int i = 0; i < nInputN; i++)
		ppnMat[i] = (int*)malloc(nInputM * sizeof(int));


	for (int i = 0; i < nInputN; i++)
	{
		cin >> szInput;
		for (int j = 0; j < nInputM; j++)
			ppnMat[i][j] = (szInput[j] == '*');
	}


	for (int i = 0; i < nInputN; i++)
	{
		for (int j = 0; j < nInputM; j++)
		{
			if (ppnMat[i][j])
				printf("*");
			else
			{
				nY = i - 1;
				nX = j - 1;
				for (nX < 0 ? nStartX = 0 : nStartX = nX; nStartX <= nX + 2 && 
					nStartX < nInputM; nStartX++)
					for (nY < 0 ? nStartY = 0 : nStartY = nY; nStartY <= nY + 2 && 
						nStartY < nInputN; nStartY++)
						if (ppnMat[nStartY][nStartX])
							nSum++;

				printf("%d", nSum);
				nSum = 0;
			}
		}
		printf("\n");
	}











	



Exit0:

	return 0;
}



