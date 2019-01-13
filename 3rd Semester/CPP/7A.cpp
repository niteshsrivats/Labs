#include<iostream>
using namespace std;

class Person {
    protected:
    string name, addr;
    int age;
    void getPerson() {
        cout<<"Enter Name: ";
        cin>>name;
        cout<<"Enter Address: ";
        getline(cin, addr);
        getline(cin, addr);
        cout<<"Enter Age: ";
        cin>>age;
    }
};

class Student : protected Person {
    protected:
    int rollno, sem;
    void getStudent() {
        getPerson();
        cout<<"Enter Roll Number: ";
        cin>>rollno;
        cout<<"Enter Semester: ";
        cin>>sem;
    }
};

class Exam : protected Student {
    protected:
    int marks1, marks2;
    float average;
    public:
    void getData() {
        getStudent();
        cout<<"Enter Marks 1: ";
        cin>>marks1;
        cout<<"Enter Marks 2: ";
        cin>>marks2;
    }
    void calculate_average() {
        average = (marks1+marks2)/2;
    }
    void display() {
        cout<<"Average: "<<average;
    }
};

int main() {
    Exam A;
    A.getData();
    A.calculate_average();
    A.display();
    return 0 ;
}