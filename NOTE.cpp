#include "NOTE.h"
#include "keep.h"

Note::Note() {
	name = "��� ������";
	surname = "��� ������";
	phone_number = "��� ������";
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
	out << "���: " << obj.name << endl;
	out << "�������: " << obj.surname << endl;
	out << "����� ��������: " << obj.phone_number << endl;
	out << "���� ��������: " << obj.data[0] << endl;
	out << "����� ��������: " << obj.data[1] << endl;
	out << "��� ��������:  " << obj.data[2] << endl;
	return out;
}

istream& operator>>(istream& in, Note& obj) {
	cout << "������� ���: ";
	getchar();
	getline(in, obj.name);

	cout << "������� �������: ";
	getline(in, obj.surname);

	cout << "������� ����� ��������: ";
	getline(in, obj.phone_number);

	cout << "������� ���� ��������: ";
	while (!(in >> obj.data[0]))
	{
		if (in.eof())
		{
			throw "eof";
		}
		in.clear(); //���������� ���� ������, ���� ������� ����
		in.ignore(1000, '\n'); //���������� ���������� � ������ ������
		cout << "���������: ";
	}

	cout << "������� ����� ��������: ";
	while (!(in >> obj.data[1]))
	{
		if (in.eof())
		{
			throw "eof";
		}
		in.clear(); //���������� ���� ������, ���� ������� ����
		in.ignore(1000, '\n'); //���������� ���������� � ������ ������
		cout << "���������: ";
	}
	cout << "������� ��� ��������: ";
	while (!(in >> obj.data[2]))
	{
		if (in.eof())
		{
			throw "eof";
		}
		in.clear(); //���������� ���� ������, ���� ������� ����
		in.ignore(1000, '\n'); //���������� ���������� � ������ ������
		cout << "���������: ";
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
	cout << "��� �� ������ ��������������� (1-���, 2-�������, 3-�������, 4-���� ��������): " << endl;
	cin >> index;
	switch (index)
	{
	case 1:
		cout << "������� ����� ���: ";
		getchar();
		getline(cin, obj.name);
		break;
	case 2:
		cout << "������� ����� �������: ";
		cin >> obj.surname;
		break;
	case 3:
		cout << "������� ����� ����� ��������: ";
		cin >> obj.phone_number;
		break;
	case 4:
		cout << "������� ����� ���� ��������: ";
		cin >> obj.data[0];
		cout << "������� ����� ����� ��������: ";
		cin >> obj.data[1];
		cout << "������� ����� ��� ��������: ";
		cin >> obj.data[2];
		break;
	case 6:
		cout << "�������� ��������������" << endl;
		break;
	default:
		break;
	}

}

void Note::beast(Note& obj)
{
	const char* arrZodiakKitay[12] = { "�����", "����", "�����", "�������", "�������", "����", "������", "����", "��������", "������", "������", "������" };
	char zodiakKitay[20] = "";

	if (data[2] % 12 == 4) strcpy_s(zodiakKitay, arrZodiakKitay[0]);	// �����
	else
		if (data[2] % 12 == 5) strcpy_s(zodiakKitay, arrZodiakKitay[1]);	// ���
		else
			if (data[2] % 12 == 6) strcpy_s(zodiakKitay, arrZodiakKitay[2]);	// ����
			else
				if (data[2] % 12 == 7) strcpy_s(zodiakKitay, arrZodiakKitay[3]);	// ������
				else
					if (data[2] % 12 == 8) strcpy_s(zodiakKitay, arrZodiakKitay[4]);	// ������
					else
						if (data[2] % 12 == 9) strcpy_s(zodiakKitay, arrZodiakKitay[5]);	// ����
						else
							if (data[2] % 12 == 10) strcpy_s(zodiakKitay, arrZodiakKitay[6]);// ������
							else
								if (data[2] % 12 == 11) strcpy_s(zodiakKitay, arrZodiakKitay[7]);// ����
								else
									if (data[2] % 12 == 0) strcpy_s(zodiakKitay, arrZodiakKitay[8]);	// ��������
									else
										if (data[2] % 12 == 1) strcpy_s(zodiakKitay, arrZodiakKitay[9]);	// �����
										else
											if (data[2] % 12 == 2) strcpy_s(zodiakKitay, arrZodiakKitay[10]);// ������
											else
												if (data[2] % 12 == 3) strcpy_s(zodiakKitay, arrZodiakKitay[11]);// ������
	cout << zodiakKitay << endl;
}

