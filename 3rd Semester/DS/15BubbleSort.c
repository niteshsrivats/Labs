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
  for (i = 0; i < size; i++)
    for (j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j + 1];
        arr[j + 1] = arr[j];
        arr[j] = temp;
      }
    }
    
  printf("They Array: ");
  for (i = 0; i < size; i++)
    printf(" %d", arr[i]);
    
  return 0;
}
