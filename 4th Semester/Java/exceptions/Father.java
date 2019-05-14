package exceptions;

public class Father{
    int age;
    Father(int age){
        try {
            if (age < 0)
                throw new NegativeAgeException();
        }
        catch (NegativeAgeException e) {
            System.out.println("Father " + e);
        }
        this.age = age;
    }
}
