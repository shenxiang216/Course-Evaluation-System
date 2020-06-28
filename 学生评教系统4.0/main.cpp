#include<iostream>
#include"class.h"
#include<conio.h>  //用_getch()的头文件
using namespace std;
int main()
{
	char x;  //定义计数控制变量
	bool quit = false;  //bool类型的控制程序开始和结束的变量
	cout << "    【欢迎进入学生评教系统】" << endl;
	cout << "    【请输入个人信息后再进行评价】" << endl;
	cout << "    【评分结果在0-100】" << endl;
	cout << "    【进行评价后才能查看期末考试成绩喔！】" << endl;
	cout << "    【请按任意键开始评教！】" << endl;
	_getch();

	Comment b;    //实例化Comment
	while (!quit)     //while循环实现多次选择

	{
		//system("cls");//清屏
		cout << "———————————————" << endl;   //菜单
		cout << "————1.查看评教是否成功——" << endl;
		cout << "————2.展示评教结果————" << endl;
		cout << "————3.教学效果查看————" << endl;
		cout << "————4.保存结果——————" << endl;
		cout << "————5.从文件读取—————" << endl;
		cout << "————0.退出系统——————" << endl;
		cout << "————请选择：" << endl;
		cin >> x;//读入选择
		switch (x)     //switch语句对读入的数字进行不同的操作

		{

		case '0': quit = true; break;   //退出程序

		case '1':b.judge(); break;     //判断评教是否成功

		case '2':b.showscore(); break;   //展示评教结果

		case '3':b.sort(); break;     //教学效果排序

		case '4':b.save(); break;    //保存文件

		case '5':b.read(); break;    //从文件读取数据

		default:cout << "您的输入有误!" << endl;   //错误抛出语句

		}

	}
	system("pause");  //暂停窗口
	return 0;
}