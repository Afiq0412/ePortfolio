public class TestWrapper {

    public static void main(String[] arg) {
        int year = 1957;
        Integer obj1; // an object
        obj1 = year;
        System.out.println("Object 1 - obj1: " + obj1);
        Integer obj2 = Integer.valueOf(1956);
        int num2;
        num2 = obj2; // unboxing
        System.out.println("Number, num2: " + num2);
        System.out.println("Object 2 - obj2: " + obj2);

        double d2 = Double.parseDouble("3.14");
        System.out.println("d2 = " + d2); // result is d2 : 3.14
        Double d3 = Double.valueOf("3.14"); // create a Double object
        System.out.println(d3 instanceof Double); // result is “true”
    }
}