#include<iostream>
#include"class.h"
#include<conio.h>  //��_getch()��ͷ�ļ�
using namespace std;
int main()
{
	char x;  //����������Ʊ���
	bool quit = false;  //bool���͵Ŀ��Ƴ���ʼ�ͽ����ı���
	cout << "    ����ӭ����ѧ������ϵͳ��" << endl;
	cout << "    �������������Ϣ���ٽ������ۡ�" << endl;
	cout << "    �����ֽ����0-100��" << endl;
	cout << "    ���������ۺ���ܲ鿴��ĩ���Գɼ�ร���" << endl;
	cout << "    ���밴�������ʼ���̣���" << endl;
	_getch();

	Comment b;    //ʵ����Comment
	while (!quit)     //whileѭ��ʵ�ֶ��ѡ��

	{
		//system("cls");//����
		cout << "������������������������������" << endl;   //�˵�
		cout << "��������1.�鿴�����Ƿ�ɹ�����" << endl;
		cout << "��������2.չʾ���̽����������" << endl;
		cout << "��������3.��ѧЧ���鿴��������" << endl;
		cout << "��������4.������������������" << endl;
		cout << "��������5.���ļ���ȡ����������" << endl;
		cout << "��������0.�˳�ϵͳ������������" << endl;
		cout << "����������ѡ��" << endl;
		cin >> x;//����ѡ��
		switch (x)     //switch���Զ�������ֽ��в�ͬ�Ĳ���

		{

		case '0': quit = true; break;   //�˳�����

		case '1':b.judge(); break;     //�ж������Ƿ�ɹ�

		case '2':b.showscore(); break;   //չʾ���̽��

		case '3':b.sort(); break;     //��ѧЧ������

		case '4':b.save(); break;    //�����ļ�

		case '5':b.read(); break;    //���ļ���ȡ����

		default:cout << "������������!" << endl;   //�����׳����

		}

	}
	system("pause");  //��ͣ����
	return 0;
}