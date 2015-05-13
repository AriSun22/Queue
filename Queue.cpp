// Очередь.cpp: определяет точку входа для консольного приложения.
/*!
\file Sortir.cpp
\brief Заголовочный файл с описанием классов

Данный файл содержит в себе определения основных 
классов, используемых в демонстрационной программе
*/
#include "stdafx.h"
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <time.h>

using namespace std;


struct Queue
{
	int *arr; //!< Указатель
	int first; //!< Переменная Первый (элемент)
	int last; //!< Переменная Последний (элемент)
	int count; //!< Переменная Итоговый (элемент)
	int size; //!< Переменная Максимальный размер очереди
	
};

/**
	Функция инициализации очереди
	*/

void Initial (int N, Queue *&p) //Инициализация очереди
{
	p = new Queue[N];
	p->arr = new int[N];
	p->first = 0;
	p->last = 0;
	p->count = 0;
	p->size = N;

}

bool Full (Queue *&p)//Проверка на полноту
{
	if (p->count == p->size)
		return true;
	else
		return false;
}


bool Empty (Queue *&p) //Проверка на пустоту
{
	if (p->count == 0)
		return true;
	else
		return false;
}

/**
	Функция добавления элемета в очередь
	*/
void add (int a, Queue *&p)//Добавление в очередь
{
	if (Full(p) == false)
	{
		p->arr[p->last] = a;
		p->last ++;
		if (p->last == p->size)
		p->last = 0;
		p->count ++;
	}
	else
		cout << endl;// "Ошибка! Очередь полна." 
}

/**
	Функция удаления элемента из очереди
	*/
void del (Queue *&p)//Удаление из очереди
{
	if (Empty(p) == false)
	{
		p->arr[p->first] = 0;
		p->first ++;
		if (p->first == p->size)
		p->first = 0;
		p->count --;
	}
	else
		cout << endl; //"Ошибка! Очередь пуста."
}

/**
	Функция вывода очереди
	*/
void Show(Queue *p) //Вывод очереди
{
	int i,temp; 
	for (i = p->first, temp=0; temp < p->count ; temp ++, i++) 
	{ 
		if (i == p->size) 
			i = 0; 
		cout << p->arr[i] << " "; 
	}
	cout << "\n";
}

//!Главная функция
int _tmain()
{
	setlocale(LC_ALL, "rus");

	Queue *p;
//	cout <<"Введите размер очереди: ";
	
	Initial (10, p);// Инициализируем очередь
	int n = 0; //кол-во операций
	cin >> n;

	int data;
	int num;
	char op;
	for (int i = 0; i < n; i++) //изначально, заполним список
	{	
		cin >> op;
		if(op=='a')
		{
			cin >> data;
			add(data, p);
		}
		else
		if(op=='d')
		{
			del(p);
		}
		
		
	}

	Show(p);


	system ("pause");
	return 0;
}
