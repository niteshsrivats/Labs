package string;

import java.util.Date;
import java.util.Scanner;

public class StringExtractor {

    private static String getDate() {
        return new Date().toString();
    }

    private static String extractString(String string, int index, int length) {
        return string.substring(index, index + length);
    }

    public static void main(String[] args) {
        Scanner scanner =  new Scanner(System.in);
        System.out.println("Date: " + getDate());
        System.out.println("Enter String: ");
        String string = scanner.next();
        System.out.println("Enter Start Index: ");
        int startIndex = scanner.nextInt();
        System.out.println("Enter Length: ");
        int length = scanner.nextInt();
        System.out.println("Extracted String: ");
        System.out.println(extractString(string, startIndex, length));

    }
}
