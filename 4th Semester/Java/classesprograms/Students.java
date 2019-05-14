package classesprograms;

public class Students {

    public static void main(String[] args) {

        Student[] s = new Student[3];
        for (int i = 0; i < 3; i++) {
            s[i] = new Student();
            System.out.println("Enter Details of Student " + (i + 1) + ": ");
            s[i].setDetails();
            s[i].calculateAverage();
            s[i].displayDetails();
            System.out.println();
        }
    }
}
