#include"MANAGEMENT.h"
Management::Management() = default;
Management::~Management(){}

//ѡ��˵�
void Management::Menu() {
	std::cout << "*****	     ��ӭʹ��ְ����Ϣ����ϵͳ		*****" << std::endl;
	std::cout << std::endl;
	std::cout << "*****		1,���Ա����Ϣ			*****" << std::endl;
	std::cout << "*****		2,��ʾԱ����Ϣ			*****" << std::endl;
	std::cout << "*****		3,ɾ��Ա����Ϣ			*****" << std::endl;
	std::cout << "*****		4,����Ա����Ϣ			*****" << std::endl;
	std::cout << "*****		5,�޸�Ա����Ϣ			*****" << std::endl;
	std::cout << "*****		6,���ϵͳ��Ϣ			*****" << std::endl;
	std::cout << "*****		0,�˳�����ϵͳ			*****" << std::endl;
	std::cout << "������ѡ��Ĺ���:" << std::endl;
}
//���Ա��
std::vector<Staff> Management::AddStaff() 
{
	std::cout << "������ְ����Ϣ:" << std::endl;
	std::cout << "����:" << '\t' << "�Ա�:" << '\t' << "����:" << '\t' << "����:" << '\t' << "ְλ:		(��Ҫ��д�������Ϣ)" << std::endl;
	std::cin >> NAME >> SEX >> AGE >> DEPARTMENT >> POSITION;
	Person p(NAME, SEX, AGE);
	Staff staff(GetNum(), p, DEPARTMENT, POSITION);
	VecStaff.push_back(staff);
	std::cout << "��ӳɹ�" << std::endl;
	system("pause");
	std::cout << std::flush;
	return VecStaff;
}

std::vector<Staff> Management::AddStaff(int count)
{	
	std::cout << "������ְ����Ϣ:" << std::endl;
	while (count!=0)
	{
		std::cout << "����:" << '\t' << "�Ա�:" << '\t' << "����:" << '\t' << "����:" << '\t' << "ְλ:		(��Ҫ��д�������Ϣ)" << std::endl;
		std::cout << std::flush;
		std::cin >> NAME >> SEX >> AGE >> DEPARTMENT >> POSITION;
		Person p(NAME, SEX, AGE);
		Staff staff(GetNum(), p, DEPARTMENT, POSITION);
		VecStaff.push_back(staff);
		count--;
	}
	std::cout << "��ӳɹ�" << std::endl;
	system("pause");
	return VecStaff;
}

//��ʾ����Ԫ����Ϣ
void Management::ShowVecStaffInfo()
{
	if (!VecStaff.empty()) {
		for (uint32 i = 0; i < VecStaff.size(); i++) {
			VecStaff[i].ShowStaffInfo();
		}
	}
	else
		std::cout << "��û����,���һЩ������" << std::endl;
		return;
}

//����Ա��
void Management::FindStaff()
{
	std::cout << "������Ҫ���ҵ���Ϣ(����,ְ�����" << std::endl;
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

//ɾ��Ա��
std::vector<Staff>& Management::DelStaff()
{
	if (!VecStaff.empty()) {
		std::cout << "������Ҫɾ����Ա����Ϣ(����,ְ�����):" << std::endl;
		std::cin >> BUFFER;
		for (auto it = VecStaff.begin(); it != VecStaff.end();) {
			if (it->per.GetPersonName() == BUFFER||std::to_string(it->StaffNum)==BUFFER) {
				it = VecStaff.erase(it);
				std::cout << "ɾ���ɹ�" << std::endl;
			}
			else
				++it;
		}
	}
	
	return VecStaff;
}

//�޸�Ա����Ϣ
std::vector<Staff>& Management::ModStaff()
{
	std::cout << "������Ҫ�޸���Ϣ��Ա��" << std::endl;
	std::cin >> BUFFER;
	Staff stf=FindStaff(BUFFER);
	std::cout << "�������µ���Ϣ:" << std::endl;
	std::cout << "����:" << '\t' << "�Ա�:" << '\t' << "����:" << '\t' << "����:" << '\t' << "ְλ:" << std::endl;
	std::cin >> NAME >> SEX >> AGE >> DEPARTMENT >> POSITION;
	Staff NewStaff(stf.StaffNum, stf.per.SetPersonInfo(NAME, SEX, AGE), DEPARTMENT, POSITION);
	for (auto it = VecStaff.begin(); it != VecStaff.end();it++) {
		if (*it == stf) {
			*it = NewStaff;
		}
	}
	std::cout << "�޸ĳɹ�" << std::endl;
	return VecStaff;
}

//���
std::vector<Staff>& Management::ClearStaff()
{
	VecStaff.clear();
	std::cout << "�����" << std::endl;
	return VecStaff;
}
