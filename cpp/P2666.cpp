/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-18 10:40
//	Comment		:	OJ(P2666)
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
#define	MAXNUM		20
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








int main(int argc, char* argv[])
{
	int				nInputN;
	int				nAns = 0;
	scanf("%d", &nInputN);

	for (int i = 0; i <= 100; i++)
		for (int j = 0; j <= 100; j++)
			for (int k = 0; k <= 100; k++)
				for (int l = 0; l <= 100; l++)
					if (i * i + j * j + k * k + l * l == nInputN)
						nAns++;

	printf("%d", nAns);
	






Exit0:

	return 0;
}



