package staff;

public class Proctor {
    private String name, studentName;

    public Proctor(String name, String studentName) {
        this.name = name;
        this.studentName = studentName;
    }

    public String getStudentName() {
        return studentName;
    }

}
