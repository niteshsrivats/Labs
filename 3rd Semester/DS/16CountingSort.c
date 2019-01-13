//Counting Sort
#include <stdio.h>

int arr[10];

int main(int argc, char const *argv[])
{
  int size, i, j, max = 0;
  int count[50] = {0};
  printf("Enter Array Size: ");
  scanf("%d", &size);
  printf("Enter Array Elements: ");
  for (i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
    if(arr[i] > max)
      max = arr[i];
  }
  for(i = 0; i < size; i++)
      count[arr[i]]=count[arr[i]]+1;

  printf("\nSorted elements are:");

  for(i = 0; i <= max; i++)
      for(j = 0; j < count[i]; j++)
       printf("%d ", i);
    
  return 0;
}
