#include "menu.h"
#include<iostream>
#include<fstream>
#include"userTree.h"
#include"Node.h"
#include<string>
#include<conio.h>
using namespace std;
menu::menu()
{
	ifstream Fang("userData.txt");
	string tempname;
	string temppassword;
	for (int i = 0; i < 20; i++)
	{
		getline(Fang, tempname, ' ');//һ��һ�����ݣ��û���������֮���ÿո�ֿ��������ո�ֹͣ
		getline(Fang, temppassword);//��������ֹͣ
		Tree.insert(tempname, temppassword);
	}
}
void menu::mainmenu()  //���˵�
{
	system("cls");              //�����Ļ
	cout << endl << endl << endl << endl;
	cout << "                                      �û���¼ϵͳ" << endl;
	cout << "                   ******************************************************" << endl;
	cout << "                   *                                                    *" << endl;
	cout << "                   *                                                    *" << endl;
	cout << "                   *        ��ѡ�������                                *" << endl;
	cout << "                   *                                                    *" << endl;
	cout << "                   *                 1.��¼                             *" << endl;
	cout << "                   *                 2.ע�����û�                       *" << endl;
	cout << "                   *                 3.�˳�ϵͳ������û�����           *" << endl;
	cout << "                   *                                                    *" << endl;
	cout << "                   *                                                    *" << endl;
	cout << "                   ******************************************************" << endl;
	cout << "                   ����1-3: ";
	string a;
	cin >> a;
	while (a.length() != 1 || a > "3" || a < "1")
	{
	   	cout << "               	   �����������������1-3: ";
		cin >> a;
	}
	int t = a[0] - '0';
	switch (t)
	{
	case 1:
		load();
		break;
	case 2:
		regist(); 
		break;
	case 3:
		close(); 
		break;
	}
}
bool menu::rightPassword(string a, string b)
{
	string::size_type idx;           //��λ����
	idx = a.find(b);                 //��a�в���b
	if (idx == string::npos)         //�������
		return false;
	else
		return true;
}
void menu::show2()  //�鿴�����û����� 
{
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                                      �����û�����" << endl;
	cout << "                   ******************************************************" << endl;
	cout << "                   *                                                    *" << endl;
	cout << "                   *                                                    *" << endl;
	Tree.show();
	cout << "                   *                                                    *" << endl;
	cout << "                   *                                                    *" << endl;
	cout << "                   ******************************************************" << endl;
	cout << "                   ��ѡ�������" << endl;
	cout << "                   1.�������˵�" << endl;
	cout << "                   2.�˳�ϵͳ������û�����" << endl;
	cout << "                   ����1-2: ";
	string a;
	cin >> a;
	while (a.length() != 1 || a > "2" || a < "1")
	{
		cout << "                   �����������������1-2: ";
		cin >> a;
	}
	int t = a[0] - '0';
	switch (t)
	{
	case 1:
		mainmenu();
		break;
	case 2:
		close();
		break;
	}
}
void menu::load(int n)   //��¼����
{
	system("cls");
	string name;
	cout << endl << endl;
	cout << "                      ����Ա�˺ţ�201806062707    ����:fangtianbin" << endl;
	cout << endl;
	cout << "                                      �û���¼����" << endl;
	cout << "                   ******************************************************" << endl;
	cout << "                   *                                                    *" << endl;
	cout << "                   *                                                    *" << endl;
	cout << "                   *      �������û���: ";
	cin >> name;
	cout << "                   *      �������û�����: ";
	string password;
	int i = 0;
	char ch;
	while ((ch = _getch()) != 13)//13�ǻس�
	{
		password += ch;
		cout << "*";
	}
	cout << endl;
	Node* ptr = Tree.search(name);
	if (n == 2)
	{
		cout << "                   *      ����������Σ��Զ��˳�ϵͳ                    *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   ******************************************************" << endl;
		close();
	}
	else if (ptr == 0)
	{
		cout << "                   *      ��¼�����û���������                        *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   ******************************************************" << endl;
		cout << "                   1.���µ�¼" << endl;
		cout << "                   2.�������˵�" << endl;
		cout << "                   3.�˳�ϵͳ������û�����" << endl;
		cout << "                   ����1-3: ";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "3" || a < "1")
		{
			cout << "                   �����������������1-3: ";
			cin >> a;
		}
		int t = a[0] - '0';
		switch (t)
		{
		case 1:
			load();
			break;
		case 2:
			mainmenu();
			break;
		case 3:
			close();
			break;
		}
	}
	else if (rightPassword(password, ptr->userPassword) && name == "201806062707")//�������Ա���棬����Ա�˻������޸�����
	{
		cout << "                   *      ��¼�ɹ���                                    *" << endl;
		cout << "                   *      �𾴵Ĺ���Ա�û������ã�                      *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   ******************************************************" << endl;
		cout << "                   ��ѡ�������" << endl;
		cout << "                   1.�鿴�����û�����" << endl;
		cout << "                   2.ɾ��ָ���û�" << endl;
		cout << "                   3.�������˵�" << endl;
		cout << "                   4.�˳�ϵͳ������û�����" << endl;
		cout << "                   ����1-4: ";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "4" || a < "1")
		{
			cout << "                   �����������������1-4: ";
			cin >> a;
		}
		int t = a[0] - '0';
		string delname;
		string b;
		switch (t)
		{
		case 1:
			show2();
			break;
		case 2:
			cout << "                   ������ɾ�����û��˺�: ";
			cin >> delname;
			Delete2(delname);
			break;
		case 3:
			mainmenu();
			break;
		case 4:
			close();
			break;
		}
	}
	else if (rightPassword(password, ptr->userPassword))
	{
		cout << "                   *      ��¼�ɹ���                                    *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   ******************************************************" << endl;
		cout << "                   ��ѡ�������" << endl;
		cout << "                   1.�޸�����" << endl;
		cout << "                   2.ɾ���û�" << endl;
		cout << "                   3.�������˵�" << endl;
		cout << "                   4.�˳�ϵͳ������û�����" << endl;
		cout << "                   ����1-4: ";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "4" || a < "1")
		{
			cout << "                   �����������������1-4: ";
			cin >> a;
		}
		int t = a[0] - '0';
		switch (t)
		{
		case 1:
			Change(Tree.search(name)); 
			break;
		case 2:
			Delete(Tree.search(name));
			break;
		case 3:
			mainmenu(); 
			break;
		case 4:
			close(); 
			break;
		}
	}
	else
	{
		n++;
		cout << "                   *      ��¼ʧ�ܣ��������                            *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   ******************************************************" << endl;
		cout << "                   ��ѡ�������" << endl;
		cout << "                   1.���µ�¼" << endl;
		cout << "                   2.�������˵�" << endl;
		cout << "                   3.�˳�ϵͳ������û�����" << endl;
		cout << "                   ����1-3: ";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "3" || a < "1")
		{
			cout << "                   �����������������1-3: ";
			cin >> a;
		}
		int t = a[0] - '0';
		switch (t)
		{
		case 1:
			load(n);
			break;
		case 2:
			mainmenu();
			break;
		case 3:
			close();
			break;
		}
	}
}
bool menu::tooEasy(string password)//���ڼ򵥵�����
{
	if (password.length() < 4)
		return true;
	if (password == "123456")
		return true;
	if (password == "12345678")
		return true;
	if (password == "123456789")
		return true;
	if (password == "8888")
		return true;
	if (password == "888888")
		return true;
	if (password == "88888888")
		return true;
	return false;
}
void menu::regist()  //ע�� 
{
	string name, password1, password2;
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                                      ���û�ע�����" << endl;
	cout << "                   ******************************************************" << endl;
	cout << "                   *                                                    *" << endl;
	cout << "                   *                                                    *" << endl;
	cout << "                   *     ��������Ҫע����û���:";
	cin >> name;
	cout << "                   *     ����������: ";
	char ch1;
	while ((ch1 = _getch()) != 13)//13�ǻس�
	{
		password1 += ch1;
		cout << "*";
	}
	cout << endl;
	cout << "                   *     ��ȷ������: ";
	char ch2;
	while ((ch2 = _getch()) != 13)//13�ǻس�
	{
		password2 += ch2;
		cout << "*";
	}
	cout << endl;
	Node* ptr = Tree.search(name);
	if (ptr == 0 && password1 == password2 && !tooEasy(password1))
	{
		Tree.insert(name, password1);
		cout << "                   *     ע��ɹ���                                     *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   ******************************************************" << endl;
		cout << "                   ��ѡ�������" << endl;
		cout << "                   1.�������˵�" << endl;
		cout << "                   2.�˳�ϵͳ������û�����" << endl;
		cout << "                   ����1-2: ";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "2" || a < "1")
		{
			cout << "                   �����������������1-2: ";
			cin >> a;
		}
		int t = a[0] - '0';
		switch (t)
		{
		case 1:
			mainmenu();
			break;
		case 2:
			close();
			break;
		}
	}
	else if (ptr != 0) 
	{ 
		cout << "                   *     ע��ʧ�ܣ��û����Ѵ���                         *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   ******************************************************" << endl;
		cout << "                   ��ѡ�������" << endl;
		cout << "                   1.����ע��" << endl;
		cout << "                   2.�������˵�" << endl;
		cout << "                   3.�˳�ϵͳ������û�����" << endl;
		cout << "                   ����1-3:";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "3" || a < "1")
		{
			cout << "                   �����������������1-3: ";
			cin >> a;
		}
		int t = a[0] - '0';
		switch (t)
		{
		case 1:
			regist();
			break;
		case 2:
			mainmenu();
			break;
		case 3:
			close();
			break;
		}
	}
	else if (password1 != password2) 
	{ 
		cout << "                   *     ע��ʧ�ܣ��������벻һ��                       *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   ******************************************************" << endl;
		cout << "                   ��ѡ�������" << endl;
		cout << "                   1.����ע��" << endl;
		cout << "                   2.�������˵�" << endl;
		cout << "                   3.�˳�ϵͳ������û�����" << endl;
		cout << "                   ����1-3: ";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "3" || a < "1")
		{
			cout << "                   �����������������1-3: ";
			cin >> a;
		}
		int t = a[0] - '0';
		switch (t)
		{
		case 1:
			regist();
			break;
		case 2:
			mainmenu();
			break;
		case 3:
			close();
			break;
		}
	}
	else if (tooEasy(password1))
	{
		cout << "                   *     ע��ʧ�ܣ�������ڼ�                         *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   ******************************************************" << endl;
		cout << "                   ��ѡ�������" << endl;
		cout << "                   1.����ע��" << endl;
		cout << "                   2.�������˵�" << endl;
		cout << "                   3.�˳�ϵͳ������û�����" << endl;
		cout << "                   ����1-3: ";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "3" || a < "1")
		{
			cout << "                   �����������������1-3: ";
			cin >> a;
		}
		int t = a[0] - '0';
		switch (t)
		{
		case 1:
			regist();
			break;
		case 2:
			mainmenu();
			break;
		case 3:
			close();
			break;
		}
	}
}
void menu::Change(Node* ptr)                   //�޸����� 
{
	string name = ptr->userName;
	string password;
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                                      �û������޸Ľ���" << endl;
	cout << "                   ******************************************************" << endl;
	cout << "                   *                                                    *" << endl;
	cout << "                   *                                                    *" << endl;
	cout << "                   *      ������������:";
	char ch;
	while ((ch = _getch()) != 13)//13�ǻس�
	{
		password += ch;
		cout << "*";
	}
	if (!tooEasy(password) && password != ptr->userPassword)
	{
		ptr->userPassword = password;
		cout << "                   *      �޸�����ɹ���                                *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   ******************************************************" << endl;
		cout << "                   ��ѡ�������" << endl;
		cout << "                   1.�������˵�" << endl;
		cout << "                   2.�˳�ϵͳ������û�����" << endl;
		cout << "                   ����1-2:";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "2" || a < "1")
		{
			cout << "                   �����������������1-2: ";
			cin >> a;
		}
		int t = a[0] - '0';
		switch (t)
		{
		case 1:
			mainmenu();
			break;
		case 2:
			close();
			break;
		}
	}
	else if (tooEasy(password))
	{
		cout << "                   *      �����޸�ʧ�ܣ�������ڼ�                    *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   ******************************************************" << endl;
		cout << "                   ��ѡ�������" << endl;
		cout << "                   1.�����޸�����" << endl;
		cout << "                   1.�������˵�" << endl;
		cout << "                   2.�˳�ϵͳ������û�����" << endl;
		cout << "                   ����1-3:";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "3" || a < "1")
		{
			cout << "                   �����������������1-3: ";
			cin >> a;
		}
		int t = a[0] - '0';
		switch (t)
		{
		case 1:
			Change(Tree.search(name));
			break;
		case 2:
			mainmenu();
			break;
		case 3:
			close();
			break;
		}
	}
	else if (password == ptr->userPassword)
	{
		cout << "                   *      �޸�����ʧ�ܣ������벻����ԭ������ͬ          *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   ******************************************************" << endl;
		cout << "                   ��ѡ�������" << endl;
		cout << "                   1.�����޸�����" << endl;
		cout << "                   1.�������˵�" << endl;
		cout << "                   2.�˳�ϵͳ������û�����" << endl;
		cout << "                   ����1-3:";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "3" || a < "1")
		{
			cout << "                   �����������������1-3: ";
			cin >> a;
		}
		int t = a[0] - '0';
		switch (t)
		{
		case 1:
			Change(Tree.search(name));
			break;
		case 2:
			mainmenu();
			break;
		case 3:
			close();
			break;
		}
	}
}
void menu::Delete2(string a)  //ɾ��ָ���û� 
{
	Node* ptr = Tree.search(a);
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                                      ɾ���û�����" << endl;
	cout << "                   ******************************************************" << endl;
	cout << "                   *                                                    *" << endl;
	cout << "                   *                                                    *" << endl;
	if (ptr == 0)
	{
		cout << "                   *      ɾ���û�ʧ�ܣ��û�������                      *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   ******************************************************" << endl;
		cout << "                   ��ѡ�������" << endl;
		cout << "                   1.�������˵�" << endl;
		cout << "                   2.�˳�ϵͳ������û�����" << endl;
		cout << "                   ����1-2: ";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "2" || a < "1")
		{
			cout << "                   �����������������1-2: ";
			cin >> a;
		}
		int t = a[0] - '0';
		switch (t)
		{
		case 1:
			mainmenu();
			break;
		case 2:
			close();
			break;
		}
	}
	else
	{
		Tree.Delete(ptr->userName);
		cout << "                   *      ɾ�����û��ɹ���                              *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   *                                                    *" << endl;
		cout << "                   ******************************************************" << endl;
		cout << "                   ��ѡ�������" << endl;
		cout << "                   1.�������˵�" << endl;
		cout << "                   2.�˳�ϵͳ������û�����" << endl;
		cout << "                   ����1-2: ";
		string a;
		cin >> a;
		while (a.length() != 1 || a > "2" || a < "1")
		{
			cout << "                   �����������������1-2: ";
			cin >> a;
		}
		int t = a[0] - '0';
		switch (t)
		{
		case 1:
			mainmenu();
			break;
		case 2:
			close();
			break;
		}
	}
}
void menu::Delete(Node* p)  //ɾ���û� 
{
	Tree.Delete(p->userName);
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "                                      ɾ���û�����" << endl;
	cout << "                   ******************************************************" << endl;
	cout << "                   *                                                    *" << endl;
	cout << "                   *                                                    *" << endl;
	cout << "                   *      ɾ�����û��ɹ���                              *" << endl;
	cout << "                   *                                                    *" << endl;
	cout << "                   *                                                    *" << endl;
	cout << "                   ******************************************************" << endl;
	cout << "                   ��ѡ�������" << endl;
	cout << "                   1.�������˵�" << endl;
	cout << "                   2.�˳�ϵͳ������û�����" << endl;
	cout << "                   ����1-2: ";
	string a;
	cin >> a;
	while (a.length() != 1 || a > "2" || a < "1")
	{
		cout << "                   �����������������1-2: ";
		cin >> a;
	}
	int t = a[0] - '0';
	switch (t)
	{
	case 1:
		mainmenu();
		break;
	case 2:
		close();
		break;
	}
}
void menu::close()  //���û����浽txt��
{
	ofstream FFang("NewuserData.txt");
	FFang << Tree;
	FFang.close();
}