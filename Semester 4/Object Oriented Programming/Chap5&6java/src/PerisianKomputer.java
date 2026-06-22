import java.util.Vector;

public class PerisianKomputer {
    public static void main(String[] args) {
        // Use generics for type safety (Object means any type can be stored)
        Vector<Object> perisian = new Vector<>();

        // Autoboxing instead of deprecated constructors    
        String nama = "Visual Image";
        Integer siri = 1235;
        Double harga = 2134.5;
        String pengeluar = "Oracle";
        Character test = 'a';  // Fixed quote character
        Float code = 12.34f;

        // Add elements to the vector
        perisian.add(nama);
        perisian.add(siri);
        perisian.add(harga);
        perisian.add(pengeluar);
        perisian.add(test);
        perisian.add(code);

        // Print vector contents
        System.out.println("Kandungan vektor:");
        System.out.println(perisian);
    }
}
