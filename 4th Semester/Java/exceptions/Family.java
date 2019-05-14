package exceptions;

import java.util.Scanner;

public class Family {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter Father & Son Age: ");
        int fatherAge = s.nextInt();
        int sonAge = s.nextInt();
        new Son(fatherAge, sonAge);
    }
}
