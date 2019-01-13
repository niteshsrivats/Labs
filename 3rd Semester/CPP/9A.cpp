#include<iostream>
#include<cstring>
using namespace std;

class Player {
  protected:
  char name[30];
  int matches_played;
  float average;
  public:
  virtual void cal_average(char[], int, int) = 0;
};

class Batsman: public Player {
  int runs_scored;
  public:
  void cal_average(char n[], int runs, int matches) {
    strcpy(name, n);
    runs_scored = runs;
    matches_played = matches;
    average = runs /(matches_played * 1.0);
    cout<<name<<" Average: "<<average;
  }
};

class Bowler: public Player {
  int runs_given;
  public:
  void cal_average(char n[], int runs, int matches) {
    strcpy(name, n);
    runs_given = runs;
    matches_played = matches;
    average = runs /(matches_played * 1.0);
    cout<<"\n"<<name<<" Average: "<<average;
  }
};

int main() {
  Player *p;
  Batsman b1;
  Bowler b2;
  p = &b1;
  p -> cal_average("Sachin", 10000, 150);
  p = &b2;
  p -> cal_average("Anil", 4000, 90);
  return 0;
}
