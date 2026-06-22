interface Salary {
    double calculateSalary();
}

abstract class Employee implements Salary {
    protected String name;
    protected String role;

    public Employee(String name, String role) {
        this.name = name;
        this.role = role;
    }

 public abstract double calculateSalary();

    public void printDetails() {
        System.out.println("Role: " + role);
        System.out.println("Name: " + name);
        System.out.println("Salary: RM " + calculateSalary());
    }
}

class Manager extends Employee {
    public Manager(String name) {
        super(name, "Manager");
    }

 public double calculateSalary()
    {
        return 9000.0;
    }
}

class Programmer extends Employee {
    public Programmer(String name) {
        super(name, "Programmer");
    }

 public double calculateSalary()
    {
        return 5600.0;
    }
}

public class TestSalary { 
    public static void main(String[] args) {
        Employee manager = new Manager("Faiz Ali");
        Employee programmer = new Programmer("Ely Tan");
        manager.printDetails();
        System.out.println();
        programmer.printDetails();
    }
}
