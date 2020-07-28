#include "userTree.h"
#include"Node.h"
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
Node* userTree::RightRotate(Node* a)//aָ��ƽ������2�ĵ㣬������ɺ󷵻���ƽ���
{
	Node* r = a->left;         
	a->left = r->right;                   
	r->right = a;
	return r;
}
Node* userTree::LeftRotate(Node* a)//����ͬ��
{
	Node* r = a->right;
	a->right = r->left;
	r->left = a;
	return r;
}
Node* userTree::LR_Rotate(Node* a)//���Ϊ��������������ע��a��λ�ã�������a��ƽ������Ϊ2�ĵ�,������ɺ󷵻���ƽ���
{
	a->left = LeftRotate(a->left);
	return RightRotate(a);
}
Node* userTree::RL_Rotate(Node* a)//������ͬ��
{
	a->right = RightRotate(a->right);
	return LeftRotate(a);
}
void userTree::insert(string name, string password)
{
	//�ж��û����Ƿ��ظ�
	int found = 0;
	Node* ptr = myRoot;
	while (ptr != 0 && !found)
	{
		if (name > ptr->userName)
			ptr = ptr->right;
		else if (name < ptr->userName)
			ptr = ptr->left;
		else
			found = 1;
	}
	if (found)
	{
		cout << "�����û�ʧ�ܣ����û�����ע��" << endl;
		return;
	}
	//�����ڲ������ݹ����
	insertAux(name, password, myRoot);
}
void userTree::insertAux(string name, string password, Node*& a)
{
	if (a == 0)
		a = new Node(name, password);
	else if (name > a->userName)
	{
		insertAux(name, password, a->right);
		if (depth(a->right) - depth(a->left) > 1)//ƽ��״̬�������ҽڵ㣬�Ҹ߼���߿϶����ڵ���0   //��ת��ƽ��
		{
			if (name > a->right->userName)       //�������������
				a = LeftRotate(a);
			if (name < a->right->userName)       //���������������
				a = RL_Rotate(a);
		}
	}
	else
	{
		insertAux(name, password, a->left);
		if (depth(a->left) - depth(a->right) > 1)
		{
			if (name < a->left->userName)            //��������
				a = RightRotate(a);
			if (name > a->left->userName)            //���ң�������
				a = LR_Rotate(a);
		}
	}
}
int userTree::depth(Node* a)//�ݹ������
{
	if (a == 0)
		return 0;
	return max(depth(a->left), depth(a->right)) + 1;
}
void userTree::Delete(string name)
{
	int found = 0;
	Node* ptr = myRoot;
	while (ptr != 0 && !found)
	{
		if (name > ptr->userName)
			ptr = ptr->right;
		else if (name < ptr->userName)
			ptr = ptr->left;
		else
			found = 1;
	}
	if (!found)
	{
		cout << "ɾ���û�ʧ�ܣ����û���δע��" << endl;
		return;
	}
	//�����ڲ������ݹ�ɾ��
	DeleteAux(name, myRoot);
}
void userTree::DeleteAux(string name, Node*& a)
{
	if (a == 0)
		return;
	else if (name > a->userName)  //��ƽ
	{
		DeleteAux(name, a->right);
		if (depth(a->left) - depth(a->right) > 1)
		{
			if (a->left->right && a->left->left)   //ɾ�������е�������������PPT
				a = RightRotate(a);
			else if (a->left->right)            //���ң�˫��
				a = LR_Rotate(a);
			else                                //��������
				a = RightRotate(a);
		}
	}
	else if (name < a->userName)   //��ƽ
	{
		DeleteAux(name, a->left);
		if (depth(a->right) - depth(a->left) > 1)
		{
			if (a->right->right && a->right->left)   //ɾ�������е�������������PPT
				a = LeftRotate(a);
			else if (a->right->left)            //����˫��
				a = RL_Rotate(a);
			else                                //���ң�����
				a = LeftRotate(a);
		}
	}
	else     //ɾ��
	{
		if (a->left && a->right)   //����������
		{
			a->userName = FindMin(a->right)->userName;
			a->userPassword = FindMin(a->right)->userPassword;
			DeleteAux(name, a->right);
		}
		else                       //ֻ��һ�����ӻ���û�к���
		{
			Node* t = a;
			if (a->left == 0)
				a = a->right;
			else if (a->right == 0)
				a = a->left;
			delete t;
		}
	}
}
Node* userTree::FindMin(Node* a)//ɾ���в���ֱ�Ӻ��
{
	if (a == 0)
		return 0;
	else
	{
		if (a->left == 0)
			return a;
		else
			return FindMin(a->left);
	}
}
void userTree::graphAux(int n, Node* root)
{
	if (root != 0)
	{
		graphAux(n + 8, root->right);
		cout << setw(n) << " " << root->userName << endl;
		graphAux(n + 8, root->left);
	}
}
void userTree::graph()
{
	graphAux( 0, myRoot);
}

Node* userTree::search(string name)
{
	Node* locptr = myRoot;
	while (locptr != 0)
	{
		if (name > locptr->userName)
			locptr = locptr->right;
		else if (name < locptr->userName)
			locptr = locptr->left;
		else
			return locptr;
	}
	return 0;
}
void outtxt(Node* a, ostream& output)  //�������
{
	if (a == 0)
		return;
	output << a->userName << " " << a->userPassword << endl;
	outtxt(a->left, output);
	outtxt(a->right, output);
}
ostream& operator <<(ostream& stream, userTree a)  //����ļ������û����浽txt�� 
{
	outtxt(a.myRoot, stream);
	return stream;
}
void userTree::showAux(Node* a) 
{
	if (a == NULL) return;
	cout << "                   *  " << a->userName << "   " << a->userPassword << endl;
	showAux(a->left);
	showAux(a->right);
}
void userTree::show()
{
	showAux(myRoot);
}