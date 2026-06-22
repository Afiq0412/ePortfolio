import java.util.ArrayList;

class CircleArrayList {
    private double radius;
    public CircleArrayList(double radius) {
    this.radius=radius;
    }
    public void setRadius(int radius) {
    this.radius = radius;
    }
    public double getRadius() {
    return radius;
    }
    public double getArea() {
    return (Math.PI*radius*radius);
    }
    }

public class TestCircleAL {
    public static void main(String[] args) {
        // Use generics to make the list type-safe
        ArrayList<CircleArrayList> cList = new ArrayList<>();

        // Add CircleArrayList objects to the list
        cList.add(new CircleArrayList(2.3));
        cList.add(new CircleArrayList(3.3));

        // Access the first element and print its area
        double area = cList.get(0).getArea();
        System.out.printf("The area: %.2f%n", area);
    }
}

