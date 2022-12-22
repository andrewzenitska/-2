#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <sstream>

using namespace std;

template <class T>
class Keeper {
	T* ptr_mas;
	int size;

public:
	Keeper()
	{
		size = 0;
		ptr_mas = nullptr;
	};
	~Keeper()
	{
		delete[] ptr_mas;
	};

	void save(string);
	void read(string);
	void add();
	void del(int index);
	void print();
	void redaction(int index);
	void search_tel();
	void sort_data();
	void beasts(int index);
};

template<class T>
void Keeper<T>::save(string s) {
	ofstream fout(s, ios::out);
	try {
		if (size == 0)
			throw exception("Данных для сохранения недостаточно");

		fout << size << endl;
		for (int i = 0; i < size; i++) {
			fout << ptr_mas[i] << endl;
		}
		cout << "Данные сохранены в файл" << endl;
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}
	fout.close();
}

template<class T>
void Keeper<T>::read(string s) {
	ifstream fin(s, ios::in);
	fin >> size;

	if (ptr_mas != nullptr)
	{
		delete[] ptr_mas;
	}

	ptr_mas = new T[size];


	for (int i = 0; i < size; i++) {
		fin >> ptr_mas[i];
	}

	cout << "Данные из файла успешно скопированы" << endl;
	fin.close();
}

template<class T>
void Keeper<T>::add() {
	T* tmp = new T[size + 1];
	for (int i = 0; i < size; i++) {
		tmp[i] = ptr_mas[i];
	}
	delete[] ptr_mas;
	cin >> tmp[size];
	ptr_mas = tmp;
	size++;
	cout << "Данные успешно добавлены" << endl;
}

template<class T>
void Keeper<T>::del(int index) {
	if (size == 0)
		cout << "Нет данных для удаления" << endl;
	else {

		try {

			if (index > size - 1 || index < 0)
				throw exception("Удаление по данному индексу невозможно");
		}
		catch (exception& ex) {
			while (index < 0 || index > size - 1) {
				cout << ex.what() << endl;
				cout << "Введите индекс: " << endl;
				cin >> index;
			}
		}

		T* tmp = new T[size - 1];
		int j = 0;
		for (int i = 0; i < size; i++) {
			if (i != index)
				tmp[j++] = ptr_mas[i];
		}
		delete[] ptr_mas;
		ptr_mas = tmp;
		size--;
		cout << "Удалено!" << endl;
	}
}

template<class T>
void Keeper<T>::redaction(int index) {

	if (size == 0)
		cout << "Редактировать нечего!" << endl;
	else {

		try {

			if (index > size - 1 || index < 0)
				throw exception("Редактирование по данному индексу невозможно!");
		}
		catch (exception& ex) {
			while (index < 0 || index > size - 1) {
				cout << ex.what() << endl;
				cout << "Введите индекс заново: " << endl;
				cin >> index;
			}
		}


		T* tmp = new T[size];
		int j = 0;
		for (int i = 0; i < size; i++) {
			if (i != index) {
				tmp[j++] = ptr_mas[i];
			}
			else {
				cout << ptr_mas[i] << endl;
				ptr_mas[i].redact(ptr_mas[i]);
			}
		}

		cout << "Объект успешно отредактирован" << endl;
	}
}

template<class T>
void Keeper<T>::search_tel() {
	string tel;
	int cnt = 0;
	cout << "Введите номер телефона: ";
	cin >> tel;
	if (size == 0)
		cout << "Невозможно!" << endl;
	else {

		for (int i = 0; i < size; i++) {

			if (ptr_mas[i].search(ptr_mas[i], tel))
			{
				cout << ptr_mas[i] << endl;
			}
			else {
				cnt++;
			}
		}
	}
	if (cnt == size)
	{
		cout << "Ничего не найдено!" << endl;
	}
}


template<class T>
void Keeper<T>::sort_data() 
{
	if (size == 0) {
		cout << "Невозможно!" << endl;
	}
	else {
		T tmp;
		for (int i = 0; i < size; i++) {
			for (int j = (size - 1); j >= (i + 1); j--) {
				if (ptr_mas[j].sort(ptr_mas[j]) < ptr_mas[j - 1].sort(ptr_mas[j - 1])) {
					tmp = ptr_mas[j];
					ptr_mas[j] = ptr_mas[j - 1];
					ptr_mas[j - 1] = tmp;
				}
			}
		}
	}
}

template<class T>
void Keeper<T>::print() 
{
	sort_data();
	int j = 1;
	if (size == 0)											
		cout << "Недостаточно данных для вывода!" << endl;
	else
			for (int i = 0; i < size; i++) 
			{
				for (j; j < size+1; j++)
				{
					
					cout << "Человек № - " << j << endl;
					break;
				}
				j++;
				cout << ptr_mas[i] << endl;
			}
}

template<class T>
void Keeper<T>::beasts(int index)
{
	if (size == 0)
		cout << "Нет данных для удаления" << endl;
	else {

		try {

			if (index > size - 1 || index < 0)
				throw exception("Удаление по данному индексу невозможно");
		}
		catch (exception& ex) {
			while (index < 0 || index > size - 1) {
				cout << ex.what() << endl;
				cout << "Введите индекс: " << endl;
				cin >> index;
			}
		}
		T* tmp = new T[size];
		int j = 0;
		int c = 1;
		for (int i = 0; i < size; i++) {
			if (i != index) {
				tmp[j++] = ptr_mas[i];
			}
			else {
				cout << ptr_mas[i] << endl;
				cout << "Человек по китайскому гороскопу родился в год ";
				ptr_mas[i].beast(ptr_mas[i]);
				cout << endl;
			}
		}
	}
}