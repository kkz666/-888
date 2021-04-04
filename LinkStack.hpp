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
	//链栈
	sqstack();
	sqstack(T num);//初始化栈
	~sqstack();
	bool setlength();
	bool isEmptyLStack();//判断栈是否为空
	T getTopLStack();//得到栈顶元素;
	bool clearLStack();//清空栈
	int LStackLength();//检测栈长度
	bool pushLStack(T n);//入栈
	bool popLStack();
};

template<typename T>
bool setlength() {
	int res;
	cout << "输入你要存储栈的大小" << endl;
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
	else cout << "内存分配失败" << endl;
}*/
template<typename T>
sqstack<T>::~sqstack() {
	delete top;
		cout << endl << "栈释放" << endl;
	}
template<typename T>
bool sqstack<T>::isEmptyLStack() {
	if (*top == 0)return true;
	else return false;
}//判断栈是否为空
template<typename T>
T sqstack<T>::getTopLStack() {
	if (top == nullptr)cout << "这是空栈无栈顶元素" << endl;
	else {
		return *top;
	}
}//得到栈顶元素
template<typename T>
bool sqstack<T>::clearLStack() {
	cout << "将栈内元素清空为0" << endl;
	StackNode* p = top;
	while (*p!=0) {
		*p=0;
		p++;
	}
	cout << "栈清空完成" << endl;
	return true;
}//清空栈
template<typename T>
int sqstack<T>::LStackLength() {
	StackNode* p = top;
	int rec = 0;
	while (*p!=0) {
		rec++;
		p++;;
	}
	return rec;
}//检测栈长度
template<typename T>
bool sqstack<T>::pushLStack(T n) {
	*now = n;
	now++;
	return true;
}//入栈
template<typename T>
bool sqstack<T>::popLStack() {
	if (top == now&&*top==0) {
		return false;
	}
	else {
		T res = *now;
		now--;
		cout << "出栈成功" << endl;
		cout << "出栈的元素为" << res << endl << endl;
		cout << "现在栈内元素为:";
		while (now>=top) {
			cout <<*now  << " ";
			now--;
		}
		cout << endl;
	}
	return true;
}//出栈
/*template<typename T>
bool pd(sqstack<T> D) {
	if (D.top == nullptr)return false;
	else return false;
};*/

#endif

