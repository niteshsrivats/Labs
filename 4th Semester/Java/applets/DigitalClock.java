package applets;

import java.applet.Applet;
import java.awt.*;
import java.util.Date;

/* <applet code="DigitalClock" width=200 height=100></applet> */

public class DigitalClock extends Applet implements Runnable {

    Date date = new Date();

    public void start() {
        new Thread(this).start();
    }

    @Override
    public void run() {
        try {
            while (true) {
                this.date = new Date();
                repaint();

                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            System.out.println("Thread Interrupted");
        }
    }

    public void paint(Graphics g) {
        g.drawString(date.toString(), 20, 50);
    }
}
