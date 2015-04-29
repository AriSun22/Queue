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

int n; //размерность очереди

struct Queue
{
	int *arr; //!< Указатель
	int first; //!< Переменная Первый (элемент)
	int last; //!< Переменная Последний (элемент)
	int count; //!< Переменная Итоговый (элемент)
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
}

bool Full (Queue *&p)//Проверка на полноту
{
	if (p->count == n)
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
		if (p->last == n)
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
		if (p->first == n)
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
		if (i == n) 
			i = 0; 
		cout << p->arr[i] << " "; 
	}
}

//!Главная функция
int _tmain()
{
	setlocale(LC_ALL, "rus");

	Queue *p;
//	cout <<"Введите размер очереди: ";
	cin >> n;
	Initial (n, p);// Инициализируем очередь

	int data;
	for (int i = 0; i < n; i++)//заполняем ее
	{	
	cin >> data;
	add (data, p);
	}
	Show (p);
	cout << endl;
	cout<<endl; //"После удаления:" 
	del (p);
	Show (p);

	system ("pause");
	return 0;
}
