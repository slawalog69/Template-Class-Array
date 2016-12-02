//#pragma once

#include <stdlib.h>  
#include <stdio.h> 
#include <conio.h>
#include <iostream>
#include "stdafx.h"


//******************************
template <typename TData>
class CArray
{
public: // Interface

	// Конструктор по умолчанию
	CArray();

	// Копирующий конструктор
	CArray(
		const CArray & _array
		);
	//******************************
	CArray(
		TData* _array,
		int len
		);
	// Деструктор
	~CArray();

	// Добавить элемент в конец массива
	void push_back(
		const TData & _value
		);

	// Добавить элемент в массив по заданному индексу
	void insert(
		unsigned int  _index,
		const TData & _value
		);

	// Удалить элемент массива по заданному индексу
	void erase(
		unsigned int _index
		);

	// изменение размера массива
	void resizeArr(
		int _new_size
		);

	// Очистить массив
	void clear();

	// Получить размер массива
	unsigned int size(); // const;

	// Получить элемент массива по заданному индексу
	TData & operator[](
		unsigned int _index
		)
	{
		if(_index < CurrentLenTData)
			return pTData[_index];
	};

	// сортировка пузырьковым методом
	void bubbleSort();
	

protected: // Attributes
	unsigned int CurrentLenTData,i;
	TData * pTData;

};




//******************************

template <typename TData>
CArray<TData>::CArray()
{
	pTData =  new TData;
	CurrentLenTData = 0;
};
//******************************
template <typename TData>
CArray<TData>::CArray(
   TData* _array,
   int len
  )
{
	CurrentLenTData = len;
	pTData =  new TData[len];
	//for (i = 0; i < (CurrentLenTData) ; i++)
	//{
	//	pTData[i] = _array[i];
	//}
	memcpy(pTData,_array,len*sizeof(TData));
	
};
//******************************
template <typename TData>
CArray<TData>::CArray(
  const CArray & _array
  )
{
	CurrentLenTData = _array.CurrentLenTData;
	pTData = _array.pTData;
	
};

//******************************
template <typename TData>
CArray<TData>::~CArray()
{
	if(pTData != NULL)
		delete [] pTData;
	pTData = NULL;
};
//***************************

template <typename TData>
void CArray<TData>::insert(
	unsigned int  _index,
	const TData & _value
	)
{
	CurrentLenTData ++;
	TData *new_arr = new TData [CurrentLenTData];
	TData * pSrc = pTData;
	TData * pDest = new_arr;
	for (i = 0; i < (CurrentLenTData) ; i++)
	{
		if(i == _index)
		{
			*pDest = _value;
			pDest++;
			continue;
		}
		*pDest = *pSrc;
		pDest++;
		pSrc++;
	}

	delete [] pTData;
	pTData = new_arr;
};

//****************************
template <typename TData>
void CArray<TData>::erase(
  unsigned int _index
  )
{
	if(_index >= CurrentLenTData)
		return;
	
	TData *new_arr = new TData [CurrentLenTData-1];
	TData * pSrc = pTData;
	TData * pDest = new_arr;
	for (i = 0; i < (CurrentLenTData) ; i++)
	{
		if(i == _index)
		{
			pSrc++;
			continue;
		}
		*pDest = *pSrc;
		pDest++;
		pSrc++;
	}
   CurrentLenTData --;
	delete [] pTData;
	pTData = new_arr;

};
//*******************************
template <typename TData>
void CArray<TData>::push_back(
  const TData & _value
  )
{
	if(CurrentLenTData == 0)
	{
		pTData[0] = _value;
		CurrentLenTData = 1;
		return;
	}
	resizeArr(CurrentLenTData+1);
	pTData[CurrentLenTData-1]=_value;

};
//******************************
template <typename TData>
unsigned int CArray<TData>::size()
{
	return CurrentLenTData;

};
//******************************
template <typename TData>
void CArray<TData>::clear()
{
	delete [] pTData;
	CurrentLenTData =0;
};

//******************************
template <typename TData>
void CArray<TData>::resizeArr(
  int _new_size
  )
{
	
	TData *new_arr = new TData [_new_size];
	for (i = 0;  i < CurrentLenTData ; i++)
		new_arr[i] = pTData[i];
	CurrentLenTData =  _new_size;
	pTData = new_arr;
}

//******************************
template <typename TData>
void CArray<TData>::bubbleSort( )
{
	TData tmp;

	for(i = 0; i < CurrentLenTData - 1; i++) 
	{            
		for(unsigned int j = 0; j < CurrentLenTData - 1; j++) 
		{     
			if (pTData[j + 1] < pTData[j]) 
			{
				tmp = pTData[j + 1]; 
				pTData[j + 1] = pTData[j]; 
				pTData[j] = tmp;
			}
		}
	}
}


