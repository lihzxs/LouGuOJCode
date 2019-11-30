/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-20 23:02
//	Comment		:	OJ(P1555)
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
#define	MAXNUM		10010
#define	EPS         0.001
#define MODNUM		100003


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;


int main(int argc, char* argv[])
{
	vector<int>			vNum2;
	vector<int>			vNum3;
	char				cTemp;
	string				szNum1;
	string				szNum2;
	int					nTemp;
	cin >> szNum1;
	cin >> szNum2;



	for (int i = 0; i < szNum2.length(); i++)
	{
		cTemp = szNum2[i];
		for (int j = 0; j <= 2; j++)
		{
			nTemp = 0;
			szNum2[i] = j + '0';
			for (int k = 0; k < szNum2.length(); k++)
				if (szNum2[k] - '0' != 0)
					nTemp += (szNum2[k] - '0') *
					pow(3, (szNum2.length() - k - 1));
			vNum3.push_back(nTemp);
		}
		szNum2[i] = cTemp;
	}

	sort(vNum3.begin(), vNum3.end());

	for (int i = 0; i < szNum1.length(); i++)
	{
		cTemp = szNum1[i];
		for (int j = 0; j <= 1; j++)
		{
			nTemp = 0;
			szNum1[i] = j + '0';
			for (int k = 0; k < szNum1.length(); k++)
				if (szNum1[k] - '0' != 0)
					nTemp += (szNum1[k] - '0') *
					pow(2, (szNum1.length() - k - 1));
			if (*(lower_bound(vNum3.begin(), vNum3.end(), nTemp)) == nTemp)
			{
				printf("%d", nTemp);
				return 0;
			}
		}
		szNum1[i] = cTemp;
	}

Exit0:
	return 0;
}