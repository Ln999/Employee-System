#pragma once
#include<iostream>
#include<string>
#include"PERSON.h"
class Staff:public Person{
	friend class Management;
public:
	std::string SDept;
	std::string SPos;
	long long StaffNum;
	Person per;

	Staff();
	Staff(long long,Person,std::string , std::string );
	Staff(const Staff&);
	void ShowStaffInfo();
	//����==�����
	bool operator==(Staff&);
	~Staff();
};
