//network
#include <iostream>
#include <fstream>
#include<direct.h>
using namespace std;
void main()
	{
	setlocale(LC_ALL, "");
	const int IP_MAX_SIZE = 16;
	const int MAC_MAX_SIZE = 18;

	char sz_ip_buffer[IP_MAX_SIZE]{};
	char sz_mac_buffer[MAC_MAX_SIZE]{};
	std::ifstream fin("201 RAW.txt");
	if (fin.is_open())
	{
		std::ofstream fout("201.txt");
		while (!fin.eof())
		{
			fin >> sz_ip_buffer >> sz_mac_buffer;
			cout << sz_mac_buffer << "\t" << sz_ip_buffer << endl;
			fout << sz_mac_buffer << "\t" << sz_ip_buffer << endl;
		}
		fout.close();
		fin.close();
	}
	else
	{
		std::cerr << "Error:File not found" << endl;
	}
	system("notepad 201.txt");
	}
