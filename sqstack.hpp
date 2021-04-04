#ifndef __SQSTACK_H__
#define __SQSTACK_H__
#include<iostream>
#include<new>
using std::cout;
using std::endl;
using std::string;

template<typename T>class sqstack {
public:
	typedef int ElemType;

private:
	struct StackNode {
		string data;
		struct StackNode* next;
		int flag = 0;
	};
	StackNode* top = nullptr;
	int count = 0;
public:
	//��ջ
	sqstack();
	sqstack(T num);//��ʼ��ջ
	~sqstack();
	bool isEmptyLStack();//�ж�ջ�Ƿ�Ϊ��
	string getTopLStack();//�õ�ջ��Ԫ��;
	bool clearLStack();//���ջ
	int LStackLength();//���ջ����
	bool pushLStack(string n);//��ջ
	bool popLStack();
	friend bool wro(string a);
};

template<typename T>
sqstack<T>::sqstack() {

}
/*template<typename T>
sqstack<T>::sqstack(T num) {
	if (StackNode* temp = new StackNode) {
		temp->data = num;
		temp->next = nullptr;
		top = temp;
	}
	else cout << "�ڴ����ʧ��" << endl;
}*/
template<typename T>
sqstack<T>::~sqstack() {
	StackNode* temp1 = top;
	if (temp1 == nullptr)return;
	else {
		StackNode* temp2 = top->next;
		while (temp1) {
			temp2 = temp1->next;
			delete temp1;
			temp1 = temp2;
		}
		temp1 = temp2 = nullptr;
		cout << endl << "ջ�ͷ�" << endl;
	}
}
template<typename T>
bool sqstack<T>::isEmptyLStack() {
	if (top == nullptr)return true;
	else return false;
}//�ж�ջ�Ƿ�Ϊ��
template<typename T>
string sqstack<T>::getTopLStack() {
	if (top == nullptr)cout << "���ǿ�ջ��ջ��Ԫ��" << endl;
	else {
		return top->data;
	}
}//�õ�ջ��Ԫ��
template<typename T>
bool sqstack<T>::clearLStack() {
	cout << "��ջ��Ԫ�����Ϊ0" << endl;
	StackNode* p = top;
	while (p) {
		p->data = '0';
		p = p->next;
	}
	cout << "ջ������" << endl;
	return true;
}//���ջ
template<typename T>
int sqstack<T>::LStackLength() {
	StackNode* p = top;
	int rec = 0;
	while (p) {
		rec++;
		p = p->next;
	}
	return rec;
}//���ջ����
template<typename T>
bool sqstack<T>::pushLStack(string n) {
	if (StackNode* temp1 = new StackNode) {
		temp1->next = top;
		temp1->data = n;
		top = temp1;
		cout << "ѹջ�ɹ�" << endl;
		StackNode* p = top;
		cout << "����ջ��Ԫ��Ϊ:";
		while (p != nullptr) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
		return true;
	}
	else
		cout << "ѹջʧ��" << endl;
	return false;
}//��ջ
template<typename T>
bool sqstack<T>::popLStack() {
	if (top == nullptr) {
		return false;
	}
	else {
		string res = top->data;
		top = top->next;
		cout << "��ջ�ɹ�" << endl;
		cout << "��ջ��Ԫ��Ϊ" << res << endl << endl;
		StackNode* p = top;
		cout << "����ջ��Ԫ��Ϊ:";
		while (p) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	return true;
}//��ջ
/*template<typename T>
bool pd(sqstack<T> D) {
	if (D.top == nullptr)return false;
	else return false;
};*/

#endif