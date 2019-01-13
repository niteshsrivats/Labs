#include<iostream>
using namespace std;

class person {
public:
    string name;
    string code;

    void getnc() {
        cout<<"Enter Name and Code of Person\n";
        cin>>name>>code;
    }
};

class pay :virtual public person {
public:
    float pay;
    void getpay() {
        cout<<"Enter pay value\n";
        cin>>pay;
    }
};

class admin :virtual public person {
public:
    int exp;
    void getexp() {
        cout<<"Enter experience\n";
        cin>>exp;
    }
};

class master : public pay , public admin {
public:
    void print() {
        cout<<"Name : "<<name;
        cout<<"\nCode : "<<code;
        cout<<"\nExperience : "<<exp;
        if(exp>15)
            cout<<"\nPay : "<<(pay+2000);
        else
            cout<<"\nPay : "<<pay;
    }
};

int main() {
    master m1;
    m1.getnc();
    m1.getpay();
    m1.getexp();
    m1.print();
    return 0;
}