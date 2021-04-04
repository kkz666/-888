#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include<iostream>
#define Maxsize 10
using std::cout;
using std::endl;
using std::string;

template<typename T>class sqstack {
public:
	typedef int ElemType;

private:
	T* top = nullptr;
	T* now;
	int count = 0;
public:
	//��ջ
	sqstack();
	sqstack(T num);//��ʼ��ջ
	~sqstack();
	bool setlength();
	bool isEmptyLStack();//�ж�ջ�Ƿ�Ϊ��
	T getTopLStack();//�õ�ջ��Ԫ��;
	bool clearLStack();//���ջ
	int LStackLength();//���ջ����
	bool pushLStack(T n);//��ջ
	bool popLStack();
};

template<typename T>
bool setlength() {
	int res;
	cout << "������Ҫ�洢ջ�Ĵ�С" << endl;
	cin >> res;
	count = res;
	if (T* p = new T[res]) {
		top = p;
		now = top;
		return true;
	}
	else return false;
}
template<typename T>
sqstack<T>::sqstack() {
	setlength();
	memset(top, 0, sizeof(top));
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
	delete top;
		cout << endl << "ջ�ͷ�" << endl;
	}
template<typename T>
bool sqstack<T>::isEmptyLStack() {
	if (*top == 0)return true;
	else return false;
}//�ж�ջ�Ƿ�Ϊ��
template<typename T>
T sqstack<T>::getTopLStack() {
	if (top == nullptr)cout << "���ǿ�ջ��ջ��Ԫ��" << endl;
	else {
		return *top;
	}
}//�õ�ջ��Ԫ��
template<typename T>
bool sqstack<T>::clearLStack() {
	cout << "��ջ��Ԫ�����Ϊ0" << endl;
	StackNode* p = top;
	while (*p!=0) {
		*p=0;
		p++;
	}
	cout << "ջ������" << endl;
	return true;
}//���ջ
template<typename T>
int sqstack<T>::LStackLength() {
	StackNode* p = top;
	int rec = 0;
	while (*p!=0) {
		rec++;
		p++;;
	}
	return rec;
}//���ջ����
template<typename T>
bool sqstack<T>::pushLStack(T n) {
	*now = n;
	now++;
	return true;
}//��ջ
template<typename T>
bool sqstack<T>::popLStack() {
	if (top == now&&*top==0) {
		return false;
	}
	else {
		T res = *now;
		now--;
		cout << "��ջ�ɹ�" << endl;
		cout << "��ջ��Ԫ��Ϊ" << res << endl << endl;
		cout << "����ջ��Ԫ��Ϊ:";
		while (now>=top) {
			cout <<*now  << " ";
			now--;
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

