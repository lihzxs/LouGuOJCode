/////////////////////////////////////////////

//
//	FileName	:	First.cpp
//	Creator		:	Fm
//	Date		:	2019-9-14 15:46
//	Comment		:	OJ(P2955)
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
using namespace std;
#define	MAXNUM		7
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

class LuckTicket
{
public:
	LuckTicket();
	~LuckTicket();
	BOOL		Init();
	void		UnInit();
	BOOL		SetNums(int* pnNums);
	int			WinNumCount(int* pnWinNums);

private:
	int*		m_pnNums;
};

LuckTicket::LuckTicket()
{
	m_pnNums			= NULL;
}

LuckTicket::~LuckTicket()
{

}
BOOL LuckTicket::Init()
{
	BOOL		bResult = false;

	m_pnNums = (int *)malloc(MAXNUM * sizeof(int));
	PROCESS_ERROR(m_pnNums);

	bResult = true;
Exit0:
	if (!bResult)
	{
		if (m_pnNums)
		{
			free(m_pnNums);
			m_pnNums = NULL;
		}
	}
	return bResult;
}

void LuckTicket::UnInit()
{
	if (m_pnNums)
	{
		free(m_pnNums);
		m_pnNums = NULL;
	}
}

BOOL LuckTicket::SetNums(int* pnNums)
{
	BOOL		bResult = false;

	PROCESS_ERROR(pnNums);

	for (int i = 0; i < MAXNUM; i++)
		m_pnNums[i] = pnNums[i];

	bResult = true;

Exit0:
	if (!bResult)
	{
		if (m_pnNums)
		{
			free(m_pnNums);
			m_pnNums = NULL;
		}
	}
	return bResult;

}

int LuckTicket::WinNumCount(int* pnWinNums)
{
	int		nRetNum		= -1;

	PROCESS_ERROR(pnWinNums);
	nRetNum = 0;
	for (int i = 0; i < MAXNUM; i++)
	{
		for (int j = 0; j < MAXNUM; j++)
		{
			if (pnWinNums[i] == m_pnNums[j])
			{
				nRetNum++;
				break;
			}
		}///for (int j = 0; j < MAXNUM; j++)
	}///for (int i = 0; i < MAXNUM; i++)

Exit0:
	return nRetNum;
}



int main(int argc, char* argv[])
{
	BOOL		bLuckTicketTempInit	= false;
	BOOL		bRetCode			= false;
	int*		pnWinNums			= NULL;
	int*		pnLuckTicketNums	= NULL;
	int*		pnAnsSeq			= NULL;
	int			nInputNum;
	LuckTicket	LuckTicketTemp;

	bRetCode = LuckTicketTemp.Init();
	PROCESS_ERROR(bRetCode);
	bLuckTicketTempInit = true;

	pnWinNums			= (int*)malloc(MAXNUM * sizeof(int));
	PROCESS_ERROR(pnWinNums);
	pnLuckTicketNums	= (int*)malloc(MAXNUM * sizeof(int));
	PROCESS_ERROR(pnLuckTicketNums);
	pnAnsSeq = (int*)malloc(MAXNUM * sizeof(int));
	PROCESS_ERROR(pnAnsSeq);
	memset(pnAnsSeq, 0, MAXNUM * sizeof(int));

	bRetCode = scanf("%d", &nInputNum);
	PROCESS_ERROR(bRetCode);

	for (int i = 0; i < MAXNUM; i++)
	{
		bRetCode = scanf("%d", pnWinNums + i);
		PROCESS_ERROR(bRetCode);
	}

	for (int j = 0; j < nInputNum; j++)
	{
		for (int i = 0; i < MAXNUM; i++)
		{
			bRetCode = scanf("%d", pnLuckTicketNums + i);
			PROCESS_ERROR(bRetCode);
		}
		bRetCode = LuckTicketTemp.SetNums(pnLuckTicketNums);
		PROCESS_ERROR(bRetCode);
		pnAnsSeq[MAXNUM - LuckTicketTemp.WinNumCount(pnWinNums)]++;
	}

	bRetCode = printf("%d", pnAnsSeq[0]);
	PROCESS_ERROR(bRetCode);
	for (int i = 1; i < MAXNUM; i++)
	{
		bRetCode = printf(" %d", pnAnsSeq[i]);
		PROCESS_ERROR(bRetCode);
	}
	bRetCode = printf("\n");
	PROCESS_ERROR(bRetCode);




Exit0:
	if (bLuckTicketTempInit)
	{
		LuckTicketTemp.UnInit();
		bLuckTicketTempInit = false;
	}
	if (pnLuckTicketNums) 
		free(pnLuckTicketNums);
	if (pnWinNums)
		free(pnWinNums);

	return 0;
}







