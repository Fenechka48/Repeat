//Filles
#include <iostream>
#include <fstream>
using namespace std;
//#define WRITE_TO_FILE
void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	ofstream fout;    //1) создаем поток
	fout.open("File.txt",std::ios_base::app); // 2) открываем потокж
	fout << "Hello World" << endl; //3) пишем в поток
	fout.close();                  //4) закрываем поток
	system("notepad File.txt");

#endif // WRITE_TO_FILE



}
