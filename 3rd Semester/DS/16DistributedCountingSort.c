//Distributed Counting Sort
#include<stdio.h>

void main() {
  int i,j,size,arr[10],s[10];
  int count[20] = {0};
  printf("Enter Array Size: ");
  scanf("%d", &size);
  printf("Enter Array Elements: ");
  for (i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
    count[arr[i]] += 1;
  }
    for(j = 1; j <= 20; j++)
  count[j] += count[j-1];
  printf("\nSorted array is:\n");

  for(i = size - 1; i >= 0; i--) {
    s[count[arr[i]] - 1] = arr[i];
    count[arr[i]] -= 1;
  }
  printf("\nSorted array is:\n");
  for(i = 0; i < size; i++)
    printf("%d\t",s[i]);
}
