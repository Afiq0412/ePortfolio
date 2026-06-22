class SuperClass2 {
    public SuperClass2() { // Constructor #1
        System.out.println("This is the superclass " +
                "no-arg constructor.");
    }

    public SuperClass2(int arg) { // Constructor #2
        System.out.println("The following argument was" +
                "passed to the superclass constructor: " + arg);
    }
}

class SubClass2 extends SuperClass2 {
    public SubClass2() { // Constructor
        super(10); // explicit call
        System.out.println("This is the " +
                "subclass constructor.");
    }
}

public class ConstructorDemo2 {
    public static void main(String[] args) {
        SubClass2 obj = new SubClass2();
    }
}