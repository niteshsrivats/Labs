package basicprograms;

import java.util.Scanner;

public class QuadraticRoots {

    private static String getRootType(float a, float b, float c) {

        int d = (int) (b * b - 4 * a * c);
        d = Integer.compare(d, 0);
        switch (d) {
            case 1:
                return "Roots are Real & Unequal";
            case 0:
                return "Roots are Real & Equal";
            case -1:
                return "Roots are Imaginary";
            default:
                return "Default is Required";
        }
    }

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        System.out.print("Enter Three Numbers: ");
        float a = s.nextFloat();
        float b = s.nextFloat();
        float c = s.nextFloat();
        System.out.print(getRootType(a, b, c));
    }
}
