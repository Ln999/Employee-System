#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"STAFF.h"
extern std::string NAME;
extern std::string DEPARTMENT;
extern std::string POSITION;
extern std::string SEX;
extern int AGE;
extern std::string BUFFER;
extern long long GetNum();
using uint32 = unsigned int;
class Management {
public:
	std::vector<Staff>VecStaff;
	Management();
	~Management();
	void Menu();
	void ShowVecStaffInfo();//显示系统内的员工信息
	std::vector<Staff>AddStaff();//添加
	std::vector<Staff>AddStaff(int);//添加
	std::vector<Staff>&DelStaff();//删除
	void FindStaff();//查找
	Staff FindStaff(std::string);//查找
	std::vector<Staff>& ModStaff();//修改
	std::vector<Staff>& ClearStaff();//清空
};
