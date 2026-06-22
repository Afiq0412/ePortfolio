import java.util.ArrayList;
import java.util.Scanner;

public class StaffSalary {

    static ArrayList<Staff> staffList = new ArrayList<>(); 

    static final int fulltimeBonus = 500; 

    public static void main(String[] args) {

        StaffSalary obj = new StaffSalary();
        obj.populateData();

        obj.calculateSalary(staffList); 
    }

    public void populateData() {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter number of staff: ");
        int total = input.nextInt(); 

        for (int i = 0; i < total; i++) {
            System.out.println();
            System.out.println("Staff #" + (i+1));

            System.out.print("Enter Staff ID: ");
            String id = input.next();

            System.out.print("Enter Name: ");
            String name = input.next();

            System.out.print("Enter Staff Type (F/P): ");
            char type = input.next().charAt(0);

            if (type == 'F') {
                System.out.print("Enter Basic Salary: ");
                double salary = input.nextDouble(); 

                Staff s = new Staff(id, name, salary, 0, 0, "FullTime"); 
                staffList.add(s);

            } else if (type == 'P') {
                System.out.print("Enter rate/hour: ");
                Double rate = input.nextDouble(); 

                System.out.print("Enter total hours: ");
                int hrs = input.nextInt();

                Staff s = new Staff(id, name, 0.0, rate, hrs, "PartTime"); 
                staffList.add(s);
            }
        }
        input.close();
    }

    public void calculateSalary(ArrayList<Staff> list) { 
        for (int i = 0; i < list.size(); i++) {
            Object ob = list.get(i); 
            Staff s = (Staff) ob; 

            double salary = s.getSalary(s.type); 
            display(s, salary);
        }
    }

    public void display(Staff s, double amount) {
        System.out.println("Staff ID: " + s.staffID);
        System.out.println("Name: " + s.name);
        System.out.println("Salary: " + amount);
        System.out.println();
    }
}

class Staff {
    String staffID;
    String name;
    double basicSalary;
    double ratePerHour;
    int totalHours;
    String type;

    public Staff(String id, String name, double salary, double rate, int hours, String t) {
        staffID = id;
        this.name = name;
        basicSalary = salary;
        ratePerHour = rate;
        totalHours = hours;
        type = t;
    }

    public double getSalary(String type) { 
        if (type.equals("FullTime")) {
            return basicSalary + StaffSalary.fulltimeBonus; 
        } else if (type.equals("PartTime")) {
            return ratePerHour * totalHours;
        } else {
            return 0.0;
        }
    }
}
