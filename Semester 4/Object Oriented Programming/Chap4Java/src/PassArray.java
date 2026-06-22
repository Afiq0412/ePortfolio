import java.util.*;

public class PassArray {
    public static void main(String[] args) {
        final int SIZE = 4;
        int[] numbers = new int[SIZE];
        getValues(numbers);
        System.out.println("Here are the numbers.");
        showArray(numbers);
        System.out.println();
    }

    public static void getValues(int[] arr) {
        Scanner kb = new Scanner(System.in);
        System.out.println("Enter a series of " + arr.length + " numbers.");
        for (int i = 0; i < arr.length; i++) {
            System.out.print("Enter number " + (i + 1) + ": ");
            arr[i] = kb.nextInt();
        }
        kb.close();
    }

    public static void showArray(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
