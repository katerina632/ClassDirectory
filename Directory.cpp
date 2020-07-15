#include "Directory.h"
#include<iostream>
#include<string>


using namespace std;


ostream& operator<<(ostream& os, const InfoFirm& dt)
{
	os << "  ==" << dt.name <<"=="<< endl;
	os << "Owner: " << dt.owner << endl;
	os << "Phone: " << dt.phone << endl;
	os << "Address: " << dt.address << endl;
	os << "Type of activity: " << dt.typeOfActivity << endl;
	cout << endl;

	return os;
}

bool InfoFirm::operator==(const string& other) const
{
	return (owner==other|| name == other|| phone == other|| owner == other);
}

 ofstream& operator<<(ofstream& of, const Directory& list) {
	of << list.firms;
	return of;
}
 
 ifstream& operator>>(ifstream& ifs, InfoFirm& list)
 {
	
	 getline(ifs, list.name);
	 getline(ifs, list.owner);
	 getline(ifs, list.phone);
	 getline(ifs, list.address);
	 getline(ifs, list.typeOfActivity);

	 return ifs;
 }
 ifstream& operator>>(ifstream& ifs,  Directory& list)
 {
	 ifs >> list.firms;
	 return ifs;
 }
 

 ofstream& operator<<(ofstream& of, const InfoFirm& list) {

	 of << list.name << endl;
	 of << list.owner << endl;
	 of << list.phone << endl;
	 of << list.address << endl;
	 of << list.typeOfActivity ;

	 return of;
 };

 void Directory::AddFirm(InfoFirm f)
 {
	 firms.AddToHead(f);
 }

 void Directory::Show() const
 {
	 firms.Print();
 }

 void Directory::SearchByName(string k)
 {
	 cout << "You were looking for: " << k << endl;
	 firms.FindByValue(k);
 }
