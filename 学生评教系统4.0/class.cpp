#include<iostream>
#include"class.h"
#include<conio.h>              //��_getch();
#include<fstream>                 //�ļ�����ͷ�ļ�
#include<cstring>
using namespace std;
Student::Student()
{
	cout << "ѧ�ţ�";
s:cin >> Id;      //����ѧ��
	int i = 0, n = 0;
	while (Id[i] != '\0')   //��ȡ���ַ�����ĩβ
	{
		n += 1;
		i++;
	}
	int j = 0, r = 0;
	while (Id[j] != '\0')//��ȡ���ַ�����ĩβ
	{

		if ((Id[j] >= '0') && (Id[j] <= '9'))  //����ASC����ж��Ƿ�Ϊ����
		{
			r += 1;
		}
		j++;
	}
	if (n != 12 || r != 12)
	{

		cout << "���������������������룺";   //�����׳�
		goto s;   //��ת�����������������
	}
	cout << "������";
	cin >> name;    //��������
	//��ʼ����ʦ������
	a[0] = Teacher(001, "����", 101, "���ݽṹ", 0);
	a[1] = Teacher(002, "����", 102, "�������������", 0);
	a[2] = Teacher(003, "��ΰ", 103, "��ɢ��ѧ", 0);
	a[3] = Teacher(004, "Tom", 104, "�ߵ���ѧ", 0);
	for (int i = 0; i < 4; i++)    //�������̷��������ҷ�������ʦ��Ӧ
	{
		cout << "��ʦ���:" << a[i].tnum << "��ʦ������" << a[i].tname << "�γ̱�ţ�" << a[i].classnum << "�γ�����" << a[i].classname << endl;
		cout << "������Ըÿγ̵����֣�0-100�֣���";
		double temp;  //����һ���������
	star:cin >> temp;  //�������ݣ�������ʱ���棬�������صı��
		if ((temp > 20) && (temp <= 100))
		{
			a[i].score=temp;
		}
		else
		{
			cout << "���������������������룺";   //�����׳�
			goto star;    //��������
		}
	}

}

