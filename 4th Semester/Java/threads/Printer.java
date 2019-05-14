package threads;

class Printer {
    private int n;

    synchronized int get() {
        try {
            System.out.println("Get: " + n);
            notify();
            wait();
            return n;
        } catch (InterruptedException e) {
            System.out.println("Get Method Interrupted");
            return -1;
        }
    }

    synchronized void put(int n) {
        try {
            this.n = n;
            System.out.println("Put: " + n);
            notify();
            wait();
        } catch(InterruptedException e) {
            System.out.println("Put Method Interrupted");
        }
    }
}
