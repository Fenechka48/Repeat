//Filles
#include <iostream>
#include <fstream>
using namespace std;
//#define WRITE_TO_FILE
//#define READ_FROM_FILE
void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	char filename[_MAX_FNAME] = {};
	cout << "Введите имя файла: ";
	cin.getline(filename, _MAX_FNAME);
	if (strcmp(filename + strlen(filename) - 4, ".txt"))strcat_s(filename,_MAX_FNAME, ".txt");
	ofstream fout;    //1) создаем поток
	fout.open(filename,std::ios_base::app); // 2) открываем потокж
	fout << "Hello Files" << endl; //3) пишем в поток
	fout.close();  //4) закрываем поток

	char sz_command[_MAX_FNAME] = "notepad ";
	strcat_s(sz_command, _MAX_FNAME, filename);
	system (sz_command);

#endif // WRITE_TO_FILE
#ifdef READ_FROM_FILE
	ifstream fin;
	fin.open("File.txt");
	if (fin.is_open())
	{
		const int SIZE = 256;
		char sz_buffer[SIZE]{};
		while (!fin.eof())
		{

			//fin >> sz_buffer;
			fin.getline(sz_buffer, SIZE);
			cout << sz_buffer << endl;
		}
		fin.close();
	}
	else
	{
		std::cerr << "Error:File not found" << endl;
		//cout - console out
		//cerr - console error
	}
#endif // READ_FROM_FILE


	// Network 
	char filename[_MAX_FNAME] = {};
	ifstream fin;
	ofstream fout;
	fin.open("201 RAW.txt");
		if (fin.is_open())
		{
			const int IP_SIZE = 16;
			char sz_buffer[IP_SIZE]{};
			const int MAC_SIZE = 18;
			char sz_buffer_2[MAC_SIZE]{};
			while (!fin.eof())
			{
				fin >> sz_buffer >> sz_buffer_2;
				cout << sz_buffer_2 << "      " << sz_buffer<<endl;
				fout << sz_buffer_2 << "      " << sz_buffer<<endl;
			}
			fin.close();
		}
		else
		{
			std::cerr << "Error:File not found" << endl;
		}
		system("notepad 201 RAW.txt");
}
