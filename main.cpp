#include<iostream>
#include<array>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<string>
#include"sqstack.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;
static int rec = 0;
char dh;
string M;
string J, K, L;
int ans, a, number, res;
bool wk(string a) {
    int siz = a.size();
    int flag = 0;
    for (int q = 0; q < siz; q++) {
        if (a[q] >= '0' && a[q] <= '9')
            continue;
        else if (q > 0 && a[q] == '.' && flag == 0) {
            flag = 1; continue;
        }
        else if(a[0] == '-')continue;
            else return false;
    }
    return true;
}
//extern bool wro(string a);
int main() {
    cout << "手动加大加粗字符——————我这次加了错误判断还用了字符串来存，随便你乱输=。=" << endl << endl;
    sqstack<int>A;
    cout << "创建一个栈----Y创建/N退出"<<endl;
    string H;
    getline(cin, H);//输入判定
    if (H.size()> 1) {
        cout << "请不要这样先生，输一个正确的字母吧." << endl; system("pause"); return 0;
    }
    char ch;
    ch = H[0];
    if (ch == 'N'||ch=='n') {
        cout << "退出" << endl;
        system("pause");
        return 0;
    }
    else if (ch == 'Y' || ch == 'y') {
        //cin.ignore(0x7fffffff, '\n');
        cout << "空栈创建" << endl;
    }
    else {
        cout << "非法输入" << endl;
        cin.ignore(0x7fffffff, '\n'); return 0;
    }
    while (A.isEmptyLStack()) {
        cout << "a:输入一个数据并压栈" << endl;
        cout << "T:退出" << endl;
        cin.clear();
        string P;
        getline(cin, P);
        if (P.size() > 1) {
            cout << "非法输入";
            system("pause");
            return 0;
        }
        dh = P[0];
        if (dh == 'T' || dh=='t')return 0;
        else if (dh == 'a'|| dh=='A') {
            string D;
            cout << "输入数据"<<endl;
            //cin.ignore(0x7fffffff, '\n');
            getline(cin,D);
            if (!wk(D)) {
                cout << "输入非法字符结束" << endl;
                return 0;
            };
            A.pushLStack(D);
        }
        else {
            cout << "非法输入，重新输入"<<endl;
        }
    }
/*  cout << endl << "a:栈顶压栈"  << endl;
    cout << "b:在栈顶加入数据" << endl;
    cout << "c:清空栈(将栈内数据重置为0)" << endl;
    cout << "d:检测栈的长度" << endl;
    cout << "e:得到栈顶的元素" << endl;
    cout << "T:退出" << endl;
    getline(cin, H);//输入判定
    if (H.size() > 1) {
        cout << "请不要这样先生，输一个正确的字母吧." << endl; system("pause"); return 0;
    }
    ch = H[0];*/
    /*cin.ignore(0x7fffffff, '\n');
    cin.ignore(0x7fffffff, '\n');*/

    while (1) {
        if (ch == 'T' || ch == 't')return 0;
        cout << "a:栈顶压栈" << endl;
        cout << "b:出栈" << endl; 
        cout << "c:清空栈(将栈内数据重置为0)" << endl;
        cout << "d:检测栈的长度" << endl;
        cout << "e:得到栈顶的元素" << endl;
        cout << "T:退出" << endl;
        string Q;
        getline(cin,Q);
        if (Q.size() > 1) {
            cout << "请不要这样先生，输一个正确的字母吧." << endl; system("pause"); return 0;
        }
        ch = Q[0];
        switch (ch) {
        case'A':
        case 'a': cout << "输入要压栈的元素" << endl; 
            cin.clear();
            getline(cin,J);
            if (!wk(J)) {
                cout << "输入非法字符结束" << endl;
                return 0;
            };
            //cin.ignore(0x7fffffff, '\n');
            if (A.pushLStack(J)) {
            cout <<  endl;
        }
            else {
                return 0;
            }            //system("pause");
            //cout << endl << "输T结束"; cin >> ch; 
            break;
        case'B':
        case'b': 
            if (A.popLStack()) {
                break;
            }
            else {
                cout << "空栈退出"<<endl; return 0;
            }//cout << endl << "输T结束"; cin >> ch; break;
        case'c': if (A.clearLStack()) 
        {
            cout << "清空栈元素成功(重置为0)" << endl<<endl;
        }
               else {
            cout << "清空失败" << endl<<endl;
        }
         break;
        case'D':
        case'd': number = A.LStackLength(); cout << "栈内元素个数为" << number << endl<<endl;   break;
        case'E':
        case'e': K = A.getTopLStack(); 
            if (!wk(K)) {
                cout << "输入非法字符结束" << endl;
                return 0;
            }; 
            cout << "栈顶元素为" << K << endl<<endl;   break;
        case'T':
        case't': break;
        default: cout << "非法输入,重新输入" << endl<<endl;
            //system("pause");
            break;
        }
    }
    return 0;
}