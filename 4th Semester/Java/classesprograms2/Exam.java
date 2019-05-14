package classesprograms2;

public class Exam extends Student {
    private int totalMarks;

    Exam(String name, int rollNo, int totalMarks) {
        super(name, rollNo);
        this.totalMarks = totalMarks;
    }

    public void display() {
        super.display();
        System.out.println("Total Marks: " + totalMarks);
        if (totalMarks < 40)
            System.out.println("Result: Fail");
        else
            System.out.println("Result: Pass");
    }
}
