import java.util.ArrayList;
import java.util.Vector;

public class AQList {
    public static void main(String[] args) {
        ArrayList<String> arrayList = new ArrayList<>();
        arrayList.add("Banana");
        arrayList.add("Olive");
        arrayList.add("Date");
        arrayList.add("Fig");
        System.out.println("List: " + arrayList);

        Vector<String> vector = new Vector<>();
        vector.add("Ants");
        vector.add("Bee");
        vector.add("Cow");
        vector.add("Dog");
        System.out.println("Vector: " + vector);

        arrayList.set(1, "Grape");
        arrayList.remove(0);

        vector.remove("Cow");
        vector.setElementAt("Fish", 2);

        System.out.println("List: " + arrayList);
        System.out.println("Vector: " + vector);
    }
}
