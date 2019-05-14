package threads;

public class Consumer implements Runnable {

    private Printer printer;

    Consumer(Printer printer) {
        this.printer = printer;
    }

    @Override
    public void run() {
        while (true) {
            printer.get();
        }
    }
}
