#pragma once
#include"Node.h"
#include"userTree.h"
class menu
{
public:
	userTree Tree;
	menu();             //���캯��
	void mainmenu();    //���˵� 
	void load(int n = 0);        //��½ nΪ����������������Ĭ��Ϊ0
	void regist();      //ע�� 
	bool tooEasy(string password);//�ж������Ƿ���ڼ�
	void Change(Node* a); //�޸����� 
	void Delete(Node* a); //ɾ���û� 
	void close();       //���û����ݱ��浽userData.txt��
	bool rightPassword(string a, string b);//��λ����
	void show2();//�鿴�����û����� 
	void Delete2(string a);//ɾ��ָ���û�
};


