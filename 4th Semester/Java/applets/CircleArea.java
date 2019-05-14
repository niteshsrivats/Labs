package applets;

import java.applet.Applet;
import java.awt.*;

/* <applet code="CircleArea" width=150 height=150></applet> */

public class CircleArea extends Applet {

    float diameter = 1;
    float area;

    public void start() {
        this.area = (float) (Math.PI * diameter * diameter / 4);
    }

    public void paint(Graphics g) {
        g.drawString(Float.toString(area), 50, 75);
    }
}
