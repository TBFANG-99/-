#pragma once
#include<iostream>
#include "Node.h"
using namespace std;
class userTree
{
private:
	Node* myRoot;
	void insertAux(string name, string password, Node*& a); //���ڲ������û����ݣ��ݹ���,a������
	void DeleteAux(string name, Node*& a);//�ݹ���
	Node* FindMin(Node* a);//ɾ����
	void graphAux(int n, Node* root);
public:
	Node* RightRotate(Node* a);//����,������ƽ��ڵ�
	Node* LeftRotate(Node* a);//������������ƽ��ڵ�
	Node* LR_Rotate(Node* a);//������
	Node* RL_Rotate(Node* a);//������
	void insert(string name, string password);//����������û����ݣ��ж��Ƿ��ظ��û���
	int depth(Node* a);//�ڵ�������ȣ�Ҷ��Ϊ1�����ϵ��������ڼ���ƽ������
	void Delete(string name);
	void graph();
	userTree() :myRoot(0) {};
	Node* search(string name);
	friend ostream& operator << (ostream& stream, userTree a);  //����ļ� 
	friend void outtxt(Node* a, ostream& output);
	void showAux(Node* a); 
	void show();
};