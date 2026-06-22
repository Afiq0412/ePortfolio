public class AutoUnboxingDemo {
    public static void main(String[] args) {
        // Autoboxing: int → Integer
        double a = 9.11;
        Double objA = a;
        System.out.println("Autoboxing: int 50 -> Integer: " + objA);
        // Unboxing: Integer → int
        Integer objB = 60;
        int b = objB;
        System.out.println("Unboxing: Integer 60 -> int: " + b);
        // Example in expression
        Integer x = 10;
        Integer y = 20;
        int sum = x + y; // Unboxing happens here
        System.out.println("Sum using unboxed Integer: " + sum);
    }
}
