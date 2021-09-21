#pragma once
#include<iostream>
#include<string>
class Person {
private:
	std::string pName;
	std::string pSex;
	int pAge;
public:
	Person();
	Person(std::string, std::string, int);
	void ShowPersonInfo();
	std::string GetPersonName();
	std::string GetPersonSex();
	int GetPersonAge();
	Person SetPersonInfo(std::string, std::string, int);
	~Person();
};

