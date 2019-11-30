/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-10 19:46
//	Comment		:	OJ(P2614)
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

using namespace std;
#define	MAXNUM		2000001
#define	EPS         0.0001
#define MODNUM		2000001


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;





int main(int argc, char* argv[])
{
	int				nInputN;
	int				nInputT;
	string			szInput;
	double			fSum			= 0;
	int				nCount			= 0;
	double			fPre			= 0;
	char			cPre			= 0;
	char			cPrePre			= 0;

	//scanf("%d%d", &nInputN, &nInputT);
	cin >> nInputN >> nInputT;
	while (cin >> szInput)
	{
		for (int j = 0; j < szInput.length(); j++)
		{
			
			if (szInput[j] == '(')
				nCount++;
			else if (szInput[j] == ')')
				nCount--;
			else if ((szInput[j] >= '0' && szInput[j] <= '9') ||
				szInput[j] == '+' || szInput[j] == '<' || szInput[j] == '*' ||
				szInput[j] == '/' || szInput[j] == '=' || szInput[j] == '%' ||
				szInput[j] == 'C' || szInput[j] == 'M' || szInput[j] == '-')
			{
				if (nCount == 0)
					fPre = 1.0;
				else
				{
					fPre = 1.0 / pow(2, nCount);
				}
				fSum += fPre;
			}
			//else if (szInput[j] == '-')
			//{
			//	fSum -= fPre;
			//	if (cPre == '-' && cPrePre == '-')
			//		fPre *= 2.0;
			//	else if (cPre == '-' && cPrePre != '-')
			//	{
			//		fPre /= 2;
			//		fPre *= 3;
			//	}
			//	else if (cPre != '-')
			//		fPre *= 2.0;
			//	fSum += fPre;
			//}
			else if (szInput[j] == '.')
			{
				fSum -= fPre;
				fPre *= 1.5;
				fSum += fPre;
			}
			if (szInput[j] != ' ' && szInput[j] != '\n')
			{
				cPrePre = cPre;
				cPre = szInput[j];
			}
				
		}
	}

	printf("%.0f", fSum * 60.0 / nInputT );



Exit0:

	return 0;
}