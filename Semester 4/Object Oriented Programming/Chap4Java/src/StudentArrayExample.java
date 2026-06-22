// Define the Student class
class Student {
    String name;
    int age;

    // Constructor
    Student(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // Method to display student info
    void displayInfo() {
        System.out.println("Name: " + name + ", Age: " + age);
    }
}

// Main class
public class StudentArrayExample {
    public static void main(String[] args) {
        // Create an array of Student objects with size 3
        Student[] students = new Student[3];

        // Initialize each element with a Student object
        students[0] = new Student("Alice", 20);
        students[1] = new Student("Bob", 22);
        students[2] = new Student("Charlie", 19);

        // Display student information
        for (int i = 0; i < students.length; i++) {
            students[i].displayInfo();
        }
    }
}
