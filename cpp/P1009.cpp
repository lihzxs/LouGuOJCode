/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-10-8 23:29
//	Comment		:	OJ(P1009)
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
#define	MAXNUM		150
#define	EPS         0.0001
#define MODNUM		1006


typedef unsigned char       BYTE;
typedef int                 BOOL;
typedef unsigned long       DWORD;

string Output[60] = { "0","1","3","9","33","153","873","5913",
"46233","409113","4037913","43954713","522956313",
"6749977113","93928268313","1401602636313","22324392524313",
"378011820620313","6780385526348313","128425485935180313",
"2561327494111820313","53652269665821260313",
"1177652997443428940313","27029669736328405580313",
"647478071469567844940313","16158688114800553828940313",
"419450149241406189412940313","11308319599659758350180940313",
"316196664211373618851684940313","9157958657951075573395300940313",
"274410818470142134209703780940313","8497249472648064951935266660940313",
"271628086406341595119153278820940313","8954945705218228090637347680100940313",
"304187744744822368938255957323620940313","10637335711130967298604907294846820940313",
"382630662501032184766604355445682020940313","14146383753727377231082583937026584420940313","537169001220328488991089808037100875620940313",
"20935051082417771847631371547939998232420940313","836850334330315506193242641144055892504420940313","34289376947494122614363304694584807557656420940313","1439295494700374021157505910939096377494040420940313","61854558558074209658512637979453093884758552420940313","2720126133346522977702138448994068984204397080420940313","122342346998826717539665299944651784048588130840420940313","5624964506810915667389970728744906677010239883800420940313","264248206017979096310354325882356886646207872272920420940313","12678163798554051767172643373255731925167694226950680420940313","620960027832821612639424806694551108812720525606160920420940313","31035053229546199656252032972759319953190362094566672920420940313" };



int main(int argc, char* argv[])
{
	int				nInputN;

	cin >> nInputN;
	cout << Output[nInputN] << endl;

Exit0:
	return 0;
}