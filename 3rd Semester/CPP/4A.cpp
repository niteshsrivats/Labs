#include<iostream>
using namespace std;

class String {
    string s1, s2, s3;
    public:
    String() {
        s1 = "BMS College";
        s2 = " Of Engineering";
        s3 = "";
    }

    String(String &obj) {
        s1 = obj.s1;
        s2 = obj.s2;
        s3 = obj.s3;
    }

    String operator+(String obj) {
        String temp_concat;
        temp_concat.s3 = s1 + obj.s2;
        return temp_concat;
    }

    void operator>(String obj) {
        int size = s1 > obj.s2;
        if(size)
            cout<<s1<<endl;
        else
            cout<<obj.s2<<endl;
    }

    friend ostream &operator<<(ostream &output, String &obj) {
        output<<obj.s3<<endl;
    }
};


int main(int argc, char const *argv[]) {
    String demo1, demo2;
    demo2 = demo1 + demo2;
    cout<<demo2;
    String demo3(demo2);
    demo3 = demo3 + demo3;
    cout<<demo3;
    demo1>demo2;
    return 0;
}