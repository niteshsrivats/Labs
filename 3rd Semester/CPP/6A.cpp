#include<iostream>
using namespace std;

class Account{
  protected:
  float Amount, Interest, Time;
  void getData() {
    cout<<"Enter Amount: ";
    cin>>Amount;
    cout<<"Enter Time: ";
    cin>>Time;
  }
};

class Savings_Account : public Account {
    float Rate = 0.04;
    public:
    void calculate_interest() {
        getData();
        Interest = Amount * Rate * Time;
        cout<<"Interest: "<<Interest;
    }
};

class Current_Account : public Account {
};

int main(){
    Savings_Account A;
    A.calculate_interest();
    return 0 ;
}
