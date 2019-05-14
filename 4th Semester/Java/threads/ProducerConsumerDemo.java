package threads;

public class ProducerConsumerDemo {

    public static void main(String[] args) {
        Printer printer =  new Printer();
        Producer producer = new Producer(printer);
        Consumer consumer = new Consumer(printer);
        new Thread(producer).start();
        new Thread(consumer).start();
    }
}
