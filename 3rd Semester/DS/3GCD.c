// @author: K Nitesh Srivats
// @title: Recursive GCD

#include<stdio.h>

int gcd(int a, int b, int c) {
  // Fix break when input is 0
  if (a == b && b == c)
      return a;
  else if (a >= b && a >= c) {
      if (b >= c)
          return gcd(b, c, a-c);
      else
          return gcd(c, b, a-b);
  }
  else if (b >= c) {
      if (a >= c) 
          return  gcd(a, c, b-c);
      else
          return gcd(c, a, b-a);
  }
  else if (a >= b) 
      return gcd(a, b, c-b);
  else
      return gcd(b, a, c-a);
}

int gcd2(int a, int b) {
    if (a == 0)
        return b;
    else if (b == 0)
        return a;
    else
        return gcd2(b, a%b);
}

int gcd3(int a, int b, int c) {
    return gcd2(gcd2(a, b), c);
}

int main(int argc, char const *argv[])
{   
    int a, b, c;
    printf("Enter 3 Numbers: ");
    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n", gcd3(a, b, c));
    return 0;
}
