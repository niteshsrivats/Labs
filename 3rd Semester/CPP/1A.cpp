#include<iostream>
using namespace std;

class Time {
  int h, m, s;
  
  public:
  Time() {
    h = m = s = 0;
  }

  Time(int hh, int mm, int ss) {
    h = hh;
    m = mm;
    s = ss;
  }
  void advance(int hh, int mm, int ss) {
    h += hh;
    m += mm;
    s += ss;
  }

  void setTime(int hh, int mm, int ss) {
    h = hh;
    m = mm;
    s = ss;
  }

  void correct() {
    m += s / 60;
    s = s % 60;
    h += m / 60;
    m = m % 60;
    h = h % 24;
  }

  void print() {
    correct();
    cout<<h<<":"<<m<<":"<<s<<endl;
  }
};

int main(int argc, char const *argv[])
{
  Time t(5, 34, 21);
  cout<<"Inital Time Through Parameterized: ";
  t.print();
  cout<<"Set Time: ";
  t.setTime(10, 24, 43);
  t.print();
  cout<<"Advance Time: ";
  t.advance(5, 46, 33);
  t.print();
  return 0;
}
