#include "str.h"

string file_load()
{
	ifstream fin;
	fin.exceptions(ios::badbit | ios::failbit | ios::eofbit);
	string load_name;
	string d, str;
	cout << "Ввод названия текстового файла для извлечения информации" << endl;
	while (!fin.is_open())
	{
		cin.ignore(32676, '\n');
		getline(cin, load_name);
		try
		{
			fin.open(load_name, ios_base::in | ios_base::out);
		}
		catch (const ios_base::failure& e)
		{
			cerr << "Не удалось открыть файл!\nПовторите:" << e.what() << "\n";
		}
	}
	try
	{
		while (getline(fin, str))
		{
			cout << str << endl;
			d.append(str).append("\n");
		}
	}
	catch (ifstream::failure e)
	{
		fin.close();
	}
	return d;
}

string find_dash_phrases(string d)
{
	int start = 0, end = 0;
	string out;
	bool is_phrase = false;
	bool is_dash_phrase = false;
	for (int i = 0; i < d.length(); i++)
	{
		if (d[i] != ' ')
		{
			if (d[i] == '-')
				if (is_phrase == true)
					is_dash_phrase = false;
				else
				{
					is_dash_phrase = true;
					start = i;
				}
			if (d[i] == '.' || d[i] == '!' || d[i] == '?' || d[i] == '\n')
				is_phrase = false;
			else
				is_phrase = true;
			if (is_dash_phrase)
			{
				if (d[i] == '.' || d[i] == '!' || d[i] == '?' || d[i] == '\n')
				{
					end = i;
					out.insert(out.length(), d, start, end - start + 1);
					out.append("\n");
					is_dash_phrase = false;
					is_phrase = false;
				}
			}
		}
	}
	return out;
}