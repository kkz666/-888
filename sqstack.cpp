#include<iostream>
#include<new>
using std::cout;
using std::endl;
template<typename T>class sqstack {
public:
	typedef int ElemType;

private:
	struct StackNode {
		T data;
		struct StackNode* next;
		int flag = 0;
	};
	StackNode* top = nullptr;
	int count = 0;
public:
	//链栈
	sqstack();
	sqstack(T num);//初始化栈
	~sqstack();
	bool isEmptyLStack();//判断栈是否为空
	T getTopLStack();//得到栈顶元素;
	bool clearLStack();//清空栈
	int LStackLength();//检测栈长度
	bool pushLStack(T n);//入栈
	T popLStack();
};

template<typename T>
sqstack<T>::sqstack() {

}
template<typename T>
sqstack<T>::sqstack(T num) {
	if (StackNode* temp = new StackNode) {
		temp->data = num;
		temp->next = nullptr;
		top = temp;
	}
	else cout << "内存分配失败"<<endl;
}
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
		cout << endl << "栈释放" << endl;
	}
}
template<typename T>
bool sqstack<T>::isEmptyLStack() {
	if (top == nullptr)return true;
	else return false;
}//判断栈是否为空
template<typename T>
T sqstack<T>::getTopLStack() {
	if (top == nullptr)cout << "这是空栈无栈顶元素" << endl;
	else {
		return top->data;
	}
}//得到栈顶元素
template<typename T>
bool sqstack<T>::clearLStack() {
	cout << "将栈内元素清空为0" << endl;
	StackNode* p = top;
	while (p) {
		p->data = 0;
		p = p->next;
	}
	cout << "栈清空完成" << endl;
	return true;
}//清空栈
template<typename T>
int sqstack<T>::LStackLength() {
	StackNode* p = top;
	int rec = 0;
	while (p) {
		rec++;
		p = p->next;
	}
	return rec;
}//检测栈长度
template<typename T>
bool sqstack<T>::pushLStack(T n) {
	if (StackNode* temp1 = new StackNode) {
			temp1->next =top;
			temp1->data = n;
			top = temp1;
			cout << "压栈成功" << endl;
		StackNode *p = top;
		cout << "现在栈内元素为:";
		while (p!=nullptr) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
		return true;
	}
	else
		cout << "压栈失败" << endl;
		return false;
}//入栈
template<typename T>
T sqstack<T>::popLStack() {
	T res= top->data;
	top = top->next;
	cout << "出栈成功" << endl;
	StackNode* p = top;
	cout << "现在栈内元素为:";
		while (p) {
			cout << p->data << " ";
			p = p->next;
		}
	cout << endl;
	return res;
}//出栈
/*template<typename T>
bool pd(sqstack<T> D) {
	if (D.top == nullptr)return false;
	else return false;
};*/