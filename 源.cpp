#include <iostream>
using namespace std;
template <class T>
class Stack {
private:
    int size;
    int top;
    T* space;
public:
    Stack(int size);
    bool push(T a);
    T    pop();
    bool IsEmpty()
    {
        return top == 0;
    }
    bool IsFull()
    {
        return top == size - 1;
    }


};


template <class T>
Stack <T>::Stack(int size)
{
    this->size = size;
    space = new T[size];
    top = 0;
}


template <class T>
bool Stack<T>::push(T a)
{
    if (!IsFull())
    {
        space[top++] = a;
        return true;
    }
    else
        return false;
}
template <class T>
T Stack<T>::pop()
{
    return space[--top];
}


int main()
{
    Stack<int>S1(10);
    S1.push(1);
    S1.push(2);
    S1.push(3);
    cout << S1.pop() << endl;
    cout << S1.pop() << endl;
    cout << S1.pop() << endl;
    return 0;
}