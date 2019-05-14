package string;

import java.util.Scanner;

public class StringOperations {

    private static String concatenate(String first, String second) {
        return first + second;
    }

    private static boolean palindrome(String string) {
        StringBuilder temp =  new StringBuilder(string);
        String reversedString = temp.reverse().toString();
        return reversedString.equals(string);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter First String: ");
        String first = scanner.next();
        System.out.println("Enter Second String: ");
        String second = scanner.next();
        String concatenated = concatenate(first, second);
        System.out.println("Concatenated: " + concatenated);
        if (palindrome(concatenated)) {
            System.out.println("Concatenated String is a Palindrome.");
        }
        else {
            System.out.println("Concatenated String is not a Palindrome.");
        }

    }
}
