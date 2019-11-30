/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-17 22:41
//	Comment		:	OJ(P4327)
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
	string			szInput;
	string*			pszAnsMat				= NULL;
	pszAnsMat = new string[5];
	cin >> szInput;
	pszAnsMat[0] = "..#...#...*...#...#...*...#...#...*...#...#...*...#...#...*..";
	pszAnsMat[1] = ".#.#.#.#.*.*.#.#.#.#.*.*.#.#.#.#.*.*.#.#.#.#.*.*.#.#.#.#.*.*.";
	pszAnsMat[2] = "#.X.#.X.*.X.*.X.#.X.*.X.*.X.#.X.*.X.*.X.#.X.*.X.*.X.#.X.*.X.*";
	pszAnsMat[3] = ".#.#.#.#.*.*.#.#.#.#.*.*.#.#.#.#.*.*.#.#.#.#.*.*.#.#.#.#.*.*.";
	pszAnsMat[4] = "..#...#...*...#...#...*...#...#...*...#...#...*...#...#...*..";

	for (int i = 0; i < szInput.length(); i++)
	{
		pszAnsMat[2][i * 4 + 2] = szInput[i];
	}
	
	if (szInput.length() % 3 != 0)
		pszAnsMat[2][szInput.length() * 4] = '#';
	for (int i = 0; i < 4 * szInput.length() + 1; i++)
		printf("%c", pszAnsMat[0][i]);
	printf("\n");
	for (int i = 0; i < 4 * szInput.length() + 1; i++)
		printf("%c", pszAnsMat[1][i]);
	printf("\n");
	for (int i = 0; i < 4 * szInput.length() + 1; i++)
		printf("%c", pszAnsMat[2][i]);
	printf("\n");
	for (int i = 0; i < 4 * szInput.length() + 1; i++)
		printf("%c", pszAnsMat[3][i]);
	printf("\n");
	for (int i = 0; i < 4 * szInput.length() + 1; i++)
		printf("%c", pszAnsMat[4][i]);
	printf("\n");






Exit0:

	return 0;
}



