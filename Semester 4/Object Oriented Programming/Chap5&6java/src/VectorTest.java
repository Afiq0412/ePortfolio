import java.util.Vector;

public class VectorTest {
    public static void main(String[] args) {
        Vector<Object> v = new Vector<>();

        v.addElement("Jamil");
        v.addElement(15.0);
        v.addElement(35.5);
        v.addElement(100);
        v.addElement(250);

        int sum = 0;
        for (int i = 0; i < v.size(); i++) {
            Object temp = v.elementAt(i);
            if (temp instanceof Integer) {
                sum += (Integer) temp;
            }
        }

        System.out.println("Sum of Double elements in vector v is: " + sum);
        System.out.println(v.capacity());
        System.out.println(v.size());

    }
}
