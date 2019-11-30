/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-10 16:47
//	Comment		:	OJ(P1217)
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

inline bool IsPalindromes(const int& nNum)
{
	string		szTemp;
	szTemp = to_string(nNum);
	int i = 0;
	int j = szTemp.length() - 1;
	while (i < j)
	{
		if (szTemp[i] != szTemp[j])
			return false;
		i++;
		j--;
	}
		
	return true;
}


inline bool IsPrime(int& nNum)
{
	for (int i = 2; i <= int(sqrt(nNum)); i++)
		if (nNum % i == 0)
			return false;
	return true;
}

int main(int argc, char* argv[])
{
	int			nInputA;
	int			nInputB;
	set<int>	setOut;
	int			nTemp;

	scanf("%d%d", &nInputA, &nInputB);

	for (int i = 0; i <= 9; i++)
	{
		nTemp = i;
		if (nTemp >= nInputA && nTemp <= nInputB && IsPrime(nTemp))
			setOut.insert(nTemp);
		nTemp = i * 10 + i;
		if (nTemp >= nInputA && nTemp <= nInputB && IsPrime(nTemp))
			setOut.insert(nTemp);
		for (int j = 0; j <= 9; j++)
		{
			nTemp = i * 100 + j * 10 + i;
			if (nTemp >= nInputA && nTemp <= nInputB && IsPrime(nTemp))
				setOut.insert(nTemp);
			nTemp = i * 1000 + j * 100 + j * 10 + i;
			if (nTemp >= nInputA && nTemp <= nInputB && IsPrime(nTemp))
				setOut.insert(nTemp);
			for (int k = 0; k <= 9; k++)
			{
				nTemp = i * 10000 + j * 1000 + k * 100 + j * 10 + i;
				if (nTemp >= nInputA && nTemp <= nInputB && IsPrime(nTemp))
					setOut.insert(nTemp);
				nTemp = i * 100000 + j * 10000 + k * 1000 + k * 100 + j * 10 + i;
				if (nTemp >= nInputA && nTemp <= nInputB && IsPrime(nTemp))
					setOut.insert(nTemp);
				for (int z = 0; z <= 9; z++)
				{
					nTemp = i * 1000000 + j * 100000 + k * 10000 + z * 1000 + k * 100 + j * 10 + i;
					if (nTemp >= nInputA && nTemp <= nInputB && IsPrime(nTemp))
						setOut.insert(nTemp);
					nTemp = i * 10000000 + j * 1000000 + k * 100000 + z * 10000 + z * 1000 + k * 100 + j * 10 + i;
					if (nTemp >= nInputA && nTemp <= nInputB && IsPrime(nTemp))
						setOut.insert(nTemp);
				}

			}
		}
	}

	for (set<int>::iterator iter = setOut.begin(); iter != setOut.end(); ++iter)
		printf("%d\n", *iter);




Exit0:

	return 0;
}