/*
TEST 2 (PRACTICAL)
SUBJECT CODE    : SECJ2154
SUBJECT NAME    : OBJECT ORIENTED PROGRAMMING
YEAR/COURSE     : 2 (SECB/ SECJ/ SECP/ SECR/ SECV)
TIME            : 02:00 PM– 04:00 PM MYT (2 HOURS)
DATE            : 27th MAY 2025 (TUESDAY)

NAME            : MUHAMMAD AFIQ DANIAL BIN ROZAIDIE
MATRIC NO       : A23CS0117
YEAR/PROGRAM    : 2 SECPH
SECTION         : 02
LECTURER NAME   : DR ZURAINI

Objective:
Refer Question Booklet.
*/

import java.util.ArrayList;

class Bank { //Total 15 marks for Bank class
    private String name;
    private Address address;
    private ArrayList<Account> accounts;

    public Bank(String name, Address address){
        this.name = name;
        this.address = address;
        accounts = new ArrayList<>();
    }
    public String getName(){
        return name;
    }
    public String getAddress(){
        return address.getFullAddress();
    }
    public void addAccount(Account account){
        accounts.add(account);
    }
    public void removeAccount(Account account){
        accounts.remove(account);
    }
    public void printAllInfo(){
        System.out.println("Bank Name: " + name);
        System.out.println("Bank Address: " + getAddress());
        System.out.println("Number of Account(s) Registered: " + accounts.size());
        System.out.println("List of Account(s):");
        for (int i = 0; i < accounts.size(); i++){
            System.out.println((i+1) + ". Account #: " +  accounts.get(i).getAccountNumber()
            + ", Type: " + accounts.get(i).getType());
        }
        System.out.println();
    }
}

class Account { //Total 15 marks
    private String accountNumber;
    private String owner;
    private double balance;
    private String type;
    private ArrayList<Transaction> transactions;

    public Account(String accountNumber, String type){
        this.accountNumber = accountNumber;
        this.type = type;
        transactions = new ArrayList<>();
    }
    public void setOwner(String owner){
        this.owner = owner;
    }
    public String getAccountNumber(){
        return accountNumber;
    }
    public double getBalance(){
        return balance;
    }
    public String getType(){
        return type;
    }
    public void deposit(double amount){
        balance += amount;
        transactions.add(new Transaction("Deposit", balance));
    }
    public void withdraw(double amount){
        balance -= amount;
        transactions.add(new Transaction("Withdrawal", amount));

    }
    public void printAllInfo(){
        System.out.println("Account #: " + accountNumber);
        System.out.println("Owner: " + owner);
        System.out.println("Type: " + type);
        System.out.println("Balance: " + balance);
        System.out.println("Number of Transaction(s): " + transactions.size());
        System.out.println("List of Transaction(s):");
        for (int i = 0; i < transactions.size(); i++){
            System.out.println((i+1) + ". Type: " + transactions.get(i).getTransactionType() + 
            ", Amount: " + transactions.get(i).getAmount());
        }
        System.out.println();
    }
}

class Customer { //Total 15 marks
    private String customerID;
    private String name;
    private Address address;
    private ArrayList<Account> accounts;

    public Customer(String customerId, String name, Address address){
        this.customerID = customerId;
        this.name = name;
        this.address = address;
        accounts = new ArrayList<>();
    }
    public String getCustomerID(){
        return customerID;
    }
    public String getName(){
        return name;
    }
    public String getAddress(){
        return address.getFullAddress();
    }
    public void addAccount(Account account, Bank bank){
        accounts.add(account);
        bank.addAccount(account);
        account.setOwner(this.name);
    }
    public void removeAccount(Account account, Bank bank){
        accounts.remove(account);
        bank.removeAccount(account);
        account.setOwner(null);
    }
    public void printAllInfo(){
        System.out.println("Customer Name: " + name);
        System.out.println("Customer ID: " + customerID);
        System.out.println("Customer Address: " + getAddress());
        System.out.println("Number of Account(s) Registered: " + accounts.size());
        System.out.println("List of Account(s):");
        for (int i = 0; i < accounts.size(); i++){
            System.out.println((i+1) + ". Account #: " +  accounts.get(i).getAccountNumber() +
            ", Balance: " + accounts.get(i).getBalance() + 
            ", Type: " + accounts.get(i).getType());
        }
        System.out.println();
    }
}

class Address { //Total 5 marks
    private String roadName;
    private String city;
    private String state;
    private String country;

    public Address(String roadName, String city, String state, String country){
        this.roadName = roadName;
        this.city = city;
        this.state = state; 
        this.country = country;
    }
    public String getFullAddress(){
        return roadName + ", " + city + ", " + state + ", " + country;
    }
}

class Transaction { //Total 5 marks
    private String transactionType;
    private double amount;

    public Transaction(String transactionType, double amount){
        this.transactionType = transactionType;
        this.amount = amount;
    }
    public String getTransactionType(){
        return transactionType;
    }
    public double getAmount(){
        return amount;
    }
}

public class BankingSystem { //Total 15 marks
    public static void main(String[] args) {
        // Create TWO (2) address objects, 1 for bank and 1 for customer
        Address a1 =  new Address("Jalan Kebudayaan", "Skudai", "Johor", "Malaysia");
        Address a2 =  new Address("Jalan Pendidikan", "Skudai", "Johor", "Malaysia");

        // Create a bank object
        Bank b = new Bank("Beacon Bank", a1);

        // Create a customer object
        Customer c = new Customer("C001", "John Doe", a2);

        // Create an account object and link it to the customer object
        Account acc1 = new Account("A001", "Savings");
        c.addAccount(acc1, b);

        // Create another account object and link it to the customer object
        Account acc2 = new Account("A002", "Current");
        c.addAccount(acc2, b);

        // Deposit and withdraw from the first account
        acc1.deposit(1000);
        acc1.withdraw(200);

        // Deposit to the second account
        acc2.deposit(2000);

        // Print info for bank, account 1 & 2, customer
        b.printAllInfo();
        acc1.printAllInfo();
        acc2.printAllInfo();
        c.printAllInfo();

        // Remove account 2 from customer
        c.removeAccount(acc2, b);

        // Print info for bank, customer
        b.printAllInfo();
        c.printAllInfo();
    }
}
