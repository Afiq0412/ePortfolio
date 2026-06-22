//Refer class 22th May - incomplete.pdf for UML class diagram

import java.util.ArrayList;

class Name {
    private String firstName;
    private String lastName;

    public Name(String firstName, String lastName){
        this.firstName = firstName;
        this.lastName = lastName;
    }

    public String getFullName(){
        return firstName + " " +lastName;
    }

}

class Address1 {
    private String street;
    private String city;
    private String postcode;

    public Address1(String street, String city, String postcode){
        this.street = street;
        this.city = city;
        this.postcode = postcode;
    }

    public String getFullAddress(){
        return toString();
    }

    public String toString() {
        return street + ", " + city + ", " + postcode;
    }
}

class Patient {
    private Name name; // Composition
    private Address1 address; // Aggregation
    
    public Patient(String first, String last, Address1 address){
        this.name = new Name(first, last); // Compostion created inside
        this.address = address; // Aggregation passed to outside
    }

    public void display(){
        System.out.println("Patient Full Name: " + name.getFullName());
        System.out.println("Patient Address: " + address.getFullAddress());
    }

}

class Hospital {
    private String name;
    private ArrayList<Patient> patients;

    public Hospital(String name){
        this.name = name;
        patients = new ArrayList<>();
    }
    public void addPatient(Patient p){
        patients.add(p);
    }
    public void displayInfo(){
        System.out.println("Hospital Name: " + name);
        System.out.println("Total patient: " + patients.size() + "\n");
        System.out.println("List of patients:");
        
        for(Patient p : patients){
            System.out.println("----------------------------------------------");
            p.display();
        }
    }
}

// Main class
public class HospitalManagementSystem {
    public static void main(String[] args) {
        
        // Create Address objects
        Address1 address = new Address1("Jalan Kenangin", "Kota Rengit", "80000");
        Address1 address1 = new Address1("Jalan Permata", "Kota Semenyih", "81000"); 
        
        // Create Patient objects
        Patient patient = new Patient("Afiq", "Danial", address);
        Patient patient1 = new Patient("Akif", "Dayyan", address1);
        

        // Create Hospital object
        Hospital hosp = new Hospital("Hospital Sultan Ismail");
        

        // Association: Add patients to hospital
        hosp.addPatient(patient);
        hosp.addPatient(patient1);
        
        // Output
        hosp.displayInfo();
    }
}

