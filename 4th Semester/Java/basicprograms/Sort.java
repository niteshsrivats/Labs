package basicprograms;

import java.util.Arrays;
import java.util.Scanner;

public class Sort {

    private static int[] bubbleSort(int[] array) {

        for (int i = 0; i < array.length; i++)
            for (int j = 0; j < array.length - i - 1; j++)
                if (array[j] > array[j + 1]) {
                    int swapTemp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = swapTemp;
                }
        return array;
    }

    public static void main(String[] args) {

        Scanner s =  new Scanner(System.in);
        System.out.print("Enter Size of Array: ");
        int size = s.nextInt();
        int[] array = new int[size];

        System.out.println("Enter Elements of the Array:");
        for (int i = 0; i < size; i++)
            array[i] = s.nextInt();
        int[] sortedArray = bubbleSort(array);

        System.out.println("Sorted Elements of the Array:");
        System.out.println(Arrays.toString(sortedArray));
    }
}
