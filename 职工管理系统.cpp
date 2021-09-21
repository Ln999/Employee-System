#pragma warning(disable:4996)
#include<ctime>
#include<sstream>
#include<conio.h>//����̨�������
#include<cstdio>
#include<cstdlib>
#include<Windows.h>
#include<fstream>
#include<thread>
#include"MANAGEMENT.h"
using namespace std;

//ȫ�ֱ���
//HANDLE hout;
int AutoI = 0;
string NAME;
string SEX;
string DEPARTMENT;
string POSITION;
string BUFFER;
int AGE;
long long NUM;
Management M;
//ofstream ofs;//C++��ͬһ���ļ��������д�ļ�����Ҫclose()����Ҫclear()
//ifstream ifs;
const string FileName = "ְ����Ϣ��.txt";

//ȫ�ֺ�������
std::string GetDate();
long long GetNum();
void ReadData(Management&);//���ļ�����
void WriteData(Management&);//д����
int Ctoi(string);
void IsStaffExist(Management&);//��ֹд���ظ�����
void MenuChoice(int&);//���ܲ˵�ѡ��
void Create_File();//�����ļ�
bool IsFileEmpty();//�ļ��Ƿ�Ϊ��
void Delstaff(Management&);

//ȫ�ֺ�������
//�����ļ�
void Create_File() {
	ofstream ofs;
	fstream f;
	f.open(FileName);
	if (!f) {
		ofs.open(FileName, ios::out);
		if (!ofs) {
			cout << "�����ļ�ʧ��" << endl;
			exit(0);
		}
		else
		{
			ofs << "ְ�����		����		�Ա�		����		����		ְλ		" << endl;
			ofs.close();
			return;
		}
	}
	else {
		f.close();
		return;
	}


}
//�ж��ļ��Ƿ�Ϊ��
bool IsFileEmpty() {
	ifstream ifs;
	string strbuf;
	char ch;
	int line = 0;
	ifs.open(FileName, ios::in);
	if (!ifs) {
		cout << "�ļ���ʧ��001" << endl;
		exit(0);
	}
	else {
		while (getline(ifs, strbuf)) {
			line++;
			if (line >= 1) {//�ӵڶ��п�ʼ������
				ch = ifs.get();
				if (ch ==EOF) {//�ڶ��ж�ȡһ���ַ�Ϊ�ļ�������
					ifs.close();
					return true;//�ļ�Ϊ��
				}
				else {
					ifs.close();
					return false;
				}
			}
		}
	}
}
void IsStaffExist(Management& M) {
//��������е��������ļ����Ѿ�����,��ɾ�������е�Ԫ��
	ifstream ifs;
	 bool Empty=IsFileEmpty();
	ifs.open(FileName, ios::in);
	if (!ifs) {
		cout << "�ļ���ʧ��002" << endl;
		exit(0);
	}
	else {
		if (Empty==0&&!M.VecStaff.empty()) {//�ļ���Ϊ���������д�������
			//��ȡÿһ�е����ݸ�������ְ����űȽ�
			string strbuf;
			int line = 0;
			while (getline(ifs, strbuf) && ifs.peek() != EOF) {
				line++;
				if (line >= 1) {
					ifs >> strbuf;
					for (auto it = M.VecStaff.begin(); it != M.VecStaff.end();) {
						if (to_string(it->StaffNum) == strbuf) {
							it = M.VecStaff.erase(it);
						}
						else {
							++it;
						}
					}
				}
			}
			ifs.close();
		}
		else {
			ifs.close();
			return;
		}
	}
}
std::string GetDate() {
	char ch[10];
	time_t Time = time(NULL);
	strftime(ch, sizeof(ch) - 1, "%Y%m%d", localtime(&Time));//��ʹ��VS�ṩ��localtime_s(),����ĿԤ���������_CRT_SECURE_NO_WARNINGS
	return ch;
}
//����ְ�����
long long GetNum() {
	stringstream strtoll;
	long long StaffNum;
	string str;
	string strbuf;
	ifstream ifs;
	int line = 0;
	string IsNewDate;
	if (!M.VecStaff.empty()) {
		IsNewDate = to_string(M.VecStaff.back().StaffNum);
	}
	bool Empty = IsFileEmpty();
	ifs.open(FileName, ios::in | ios::beg);
	if (!ifs) {
		cout << "��ȡ���ʧ��" << endl;
	}
	else {
		if (Empty==1||IsNewDate.compare(GetDate())<0) {//���ڱ��,���������ڱ��
			ifs.close();
			AutoI++;
			if (AutoI < 10) {
				str = GetDate() + "00" + std::to_string(AutoI);
			}
			else if (AutoI >= 10 && AutoI < 100) {
				str = GetDate() + "0" + std::to_string(AutoI);
			}
			else if (AutoI >= 100 && AutoI < 1000) {
				str = GetDate() + std::to_string(AutoI);
			}
			else {
				exit(-1);
			}
			strtoll << str;
			strtoll >> StaffNum;
			return StaffNum;
		}
		else {//�ļ���Ϊ��,ʹ���ļ��еı��
			while (getline(ifs,strbuf)&&ifs.peek()!=EOF)
			{
				line++;
				if (line >= 1) {
					ifs >> str;
				}
			}
			ifs.close();
		}
		strtoll << str;
		strtoll >> StaffNum;
		if (StaffNum < M.VecStaff.back().StaffNum) {
			StaffNum = M.VecStaff.back().StaffNum;
			return StaffNum += 1;
		}
		else {
			return StaffNum + 1;
		}
		
	}
	/*AutoI++;
	if (AutoI < 10) {
		str = GetDate() + "00" + std::to_string(AutoI);
	}
	else if (AutoI >= 10 && AutoI < 100) {
		str = GetDate() + "0" + std::to_string(AutoI);
	}
	else if (AutoI >= 100 && AutoI < 1000) {
		str = GetDate() + std::to_string(AutoI);
	}
	else {
		exit(-1);
	}*/

	/*strtoll << str;
	strtoll >> StaffNum;
	return StaffNum;*/
	/*
	* AutoI++;
	if (AutoI < 10) {
		str = GetDate() + "00" + std::to_string(AutoI);
	}
	else if (AutoI >= 10 && AutoI < 100) {
		str = GetDate() + "0" + std::to_string(AutoI);
	}
	else if (AutoI >= 100 && AutoI < 1000) {
		str = GetDate() + std::to_string(AutoI);
	}
	else {
		exit(-1);
	}
	*/
}
//���ļ�д������
void WriteData( Management& M) {
	ofstream ofs;
	ofs.open(FileName, ios::out | ios::app);
	if (!ofs) {
		cout << "���ļ�ʧ��003" << endl;
		return;
	}
	else {
		for (uint32 i = 0; i < M.VecStaff.size(); i++) {
					ofs << M.VecStaff[i].StaffNum << '\t' << '\t' << M.VecStaff[i].per.GetPersonName() << '\t' << '\t' <<
						M.VecStaff[i].per.GetPersonSex() << '\t' << '\t' << M.VecStaff[i].per.GetPersonAge() << '\t' << '\t' <<
						M.VecStaff[i].SDept << '\t' << '\t' << M.VecStaff[i].SPos << endl;
		}
	}
	ofs.close();
	return;
}
//���ļ���������
void ReadData(Management& M) {
	ifstream ifs;
	bool Empty = IsFileEmpty();
	ifs.open(FileName, ios::in);//ָ���ļ�
	if (!ifs) {
		cout << "��ȡ����ʧ��" << endl;
		exit(0);
	}
	else {
		//�ļ����ݲ�Ϊ��
		if (Empty== 0) {
			string strbuf;
			int line = 0;
			while (getline(ifs, strbuf) && ifs.peek() != EOF) {
				line++;
				if (line>= 1) {
					ifs >> NUM >> NAME >> SEX >> AGE >> DEPARTMENT >> POSITION;
					Person p(NAME, SEX, AGE);
					Staff staff(NUM, p, DEPARTMENT, POSITION);
					M.VecStaff.push_back(staff);
				}
			}
			//����������,�ر��ļ�
			ifs.close();
			return;
		}
		else {
			//�ļ�Ϊ��,�ر��ļ����˳�����
			ifs.close();
			return;
		}
	}
	
}
//��ȡ��������
void Delstaff(Management&M) {
	ofstream ofs;
	fstream tmp;
	string strbuf;
	tmp.open("temp.txt", ios::out|ios::app);
	if (!tmp) {
		cout << "��ʱ�ļ�����ʧ��" << endl;
		return;
	}
	else {
		tmp << "ְ�����		����		�Ա�		����		����		ְλ		" << endl;
		for (uint32 i = 0; i < M.VecStaff.size(); i++) {
			tmp << M.VecStaff[i].StaffNum << '\t' << '\t' << M.VecStaff[i].per.GetPersonName() << '\t' << '\t' <<
				M.VecStaff[i].per.GetPersonSex() << '\t' << '\t' << M.VecStaff[i].per.GetPersonAge() << '\t' << '\t' <<
				M.VecStaff[i].SDept << '\t' << '\t' << M.VecStaff[i].SPos << endl;
		}
	}
	remove("ְ����Ϣ��.txt");
	Create_File();
	ofs.open(FileName,ios::out|ios::app);
	while (getline(tmp, strbuf)) {
		ofs << strbuf;
	}
	tmp.close();
	remove("temp.txt");
	return;
}
void  read_input_buffer(int& choice) {
	//����յ��ַ���ʱ��֪����ô���
	string buffer;
	cin >> buffer;
	if (buffer.size() == 1 && isdigit(buffer[0])) {
		choice = Ctoi(buffer);
		buffer = "";
	}
	else {
		if (buffer == "exit") {
			exit(0);
		}
		else if (buffer == "clear") {
			system("cls");
		}
		/*else if (buffer == "save") {
			IsStaffExist(M);
			WriteData(M);
			return;
		}*/
		else {
			cout << "�޷�ʶ������:" << buffer << endl;
			system("pause");
		}
	}
}
//���ܲ˵�ѡ��
void MenuChoice(int& choice) {
	switch (choice)//�˵�����ʵ��
	{
		//�˳�ϵͳǰд������
	case 0: {
		IsStaffExist(M);
		WriteData(M);
		exit(0);
	}
	case 1: {
		int count = 0;
		cout << "Ҫ��ӵ�Ա������:";
		cin >> count;
		if (count == 0) {
			system("cls");
			break;
		}
		else if (count == 1) {
			M.AddStaff();
		}
		else {
			M.AddStaff(count);
		}
		system("cls");
		break;
	}
	case 2: {
		M.ShowVecStaffInfo();
		system("pause");
		system("cls");
		break;
	}
	case 3: {
		M.DelStaff();
		Delstaff(M);
		system("pause");
		system("cls");
		break;
	}
	case 4: {
		M.FindStaff();
		system("pause");
		system("cls");
		break;
	}
	case 5: {
		M.ModStaff();
		Delstaff(M);
		system("pause");
		system("cls");
		break;
	}
	case 6: {
		M.ClearStaff();
		cout << "����!" << endl;
		system("pause");
		system("cls");
		break;
	}
	default:
		system("cls");
		break;
	}
}

//char����תint����
int Ctoi(string s) {
	int num = 0;
	stringstream strtoi;
	strtoi << s;
	strtoi >> num;
	return num;
}

int main() {
	//�����ļ�
	Create_File();
	//�����ļ��е�����
	ReadData(M);
	int choice = 99;
	//��ȡ��������
	while (true)
	{
		M.Menu();
		cout << "ְ����Ϣ����ϵͳ:>";
		read_input_buffer(choice);
		MenuChoice(choice);
	}
	return 0;
}
