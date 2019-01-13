#include<iostream>
using namespace std;

class Matrix {
  float arr[2][2];
  public:
  Matrix() {
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++) 
        arr[i][j] = 0;
  }


  Matrix(Matrix &x) {
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++)
        arr[i][j] = x.arr[i][j];
  }


  void getMatrix() {
    cout<<"Enter the Matrix:\n";
    for (int i = 0; i < 2; i++) {
        cout<<"Enter Row "<<i+1<<": ";
        cin>>arr[i][0]>>arr[i][1];
      }
  }


  float determinant() {
    return arr[0][0] * arr[1][1] - arr[1][0] * arr[0][1];
  }


  Matrix inverse() {
    Matrix x;
    if(!isSingular()) {
      float det = determinant();
      x.arr[0][0]  = arr[1][1] / det;
      x.arr[0][1]  = -arr[0][1] / det;
      x.arr[1][0]  = -arr[1][0] / det;
      x.arr[1][1]  = arr[0][0] / det;
    }
    return x;
  }


  bool isSingular() {
    if (determinant() == 0)
      return true;
    else
      return false;
  }


  void print() {
    cout<<"Matrix: \n";
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) 
        cout<<arr[i][j]<<" ";
      cout<<endl;
    }     
  }
};


int main(int argc, char const *argv[]) {
  Matrix initial, inv;
  initial.getMatrix();
  initial.print();
  inv = initial.inverse();
  cout<<"Inverse ";
  inv.print();
  Matrix test(inv);
  test = test.inverse();
  cout<<"Inverse ";
  test.print();
  return 0;
}

