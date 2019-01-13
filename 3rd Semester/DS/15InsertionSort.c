#include <stdio.h>

int arr[10];

int main(int argc, char const *argv[])
{
  int size, i, j, temp;
  printf("Enter Array Size: ");
  scanf("%d", &size);
  printf("Enter Array Elements: ");
  for (i = 0; i < size; i++)
    scanf("%d", &arr[i]);
  for (i = 1; i < size; i++)
    for (j = 0; j <= i; j++) {
      if (arr[j] > arr[i]) {
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
      }
    }
  printf("They Array: ");
  for (i = 0; i < size; i++)
    printf(" %d", arr[i]);
    
  return 0;
}
