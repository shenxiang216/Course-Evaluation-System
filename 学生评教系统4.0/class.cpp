#include<iostream>
#include"class.h"
#include<conio.h>              //用_getch();
#include<fstream>                 //文件操作头文件
#include<cstring>
using namespace std;
Student::Student()
{
	cout << "学号：";
s:cin >> Id;      //输入学号
	int i = 0, n = 0;
	while (Id[i] != '\0')   //读取到字符数组末尾
	{
		n += 1;
		i++;
	}
	int j = 0, r = 0;
	while (Id[j] != '\0')//读取到字符数组末尾
	{

		if ((Id[j] >= '0') && (Id[j] <= '9'))  //根据ASC码表判断是否为数字
		{
			r += 1;
		}
		j++;
	}
	if (n != 12 || r != 12)
	{

		cout << "您的输入有误！请重新输入：";   //错误抛出
		goto s;   //跳转到输入语句重新输入
	}
	cout << "姓名：";
	cin >> name;    //输入姓名
	//初始化教师类数组
	a[0] = Teacher(001, "王刚", 101, "数据结构", 0);
	a[1] = Teacher(002, "李明", 102, "面向对象程序设计", 0);
	a[2] = Teacher(003, "刘伟", 103, "离散数学", 0);
	a[3] = Teacher(004, "Tom", 104, "高等数学", 0);
	for (int i = 0; i < 4; i++)    //输入评教分数，并且分数与老师对应
	{
		cout << "教师编号:" << a[i].tnum << "教师姓名：" << a[i].tname << "课程编号：" << a[i].classnum << "课程名称" << a[i].classname << endl;
		cout << "请输入对该课程的评分（0-100分）：";
		double temp;  //定义一个缓冲变量
	star:cin >> temp;  //读入数据，并且暂时保存，语句做相关的标号
		if ((temp > 20) && (temp <= 100))
		{
			a[i].score=temp;
		}
		else
		{
			cout << "您的输入有误！请重新输入：";   //错误抛出
			goto star;    //重新输入
		}
	}

}

