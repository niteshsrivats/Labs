package exceptions;

import java.util.Scanner;

public class Son extends Father {

    Son(int fatherAge, int sonAge) {
        super(fatherAge);
        try {
            if (sonAge < 0)
                throw new NegativeAgeException();
            else if (sonAge >= fatherAge)
                throw new IncompatibleAgeException();
            age = sonAge;
        } catch (NegativeAgeException e) {
            System.out.println("Son " + e);
        } catch (IncompatibleAgeException e) {
            System.out.println(e);
        }
    }

}
