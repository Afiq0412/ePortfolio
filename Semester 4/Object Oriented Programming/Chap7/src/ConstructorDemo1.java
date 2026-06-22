class SuperClass1 {
    public SuperClass1() { /** Constructor */
        System.out.println("This is the " +
                "superclass constructor.");
    }
}

class SubClass1 extends SuperClass1 {
    public SubClass1() {/** Constructor */
        // implicit call
        System.out.println("This is the " +
                "subclass constructor.");
    }
}

public class ConstructorDemo1 {
    public static void main(String[] args) {
        SubClass1 obj = new SubClass1();
    }
}