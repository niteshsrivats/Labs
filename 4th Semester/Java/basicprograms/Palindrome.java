package basicprograms;

import java.util.Scanner;

public class Palindrome {

    private static int reverseNumber(int number) {

        int reverse = 0, digit;
        while (number != 0) {
            digit = number % 10;
            number = number / 10;
            reverse = reverse * 10 + digit;
        }
        return reverse;
    }

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        System.out.print("Enter a Number: ");
        int number = s.nextInt();

        if (number == reverseNumber(number))
            System.out.print("The Number is a Palindrome");
        else
            System.out.print("The Number is not a Palindrome");
    }
}
