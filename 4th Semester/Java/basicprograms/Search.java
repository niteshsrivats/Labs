package basicprograms;

import java.util.Scanner;

public class Search {

    private static int binarySearch(int[] array, int searchElement) {

        int beg = 0, end = array.length, mid;
        while (beg < end) {
            mid = (beg + end) / 2;
            if (array[mid] < searchElement)
                beg = mid + 1;
            else if (array[mid] > searchElement)
                end = mid - 1;
            else
                return mid + 1;
        }
        return -1;
    }

    public static void main(String[] args) {

        Scanner s =  new Scanner(System.in);
        System.out.print("Enter Size of Array: ");
        int size = s.nextInt();
        int[] array = new int[size];

        System.out.println("Enter Elements of the Array:");
        for (int i = 0; i < size; i++)
            array[i] = s.nextInt();

        System.out.print("Enter Search Element: ");
        int searchElement = s.nextInt();

        int position = binarySearch(array, searchElement);
        if (position > 0)
            System.out.println("Element Found at Position: " + position);
        else
            System.out.println("Element Not Found");
    }
}
