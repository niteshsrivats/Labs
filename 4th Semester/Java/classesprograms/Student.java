package classesprograms;

import java.util.Scanner;

public class Student {

    private int studentID;
    private int[] marks = new int[3];
    private float average;
    private Scanner s = new Scanner(System.in);

    public void setDetails() {

        System.out.print("Enter ID: ");
        studentID = s.nextInt();
        System.out.print("Enter Marks in " + marks.length + " Subjects: ");
        for (int i = 0; i < marks.length; i++)
            marks[i] = s.nextInt();
        System.out.println();
    }

    public void calculateAverage() {

        average = 0;
        for (int i = 0; i < marks.length; i++)
            average += marks[i];
        average /= 3.0;
    }

    public void displayDetails() {

        System.out.println("Student ID: " + studentID);
        for (int i = 0; i < marks.length; i++)
            System.out.println("Mark " + (i + 1) + ": " + marks[i]);
        System.out.println("Average: " + average);
    }
}
