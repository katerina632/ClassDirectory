#include<iostream>
#include "Directory.h"


using namespace std;

int main()
{
	Directory d1;
	d1.AddFirm(InfoFirm("Shpulka", "Black Bob", "12345678", "Rivne", "Sale of sewing machines"));
	cout << "==Show 1 firm==" << endl;
	d1.Show();

	InfoFirm f("Candy", "Ann Sweety", "87654321", "Kiev", "Sale of sweets");
	

	d1.AddFirm(f);
	cout << "==Show 2 firms==" << endl;
	d1.Show();

	
	d1.SearchByName("Candy");
	d1.SearchByName("John Drew");	
	

	ofstream ofs("Firms.txt");
	ofs << d1;
	ofs.close();

	Directory d2;
	ifstream ifs("Firms.txt");
	ifs >> d2;
	ifs.close();

	cout << endl;
	d2.Show();

	system("pause");
	return 0;
}