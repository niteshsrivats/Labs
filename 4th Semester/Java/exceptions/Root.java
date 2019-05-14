package exceptions;

import java.util.Scanner;

public class Root {

    public static void main(String[] args) {
        System.out.println("Enter a number:");
        Scanner s = new Scanner(System.in);
        int num = s.nextInt();
        try {
            if (num < 0 )
                throw new NegativeRootException();
            else
                System.out.println(Math.sqrt(num));
        }
        catch (NegativeRootException e) {
            System.out.println(e);
        }
    }
}
