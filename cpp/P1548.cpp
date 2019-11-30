/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-17 21:04
//	Comment		:	OJ(P1548)
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
#define	MAXNUM		100010
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
	memset(pbyIsPrime, true, MAXNUM * sizeof(BYTE));
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
	int				nInputN;
	int				nInputM;
	int				nCountRec			= 0;
	int				nCountSqu			= 0;

	scanf("%d%d", &nInputN, &nInputM);
	for (int i = 0; i <= nInputN; i++)
	{
		for (int j = 0; j <= nInputM; j++)
		{
			for (int k = i + 1; k <= nInputN; k++)
			{
				for (int l = j + 1; l <= nInputM; l++)
				{
					if ((k - i) != (l - j))
						nCountRec++;
					else
						nCountSqu++;
				}
			}
		}///for (int j = 1; j <= nInputM; j++)
	}///for (int i = 1; i <= nInputN; i++)

	printf("%d %d", nCountSqu, nCountRec);

Exit0:

	return 0;
}



