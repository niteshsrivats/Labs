package basicprograms;

import java.util.Scanner;

public class GCD {

    private static int getGCD(int a, int b) {

        if (a == 0)
            return b;
        else if (b == 0)
            return a;
        else
            if (a > b)
                return getGCD(a % b, b);
            else
                return getGCD(b % a, a);
    }

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        System.out.print("Enter Two Positive Numbers: ");
        int a = s.nextInt();
        int b = s.nextInt();
        System.out.print("GCD: " + getGCD(a, b));
    }
}
