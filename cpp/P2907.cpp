/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-16 21:25
//	Comment		:	OJ(P2907)
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
#define	MAXNUM		1000001
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

int			g_nCount		= 0;

void DFS(int nInputN, int nInputK)
{
	if (nInputN <= nInputK || 
		(nInputN + nInputK) % 2 != 0)
	{
		g_nCount++;
		return ;
	}
	DFS((nInputN + nInputK) / 2, nInputK);
	DFS(nInputN - (nInputN + nInputK) / 2, nInputK);
}



int main(int argc, char* argv[])
{
	int			nInputN;
	int			nInputK;

	scanf("%d%d", &nInputN, &nInputK);

	DFS(nInputN, nInputK);

	printf("%d", g_nCount);

Exit0:

	return 0;
}