void Student::show()   //չʾ���̽��
{
	cout << "������������������������������������" << endl;
	cout << "ѧ�ţ�" << Id << endl;
	cout << "������" << name << endl;
	cout << "�����̽����" << endl;
	for (int i = 0; i < 4; i++)   //չʾ���ݳ�Ա
	{
		cout << "   ��ʦ���:" << a[i].tnum << endl;
		cout << "   ��ʦ������" << a[i].tname << endl;
		cout << "   �γ̱�ţ�" << a[i].classnum << endl;
		cout << "   �γ�����:" << a[i].classname << endl;
		cout << "   �γ�����:" << a[i].score << endl;
	}
	cout << "������������������������������������" << endl;
}
Teacher::Teacher(double num, string name, double classn, string clas, double scor)   //���캯����Ϊ��ʦ�����ֵ
{
	tnum = num;  //�������ݳ�Ա��ֵ
	tname = name;
	classnum = classn;
	classname = clas;
	score = scor;
}
//�����ʦ���̷���ƽ���֣����ҽ�������Ͷ������
void Comment::sort()
{
	double sjjg = 0, mxdx = 0, lssx = 0, gdsx = 0;    //��������ܳɼ�����
	double sjjgaverage = 0, mxdxaverage = 0, lssxaverage = 0, gdsxaverage = 0; //�������ƽ���ֱ���
	 //����������̳ɼ����ܺ�
	
	//��ȡ����Ԫ�صĸ���
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
	sjjgaverage = sjjg / n;  //ƽ����

	for (int i = 0; i < n; i++)
	{
		mxdx += stu[i].a[1].score;
	}
	mxdxaverage = mxdx / n;//ƽ����
	for (int i = 0; i < n; i++)
	{
		lssx += stu[i].a[2].score;
	}
	lssxaverage = lssx / n;//ƽ����
	for (int i = 0; i < n; i++)
	{
		gdsx += stu[i].a[3].score;
	}
	gdsxaverage = gdsx / n;//ƽ����
	double average[4] = { sjjgaverage,mxdxaverage,lssxaverage,gdsxaverage };  //ƽ���ַ���������
	double temp;    //������ʱ���������������ݴ�����
	string label[4] = { "���ݽṹ��","������������ƣ�" ,"��ɢ��ѧ:","�ߵ���ѧ"};  //�����ǩ����
	string tem;  //�����м��ݴ�string����
	//��������
	for (int i = 0; i < 3; i++)
	{
		for (int j = i + 1; j < 4; j++)
		{
			if (average[i] < average[j])    //����жϳ���
			{
				temp = average[i];
				average[i] = average[j];   //�򽻻�λ��
				average[j] = temp;
				tem = label[i];
				label[i] = label[j];   //�򽻻�λ��
				label[j] = tem;
			}
		}
	}
	//���ݶ�Ӧ��ǩ���
	for (int i = 0; i < 4; i++)
	{
		cout << label[i] << average[i] << endl;
	}
	//���ݶ�Ӧ��ǩ���
	/*for (int i = 0; i < 4; i++)
	{
		if (average[i] == sjjgaverage)
		{
			cout << "���ݽṹ:" << average[i] << endl;    //���ݽṹ
		}
		else if (average[i] == mxdxaverage)
		{
			cout << "�������������:" << average[i] << endl; //�������������
		}
		else if (average[i] == lssxaverage)
		{
			cout << "��ɢ��ѧ:" << average[i] << endl; //��ɢ��ѧ
		}
		else
		{
			cout << "�ߵ���ѧ:" << average[i] << endl; //�ߵ���ѧ
		}
	}*/
}
//չʾ���̽��
void Comment::showscore()
{
	//��ȡԪ�ظ���
	int i = 0,n = 0;
	while (stu[i].a[0].score>20)
	{
		n += 1;
		i++;
	}
	for (int i = 0; i < n; i++)
	{
		stu[i].show();   //����ѧ��������show�������
	}
}
//�������̽��
void Comment::save()
{
	out.open("D://outfile.txt");   //���ļ�
	//��ȡ����Ԫ�صĸ���
	int i = 0, n = 0;
	while (stu[i].a[0].score > 20)
	{
		n += 1;
		i++;
	}
	for (int i = 0; i < n; i++)   //ѭ��д��
	{
		out << "ѧ��:" << stu[i].Id << "������" << stu[i].name << endl;    //д��ѧ������
		for (int j = 0; j < 4; j++)  //д��������Ϣ�ͷ���
		{
			out << "��ʦ���:" << stu[i].a[j].tnum << "��ʦ������" << stu[i].a[j].tname << "�γ̱�ţ�" << stu[i].a[j].classnum << "�γ�����" << stu[i].a[j].classname << "�γ�����" << stu[i].a[j].score << endl;
		}
	}
	double sjjg = 0, mxdx = 0, lssx = 0, gdsx = 0;    //��������ܳɼ�����
	double sjjgaverage = 0, mxdxaverage = 0, lssxaverage = 0, gdsxaverage = 0; //�������ƽ���ֱ���

	 //����������̳ɼ����ܺ�
	for (int i = 0; i < n; i++)
	{
		sjjg += stu[i].a[0].score;
	}
	sjjgaverage = sjjg / n;  //ƽ����

	for (int i = 0; i < n; i++)
	{
		mxdx += stu[i].a[1].score;
	}
	mxdxaverage = mxdx / n;//ƽ����
	for (int i = 0; i < n; i++)
	{
		lssx += stu[i].a[2].score;
	}
	lssxaverage = lssx / n;//ƽ����
	for (int i = 0; i < n; i++)
	{
		gdsx += stu[i].a[3].score;
	}
	gdsxaverage = gdsx / n;//ƽ����
	double average[4] = { sjjgaverage,mxdxaverage,lssxaverage,gdsxaverage };  //ƽ���ַ���������
	double temp;    //������ʱ���������������ݴ�����
	string label[4] = { "���ݽṹ��","������������ƣ�" ,"��ɢ��ѧ:","�ߵ���ѧ" };  //�����ǩ����
	string tem;  //�����м��ݴ�string����
	//��������
	for (int i = 0; i < 3; i++)
	{
		for (int j = i + 1; j < 4; j++)
		{
			if (average[i] < average[j])    //����жϳ���
			{
				temp = average[i];
				average[i] = average[j];   //�򽻻�λ��
				average[j] = temp;
				tem = label[i];
				label[i] = label[j];   //�򽻻�λ��
				label[j] = tem;
			}
		}
	}
	//���ݶ�Ӧ��ǩ���
	out << "��ѧЧ����" << endl;
	//���ݶ�Ӧ��ǩ���
	for (int i = 0; i < 4; i++)
	{
		cout << label[i] << average[i] << endl;
	}
	out.close();   //�ر��ļ�
	cout << "����ɹ�!" << endl;    //����ɹ�����ʾ
}
//�ж������Ƿ�ɹ�
void Comment::judge()
{
	cout << "���̳ɹ�" << endl;
}
void Comment::read()
{
	in.open("D://inputfile.txt");   //���ļ�
	cout << "���ļ��ļ��ɹ���" << endl;
	int i = 0, n = 0;
	while (stu[i].a[0].score > 20)
	{
		n += 1;
		i++;
	}
	for (int i = 0; i < n; i++)   //ѭ��д��
	{
		in >> stu[i].Id;  //д��ѧ��
		for (int j = 0; j < 4; j++)  //д��������Ϣ�ͷ���
		{
			in >> stu[i].a[j].score;     //д�����̳ɼ�
		}
	}
	in.close();
	cout << "��ȡ�ļ��ɹ���";
}