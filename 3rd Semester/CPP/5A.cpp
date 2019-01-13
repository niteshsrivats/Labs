#include<iostream>
using namespace std;

class Stack {
    int arr[10], top, max;
    public:
    Stack() {
        top = -1;
        max = 2;
    }
    void operator+(int element) {
        if(top == max-1)
            cout<<"Stack Overflow.\n";
        else {
            top++;
            arr[top] = element;
        }
    }
    void operator-(int zero) {
        if(top == -1)
            cout<<"Stack Underflow.\n";
        else {
            cout<<"Popping: "<<arr[top];
            top--;
        }
    }
    friend ostream &operator<<(ostream &output, Stack &obj) {
        if(obj.top == -1)
            cout<<"Stack empty";
        else {
            cout<<"The Stack: ";
            for(int i = 0; i <= obj.top; i++)
                output<<obj.arr[i]<<" ";
            output<<endl;
        }
    }
};

int main(int argc, char const *argv[]) {
    Stack demo;
    int ch = 1, element;
    while(ch) {
        cout<<"\n1. Push.\n2. Pop.\n3. Display.\n0. Exit.\n";
        cin>>ch;
        switch(ch) {
            case 1:
                cout<<"Enter Element: ";
                cin>>element;
                demo+element;
                break;
            case 2:
                demo-0;
                break;
            case 3:
                cout<<demo;
                break;
        }
    }
    return 0;
}