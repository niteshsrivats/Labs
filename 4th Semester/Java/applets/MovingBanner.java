package applets;

import java.applet.Applet;
import java.awt.*;

/* <applet code="MovingBanner" width=300 height=150></applet> */

public class MovingBanner extends Applet implements Runnable {

    private String message = "Department of Computer Science and Engineering ";
    private boolean running = false;

    public void start() {
        running = true;
        new Thread(this).start();
    }

    @Override
    public void run() {
        try {
            while (running) {
                message = message.substring(1) + message.charAt(0);
                repaint();
                Thread.sleep(250);
            }
        } catch (InterruptedException e) {
            System.out.println("Thread Interrupted");
        }
    }

    public void paint(Graphics g) {
        g.drawString(message, 10, 75);
    }

    public void stop() {
        running = false;
    }
}
