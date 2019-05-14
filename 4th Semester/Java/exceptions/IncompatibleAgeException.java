package exceptions;

public class IncompatibleAgeException extends Exception {

    public String toString() {
        return "Father cannot be younger than son";
    }
}
