#include<iostream>
using namespace std;

template <class array, class size, class item>
          void binary_search(array a, size end, item e) {
            end -= 1;
            int beg = 0, mid = (beg + end) / 2;
            while (beg <= end) {
              if (a[mid] > e)
                end = mid - 1;
              else if(a[mid] < e)
                beg = mid + 1;
              else
                break;
              mid = (beg + end) / 2;
            }
            if (beg > end)
              cout<<"Element Not Found.\n";
            else
              cout<<"Element at "<<mid+1<<" Position.\n";
} 

int main(int argc, char const *argv[]) {
  int size;
  char arr[20], element;
  cout<<"Enter Size of Array:\n";
  cin>>size;
  cout<<"Enter Sorted Array:\n";
  for (int i = 0; i < size; i++)
    cin>>arr[i];
  cout<<"Enter Search Element: ";
  cin>>element;
  binary_search(arr, size, element);
  return 0;
}
