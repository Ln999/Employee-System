#include"MANAGEMENT.h"
Management::Management() = default;
Management::~Management(){}

//选择菜单
void Management::Menu() {
	std::cout << "*****	     欢迎使用职工信息管理系统		*****" << std::endl;
	std::cout << std::endl;
	std::cout << "*****		1,添加员工信息			*****" << std::endl;
	std::cout << "*****		2,显示员工信息			*****" << std::endl;
	std::cout << "*****		3,删除员工信息			*****" << std::endl;
	std::cout << "*****		4,查找员工信息			*****" << std::endl;
	std::cout << "*****		5,修改员工信息			*****" << std::endl;
	std::cout << "*****		6,清空系统信息			*****" << std::endl;
	std::cout << "*****		0,退出管理系统			*****" << std::endl;
	std::cout << "请输入选择的功能:" << std::endl;
}
//添加员工
std::vector<Staff> Management::AddStaff() 
{
	std::cout << "请输入职工信息:" << std::endl;
	std::cout << "姓名:" << '\t' << "性别:" << '\t' << "年龄:" << '\t' << "部门:" << '\t' << "职位:		(不要填写多余的信息)" << std::endl;
	std::cin >> NAME >> SEX >> AGE >> DEPARTMENT >> POSITION;
	Person p(NAME, SEX, AGE);
	Staff staff(GetNum(), p, DEPARTMENT, POSITION);
	VecStaff.push_back(staff);
	std::cout << "添加成功" << std::endl;
	system("pause");
	std::cout << std::flush;
	return VecStaff;
}

std::vector<Staff> Management::AddStaff(int count)
{	
	std::cout << "请输入职工信息:" << std::endl;
	while (count!=0)
	{
		std::cout << "姓名:" << '\t' << "性别:" << '\t' << "年龄:" << '\t' << "部门:" << '\t' << "职位:		(不要填写多余的信息)" << std::endl;
		std::cout << std::flush;
		std::cin >> NAME >> SEX >> AGE >> DEPARTMENT >> POSITION;
		Person p(NAME, SEX, AGE);
		Staff staff(GetNum(), p, DEPARTMENT, POSITION);
		VecStaff.push_back(staff);
		count--;
	}
	std::cout << "添加成功" << std::endl;
	system("pause");
	return VecStaff;
}

//显示容器元素信息
void Management::ShowVecStaffInfo()
{
	if (!VecStaff.empty()) {
		for (uint32 i = 0; i < VecStaff.size(); i++) {
			VecStaff[i].ShowStaffInfo();
		}
	}
	else
		std::cout << "还没人呢,添加一些进来吧" << std::endl;
		return;
}

//查找员工
void Management::FindStaff()
{
	std::cout << "请输入要查找的信息(姓名,职工编号" << std::endl;
	std::cin >> BUFFER;
	for (auto it = VecStaff.begin(); it != VecStaff.end(); it++) {
		if (it->per.GetPersonName() == BUFFER || std::to_string(it->StaffNum) == BUFFER)
		{
			it->ShowStaffInfo();
		}
	}
}

Staff Management::FindStaff(std::string BUFFER)
{
	uint32 i = 0;
	for (; i < VecStaff.size(); i++) {
		if (VecStaff[i].per.GetPersonName() == BUFFER || std::to_string(VecStaff[i].StaffNum) == BUFFER)
		{
			VecStaff[i].ShowStaffInfo();
			return VecStaff[i];
		}
	}
	return VecStaff[i];
}

//删除员工
std::vector<Staff>& Management::DelStaff()
{
	if (!VecStaff.empty()) {
		std::cout << "请输入要删除的员工信息(姓名,职工编号):" << std::endl;
		std::cin >> BUFFER;
		for (auto it = VecStaff.begin(); it != VecStaff.end();) {
			if (it->per.GetPersonName() == BUFFER||std::to_string(it->StaffNum)==BUFFER) {
				it = VecStaff.erase(it);
				std::cout << "删除成功" << std::endl;
			}
			else
				++it;
		}
	}
	
	return VecStaff;
}

//修改员工信息
std::vector<Staff>& Management::ModStaff()
{
	std::cout << "请输入要修改信息的员工" << std::endl;
	std::cin >> BUFFER;
	Staff stf=FindStaff(BUFFER);
	std::cout << "请输入新的信息:" << std::endl;
	std::cout << "姓名:" << '\t' << "性别:" << '\t' << "年龄:" << '\t' << "部门:" << '\t' << "职位:" << std::endl;
	std::cin >> NAME >> SEX >> AGE >> DEPARTMENT >> POSITION;
	Staff NewStaff(stf.StaffNum, stf.per.SetPersonInfo(NAME, SEX, AGE), DEPARTMENT, POSITION);
	for (auto it = VecStaff.begin(); it != VecStaff.end();it++) {
		if (*it == stf) {
			*it = NewStaff;
		}
	}
	std::cout << "修改成功" << std::endl;
	return VecStaff;
}

//清空
std::vector<Staff>& Management::ClearStaff()
{
	VecStaff.clear();
	std::cout << "已清空" << std::endl;
	return VecStaff;
}
