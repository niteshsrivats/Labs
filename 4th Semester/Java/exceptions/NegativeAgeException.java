package exceptions;

public class NegativeAgeException extends Exception {

    public String toString() {
        return "cannot have negative age";
    }
}
