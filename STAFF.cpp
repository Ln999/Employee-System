#include"STAFF.h"
Staff::Staff() = default;
Staff::~Staff() {

}
//ÖØÔØ==ÔËËã·û
bool Staff::operator==(Staff& stf) {
	
	return (this->GetPersonName() == stf.GetPersonName() 
		&& this->StaffNum == stf.StaffNum) ? true : false;
}

Staff::Staff(long long num,Person p,std::string dept, std::string pos) 
{
	per = p;
	this->StaffNum = num;
	this->SDept = dept;
	this->SPos = pos;
}
Staff::Staff(const Staff& stf)
{
	this->per = stf.per;
	this->SDept = stf.SDept;
	this->StaffNum = stf.StaffNum;
	this->SPos = stf.SPos;
}
void Staff::ShowStaffInfo()
{
	/*std::cout << per.pName << ' ' << per.pSex << ' ' << per.pAge << ' ' 
		<< this->StaffNum << ' '<< this->SDept << ' ' << this->SPos << std::endl;*/
	per.ShowPersonInfo();
	std::cout<<this->StaffNum << ' ' << this->SDept << ' ' << this->SPos << std::endl;
}



