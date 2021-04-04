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
    cout << "�ֶ��Ӵ�Ӵ��ַ�����������������μ��˴����жϻ������ַ������棬���������=��=" << endl << endl;
    sqstack<int>A;
    cout << "����һ��ջ----Y����/N�˳�"<<endl;
    string H;
    getline(cin, H);//�����ж�
    if (H.size()> 1) {
        cout << "�벻Ҫ������������һ����ȷ����ĸ��." << endl; system("pause"); return 0;
    }
    char ch;
    ch = H[0];
    if (ch == 'N'||ch=='n') {
        cout << "�˳�" << endl;
        system("pause");
        return 0;
    }
    else if (ch == 'Y' || ch == 'y') {
        //cin.ignore(0x7fffffff, '\n');
        cout << "��ջ����" << endl;
    }
    else {
        cout << "�Ƿ�����" << endl;
        cin.ignore(0x7fffffff, '\n'); return 0;
    }
    while (A.isEmptyLStack()) {
        cout << "a:����һ�����ݲ�ѹջ" << endl;
        cout << "T:�˳�" << endl;
        cin.clear();
        string P;
        getline(cin, P);
        if (P.size() > 1) {
            cout << "�Ƿ�����";
            system("pause");
            return 0;
        }
        dh = P[0];
        if (dh == 'T' || dh=='t')return 0;
        else if (dh == 'a'|| dh=='A') {
            string D;
            cout << "��������"<<endl;
            //cin.ignore(0x7fffffff, '\n');
            getline(cin,D);
            if (!wk(D)) {
                cout << "����Ƿ��ַ�����" << endl;
                return 0;
            };
            A.pushLStack(D);
        }
        else {
            cout << "�Ƿ����룬��������"<<endl;
        }
    }
/*  cout << endl << "a:ջ��ѹջ"  << endl;
    cout << "b:��ջ����������" << endl;
    cout << "c:���ջ(��ջ����������Ϊ0)" << endl;
    cout << "d:���ջ�ĳ���" << endl;
    cout << "e:�õ�ջ����Ԫ��" << endl;
    cout << "T:�˳�" << endl;
    getline(cin, H);//�����ж�
    if (H.size() > 1) {
        cout << "�벻Ҫ������������һ����ȷ����ĸ��." << endl; system("pause"); return 0;
    }
    ch = H[0];*/
    /*cin.ignore(0x7fffffff, '\n');
    cin.ignore(0x7fffffff, '\n');*/

    while (1) {
        if (ch == 'T' || ch == 't')return 0;
        cout << "a:ջ��ѹջ" << endl;
        cout << "b:��ջ" << endl; 
        cout << "c:���ջ(��ջ����������Ϊ0)" << endl;
        cout << "d:���ջ�ĳ���" << endl;
        cout << "e:�õ�ջ����Ԫ��" << endl;
        cout << "T:�˳�" << endl;
        string Q;
        getline(cin,Q);
        if (Q.size() > 1) {
            cout << "�벻Ҫ������������һ����ȷ����ĸ��." << endl; system("pause"); return 0;
        }
        ch = Q[0];
        switch (ch) {
        case'A':
        case 'a': cout << "����Ҫѹջ��Ԫ��" << endl; 
            cin.clear();
            getline(cin,J);
            if (!wk(J)) {
                cout << "����Ƿ��ַ�����" << endl;
                return 0;
            };
            //cin.ignore(0x7fffffff, '\n');
            if (A.pushLStack(J)) {
            cout <<  endl;
        }
            else {
                return 0;
            }            //system("pause");
            //cout << endl << "��T����"; cin >> ch; 
            break;
        case'B':
        case'b': 
            if (A.popLStack()) {
                break;
            }
            else {
                cout << "��ջ�˳�"<<endl; return 0;
            }//cout << endl << "��T����"; cin >> ch; break;
        case'c': if (A.clearLStack()) 
        {
            cout << "���ջԪ�سɹ�(����Ϊ0)" << endl<<endl;
        }
               else {
            cout << "���ʧ��" << endl<<endl;
        }
         break;
        case'D':
        case'd': number = A.LStackLength(); cout << "ջ��Ԫ�ظ���Ϊ" << number << endl<<endl;   break;
        case'E':
        case'e': K = A.getTopLStack(); 
            if (!wk(K)) {
                cout << "����Ƿ��ַ�����" << endl;
                return 0;
            }; 
            cout << "ջ��Ԫ��Ϊ" << K << endl<<endl;   break;
        case'T':
        case't': break;
        default: cout << "�Ƿ�����,��������" << endl<<endl;
            //system("pause");
            break;
        }
    }
    return 0;
}