// tstG5e.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#include <stdlib.h>  
#include <stdio.h> 
#include <conio.h>
#include <iostream>
#include <string>
#include <ctime>
#include "stdafx.h"
#include "tst.h"
#include "txtExmpl.h"
using namespace std;
//******************************

	int main()
	{
		//1. ������ � ������� (int).
		CArray <int> m_intArr = CArray<int>();
		//	1.1. ���������� � ����� 20 ��������� ����� � ��������� �� 0 �� 100.
		srand( time(0) );
		unsigned int ArrayLength = 20;
		unsigned int i = 0;
		for (; i < ArrayLength ; i++)
		{
			int u = rand() % (100);  
			m_intArr.push_back(u);
		}
		printf("\n******** Integrers **********\n\n");
		printf("Let new int array:\n");
		for ( i = 0; i < ArrayLength ; i++)
		{
			int val = m_intArr[i];
			printf("%d ",val); //m_intArr[i]);
		}
		

		//	1.2. �������������� ������������� ������ ����� �� �����������.
		m_intArr.bubbleSort();
		printf("\n\nSorted array:\n");
		for ( i = 0; i < ArrayLength ; i++)
		{
			printf("%d ",m_intArr[i]);
		}

		//	1.3. �������� ������� 2 ��������.
		i = 0;
		while(i++ <= 10)
		{
			m_intArr.erase(i) ;
		}
		ArrayLength = m_intArr.size();

		printf("\n\nArray restricted evry second item:\n");
		for ( i = 0; i < ArrayLength ; i++)
		{
			printf("%d ",m_intArr[i]);
		}

		//	1.4. ������� 10 ��������� ����� � ��������� �� 0 �� 100 �� ��������� �������.

		
		i = 0;
		srand( time(0) );
		while(i++ < 10)
		{
			int posToInsert = rand() % (ArrayLength);
			int newValue = rand() % (100);
			m_intArr.insert(posToInsert,newValue);
			ArrayLength = m_intArr.size();
		}
		printf("\n\nAdd random item on random position:\n");
		for ( i = 0; i < ArrayLength ; i++)
		{
			printf("%d ",m_intArr[i]);
		}

		
		//	1.5. ������� ����������.
		m_intArr.clear();

		//		2. ������ � ��������� (std:string).
		printf("\n\n******** Strings **********\n");
		CArray <std::string> m_ExmplStrngs = CArray<std::string>(); // ������������� ��������� ��� ��������� ������
		

		char*pCh = (char*)chTxt;
		char *temp = new char[64];
		memset(temp,0,64);
		int cnt =0;
		while(*pCh != 0)
		{
			temp[cnt] = *pCh;
			cnt++;
			pCh++;

			if((*pCh == ' ')|| //  
				(*pCh == '-'))// �������������� ����� '-'
			{
				temp[cnt] =0;
				
				if((islower(temp[0])) && (cnt > 2)) //  � ������ �������� � �������� �������� ��������
				{
					if((temp[cnt-1]=='.')||
						(temp[cnt-1]==','))
						temp[cnt-1]= 0; // �������� ����� ��� �������
				 m_ExmplStrngs.push_back(string(temp));
				}
				cnt = 0;
				pCh++;
			}
		}

		printf("\nlowercase words from text:\n");
		for ( i = 0; i < m_ExmplStrngs.size() ; i++)
		{
			printf(m_ExmplStrngs[i].c_str());
			printf(" ");
		}

		//2.1. ���������� � ����� 15 �������� ��������� ����, ��������� �� ��������� ���� � ������ ��������.
		CArray <std::string> m_TargetStrngs = CArray<std::string>(); // ����� ���������

		i = 0;
		srand( time(0) );
		while(i++ < 15)
		{
			int posToChoice = rand() % (m_ExmplStrngs.size());
			string tStr = m_ExmplStrngs[posToChoice];
			m_TargetStrngs.push_back(tStr);
		}


		printf("\n\nRandom 15 words from text:\n");
		for ( i = 0; i < m_TargetStrngs.size() ; i++)
		{
			printf(m_TargetStrngs[i].c_str());
			printf(" ");
		}

		//2.2. �������������� ������������� ������ ���� �� �����������.
		m_TargetStrngs.bubbleSort();
		printf("\n\nSorted words :\n");
		for ( i = 0; i < m_TargetStrngs.size() ; i++)
		{
			printf(m_TargetStrngs[i].c_str());
			printf(" ");
		}
		//2.3. �������� ������� �����, ����������� � ���� ����� �� ���� a, b, c, d, e.
		for ( i = 0; i < m_TargetStrngs.size() ; )
		{
			string tStr = m_TargetStrngs[i];
			if((tStr.find("a") != string.npos)||
				(tStr.find("b") != string.npos)||
				(tStr.find("c") != string.npos)||
				(tStr.find("d") != string.npos)||
				(tStr.find("e") != string.npos))
			{
				m_TargetStrngs.erase(i);
				continue;
			}
			i++;
		}
		printf("\n\nDeleted words with included 'a' or 'b' or 'c' or 'd' or 'e' :\n");
		if(m_TargetStrngs.size() == 0)
			printf("--- Array empty --\n");
		else
		{
			for ( i = 0; i < m_TargetStrngs.size() ; i++)
			{
				printf(m_TargetStrngs[i].c_str());
				printf(" ");
			}
		}
		//2.4. ������� 3 ����� �������� ��������� ���� �� ��������� �������.
		i = 0;
		srand( time(0) );
		while(i++ < 3)
		{
			int pos = rand() % (m_ExmplStrngs.size());
			string tStr = m_ExmplStrngs[pos];
			
			if(m_TargetStrngs.size() == 0)
				pos =0;
			else
			 pos = rand() % (m_TargetStrngs.size());

			m_TargetStrngs.insert(pos,tStr);
		}
		printf("\n\nInserted 3 random words on random position :\n");
		for ( i = 0; i < m_TargetStrngs.size() ; i++)
			{
				printf(m_TargetStrngs[i].c_str());
				printf(" ");
			}

		getch();
		return 0;
	}
//}

