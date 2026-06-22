import java.util.*;

// Association Example 1: Student register Course

class Student {
  private String name;
  private String matrix;
  private Course[] courseList;
  private int numOfCourse;

  public Student(String n, String m, String c) {
    name = n;
    matrix = m;
    courseList = new Course[10];
  }

  public String getName() {
    return name;
  }

  public String getMatrix() {
    return matrix;
  }

  public void registerCourse(Course cs) {
    courseList[numOfCourse] = cs;
    numOfCourse++;
  }

  public int getNumOfCourse() {
    return numOfCourse;
  }

  public void printAllInfo() {
    System.out.println("\nSTUDENT NAME :" + name);
    System.out.println("NUMBER OF SUBJECT(s) TAKEN :" + numOfCourse);
    System.out.println("LIST OF SUBJECT(s) TAKEN :");
    for (int i = 0; i < numOfCourse; i++) {
      Course s = (Course) courseList[i];
      System.out.println((i + 1) + ". " + s.getName());
    }
  }
} // Student

// -----------------------------------------------------------------------------

class Course {
  private String name;
  private String code;
  private int section;

  public Course(String n, String c, int s) {
    name = n;
    code = c;
    section = s;
  }

  public String getName() {
    return name;
  }
} // Course

public class TestAssociate {
  public static void main(String args[]) {
    Course cs1 = new Course("OOP", "SCP3103", 3);
    Course cs2 = new Course("TP1", "SCJ1013", 3);
    Course cs3 = new Course("TP2", "SCJ1213", 3);
    Course cs4 = new Course("KP", "SCP2113", 3);

    Student s1 = new Student("ALI", "AC1234", "2SCS");
    s1.registerCourse(cs1);
    s1.registerCourse(cs2);
    s1.printAllInfo();
    System.out.println();

    Student s2 = new Student("AHMAD", "AC1122", "3SCK");
    s2.registerCourse(cs1);
    s2.registerCourse(cs3);
    s2.registerCourse(cs4);
    s2.printAllInfo();
  }

} // TestAssociate