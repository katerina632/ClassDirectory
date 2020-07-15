#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include "List.h"
using namespace std;

struct InfoFirm {
	string name;
	string owner;
	string phone;
	string address;
	string typeOfActivity;

	InfoFirm()
		: name("No name"), owner("No owner"), phone("No phone"), address("No address"), typeOfActivity("No type") {}

	InfoFirm(string name, string owner, string phone, string address, string type)
		: name(name), owner(owner), phone(phone), address(address), typeOfActivity(type) {}

	friend ostream& operator<<(ostream& os, const InfoFirm& dt);
	friend ofstream& operator<<(ofstream& of, const InfoFirm& list);
	friend ifstream& operator>>(ifstream& ifs, InfoFirm& list);

	bool operator==(const string& other) const;
};

class Directory
{
private:	

	List<InfoFirm> firms;	
	
	friend ofstream& operator<<(ofstream& of, const Directory& list);
	friend ifstream& operator>>(ifstream& ifs,  Directory& list);

public:
	Directory() {}
	
	void AddFirm(InfoFirm f);

	void Show() const;

	void SearchByName(string k);
	
};

ostream& operator<<(ostream& os, const InfoFirm& dt);

ofstream& operator<<(ofstream& of, const InfoFirm& list);

ifstream& operator>>(ifstream& ifs, InfoFirm& list);

ofstream& operator<<(ofstream& of, const Directory& list);

ifstream& operator>>(ifstream& ifs,  Directory& list);

