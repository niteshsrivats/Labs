#include<iostream>
using namespace std;

class Automobile {
  int litres_fuel;
  public:
  void set_fuel(int i) {
    try {
      if (i > 20)
        throw 1;
      else
        litres_fuel = i;
    }
    catch (int i){
      cout<<"Exceeds Fuel Capacity.\n";
    }
  }
};

int main(int argc, char const *argv[]) {
  Automobile a;
  int litres;
  cout<<"Enter Fuel Quantity: ";
  cin>>litres;
  a.set_fuel(litres);
  return 0;
}
