////C����ʵ�ֿ���̨�й�������ƶ�
//#include <stdio.h>
//#include <windows.h>
//#include <conio.h>
//
//HANDLE hout;
////�������
//char getInput()
//{
//    int ch; //�����ַ���
//
//    COORD coord; //��Ļ�ϵ�����
//    CONSOLE_SCREEN_BUFFER_INFO csbi; //����̨��Ļ��������Ϣ
//
//    coord.X = 10;
//    coord.Y = 10;
//
//    ch = getch();
//
//    //0x0d��ʾ�س���0XE0��ʾ�������ҵȼ��ļ���
//    while (ch == 0xE0 || ch == 0x0d)
//    {
//        GetConsoleScreenBufferInfo(hout, &csbi);
//        coord.X = csbi.dwCursorPosition.X; //�õ�����X��ֵ
//        coord.Y = csbi.dwCursorPosition.Y; //�õ�����Y��ֵ
//        //����ǻس�
//        if (ch == 0x0d)
//        {
//            coord.X = 0;
//            coord.Y++;
//            SetConsoleCursorPosition(hout, coord);
//            break;
//        }
//        ch = getch();
//        //��
//        if (ch == 0x48)
//        {
//            if (coord.Y != 0)coord.Y--;
//        }
//        //��
//        else if (ch == 0x50)
//        {
//            coord.Y++;
//        }
//        //��
//        else if (ch == 0x4b)
//        {
//            if (coord.X != 0) { coord.X--; }
//        }
//        //��
//        else if (ch == 0x4d)
//        {
//            if (coord.X != 79)coord.X++;
//            else
//            {
//                coord.X = 0;
//                coord.Y++;
//            }
//        }
//        SetConsoleCursorPosition(hout, coord);
//        ch = getch();
//    }
//    return ch;
//}
//int main()
//{
//    char ch;
//    hout = GetStdHandle(STD_OUTPUT_HANDLE);
//    //�Ӽ��̻�ȡ���룬����Ƿ������ִ�з����ܣ�����ǻس������У�������ַ������
//    while (1)
//    {
//        ch = getInput();
//        printf("%c", ch);
//    }
//    getchar();
//}