import java.util.Scanner;
import student.Student;
import staff.Proctor;

public class StudentStaffDemo {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        Student[] student = new Student[3];
        Proctor[] proctor = new Proctor[3];
        for(int i = 0; i < 3; i++) {
            System.out.println("Enter Student " + (i + 1) + " Details: ");
            String name = s.next();
            String proctorName = s.next();
            student[i] = new Student(name, proctorName);
            System.out.println("Enter Proctor " + (i + 1) + " Details: ");
            name = s.next();
            String studentName = s.next();
            proctor[i] = new Proctor(name, studentName);
        }
        System.out.println("Common Students & Their Proctors: ");
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if (student[i].getName().equals(proctor[j].getStudentName()))
                    student[i].display();
            }
        }
    }
}
