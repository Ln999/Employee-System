#pragma warning(disable:4996)
#include<ctime>
#include<sstream>
#include<conio.h>//控制台输入输出
#include<cstdio>
#include<cstdlib>
#include<Windows.h>
#include<fstream>
#include<thread>
#include"MANAGEMENT.h"
using namespace std;

//全局变量
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
//ofstream ofs;//C++用同一个文件流对象读写文件除了要close()还需要clear()
//ifstream ifs;
const string FileName = "职工信息表.txt";

//全局函数声明
std::string GetDate();
long long GetNum();
void ReadData(Management&);//读文件数据
void WriteData(Management&);//写数据
int Ctoi(string);
void IsStaffExist(Management&);//防止写入重复数据
void MenuChoice(int&);//功能菜单选择
void Create_File();//创建文件
bool IsFileEmpty();//文件是否为空
void Delstaff(Management&);

//全局函数定义
//创建文件
void Create_File() {
	ofstream ofs;
	fstream f;
	f.open(FileName);
	if (!f) {
		ofs.open(FileName, ios::out);
		if (!ofs) {
			cout << "创建文件失败" << endl;
			exit(0);
		}
		else
		{
			ofs << "职工编号		姓名		性别		年龄		部门		职位		" << endl;
			ofs.close();
			return;
		}
	}
	else {
		f.close();
		return;
	}


}
//判断文件是否为空
bool IsFileEmpty() {
	ifstream ifs;
	string strbuf;
	char ch;
	int line = 0;
	ifs.open(FileName, ios::in);
	if (!ifs) {
		cout << "文件打开失败001" << endl;
		exit(0);
	}
	else {
		while (getline(ifs, strbuf)) {
			line++;
			if (line >= 1) {//从第二行开始读数据
				ch = ifs.get();
				if (ch ==EOF) {//第二行读取一个字符为文件结束符
					ifs.close();
					return true;//文件为空
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
//如果容器中的数据在文件中已经存在,则删除容器中的元素
	ifstream ifs;
	 bool Empty=IsFileEmpty();
	ifs.open(FileName, ios::in);
	if (!ifs) {
		cout << "文件打开失败002" << endl;
		exit(0);
	}
	else {
		if (Empty==0&&!M.VecStaff.empty()) {//文件不为空且容器中存在数据
			//读取每一行的数据跟容器的职工编号比较
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
	strftime(ch, sizeof(ch) - 1, "%Y%m%d", localtime(&Time));//不使用VS提供的localtime_s(),在项目预处理定义添加_CRT_SECURE_NO_WARNINGS
	return ch;
}
//生成职工编号
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
		cout << "获取编号失败" << endl;
	}
	else {
		if (Empty==1||IsNewDate.compare(GetDate())<0) {//日期变更,生成新日期编号
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
		else {//文件不为空,使用文件中的编号
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
//向文件写入数据
void WriteData( Management& M) {
	ofstream ofs;
	ofs.open(FileName, ios::out | ios::app);
	if (!ofs) {
		cout << "打开文件失败003" << endl;
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
//从文件读出数据
void ReadData(Management& M) {
	ifstream ifs;
	bool Empty = IsFileEmpty();
	ifs.open(FileName, ios::in);//指向文件
	if (!ifs) {
		cout << "读取数据失败" << endl;
		exit(0);
	}
	else {
		//文件内容不为空
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
			//加载完数据,关闭文件
			ifs.close();
			return;
		}
		else {
			//文件为空,关闭文件并退出加载
			ifs.close();
			return;
		}
	}
	
}
//获取键盘输入
void Delstaff(Management&M) {
	ofstream ofs;
	fstream tmp;
	string strbuf;
	tmp.open("temp.txt", ios::out|ios::app);
	if (!tmp) {
		cout << "临时文件创建失败" << endl;
		return;
	}
	else {
		tmp << "职工编号		姓名		性别		年龄		部门		职位		" << endl;
		for (uint32 i = 0; i < M.VecStaff.size(); i++) {
			tmp << M.VecStaff[i].StaffNum << '\t' << '\t' << M.VecStaff[i].per.GetPersonName() << '\t' << '\t' <<
				M.VecStaff[i].per.GetPersonSex() << '\t' << '\t' << M.VecStaff[i].per.GetPersonAge() << '\t' << '\t' <<
				M.VecStaff[i].SDept << '\t' << '\t' << M.VecStaff[i].SPos << endl;
		}
	}
	remove("职工信息表.txt");
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
	//多接收的字符暂时不知道怎么解决
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
			cout << "无法识别命令:" << buffer << endl;
			system("pause");
		}
	}
}
//功能菜单选择
void MenuChoice(int& choice) {
	switch (choice)//菜单功能实现
	{
		//退出系统前写入数据
	case 0: {
		IsStaffExist(M);
		WriteData(M);
		exit(0);
	}
	case 1: {
		int count = 0;
		cout << "要添加的员工数量:";
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
		cout << "做梦!" << endl;
		system("pause");
		system("cls");
		break;
	}
	default:
		system("cls");
		break;
	}
}

//char类型转int类型
int Ctoi(string s) {
	int num = 0;
	stringstream strtoi;
	strtoi << s;
	strtoi >> num;
	return num;
}

int main() {
	//创建文件
	Create_File();
	//加载文件中的数据
	ReadData(M);
	int choice = 99;
	//获取键盘输入
	while (true)
	{
		M.Menu();
		cout << "职工信息管理系统:>";
		read_input_buffer(choice);
		MenuChoice(choice);
	}
	return 0;
}
