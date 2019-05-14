package classesprograms2;

public class Student {

    private int rollNo;
    private String name;

    Student(String name,  int rollNo) {
        this.name = name;
        this.rollNo = rollNo;
    }

    public void display() {
        System.out.println("Roll Number: " + rollNo);
        System.out.println("Name: " + name);
    }
}
