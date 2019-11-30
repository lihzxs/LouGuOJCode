/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-13 13:50
//	Comment		:	OJ(P432)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <string>
using namespace std;
#define  MAXNUM		42

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



int main(int argc, char* argv[])
{
	unsigned int*			punSeq			= NULL;
	int						nAns			= 0;
	int						nCountTemp		= 0;
	int						nNum;
	int						nInputTemp;
	


	scanf("%d", &nNum);

	punSeq = (unsigned int*)malloc(nNum * sizeof(unsigned int));
	//memset(punSeq, 0, MAXNUM * sizeof(unsigned int));

	
	for (int i = 0; i < nNum; i++)
	{
		scanf("%d", &nInputTemp);
		punSeq[i]	= nInputTemp;
		nCountTemp	= 0;
		for (int j = 0; j < i; j++)
		{
			if (punSeq[j] < punSeq[i])
				nCountTemp++;
		}
		if (i == 0) 
			printf("0");
		else
			printf(" %d", nCountTemp);
	}
	printf("\n");
		
	

		



Exit0:

	return 0;
}







