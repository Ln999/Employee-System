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
	void ShowVecStaffInfo();//��ʾϵͳ�ڵ�Ա����Ϣ
	std::vector<Staff>AddStaff();//���
	std::vector<Staff>AddStaff(int);//���
	std::vector<Staff>&DelStaff();//ɾ��
	void FindStaff();//����
	Staff FindStaff(std::string);//����
	std::vector<Staff>& ModStaff();//�޸�
	std::vector<Staff>& ClearStaff();//���
};
