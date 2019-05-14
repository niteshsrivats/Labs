package student;

public class Student {
    private String name, proctorName;

    public Student(String name, String proctorName) {
        this.name = name;
        this.proctorName = proctorName;
    }

    public String getName() {
        return name;
    }

    public void display() {
        System.out.println("Student Name: " + name);
        System.out.println("Proctor Name: " + proctorName);
    }
}
