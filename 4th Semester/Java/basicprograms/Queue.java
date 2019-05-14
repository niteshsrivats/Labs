package basicprograms;

import java.util.Scanner;

public class Queue {

    private static int size, front = -1, rear = -1;
    private static int[] queue;
    private static Scanner s = new Scanner(System.in);

    private static void insert() {

        if (rear == size - 1)
            System.out.println("Queue Overflow");
        else {
            if (rear == -1)
                front += 1;
            rear += 1;
            System.out.print("Enter Number to Insert: ");
            queue[rear] = s.nextInt();
        }
    }

    private static void delete() {

        if (front == -1)
            System.out.println("Queue Underflow");
        else {
            System.out.println("Deleted: " + queue[front]);
            if (front == rear)
                front = rear = -1;
            else
                front += 1;
        }
    }

    private static void display() {

        if (rear == -1)
            System.out.println("Queue Empty");
        else {
            System.out.print("The Queue: ");
            for (int i = front; i <= rear; i++)
                System.out.print(queue[i] + " ");
            System.out.println();
        }
    }

    public static void main(String[] args) {
        System.out.print("Enter Size of Queue: ");
        size = s.nextInt();
        queue = new int[size];
        int choice = 1;

        while (choice != 0) {
            System.out.println("1. Insert\n2. Delete\n3. Display\n0. Exit");
            choice = s.nextInt();

            switch (choice) {
                case 1:
                    insert();
                    break;
                case 2:
                    delete();
                    break;
                case 3:
                    display();
                    break;
            }
        }
    }
}