void Student::show()   //展示评教结果
{
	cout << "——————————————————" << endl;
	cout << "学号：" << Id << endl;
	cout << "姓名：" << name << endl;
	cout << "【评教结果】" << endl;
	for (int i = 0; i < 4; i++)   //展示数据成员
	{
		cout << "   教师编号:" << a[i].tnum << endl;
		cout << "   教师姓名：" << a[i].tname << endl;
		cout << "   课程编号：" << a[i].classnum << endl;
		cout << "   课程名称:" << a[i].classname << endl;
		cout << "   课程评分:" << a[i].score << endl;
	}
	cout << "——————————————————" << endl;
}
Teacher::Teacher(double num, string name, double classn, string clas, double scor)   //构造函数，为教师类对象赋值
{
	tnum = num;  //给各数据成员赋值
	tname = name;
	classnum = classn;
	classname = clas;
	score = scor;
}
//计算教师评教分数平均分，并且进行排序和对于输出
void Comment::sort()
{
	double sjjg = 0, mxdx = 0, lssx = 0, gdsx = 0;    //定义各科总成绩变量
	double sjjgaverage = 0, mxdxaverage = 0, lssxaverage = 0, gdsxaverage = 0; //定义各科平均分变量
	 //计算各科评教成绩的总和
	
	//获取数组元素的个数
	int i = 0, n = 0;
	while (stu[i].a[0].score > 20)
	{
		n += 1;
		i++;
	}
	for (int i = 0; i < n; i++)
	{
		sjjg += stu[i].a[0].score;
	}
	sjjgaverage = sjjg / n;  //平均分

	for (int i = 0; i < n; i++)
	{
		mxdx += stu[i].a[1].score;
	}
	mxdxaverage = mxdx / n;//平均分
	for (int i = 0; i < n; i++)
	{
		lssx += stu[i].a[2].score;
	}
	lssxaverage = lssx / n;//平均分
	for (int i = 0; i < n; i++)
	{
		gdsx += stu[i].a[3].score;
	}
	gdsxaverage = gdsx / n;//平均分
	double average[4] = { sjjgaverage,mxdxaverage,lssxaverage,gdsxaverage };  //平均分放入数组中
	double temp;    //定义临时变量，在排序中暂存数据
	string label[4] = { "数据结构：","面向对象程序设计：" ,"离散数学:","高等数学"};  //定义标签数组
	string tem;  //定义中间暂存string变量
	//降序排序
	for (int i = 0; i < 3; i++)
	{
		for (int j = i + 1; j < 4; j++)
		{
			if (average[i] < average[j])    //如果判断成立
			{
				temp = average[i];
				average[i] = average[j];   //则交换位置
				average[j] = temp;
				tem = label[i];
				label[i] = label[j];   //则交换位置
				label[j] = tem;
			}
		}
	}
	//数据对应标签输出
	for (int i = 0; i < 4; i++)
	{
		cout << label[i] << average[i] << endl;
	}
	//数据对应标签输出
	/*for (int i = 0; i < 4; i++)
	{
		if (average[i] == sjjgaverage)
		{
			cout << "数据结构:" << average[i] << endl;    //数据结构
		}
		else if (average[i] == mxdxaverage)
		{
			cout << "面向对象程序设计:" << average[i] << endl; //面向对象程序设计
		}
		else if (average[i] == lssxaverage)
		{
			cout << "离散数学:" << average[i] << endl; //离散数学
		}
		else
		{
			cout << "高等数学:" << average[i] << endl; //高等数学
		}
	}*/
}
//展示评教结果
void Comment::showscore()
{
	//获取元素个数
	int i = 0,n = 0;
	while (stu[i].a[0].score>20)
	{
		n += 1;
		i++;
	}
	for (int i = 0; i < n; i++)
	{
		stu[i].show();   //调用学生类对象的show（）输出
	}
}
//保存评教结果
void Comment::save()
{
	out.open("D://outfile.txt");   //打开文件
	//获取数组元素的个数
	int i = 0, n = 0;
	while (stu[i].a[0].score > 20)
	{
		n += 1;
		i++;
	}
	for (int i = 0; i < n; i++)   //循环写入
	{
		out << "学号:" << stu[i].Id << "姓名：" << stu[i].name << endl;    //写入学号姓名
		for (int j = 0; j < 4; j++)  //写入评教信息和分数
		{
			out << "教师编号:" << stu[i].a[j].tnum << "教师姓名：" << stu[i].a[j].tname << "课程编号：" << stu[i].a[j].classnum << "课程名称" << stu[i].a[j].classname << "课程评分" << stu[i].a[j].score << endl;
		}
	}
	double sjjg = 0, mxdx = 0, lssx = 0, gdsx = 0;    //定义各科总成绩变量
	double sjjgaverage = 0, mxdxaverage = 0, lssxaverage = 0, gdsxaverage = 0; //定义各科平均分变量

	 //计算各科评教成绩的总和
	for (int i = 0; i < n; i++)
	{
		sjjg += stu[i].a[0].score;
	}
	sjjgaverage = sjjg / n;  //平均分

	for (int i = 0; i < n; i++)
	{
		mxdx += stu[i].a[1].score;
	}
	mxdxaverage = mxdx / n;//平均分
	for (int i = 0; i < n; i++)
	{
		lssx += stu[i].a[2].score;
	}
	lssxaverage = lssx / n;//平均分
	for (int i = 0; i < n; i++)
	{
		gdsx += stu[i].a[3].score;
	}
	gdsxaverage = gdsx / n;//平均分
	double average[4] = { sjjgaverage,mxdxaverage,lssxaverage,gdsxaverage };  //平均分放入数组中
	double temp;    //定义临时变量，在排序中暂存数据
	string label[4] = { "数据结构：","面向对象程序设计：" ,"离散数学:","高等数学" };  //定义标签数组
	string tem;  //定义中间暂存string变量
	//降序排序
	for (int i = 0; i < 3; i++)
	{
		for (int j = i + 1; j < 4; j++)
		{
			if (average[i] < average[j])    //如果判断成立
			{
				temp = average[i];
				average[i] = average[j];   //则交换位置
				average[j] = temp;
				tem = label[i];
				label[i] = label[j];   //则交换位置
				label[j] = tem;
			}
		}
	}
	//数据对应标签输出
	out << "教学效果：" << endl;
	//数据对应标签输出
	for (int i = 0; i < 4; i++)
	{
		cout << label[i] << average[i] << endl;
	}
	out.close();   //关闭文件
	cout << "保存成功!" << endl;    //保存成功的提示
}
//判断评教是否成功
void Comment::judge()
{
	cout << "评教成功" << endl;
}
void Comment::read()
{
	in.open("D://inputfile.txt");   //打开文件
	cout << "打开文件文件成功！" << endl;
	int i = 0, n = 0;
	while (stu[i].a[0].score > 20)
	{
		n += 1;
		i++;
	}
	for (int i = 0; i < n; i++)   //循环写入
	{
		in >> stu[i].Id;  //写入学号
		for (int j = 0; j < 4; j++)  //写入评教信息和分数
		{
			in >> stu[i].a[j].score;     //写入评教成绩
		}
	}
	in.close();
	cout << "读取文件成功！";
}