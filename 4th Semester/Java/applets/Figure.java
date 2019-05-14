package applets;

import java.applet.Applet;
import java.awt.*;

/* <applet code="Figure" width=400 height=400></applet> */

public class Figure extends Applet {

        public void paint(Graphics g) {
            // Face
            g.drawOval(75, 75, 250, 250);
            // Eyes
            g.fillOval(130, 150, 40, 20);
            g.fillOval(230, 150, 40, 20);
            // Nose
            g.drawLine(200, 200, 200, 160);
            // Smile
            g.drawArc(150, 200, 100, 50, 0, -180);
        }
}
