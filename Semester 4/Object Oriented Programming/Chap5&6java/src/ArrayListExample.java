import java.util.ArrayList;

public class ArrayListExample {
    public static void main(String[] args) {
        ArrayList<String> potions = new ArrayList<>();
        potions.add("Healing Potion");
        potions.add("Mana Potion");
        potions.add("Stamina Potion");
        potions.add("Love Potion");
        potions.add("Fire Resistance Potion");

        System.out.println("ArrayList Potions: " + potions + "\n");

        // for (String potion: potions) {
        //     System.out.println("Type of potion: " + potion);
        // }
        potions.set(4,"Agility Potion");
        //potions.add("Strength Potion");
        //potions.add("Intelligence Potion");

        System.out.println("Size of ArrayList: " + potions.size() + "\n");
        System.out.println("List of Potions:");
        for (int i = 0; i<potions.size(); i++){
            System.out.println((i+1) + ") " + potions.get(i));
        }

        System.out.println(potions.indexOf("Love Potion"));

        //potions.clear();
        //System.out.println("After removal: " + potions);
    }
}