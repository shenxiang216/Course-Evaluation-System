#pragma once
#include<string>
#include<fstream>
using namespace std;
class Teacher
{
public:
	double tnum;  //��ʦ���
	string tname;  //��ʦ����
	double classnum;  //�γ̱��
	string classname;  //�γ�����
	double score;   //���̵÷�
	Teacher(double num = 0, string name = "a", double classn = 0, string clas = "a", double scor = 0);//���캯����Ϊ��ʦ�����ֵ
};
class Student
{
public:
	char Id[25];    //ѧ��
	char name[20];    //ѧ��
	Teacher a[4];//��ʦ������
	Student();  //�������ݺ���
	void show();       //չʾ���ݳ�Ա�ĺ���
};
class Comment
{

public:
	void showscore();//չʾ���̽��
	Student stu[10];   // ѧ��������
	void sort();   //�γ�ƽ�������򣬽�ѧ���а�
	void save();  //���溯��
	void judge();  //�ж��Ƿ����̳ɹ�

	void read();     //���ļ���ȡ����
private:
	ifstream in;   //�ļ�������
	ofstream out;    //�ļ������
};