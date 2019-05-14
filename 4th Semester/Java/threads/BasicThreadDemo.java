package threads;

public class BasicThreadDemo {

    public static void main(String[] args) {
        Thread currentThread = Thread.currentThread();
        currentThread.setName("IronChain");
        try {
            System.out.println(currentThread);
            currentThread.sleep(5000);
            System.out.println("Bye Bye");
        } catch (InterruptedException e) {
            System.out.println("Therad Interrupted");
        }
    }
}
