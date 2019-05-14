package classesprograms;

public class Cylinder extends Solid {

    private float radius, height;

    Cylinder(float height, float radius) {
        this.height = height;
        this.radius = radius;
        calculate();
    }

    public void calculate() {
        surfaceArea = 2 * PI * radius * (radius + height);
        volume = PI * radius * radius * height;
    }

    public void display() {
        System.out.println("Cylinder Surface Area: " + surfaceArea);
        System.out.println("Cylinder Volume: " + volume);
    }
}
