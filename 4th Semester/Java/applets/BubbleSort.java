package applets;

import java.applet.Applet;
import java.awt.*;
import java.util.ArrayList;
import java.util.Arrays;

/* <applet code="BubbleSort" width=200 height=250></applet> */

public class BubbleSort extends Applet implements Runnable {

    private int[] array = {5, 4, 3, 2, 1};
    private ArrayList<String> arrays;

    public BubbleSort() {
        int size = (array.length * (array.length - 1)) / 2;
        arrays = new ArrayList<>(size);
    }

    public void start() {
        new Thread(this).start();
    }

    @Override
    public void run() {
        int temp;
        for (int i = 0; i < array.length; i++) {
            for (int j = 0; j < array.length - i - 1; j++) {
                if (array[j + 1] < array[j]) {
                    temp = array[j + 1];
                    array[j + 1] = array[j];
                    array[j] = temp;
                    arrays.add(Arrays.toString(array));
                    repaint();
                    try {
                        Thread.sleep(500);
                    } catch (InterruptedException e) {
                        System.out.println("Thread Interrupted.");
                    }
                }
            }
        }
    }

    public void paint(Graphics g) {
        for (int i = 0; i < arrays.size(); i++) {
            g.drawString(arrays.get(i), 10, 20 * (i + 1));
        }
    }
}
