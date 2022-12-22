
#include <iostream>
#include "NOTE.h"
#include "keep.h"
#include "str.h"

using namespace std;

template <typename T>
void Menu(T& obj, string s) {
	int menu;
	int menup;
	int count;
	int index;
	string d = "";
	string out = "";
	int small = 1;
	while (small)
	{
		system("cls");
		int flag = 1;
		cout << "Выверите задание: 1-Стандартные потоки, 2-Файловые и строковые потоки" << endl << "-->";
		cin >> menup;
		switch (menup)
		{
		case 1:
			while (flag) {
				system("cls");
				cout << "1 - Добавить человека" << endl;
				cout << "2 - Удалить человека" << endl;
				cout << "3 - Чтение из файла" << endl;
				cout << "4 - Сохранение информации в файл" << endl;
				cout << "5 - Показать всю информацию" << endl;
				cout << "6 - Редактирование" << endl;
				cout << "7 - Поиск по номеру телефона" << endl;
				cout << "8 - Гороскоп" << endl;
				cout << "9 - Выбор задания" << endl;
				cout << "0 - Выход" << endl;
				cout << "Введите номер: ";
				cin >> menu;
				switch (menu) {
				case 1:
					obj.add();
					system("pause");
					break;
				case 2:
					obj.print();
					cout << "Введите номер удаляемого объекта: ";
					cin >> index;
					obj.del(index);
					system("pause");
					break;
				case 3:
					obj.read(s);
					system("pause");
					break;
				case 4:
					obj.save(s);
					system("pause");
					break;
				case 5:
					obj.print();
					system("pause");
					break;
				case 6:
					obj.print();
					cout << "Введите номер редактируемого объекта: ";
					cin >> index;
					obj.redaction(index);
					system("pause");
					break;
				case 7:
					obj.search_tel();
					system("pause");
					break;
				case 9:
					flag = 0;
					break;
				case 0:
					small = 0;
					break;
				case 8:
					obj.print();
					cout << "Введите номер объекта, чтобы узнать, в год какого животного он родился: ";
					cin >> index;
					obj.beasts(index);
					system("pause");
					break;
				default:
					cout << "Error!" << endl;
					system("pause");
					break;
				}

			}
		case 2:
			while (flag) {
				system("cls");
				cout << "1 - Чтение файла" << endl;
				cout << "2 - Вывод предложений с тире" << endl;
				cout << "3 - Показать всю информацию" << endl;
				cout << "4 - Вернуться к выбору задания" << endl;
				cout << "5 - Выход" << endl;
				cout << "Введите номер: ";
				cin >> menu;
				switch (menu) {
				case 1:
					d = file_load();
					system("pause");
					break;
				case 2:
					out = find_dash_phrases(d);
					cout << "Вывод информации по заданию:\n" << out.c_str() << endl;
					system("pause");
					break;
				case 3:
					cout << " \n" << d << endl;;
					system("pause");
					break;
				case 4:
					flag = 0;
					break;
				case 5:
					small = 0;
					break;
				default:
					cout << "Error!" << endl;
					system("pause");
					break;
				}
			}
		}
	}
}

int main()
{
	system("chcp 1251");
	system("cls");
	setlocale(LC_ALL, "Russian");
	Keeper<Note> obj;
	Menu(obj, "people.txt");
	int menup;
	int menu;
	int flag = 1;
}