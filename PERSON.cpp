#include"PERSON.h"
Person::Person() = default;
Person::~Person() = default;
Person::Person(std::string name,std::string sex,int age)
{
	this->pName = name;
	this->pSex = sex;
	this->pAge = age;
}
void Person::ShowPersonInfo()
{
	std::cout << this->pName << ' ' << this->pSex << ' ' << this->pAge <<' ';
}

std::string Person::GetPersonName()
{
	this->pName = pName;
	return this->pName;
}
std::string Person::GetPersonSex()
{
	this->pSex = pSex;
	return this->pSex;
}
int Person::GetPersonAge()
{
	this->pAge = pAge;
	return this->pAge;
}


Person Person::SetPersonInfo(std::string name, std::string sex, int age)
{
	this->pName = name;
	this->pSex = sex;
	this->pAge = age;
	return *this;
}
