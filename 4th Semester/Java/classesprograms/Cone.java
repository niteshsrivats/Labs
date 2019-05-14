package classesprograms;

public class Cone extends Solid {

    private float radius, height;

    Cone(float height, float radius) {
        this.height = height;
        this.radius = radius;
        calculate();
    }

    public void calculate() {
        surfaceArea = (float)(PI * radius * (radius + Math.sqrt(height * height + radius * radius)));
        volume = PI * radius * radius * height / 3;
    }

    public void display() {
        System.out.println("Cone Surface Area: " + surfaceArea);
        System.out.println("Cone Volume: " + volume);
    }
}
