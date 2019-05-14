package threads;

public class Producer implements Runnable {

    private Printer printer;

    Producer(Printer printer) {
        this.printer = printer;
    }

    @Override
    public void run() {
        int i = 0;
        while (true) {
            printer.put(i);
            i += 1;
        }
    }
}
