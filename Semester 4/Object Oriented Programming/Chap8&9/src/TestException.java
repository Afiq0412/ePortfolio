import java.io.*;

public class TestException {
    public static void main(String[] args) throws IOException {
        try {
            method();
            System.out.println("After method call");
        } catch (ArithmeticException ex) {
            System.out.println("ArithmeticException");
        } catch (RuntimeException ex) {
            System.out.println("RunTimeException");
        } catch (Exception ex) {
            System.out.println("Exception");
        }
    }

    static void method() throws Exception {
        System.out.println(1 / 0);
    }
}