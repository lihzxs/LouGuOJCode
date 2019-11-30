/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-14 22:20
//	Comment		:	OJ(P1867)
//
///////////////////////////////////////////

//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <stack>
#include <string>
#include <string.h>
using namespace std;
#define	MAXNUM		5
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
	int			nInputX;
	double		fLifeValue		= 10;	
	double		fInputHurt;
	int			nInputExam;
	int			nSumExam		= 0;
	int			nAnsGrade		= 0;
	int			nAnsExam;

	scanf("%d", &nInputX);
	
	for (int i = 0; i < nInputX; i++)
	{
		scanf("%lf%d", &fInputHurt, &nInputExam);
		fLifeValue -= fInputHurt;
		if (fLifeValue > 10)
			fLifeValue = 10;
		if (fLifeValue <= 0)
		{
			while (nSumExam >= pow(2, nAnsGrade))
			{
				nSumExam -= pow(2, nAnsGrade);
				nAnsGrade++;
			}
			nAnsExam = nSumExam;
			printf("%d %d\n", nAnsGrade, nAnsExam);
			return 0;
		}
		nSumExam += nInputExam;

	}
	
	while (nSumExam >= pow(2, nAnsGrade))
	{
		nSumExam -= pow(2, nAnsGrade);
		nAnsGrade++;
	}
	nAnsExam = nSumExam;
	printf("%d %d\n", nAnsGrade, nAnsExam);






Exit0:

	return 0;
}







