package classesprograms;

public class Sphere extends Solid {

    private float radius;
    Sphere(float radius) {
        this.radius = radius;
        calculate();
    }

    public void calculate() {
        surfaceArea = 4 * PI * radius * radius;
        volume = 4 * PI * radius * radius * radius / 3;
    }

    public void display() {
        System.out.println("Sphere Surface Area: " + surfaceArea);
        System.out.println("Sphere Volume: " + volume);
    }
}
