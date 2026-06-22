public class TryThrowFinallyExample {
    public static void main(String[] args) {
        int age = 9;

        try {
            // We check the age
            if (age < 0) {
                // If it's invalid, we throw an exception
                throw new IllegalArgumentException("Age cannot be negative!");
            }

            System.out.println("Age is valid: " + age);
        } catch (IllegalArgumentException e) {
            // We catch the exception here
            System.out.println("Caught an exception: " + e.getMessage());
        } finally {
            // This will always run, no matter what
            System.out.println("This is the finally block. It always runs!");
        }

        System.out.println("Program continues...");
    }
}
