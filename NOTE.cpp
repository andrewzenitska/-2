#include "NOTE.h"
#include "keep.h"

Note::Note() {
	name = "Нет данных";
	surname = "Нет данных";
	phone_number = "Нет данных";
	data[0] = 0;
	data[1] = 0;
	data[2] = 0;
}


Note::Note(const Note& obj) {
	*this = obj;
}

Note::~Note() {
	
}

Note& Note::operator=(const Note& other) {
	this->name = other.name;
	this->surname = other.surname;
	this->phone_number = other.phone_number;
	this->data[0] = other.data[0];
	this->data[1] = other.data[1];
	this->data[2] = other.data[2];
	return *this;
}

ostream& operator<<(ostream& out, Note& obj) {
	out << "Имя: " << obj.name << endl;
	out << "Фамилия: " << obj.surname << endl;
	out << "Номер телефона: " << obj.phone_number << endl;
	out << "День рождения: " << obj.data[0] << endl;
	out << "Месяц рождения: " << obj.data[1] << endl;
	out << "Год рождения:  " << obj.data[2] << endl;
	return out;
}

istream& operator>>(istream& in, Note& obj) {
	cout << "Введите имя: ";
	getchar();
	getline(in, obj.name);

	cout << "Введите фамилию: ";
	getline(in, obj.surname);

	cout << "Введите номер телефона: ";
	getline(in, obj.phone_number);

	cout << "Введите день рождения: ";
	while (!(in >> obj.data[0]))
	{
		if (in.eof())
		{
			throw "eof";
		}
		in.clear(); //Сбрасываем флаг ошибки, если таковая была
		in.ignore(1000, '\n'); //Игнорируем оставшиеся в потоке данные
		cout << "Повторите: ";
	}

	cout << "Введите месяц рождения: ";
	while (!(in >> obj.data[1]))
	{
		if (in.eof())
		{
			throw "eof";
		}
		in.clear(); //Сбрасываем флаг ошибки, если таковая была
		in.ignore(1000, '\n'); //Игнорируем оставшиеся в потоке данные
		cout << "Повторите: ";
	}
	cout << "Введите год рождения: ";
	while (!(in >> obj.data[2]))
	{
		if (in.eof())
		{
			throw "eof";
		}
		in.clear(); //Сбрасываем флаг ошибки, если таковая была
		in.ignore(1000, '\n'); //Игнорируем оставшиеся в потоке данные
		cout << "Повторите: ";
	}
	return in;
}

string Note::sort(Note& obj)
{
	string str = to_string(data[2]) + to_string(data[1]) + to_string(data[0]);
	return str;
}

bool Note::search(Note& obj, string tel)
{
	return tel == obj.phone_number;
}


ofstream& operator<<(ofstream& fout, Note& obj) {
	fout << obj.name << endl;
	fout << obj.surname << endl;
	fout << obj.phone_number << endl;
	fout << obj.data[0] << endl;
	fout << obj.data[1] << endl;
	fout <<  obj.data[2] << endl;
	return fout;
}

ifstream& operator>>(ifstream& fin, Note& obj) {

	fin.get();
	getline(fin, obj.name);
	//fin.get();
	getline(fin, obj.surname);
	//fin.get();
	getline(fin, obj.phone_number);
	fin >> obj.data[0];
	fin >> obj.data[1];
	fin >> obj.data[2];
	fin.get();
	return fin;
}

void Note::redact(Note& obj)
{
	int index;
	cout << "Что вы хотите отредактировать (1-имя, 2-фамилия, 3-телефон, 4-дата рождения): " << endl;
	cin >> index;
	switch (index)
	{
	case 1:
		cout << "Введите новое имя: ";
		getchar();
		getline(cin, obj.name);
		break;
	case 2:
		cout << "Введите новую фамилию: ";
		cin >> obj.surname;
		break;
	case 3:
		cout << "Введите новый номер телефона: ";
		cin >> obj.phone_number;
		break;
	case 4:
		cout << "Введите новый день рождения: ";
		cin >> obj.data[0];
		cout << "Введите новый месяц рождения: ";
		cin >> obj.data[1];
		cout << "Введите новый год рождения: ";
		cin >> obj.data[2];
		break;
	case 6:
		cout << "Успешное редактирование" << endl;
		break;
	default:
		break;
	}

}

void Note::beast(Note& obj)
{
	const char* arrZodiakKitay[12] = { "Крысы", "Быка", "Тигра", "Кролика", "Дракона", "Змеи", "Лошади", "Овцы", "Обезьяны", "Петуха", "Собаки", "Свиньи" };
	char zodiakKitay[20] = "";

	if (data[2] % 12 == 4) strcpy_s(zodiakKitay, arrZodiakKitay[0]);	// Крыса
	else
		if (data[2] % 12 == 5) strcpy_s(zodiakKitay, arrZodiakKitay[1]);	// Бык
		else
			if (data[2] % 12 == 6) strcpy_s(zodiakKitay, arrZodiakKitay[2]);	// Тигр
			else
				if (data[2] % 12 == 7) strcpy_s(zodiakKitay, arrZodiakKitay[3]);	// Кролик
				else
					if (data[2] % 12 == 8) strcpy_s(zodiakKitay, arrZodiakKitay[4]);	// Дракон
					else
						if (data[2] % 12 == 9) strcpy_s(zodiakKitay, arrZodiakKitay[5]);	// Змея
						else
							if (data[2] % 12 == 10) strcpy_s(zodiakKitay, arrZodiakKitay[6]);// Лошадь
							else
								if (data[2] % 12 == 11) strcpy_s(zodiakKitay, arrZodiakKitay[7]);// Овца
								else
									if (data[2] % 12 == 0) strcpy_s(zodiakKitay, arrZodiakKitay[8]);	// Обезьяна
									else
										if (data[2] % 12 == 1) strcpy_s(zodiakKitay, arrZodiakKitay[9]);	// Петух
										else
											if (data[2] % 12 == 2) strcpy_s(zodiakKitay, arrZodiakKitay[10]);// Собака
											else
												if (data[2] % 12 == 3) strcpy_s(zodiakKitay, arrZodiakKitay[11]);// Свинья
	cout << zodiakKitay << endl;
}

