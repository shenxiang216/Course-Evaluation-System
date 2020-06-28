#pragma once
#include<string>
#include<fstream>
using namespace std;
class Teacher
{
public:
	double tnum;  //教师编号
	string tname;  //教师姓名
	double classnum;  //课程编号
	string classname;  //课程名称
	double score;   //评教得分
	Teacher(double num = 0, string name = "a", double classn = 0, string clas = "a", double scor = 0);//构造函数，为教师类对象赋值
};
class Student
{
public:
	char Id[25];    //学号
	char name[20];    //学号
	Teacher a[4];//教师类数组
	Student();  //输入数据函数
	void show();       //展示数据成员的函数
};
class Comment
{

public:
	void showscore();//展示评教结果
	Student stu[10];   // 学生类数组
	void sort();   //课程平均分排序，教学排行榜
	void save();  //保存函数
	void judge();  //判断是否评教成功

	void read();     //从文件读取数据
private:
	ifstream in;   //文件输入流
	ofstream out;    //文件输出流
};