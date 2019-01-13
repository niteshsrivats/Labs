#include<iostream>
using namespace std;

class Student {
  float sgpaOne, sgpaTwo, cgpa;
  public:
  float getSgpa(int semester) {
    int total = 0, gradePoint;
    cout<<"Enter Grade Points of Semester "<<semester<<endl;
    for (int subject = 1; subject < 4; subject++) {
      cout<<"Subject "<<subject<<" Credits - "<<(4-subject)*2<<": ";
      cin>>gradePoint;
      total += gradePoint*(4-subject)*2;
    }
    cout<<endl;
    return total/12.0;
  }
  void display() {
    cout<<"Semester 1 GPA: "<<sgpaOne;
    cout<<"\nSemester 2 GPA: "<<sgpaTwo;
    cout<<"\nCGPA: "<<cgpa<<endl;
  }
  friend Student calculate();
};

Student calculate() {
  Student x;
  x.sgpaOne = x.getSgpa(1);
  x.sgpaTwo = x.getSgpa(2);
  x.cgpa = (x.sgpaOne + x.sgpaTwo) / 2.0;
  return x;
}


int main(int argc, char const *argv[]) {
  Student nitesh = calculate();
  nitesh.display();
  return 0;
}
