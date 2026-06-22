class Employee {
    private String name;
    private int id;

    public Employee(){
        System.out.println("Employee default cosntructor called");
    }

    public Employee(String name, int id) {
        this.name = name;
        this.id = id;
    }

    public void displayInfo(){
        System.out.println("Employee name: " + name);
        System.out.println("Employee id: " + id);
    }
}

class Manager extends Employee{
    private String department;

    public Manager(String name, int id, String department){
        super(name, id);
        this.department = department;
    }

    //@Override
    public void displayInfo(){
        System.out.println("Manager Details");
        super.displayInfo();
        System.out.println("Department: " + department);
    }
}

public class Main{
    public static void main(String[] args){
        Manager m = new Manager("Ali", 111, "IT");
        m.displayInfo();
    }
}
